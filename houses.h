#ifndef HOUSES_H
#define HOUSES_H

#include <QWidget>

namespace Ui {
class houses;
}

class houses : public QWidget
{
    Q_OBJECT

public:
    explicit houses(QWidget *parent = 0);
    ~houses();

private slots:
    void btnGrpSlots(int);

private:
    Ui::houses *ui;
};

#endif // HOUSES_H
