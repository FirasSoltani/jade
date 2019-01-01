#include "webcam.h"
#include "ui_webcam.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QFileDialog>

Webcam::Webcam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Webcam)
{
    ui->setupUi(this);
    mCamera=new QCamera(this);
    mCameraViewfinder=new QCameraViewfinder(this);
    mCameraImageCapture=new  QCameraImageCapture(mCamera,this);
    mLayout=new QVBoxLayout;

    moptions=new QMenu("Options",this);
    mOpen=new QAction("Open",this);
    mClose=new QAction("Close",this);
    mCapture=new QAction("capture",this);

    moptions->addActions({mOpen,mClose, mCapture});
    ui->pushButton->setMenu(moptions);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);
    connect(mOpen,&QAction::triggered ,[&]( ) {
        mCamera->start();
    } );

    connect(mClose,&QAction::triggered ,[&]() {
        mCamera->stop();
    } );
    connect(mCapture,&QAction::triggered ,[&]() {
     auto filename=  QFileDialog::getSaveFileName(this,"capture","/","image (*.jpg;*.jpeg");
     if (filename.isEmpty()){
         return ;
     }
     mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600,1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    } );
}

Webcam::~Webcam()
{
    delete ui;
}
