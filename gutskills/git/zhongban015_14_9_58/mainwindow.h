#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mylabel.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QImage>
#include<opencv2\opencv.hpp>
#include<QTimer>

using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void zoomIn();
    void zoomOut();
	void play(int temp_video);
	void play_pause_video(int );
	QImage MatToQImage(const cv::Mat& mat);
private:
    Ui::MainWindow *ui;
    QImage *image;
    QImage select_image;//label_2显示图片
    QImage* imgScaled ;//放大图片
    QImage *img1;
    QImage *img2;
    QImage *img3;
    QString filename;
    QString firstname;
    QString imagename;
	int i;
	//video_parameters
	string video_path;
	QTimer *theTimer;
	QString video_delay;
	VideoCapture capture;
	Mat current_frame;
	int *delay_video;
	int *time_pause_video;



private slots:
    void openFile();
    void getRect(QRect);
    void saveRect();
    void next_image();
    void up_image();
	//video
	void open_video();
    void on_start_video_clicked();
	void updateImage();
	void paintEvent(QPaintEvent *e);
    void on_pause_button_clicked();

};

#endif // MAINWINDOW_H
