#include "form1.h"
#include "ui_form1.h"
#include <QFileDialog>
#include <QListView>
#include <QTreeView>
#include <QDialogButtonBox>
#include "cfiledialog.h"
#include <QDebug>
#include <QCheckBox>
#include "StdAfx.h"
#include "SearchFile.h"
#include "Pack.h"
#include <vector>
#include <huff.h>
QString srcPathString=NULL;
QString desPath1=NULL;
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
        //qDebug() << fileDialog.selectedFiles();
        QStringList srcPath=fileDialog.selectedFiles();

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
    desPath1 = QFileDialog::getSaveFileName(this,
                                            tr("命名压缩包并选择存放位置"),
                                            tr("D:/TestBackupSoftware/mytar.tar"),
                                            tr("tar files(*.tar)"));
    //路径放入lineEdit中
    ui->lineEdit_2->setText(desPath1);
}

//打包函数
void mainPack(){
    Pack pf;
    vector<string> vec_file;
    vector<string>::iterator f;
    char fileSrcPath[MAX_FILE_NUM][MAX_PATH_LEN];
    char fileDesPath[MAX_PATH_LEN] = "";
    int fNum = 0;
    string fileNamePath[MAX_PATH_LEN];

    //将QString类型的源路径转换为string类型
    string userInputSrc=srcPathString.toStdString();
    replace(userInputSrc.begin(), userInputSrc.end(), '/', '\\'); //斜杠修改为反斜杠

    for (int i = 0; i < userInputSrc.length(); i++) {
        if (userInputSrc[i] == ';') {
            fNum++;
            continue;
        }
        fileNamePath[fNum]+= userInputSrc[i];
    }
    for (int j = 0; j < fNum; j++) {
        int i = 0;
        for (i = 0; i < fileNamePath[j].length(); i++) {
            fileSrcPath[j][i] = fileNamePath[j][i];
        }
        fileSrcPath[j][i] = '\0';
    }
    for (int i = 0; i < fNum; i++) {
        vec_file.clear();
        Search::getInstance()->GetFileList(fileSrcPath[i], vec_file);
        //添加要打包的文件
        for (f = vec_file.begin(); f < vec_file.end(); f++) {
            pf.AddFile((*f).c_str(), fileSrcPath[i]);
        }
    }
    qDebug()<<"文件个数："<<fNum;
    //将QString类型的目标路径转换为string类型
    string userInputDes=desPath1.toStdString();
    replace(userInputDes.begin(), userInputDes.end(), '/', '\\'); //斜杠修改为反斜杠
    int k = 0;
    for (k = 0; k < userInputDes.length(); k++) {
        fileDesPath[k] = userInputDes[k];
    }
    fileDesPath[k-4] = '\0';

    //strcpy(fileDesPath,"D:\\TestBackupSoftware\\mytest");
    pf.SetPackedFile(fileDesPath);//设置输出文件
    pf.PackFile();//执行打包
}

//霍夫曼压缩函数
void mainHuffman(){

    string infilename, outfilename;
    outfilename=desPath1.toStdString();
    replace(outfilename.begin(),outfilename.end(),'/','\\');
    infilename=outfilename.substr(0,outfilename.length()-4);

    Huffman Test(1, infilename, outfilename);

    //cout<<"huffman in out path"<<infilename<<","<<outfilename<<endl;
    //cout<<"test running...";
}

//霍夫曼压缩带验证
void mainHuffmanWithValidate(){
    string infilename, outfilename;
    outfilename=desPath1.toStdString();
    replace(outfilename.begin(),outfilename.end(),'/','\\');
    infilename=outfilename.substr(0,outfilename.length()-4);

    Huffman Test(3, infilename, outfilename);
    //cout<<"huffman in out path"<<infilename<<","<<outfilename<<endl;
}

//删除中间文件
void deleteIntermediateFile(){
    string infilename, outfilename;
    outfilename=desPath1.toStdString();
    replace(outfilename.begin(),outfilename.end(),'/','\\');
    infilename=outfilename.substr(0,outfilename.length()-4);  //得到所要删除的中间文件的路径

    //string类型转为char *类型
    char intermediatePath[MAX_PATH_LEN] = "";
    int k = 0;
    for (k = 0; k < infilename.length(); k++) {
        intermediatePath[k] = infilename[k];
    }
    intermediatePath[k] = '\0';
    if (remove(intermediatePath) == 0)
        printf("Removed %s.", intermediatePath);
    else
        perror("remove");

}
//开始备份
void Form1::on_startBackupBtn_clicked()
{
    if(ui->checkBox->checkState()==2){
        qDebug() <<"开始验证备份";
        mainPack();
        mainHuffmanWithValidate();
        deleteIntermediateFile();
    }else if (ui->checkBox->checkState()==0){
        qDebug()<<"开始普通备份";
        //进行打包过程
        mainPack();
        mainHuffman();
        //删除中间文件
        deleteIntermediateFile();
    }
}




