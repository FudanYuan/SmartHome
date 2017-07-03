#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "houses.h"

namespace Ui {
class mainwindow;
}

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();

private slots:
    void on_house_clicked();

private:
    Ui::mainwindow *ui;
    houses house;
};

#endif // MAINWINDOW_H
