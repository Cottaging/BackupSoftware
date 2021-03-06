#include "form2.h"
#include "ui_form2.h"
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <cstring>
#include <StdAfx.h>
#include <Pack.h>
#include <huff.h>
#include <QMessageBox>
QString srcPath=NULL;
QString desPath2=NULL;

//string srcPathToString;
//string desPath2ToString;
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

}

Form2::~Form2()
{
    delete ui;
}

//选择源路径
void Form2::on_recoverSrcBtn_clicked()
{
    srcPath=QFileDialog::getOpenFileName(this,"选择要解压的压缩包","D:\\TestBackupSoftware","tar files(*.tar)");

    //路径放入lineEdit中
    ui->lineEdit->setText(srcPath);
    //srcPathToString=srcPath.toStdString();
}

//选择目标路径
void Form2::on_recoverDesBtn_clicked()
{
     desPath2=QFileDialog::getExistingDirectory(this,"选择存放位置","D:\\TestBackupSoftware");

    //路径放入lineEdit中
    ui->lineEdit_2->setText(desPath2);
    //desPath2ToString=desPath2.toStdString();
}

//霍夫曼解压缩
int Form2::mainHuffmanUnpack(){
    string infilename, outfilename;
    infilename=srcPath.toStdString();
    replace(infilename.begin(),infilename.end(),'/','\\');

    outfilename=infilename.substr(0,infilename.length()-4);

    if (infilename.length() < 1)
    {
        QMessageBox::information(this,"提示","请选择想要解压的压缩包！");
        return 1;
    }
    if (desPath2.length() < 1)
    {
        QMessageBox::information(this,"提示","没有指定输出位置！");
        return 1;
    }
    Huffman Test(2, infilename, outfilename);
    return 0;
}

//解包
void mainUnpack(){
    //Huffman Test(2, "D:/TestBackupSoftware/mytest.tar", "D:/TestBackupSoftware/mytest");
    char fileSrcPath[MAX_PATH_LEN] = "";
    char fileDesPath[MAX_PATH_LEN] = "";
//    printf("请输入需要解包的文件路径:");
//    scanf("%s", fileSrcPath);
    string userInputSrc=srcPath.toStdString();
    replace(userInputSrc.begin(), userInputSrc.end(), '/', '\\'); //斜杠修改为反斜杠
    int k = 0;
    for (k = 0; k < userInputSrc.length(); k++) {
        fileSrcPath[k] = userInputSrc[k];
    }
    fileSrcPath[k-4] = '\0';

    //strcpy(fileSrcPath,"D:\\TestBackupSoftware\\myfolder\\mytar");

//    printf("解包到:");
//    scanf("%s", fileDesPath);

    string userInputDes=desPath2.toStdString();
    replace(userInputDes.begin(), userInputDes.end(), '/', '\\'); //斜杠修改为反斜杠
    int m = 0;
    for (m = 0; m < userInputDes.length(); m++) {
        fileDesPath[m] = userInputDes[m];
    }
    fileDesPath[m] = '\0';

    Pack upf;
    upf.UnpackFile(fileSrcPath, fileDesPath);//执行解包
}


//删除中间文件
void deleteIntermediateFile2(){
    string infilename, outfilename;
    infilename=srcPath.toStdString();
    replace(infilename.begin(),infilename.end(),'/','\\');

    outfilename=infilename.substr(0,infilename.length()-4);  //得到所要删除的中间文件的路径

    //string类型转为char *类型
    char intermediatePath[MAX_PATH_LEN] = "";
    int k = 0;
    for (k = 0; k < outfilename.length(); k++) {
        intermediatePath[k] = outfilename[k];
    }
    intermediatePath[k] = '\0';
    if (remove(intermediatePath) == 0)
        printf("Removed %s.", intermediatePath);
    else
        perror("remove");

}

//开始恢复
void Form2::on_startRecoverBtn_clicked()
{
    qDebug()<<"开始恢复";
    if(mainHuffmanUnpack()==0){
        mainUnpack();
        deleteIntermediateFile2();
        QMessageBox::information(this, "提示", "压缩包解压成功！");
    }

}
