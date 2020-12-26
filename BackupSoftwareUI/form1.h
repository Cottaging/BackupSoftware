#ifndef FORM1_H
#define FORM1_H

#include <QWidget>

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();

signals:
    //自定义信号，告诉主场景点击了返回
    void form1Back();

private:
    Ui::Form1 *ui;
private slots:
    void on_backupSrcBtn_clicked();
    void on_backupDesBtn_clicked();

};

#endif // FORM1_H
