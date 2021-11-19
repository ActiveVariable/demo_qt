#include "Dialog.h"
#include "ui_Dialog.h"
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>
#include <QDebug>
#include <QDir>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //选择文件
     connect(ui->pushButton_selectFile,&QPushButton::clicked,
             this,[=]()
     {
         QString strFilePath = QFileDialog::getOpenFileName(nullptr,"请选择文件",QApplication::applicationFilePath());
         if(!strFilePath.isEmpty())
         {
             ui->lineEdit_filePath->setText(strFilePath);
         }
     });
     //删除文件
     connect(ui->pushButton_deleteFile,&QPushButton::clicked,
             this,[=]()
     {
         QString strFilePath = ui->lineEdit_filePath->text();
         if(!strFilePath.isEmpty())
         {
             QFile file(strFilePath);
             if(file.remove())
             {
                 QMessageBox::information(nullptr,"提示","删除成功 文件名:" + file.fileName());
             }
             else
             {
                 QMessageBox::information(nullptr,"提示","删除失败 文件名:" + file.fileName());
             }
         }
     });
     //文件信息
     connect(ui->pushButton_fileInfo,&QPushButton::clicked,
             this,[=]()
     {
         QString strFilePath = ui->lineEdit_filePath->text();
         if(!strFilePath.isEmpty())
         {
             QFileInfo file(strFilePath);
             QString strText;
             strText += "absoluteFilePath():" + file.absoluteFilePath() + "\n";
             strText += "absolutePath():" + file.absolutePath() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
 //            strText += "xxx():" + file.xxx() + "\n";
             ui->textBrowser_fileInfo->setText(strText);
         }
     });
}

Dialog::~Dialog()
{
    delete ui;
}

