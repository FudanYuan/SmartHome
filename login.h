#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QSettings>
#include "mainwindow.h"

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    void        savecfg();
    void        loadcfg();



private slots:
    void on_login_2_clicked();

    void on_rmbPwd_clicked();

    void on_autoLogin_clicked();

private:
    Ui::login *ui;
    QString act;
    QString pwd;
    QString rmbPwd;
    QString autoLogin;
    bool isrmbPasswd;
    bool isautoLogin;
    mainwindow main;
};

#endif // LOGIN_H
