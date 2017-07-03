#include "houses.h"
#include "ui_houses.h"
#include <QDebug>

houses::houses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::houses)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentWidget(ui->tab_welcome);
    connect(ui->menusBtnGrp, SIGNAL(buttonClicked(int)), this, SLOT(btnGrpSlots(int)));
}

houses::~houses()
{
    delete ui;
}

void houses::btnGrpSlots(int id)
{
    QPushButton* btn = (QPushButton*)(ui->menusBtnGrp)->button(id);
    QString t = btn->text();
    qDebug()<<id;
    switch(-id){
    case 2:{
        ui->tabWidget->setCurrentWidget(ui->tab_houses);
        break;
    }
    case 3:{
         ui->tabWidget->setCurrentWidget(ui->tab_model);
         break;
    }
    default:
        break;
    }
}
