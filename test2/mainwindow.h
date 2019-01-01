#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "components/qtmaterialappbar.h"
#include "components/qtmaterialiconbutton.h"
#include "components/lib/qtmaterialtheme.h"
#include "components/qtmaterialflatbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
