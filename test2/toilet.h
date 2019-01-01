#ifndef TOILET_H
#define TOILET_H

#include <QWidget>

namespace Ui {
class toilet;
}

class toilet : public QWidget
{
    Q_OBJECT

public:
    explicit toilet(QWidget *parent = nullptr);
    ~toilet();

private:
    Ui::toilet *ui;
};

#endif // TOILET_H
