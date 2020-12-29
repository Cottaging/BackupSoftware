/********************************************************************************
** Form generated from reading UI file 'form1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM1_H
#define UI_FORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form1
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *backupDesBtn;
    QPushButton *backupSrcBtn;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *startBackupBtn;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *backBtn1;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *Form1)
    {
        if (Form1->objectName().isEmpty())
            Form1->setObjectName(QString::fromUtf8("Form1"));
        Form1->resize(600, 400);
        verticalLayout = new QVBoxLayout(Form1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        widget = new QWidget(Form1);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        backupDesBtn = new QPushButton(widget);
        backupDesBtn->setObjectName(QString::fromUtf8("backupDesBtn"));

        gridLayout->addWidget(backupDesBtn, 2, 1, 1, 1);

        backupSrcBtn = new QPushButton(widget);
        backupSrcBtn->setObjectName(QString::fromUtf8("backupSrcBtn"));

        gridLayout->addWidget(backupSrcBtn, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 2, 0, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 3, 0, 1, 1);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(Form1);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox = new QCheckBox(widget_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(true);

        horizontalLayout_3->addWidget(checkBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        startBackupBtn = new QPushButton(widget_3);
        startBackupBtn->setObjectName(QString::fromUtf8("startBackupBtn"));

        horizontalLayout_3->addWidget(startBackupBtn);


        verticalLayout->addWidget(widget_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        widget_4 = new QWidget(Form1);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        backBtn1 = new QPushButton(widget_4);
        backBtn1->setObjectName(QString::fromUtf8("backBtn1"));
        backBtn1->setMaximumSize(QSize(70, 30));

        horizontalLayout_4->addWidget(backBtn1);


        verticalLayout->addWidget(widget_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        retranslateUi(Form1);

        QMetaObject::connectSlotsByName(Form1);
    } // setupUi

    void retranslateUi(QWidget *Form1)
    {
        Form1->setWindowTitle(QCoreApplication::translate("Form1", "Form", nullptr));
        backupDesBtn->setText(QCoreApplication::translate("Form1", "\351\200\211\346\213\251\345\255\230\346\224\276\350\267\257\345\276\204", nullptr));
        backupSrcBtn->setText(QCoreApplication::translate("Form1", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        checkBox->setText(QCoreApplication::translate("Form1", "\345\244\207\344\273\275\345\220\216\350\277\233\350\241\214\346\225\260\346\215\256\346\240\241\351\252\214", nullptr));
        startBackupBtn->setText(QCoreApplication::translate("Form1", "\345\274\200\345\247\213\345\244\207\344\273\275", nullptr));
        backBtn1->setText(QCoreApplication::translate("Form1", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form1: public Ui_Form1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM1_H
