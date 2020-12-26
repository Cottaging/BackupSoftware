#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form1.h"
#include "form2.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Form1 *form1=NULL;
    Form2 *form2=NULL;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
