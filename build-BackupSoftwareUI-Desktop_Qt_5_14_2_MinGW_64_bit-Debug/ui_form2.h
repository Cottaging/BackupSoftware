/********************************************************************************
** Form generated from reading UI file 'form2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM2_H
#define UI_FORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form2
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *recoverSrcBtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *recoverDesBtn;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_5;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *startRecoverBtn;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *backBtn2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *Form2)
    {
        if (Form2->objectName().isEmpty())
            Form2->setObjectName(QString::fromUtf8("Form2"));
        Form2->resize(600, 400);
        verticalLayout = new QVBoxLayout(Form2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(Form2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 3, 0, 1, 1);

        recoverSrcBtn = new QPushButton(widget_2);
        recoverSrcBtn->setObjectName(QString::fromUtf8("recoverSrcBtn"));

        gridLayout->addWidget(recoverSrcBtn, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

        recoverDesBtn = new QPushButton(widget_2);
        recoverDesBtn->setObjectName(QString::fromUtf8("recoverDesBtn"));

        gridLayout->addWidget(recoverDesBtn, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 0, 1, 1);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(Form2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        startRecoverBtn = new QPushButton(widget_3);
        startRecoverBtn->setObjectName(QString::fromUtf8("startRecoverBtn"));
        startRecoverBtn->setMaximumSize(QSize(92, 28));

        horizontalLayout->addWidget(startRecoverBtn);


        verticalLayout->addWidget(widget_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        widget = new QWidget(Form2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        backBtn2 = new QPushButton(widget);
        backBtn2->setObjectName(QString::fromUtf8("backBtn2"));
        backBtn2->setMaximumSize(QSize(70, 30));

        horizontalLayout_2->addWidget(backBtn2);


        verticalLayout->addWidget(widget);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(Form2);

        QMetaObject::connectSlotsByName(Form2);
    } // setupUi

    void retranslateUi(QWidget *Form2)
    {
        Form2->setWindowTitle(QCoreApplication::translate("Form2", "Form", nullptr));
        recoverSrcBtn->setText(QCoreApplication::translate("Form2", "\351\200\211\346\213\251\345\216\213\347\274\251\345\214\205", nullptr));
        recoverDesBtn->setText(QCoreApplication::translate("Form2", "\351\200\211\346\213\251\345\255\230\346\224\276\350\267\257\345\276\204", nullptr));
        startRecoverBtn->setText(QCoreApplication::translate("Form2", "\345\274\200\345\247\213\346\201\242\345\244\215", nullptr));
        backBtn2->setText(QCoreApplication::translate("Form2", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form2: public Ui_Form2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM2_H
