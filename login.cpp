#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->account->setPlaceholderText(QString("请输入账号")); // 文本提示
    ui->password->setPlaceholderText(QString("请输入密码")); // 文本提示
    ui->password->setEchoMode(QLineEdit::Password);//当输入密码时，显示为******
    loadcfg();
}

login::~login()
{
    delete ui;
}

// 记录配置
void login::savecfg()
{
    if(isrmbPasswd == true){
        act= ui->account->text();
        pwd= ui->password->text();
    }else{
        act = "";
        pwd = "";
        isautoLogin = false;
    }
    // 记录配置
    QSettings setting("smartHomeConfig.ini", QSettings::IniFormat);//生成配置文件
    setting.beginGroup("config");//beginGroup与下面endGroup 相对应，“config”是标记
    setting.setValue("account",QVariant(act));
    setting.setValue("password",QVariant(pwd));
    setting.setValue("rmbPwd",QVariant(isrmbPasswd));
    setting.setValue("autoLogin",QVariant(isautoLogin));
    setting.endGroup();
}

// 下载配置
void login::loadcfg()
{
    // 下载配置
    QSettings setting("smartHomeConfig.ini", QSettings::IniFormat);//下载配置文件
    setting.beginGroup("config");
    act=setting.value("account").toString();
    pwd=setting.value("password").toString();
    rmbPwd=setting.value("rmbPwd").toString();
    autoLogin=setting.value("autoLogin").toString();

    // 设置配置
    ui->account->setText(act);
    ui->password->setText(pwd);

    if(rmbPwd == "true"){
        ui->rmbPwd->setChecked(true);
    }else{
        ui->rmbPwd->setChecked(false);
    }
    if(autoLogin == "true"){
        ui->autoLogin->setChecked(true);
    }else{
        ui->autoLogin->setChecked(false);
    }
}

// 登录槽函数
void login::on_login_2_clicked()
{
    // 判断是否记住密码
    if(ui->rmbPwd->isChecked()){
        isrmbPasswd = true;
    }
    else{
        isrmbPasswd = false;
    }
    // 判断是否自动登录
    if(ui->autoLogin->isChecked()){
        isautoLogin= true;
    }
    else{
        isautoLogin= false;
    }
    // 判断账号和密码是否正确
    QString account = ui->account->text();
    QString password = ui->password->text();
    if(account == QString("admin") && password == QString("admin")){
        savecfg();
        this->close();
        main.show();
    }
}

// 判断是否记住密码
void login::on_rmbPwd_clicked()
{
    if(ui->rmbPwd->isChecked()){
        isrmbPasswd = true;
    }
    else{
        isrmbPasswd = false;
    }
}

// 判断是否自动登录
void login::on_autoLogin_clicked()
{
    if(ui->autoLogin->isChecked()){
        isautoLogin= true;
    }
    else{
        isautoLogin= false;
    }
}
