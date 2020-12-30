#ifndef FORM2_H
#define FORM2_H

#include <QWidget>

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();
signals:
    //自定义信号，告诉主场景点击了返回
    void form2Back();
private:
    Ui::Form2 *ui;
private slots:
    void on_recoverSrcBtn_clicked();
    void on_recoverDesBtn_clicked();
    void on_startRecoverBtn_clicked();
    int mainHuffmanUnpack();
};

#endif // FORM2_H
