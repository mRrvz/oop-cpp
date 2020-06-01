#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QObject>

class button : public QPushButton
{
    Q_OBJECT;

    enum button_status
    {
        active,
        not_active
    };

public:
    button(QWidget *parent = nullptr);
    ~button() = default;

    void set_floor(const ssize_t &floor);

public slots:
    void pressed();
    void finish();

private:
    button_status status;
    ssize_t button_floor;
};

#endif
