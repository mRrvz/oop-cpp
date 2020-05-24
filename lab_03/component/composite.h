#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "component.h"
#include "model.h"

class composite : public component
{
public:
    composite() = default;
    composite(std::shared_ptr<component> &component);
    composite(vector<std::shared_ptr<component>> vector);

    size_t size() const;

    virtual bool add(const std::shared_ptr<component> &component) override;
    virtual bool remove(const iterator<std::shared_ptr<component>> &iterator) override;

    virtual iterator<std::shared_ptr<component>> begin() override;
    virtual iterator<std::shared_ptr<component>> end() override;

    virtual bool is_composite() const override;
    virtual void draw(draw_manager &manager) const override;
    virtual void reform(const point &move, const point &scale, const point &turn) override;

private:
    vector<std::shared_ptr<component>> components;

};

class cams_composite : public camera_obj
{
public:
    cams_composite() = default;
    cams_composite(std::shared_ptr<camera_obj> &obj);
    cams_composite(vector<std::shared_ptr<camera_obj>> vector);

    size_t size() const;

    virtual bool add(const std::shared_ptr<camera_obj> &component) override;
    virtual bool remove(const iterator<std::shared_ptr<camera_obj>> &iterator) override;

    virtual iterator<std::shared_ptr<camera_obj>> begin() override;
    virtual iterator<std::shared_ptr<camera_obj>> end() override;

    virtual bool is_composite() const override;
    virtual void reform(const point &move) override;

private:
    vector<std::shared_ptr<camera_obj>> objects;
};

#endif
