#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QFileDialog>
#include <QLabel>
#include <QFile>
#include <QMessageBox>
#include <QImage>
#include <QDebug>
#include <QScrollArea>
#include <QMouseEvent>
#include <QMatrix>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*----------以后修改
     */
    centralWidget()->setMouseTracking(true);
        setMouseTracking(true);
        ui->label_select1->setMouseTracking(true);
        ui->label_select2->setMouseTracking(true);
        ui->label_select3->setMouseTracking(true);

		img1 = new QImage;
        img2 = new QImage;
        img3 = new QImage;
        img1->load("D:\\360极速浏览器下载\\1.jpg");
		img2->load("D:\\360极速浏览器下载\\2.jpg");
		img3->load("D:\\360极速浏览器下载\\3.jpg");

        ui->label_select1->setPixmap(QPixmap::fromImage(*img1));
        ui->label_select1->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->label_select2->setPixmap(QPixmap::fromImage(*img2));
        ui->label_select2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->label_select3->setPixmap(QPixmap::fromImage(*img3));
        ui->label_select3->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        /*----------以后修改
         */

		//定时器
		theTimer = new QTimer(this);
	connect(ui->action_O,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->label,SIGNAL(sendData(QRect)),this,SLOT(getRect(QRect)));
    connect(ui->action_S,SIGNAL(triggered()),this,SLOT(saveRect()));
    connect(ui->action_N,SIGNAL(triggered()),this,SLOT(next_image()));
    connect(ui->action_U,SIGNAL(triggered()),this,SLOT(up_image()));

	connect(ui->action_V, SIGNAL(triggered()),this,SLOT(open_video()));
	connect(theTimer, SIGNAL(timeout()), this, SLOT(updateImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openFile()
{
    i=0;
    image=new QImage(ui->label->width(),ui->label->height(),QImage::Format_RGB32);//image在头文件中定义,设置图片大小和图片类型      //RGB32位
    filename=QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("选择图像"),"",tr("Images (*.png *.bmp *.jpg *.tif *.GIF *.jpeg)")); //filename在头文件中定义
    firstname=filename.section('/',0,-2);
    if(!filename.isEmpty())
    {
        if(image->load(filename))//读取图像
        {
            ui->label->setAlignment(Qt::AlignCenter);//居中
            ui->label->setPixmap(QPixmap::fromImage(*image));
            ui->label->resize(QSize(image->width(),image->height()));//标签为图片大小
        }
        else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("打开图像失败"),QString::fromLocal8Bit("打开图像失败!"));
            delete image;
            return;
        }
    }
    else
    {
       return;
    }
}
void MainWindow::getRect(QRect select_Rect)
{
    select_image=image->copy(select_Rect);
    ui->label_2->setPixmap(QPixmap::fromImage(select_image));
    ui->label_2->setScaledContents(true);
 }
void MainWindow::saveRect()
{
    firstname=filename.section('/',0,-2);
    QString str=QString::number(i);
    QString image_rect_name=firstname+"/"+str+".jpeg";
    select_image.save(image_rect_name);
    QMessageBox::information(this,QString::fromLocal8Bit("截图成功"),QString::fromLocal8Bit("截图成功!"));
}
void MainWindow::next_image()
{
    i++;
    QDir dir(firstname);
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();
    QFileInfo fileInfo = list.at(i);
    imagename =firstname+"/"+fileInfo.fileName();
    //qDebug()<<fileInfo.fileName()<< imagename << endl;
    image=new QImage(ui->label->width(),ui->label->height(),QImage::Format_RGB32);//设置图片大小和图片类型
    if(!imagename.isEmpty())
                  {
                      if(image->load(imagename))//读取图像
                      {
                          ui->label->setPixmap(QPixmap::fromImage(*image));
                      }
                      else
                      {
                          QMessageBox::information(this,QString::fromLocal8Bit("打开图像失败"),QString::fromLocal8Bit("打开图像失败!"));
                          delete image;
                          return;
                      }
                  }
                  else
                  {
                     return;
                  }
}
void MainWindow::up_image()
{
    i--;
    QDir dir(firstname);
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList list = dir.entryInfoList();
    QFileInfo fileInfo = list.at(i);
    imagename =firstname+"/"+fileInfo.fileName();
    image=new QImage(ui->label->width(),ui->label->height(),QImage::Format_RGB32);//设置图片大小和图片类型
    if(!imagename.isEmpty())
                  {
                      if(image->load(imagename))//读取图像
                      {
                          ui->label->setPixmap(QPixmap::fromImage(*image));
                      }
                      else
                      {
                          QMessageBox::information(this,QString::fromLocal8Bit("打开图像失败"),QString::fromLocal8Bit("打开图像失败!"));
                          delete image;
                          return;
                      }
                  }
                  else
                  {
                     return;
                  }
}
void MainWindow::wheelEvent(QWheelEvent *event)
{
    QPoint pos;
    QPoint pos1;
    QPoint pos2;
    pos1 = mapToGlobal(QPoint(0,0));//将窗口坐标（0，0）转换成显示器坐标
    pos2 = event->globalPos();
    pos = pos2 - pos1;
    //horizontalScrollBar()->setValue(oldHPos);
   // verticalScrollBar()->setValue(oldVPos);
    //判断鼠标位置是否在图像显示区域
    if (pos.x() > ui->label->x() && pos.x() < ui->label->x()+ui->label->width()
            && pos.y() > ui->label->y() && pos.y() < ui->label->y()+ui->label->height())
    {
        // 当滚轮远离使用者时进行放大，当滚轮向使用者方向旋转时进行缩小
        if(event->delta() > 0)
        {
            zoomIn();
        }
        else
        {
            zoomOut();
        }
    }
    update();
}
void MainWindow::zoomIn()
{
    imgScaled = new QImage;
    qreal width = image->width();//获得以前图片的宽和高
    qreal height = image->height();
    *imgScaled = image->scaled(width*1.2,height*1.2,Qt::KeepAspectRatio);
    ui->label->setPixmap(QPixmap::fromImage(*imgScaled));
}
void MainWindow::zoomOut()
{
   imgScaled = new QImage;
    qreal width = image->width();//获得以前图片的宽和高
    qreal height = image->height();
    *imgScaled = image->scaled(width*0.8,height*0.8,Qt::KeepAspectRatio);
    ui->label->setPixmap(QPixmap::fromImage(*imgScaled));
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "haha11";
	QRect labelrect1 = QRect(ui->scrollArea->pos() + ui->centralWidget->pos() + ui->label_select1->pos(), ui->label_select1->size());
	QRect labelrect2 = QRect(ui->scrollArea->pos() + ui->centralWidget->pos() + ui->label_select2->pos(), ui->label_select2->size());
	QRect labelrect3 = QRect(ui->scrollArea->pos() + ui->centralWidget->pos() + ui->label_select3->pos(), ui->label_select3->size());
	if (labelrect1.contains(event->pos()))
	{
		qDebug() << "haha";
		
		ui->label_select->setPixmap(QPixmap::fromImage(*img1));

	}

	else if (labelrect2.contains(event->pos()))
	{
	
		ui->label_select->setPixmap(QPixmap::fromImage(*img2));
	}

	else if (labelrect3.contains(event->pos()))
	{
		
		ui->label_select->setPixmap(QPixmap::fromImage(*img3));
	}
}

void MainWindow::open_video()//打开视频
{
	QString video_file_path;
	video_file_path = QFileDialog::getOpenFileName(this, "open", "../");\
	video_path = video_file_path.toStdString();
	capture.open(video_path);
	play_pause_video(1);
	

}
void MainWindow::on_start_video_clicked()//播放按钮
{
	play_pause_video(1);
}


void MainWindow::updateImage()
{
	capture >> current_frame;
	if (current_frame.data)
	{
		cvtColor(current_frame, current_frame, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR  
		this->update();  //发送刷新消息  
	}
}

void MainWindow::paintEvent(QPaintEvent *e)//Lable中显示视频
{
	QImage image2 = QImage((uchar*)(current_frame.data), current_frame.cols, current_frame.rows, QImage::Format_RGB888);
	ui->label->setPixmap(QPixmap::fromImage(image2));
	ui->label->resize(image2.size());
	ui->label->show();
}
QImage MainWindow::MatToQImage(const cv::Mat& mat)//Mat to Qimage 转换
{
	// 8-bits unsigned, NO. OF CHANNELS = 1    
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)    
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat    
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3    
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat    
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat    
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		qDebug() << "CV_8UC4";
		// Copy input Mat    
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat    
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}
void MainWindow::on_pause_button_clicked()
{
	//QMessageBox::information(this, tr("pause"), tr("ssse"));
	play_pause_video(0);
	//capture.grab();//捕获当前帧
	//capture.read(current_frame);
	//添加对每一帧的操作
	//capture.get(CV_CAP_PROP_POS_FRAMES);
	//capture.retrieve(image);
	QImage *image_change;//临时存储转换后的Qimage地址
	*image_change = MatToQImage(current_frame);
	image = image_change;
}


void MainWindow::play_pause_video(int temp_pause_video)	//读取帧，
{
	if (temp_pause_video)
	{
		if (capture.isOpened())
		{
			current_frame = Mat::zeros(capture.get(CV_CAP_PROP_FRAME_HEIGHT), capture.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3);
			theTimer->start(33);
		}
	}

	else
		theTimer->stop();
}

