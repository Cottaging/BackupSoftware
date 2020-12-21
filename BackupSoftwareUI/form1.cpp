#include "form1.h"
#include "ui_form1.h"
#include <QFileDialog>
Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    this->setFixedSize(600,400);
    this->setWindowTitle("备份");

    connect(ui->backBtn1,&QPushButton::clicked,[=](){
        //qDebug()<<"点击了返回按钮";

        //主场景监听backupwindow的返回按钮
        emit this->form1Back();
    });

    //点击选取文件按钮，弹出文件对话框
    //源路径
    connect(ui->backupSrcBtn,&QPushButton::clicked,[=](){
        QStringList srcPath=QFileDialog::getOpenFileNames(this,"选择要压缩的文件","D:\\TestBackupSoftware");
        QString srcPathString=NULL;
        //路径放入lineEdit中
        QList<QString>::Iterator it = srcPath.begin(),itend = srcPath.end();
        int i = 0;
        for (;it != itend; it++,i++){
            srcPathString=srcPathString+*it+";";
        }

        ui->lineEdit->setText(srcPathString);

    });
    //目标路径
    connect(ui->backupDesBtn,&QPushButton::clicked,[=](){
        //QString desPath=QFileDialog::getOpenFileName(this,"选择存放位置","D:\\TestBackupSoftware");
        QString desPath = QFileDialog::getExistingDirectory(this,"选择压缩包存放位置","D:\\TestBackupSoftware");

        //路径放入lineEdit中
        ui->lineEdit_2->setText(desPath);
    });

}

Form1::~Form1()
{
    delete ui;
}
