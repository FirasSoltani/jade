#ifndef WEBCAM_H
#define WEBCAM_H

#include <QDialog>

namespace Ui {
class Webcam;
}
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

class Webcam : public QDialog
{
    Q_OBJECT

public:
    explicit Webcam(QWidget *parent = nullptr);
    ~Webcam();

private:
    Ui::Webcam *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *moptions;
    QAction *mOpen;
    QAction *mClose;
    QAction *mCapture;
};

#endif // WEBCAM_H
