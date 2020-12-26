#include "form1.h"
#include "ui_form1.h"
#include <QFileDialog>
#include <QListView>
#include <QTreeView>
#include <QDialogButtonBox>
#include "cfiledialog.h"
#include <QDebug>
Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    this->setFixedSize(600,400);
    this->setWindowTitle("备份");
    connect(ui->backBtn1,&QPushButton::clicked,[=](){
        //主场景监听backupwindow的返回按钮
        emit this->form1Back();
    });
}

Form1::~Form1()
{
    delete ui;
}

//选择源路径
void Form1::on_backupSrcBtn_clicked()
{
    CFileDialog fileDialog;
    if ( fileDialog.exec() == QDialog::Accepted)
    {
        qDebug() << fileDialog.selectedFiles();
        QStringList srcPath=fileDialog.selectedFiles();
        QString srcPathString=NULL;
        //路径放入lineEdit中
        QList<QString>::Iterator it = srcPath.begin(),itend = srcPath.end();
        int i = 0;
        for (;it != itend; it++,i++){
            srcPathString=srcPathString+*it+";";
        }
        ui->lineEdit->setText(srcPathString);
    }
}

//选择目标路径
void Form1::on_backupDesBtn_clicked()
{
    QString desPath = QFileDialog::getSaveFileName(this,"命名压缩包并选择存放位置","D:\\TestBackupSoftware");
    //路径放入lineEdit中
    ui->lineEdit_2->setText(desPath);
}
