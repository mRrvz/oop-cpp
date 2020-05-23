#ifndef FACADE_H
#define FACADE_H

#include "scene.h"
#include "../managers/load_manager.h"
#include "../managers/draw_manager.h"
#include "../managers/scene_manager.h"
#include "../managers/reform_manager.h"

class facade
{
public:
    static std::shared_ptr<facade> instance()
    {
        static std::shared_ptr<facade> _facade(new facade());

        return _facade;
    }

    ~facade() = default;

    void load_model(std::string fname); // ready
    void remove_model(const size_t &index);

    void add_camera();
    void remove_camera(const size_t &index);

    void draw_scene(std::shared_ptr<base_drawer> _drawer); // ready

    void reform_model(const size_t &model_numb, const point &move, const point &scale, const point &turn);
    void reform_models(const point &move, const point &scale, const point &turn);

    void reform_cam(const size_t &cam_numb, const double &x_shift, const double &y_shift);
    void reform_cams(const double &x_shift, const double &y_shift);

private:
    facade() = default;
    facade(const facade &) = delete;
    facade &operator=(const facade &) = delete;

    scene_manager _scene_manager;
    load_manager _load_manager;
    draw_manager _draw_manager;
    reform_manager _reform_manager;
    //camera_manager _camera_manager;
};

#endif