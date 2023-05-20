/********************************************************************************
** Form generated from reading UI file 'widjet_applicationjfCTkM.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WIDJET_APPLICATIONJFCTKM_H
#define WIDJET_APPLICATIONJFCTKM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widjet_applicationClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *output;
    QLineEdit *enter;
    QPushButton *to_do;
    QTextBrowser *disc;
    QPushButton *variant;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *widjet_applicationClass)
    {
        if (widjet_applicationClass->objectName().isEmpty())
            widjet_applicationClass->setObjectName("widjet_applicationClass");
        widjet_applicationClass->resize(610, 683);
        centralWidget = new QWidget(widjet_applicationClass);
        centralWidget->setObjectName("centralWidget");
        output = new QTextBrowser(centralWidget);
        output->setObjectName("output");
        output->setGeometry(QRect(10, 190, 581, 421));
        QFont font;
        font.setPointSize(10);
        output->setFont(font);
        output->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        output->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        enter = new QLineEdit(centralWidget);
        enter->setObjectName("enter");
        enter->setGeometry(QRect(10, 60, 461, 51));
        to_do = new QPushButton(centralWidget);
        to_do->setObjectName("to_do");
        to_do->setGeometry(QRect(10, 120, 141, 24));
        disc = new QTextBrowser(centralWidget);
        disc->setObjectName("disc");
        disc->setGeometry(QRect(10, 160, 581, 31));
        variant = new QPushButton(centralWidget);
        variant->setObjectName("variant");
        variant->setGeometry(QRect(170, 120, 141, 24));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 211, 16));
        widjet_applicationClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(widjet_applicationClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 610, 22));
        widjet_applicationClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(widjet_applicationClass);
        mainToolBar->setObjectName("mainToolBar");
        widjet_applicationClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(widjet_applicationClass);
        statusBar->setObjectName("statusBar");
        widjet_applicationClass->setStatusBar(statusBar);

        retranslateUi(widjet_applicationClass);
        QObject::connect(to_do, SIGNAL(clicked(bool)), widjet_applicationClass, SLOT(Click_to_info()));
        QObject::connect(variant, SIGNAL(clicked(bool)), widjet_applicationClass, SLOT(Click_to_description()));

        QMetaObject::connectSlotsByName(widjet_applicationClass);
    } // setupUi

    void retranslateUi(QMainWindow *widjet_applicationClass)
    {
        widjet_applicationClass->setWindowTitle(QCoreApplication::translate("widjet_applicationClass", "widjet_application", nullptr));
        to_do->setText(QCoreApplication::translate("widjet_applicationClass", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270", nullptr));
        disc->setHtml(QCoreApplication::translate("widjet_applicationClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">name 	.name	 date 	atributes</p></body></html>", nullptr));
        variant->setText(QCoreApplication::translate("widjet_applicationClass", "\320\276\321\202\320\274\320\265\321\202\320\270\321\202\321\214 jpg &", nullptr));
        label->setText(QCoreApplication::translate("widjet_applicationClass", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\321\203\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widjet_applicationClass: public Ui_widjet_applicationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WIDJET_APPLICATIONJFCTKM_H
