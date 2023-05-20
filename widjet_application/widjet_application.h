#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_widjet_application.h"

class widjet_application : public QMainWindow
{
    Q_OBJECT

public:
    widjet_application(QWidget* parent = nullptr);

    ~widjet_application();

private slots:

    void Click_to_info();

    void Click_to_description();

private:
    Ui::widjet_applicationClass ui;
};