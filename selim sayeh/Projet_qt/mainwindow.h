#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "temperature.h"
#include "voiture.h"
#include "webcam.h"
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Temperature *T;
    Voiture *V;
    Webcam *C;
    QPropertyAnimation *Animation;
};

#endif // MAINWINDOW_H
