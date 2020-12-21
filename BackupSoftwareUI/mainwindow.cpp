#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(600,400);

    form1=new Form1;

    //监听返回按钮的信号
    connect(form1,&Form1::form1Back,this,[=](){
        form1->hide();
        this->show();
    });
    //点击备份按钮
    connect(ui->backupButton,&QPushButton::clicked,[=](){
        //自身隐藏
        this->hide();

        //显示备份场景
        form1->show();
    });

    form2=new Form2;

    //监听返回按钮的信号
    connect(form2,&Form2::form2Back,this,[=](){
        form2->hide();
        this->show();
    });
    //点击恢复按钮
    connect(ui->recoverButton,&QPushButton::clicked,[=](){
        //自身隐藏
        this->hide();

        //显示恢复场景
        form2->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

