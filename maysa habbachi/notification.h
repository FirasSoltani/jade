#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include <QDialog>

namespace Ui {
class notification;
}

class notification : public QDialog
{
    Q_OBJECT

public:
    explicit notification(QWidget *parent = nullptr);
    ~notification();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::notification *ui;
    QSystemTrayIcon *notifyIcon;

};


#endif // NOTIFICATION_H
