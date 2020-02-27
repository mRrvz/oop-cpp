#include "points.h"

double to_radians(double (*f)(double), const double &angle)
{
    return (*f)(angle * PI / 180);
}

static err_t read_amount(FILE *f, pdata_t &points)
{
    if ((fscanf(f, "%d", &points.size)) != 1)
    {
        return READ_ERR;
    }

    if (points.size < 1)
    {
        return PSIZE_ERR;
    }

    return OK;
}

static err_t read_points(FILE *f, const int &size, point_t *const array)
{
    for (int i = 0; i < size; i++)
    {
        if ((fscanf(f, "%lf %lf %lf", &array[i].x, &array[i].y, &array[i].z)) != 3)
        {
            return READ_ERR;
        }
    }

    return OK;
}

static err_t allocate_links(pdata_t &points)
{
    point_t *temp_array = (point_t *)malloc(points.size * sizeof(point_t));

    if (temp_array == NULL)
    {
        return ALLOC_ERR;
    }

    points.array = temp_array;

    return OK;
}

void free_points(const pdata_t &points)
{
    if (points.array != NULL)
    {
        free(points.array);
    }
}

err_t handle_points(FILE *f, pdata_t &points)
{
    err_t error_code;

    if ((error_code = read_amount(f, points)))
    {
        return error_code;
    }

    if ((error_code = allocate_links(points)))
    {
        return error_code;
    }

    if ((error_code = read_points(f, points.size, points.array)))
    {
        free_points(points);
        return error_code;
    }

    return OK;
}

void move_point(point_t &point, const move_t &coeffs)
{
    point.x += coeffs.dx;
    point.y += coeffs.dy;
    point.z += coeffs.dz;
}

void scale_point(point_t &point, const scale_t &coeffs)
{
    point.x *= coeffs.kx;
    point.y *= coeffs.ky;
    point.z *= coeffs.kz;
}

void turn_xpoint(point_t &point, const double &angle)
{
    double cos_radians = to_radians(cos, angle);
    double sin_radians = to_radians(sin, angle);

    point.y = point.y + cos_radians + point.z * sin_radians;
    point.z = -point.y * sin_radians + point.z * cos_radians;
}

void turn_ypoint(point_t &point, const double &angle)
{
    double cos_radians = to_radians(cos, angle);
    double sin_radians = to_radians(sin, angle);

    point.x = point.x * cos_radians + point.z * sin_radians;
    point.z = -point.x * sin_radians + point.z * cos_radians;
}

void turn_zpoint(point_t &point, const double &angle)
{
    double cos_radians = to_radians(cos, angle);
    double sin_radians = to_radians(sin, angle);

    point.x = point.x * cos_radians + point.y * sin_radians;
    point.y = -point.x * sin_radians + point.y * cos_radians;
}

