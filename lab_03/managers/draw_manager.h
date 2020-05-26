#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include "../gui/drawer.h"
#include "../scene/scene.h"
#include "../visitor/visitor.h"

class draw_manager : public visitor
{
public:
    draw_manager() = default;
    draw_manager(draw_manager &manager) : _drawer(manager._drawer), cam(manager.cam) {};
    ~draw_manager() = default;

    virtual void visit(const camera &cam) override;
    virtual void visit(const model &model) override;
    virtual void visit(const cams_composite &composite) override;
    virtual void visit(const models_composite &composite) override;

    void set_drawer(std::shared_ptr<base_drawer>);
    void set_cam(std::shared_ptr<camera>);

private:
    point proect_point(const point &point);
    std::shared_ptr<base_drawer> _drawer;
    std::shared_ptr<camera> cam;
};

#endif
