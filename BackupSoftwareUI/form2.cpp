#include "form2.h"
#include "ui_form2.h"
#include <QFileDialog>
Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    this->setFixedSize(600,400);
    this->setWindowTitle("恢复");

    connect(ui->backBtn2,&QPushButton::clicked,[=](){
        //qDebug()<<"点击了返回按钮";

        //主场景监听backupwindow的返回按钮
        emit this->form2Back();
    });

    //点击选取文件按钮，弹出文件对话框
    //源路径
    connect(ui->recoverSrcBtn,&QPushButton::clicked,[=](){
        QString srcPath=QFileDialog::getOpenFileName(this,"选择要解压的压缩包","D:\\TestBackupSoftware");

        //路径放入lineEdit中
        ui->lineEdit->setText(srcPath);
    });
    //目标路径
    connect(ui->recoverDesBtn,&QPushButton::clicked,[=](){
        QString desPath=QFileDialog::getExistingDirectory(this,"选择存放位置","D:\\TestBackupSoftware");

        //路径放入lineEdit中
        ui->lineEdit_2->setText(desPath);
    });
}

Form2::~Form2()
{
    delete ui;
}
