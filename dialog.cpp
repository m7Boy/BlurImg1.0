#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "QString"




#include "CImage.h"			// header a CImage class 

#include <iostream>
#include <string>

			

CImage buff;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
	//processing buttons
    this->connect(this->ui->btnBlur,SIGNAL(clicked()),this,SLOT(btnBlur_click()) );
    this->connect(this->ui->btnView,SIGNAL(clicked()),this,SLOT(btnView_click()) );
    this->connect(this->ui->btnOpen,SIGNAL(clicked()),this,SLOT(btnOpen_click()) );

}

Dialog::~Dialog()
{
    delete ui;
}

//Processing  blur

void Dialog::btnBlur_click()
{



    QString str = this->ui->textEdit->toPlainText();
    int blr;
    blr = str.split(" ")[0].toInt();

	// Set the kernel blurring of object buff
   
    buff.setBlur(blr);

	//call function for bluring, parameter this we need to display a progress bar dialog
	
    buff.bluringImg(this);

    this->ui->lineEdit->setText("Complete!");


}

//Processing button View

void Dialog::btnView_click()
{
    buff.ImgShow();

}

//Processing button Open

void Dialog::btnOpen_click()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Image (*.jpg *.png *.bmp)"));


    std::string path = fileName.toLocal8Bit().constData();
	//set path to image for bluring 
     buff.setPath(path);

}

//function for Error Message 

void Dialog::messageBox(const QString& erorrMessage)
{
    QMessageBox::question(this,"Erorr",erorrMessage,QMessageBox::Ok);
}
