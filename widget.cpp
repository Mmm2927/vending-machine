#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
     ui->pbCoffee->setEnabled(money>=200);
     ui->pbMilk->setEnabled(money>=100);
     ui->pbTea->setEnabled(money>=150);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);

}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

//void


void Widget::on_pbReset_clicked()
{
    char result[200];
    int count500 = 0;
    int count100 = 0;
    int count50 = 0;
    int count10 = 0;

    while(1){
        if(money >= 500){
            count500 += 1;
            money -= 500;
            continue;
        }
        if(money >= 100){
            count100 += 1;
            money -= 100;
            continue;
        }
        if(money >= 50){
            count50 += 1;
            money -= 50;
            continue;
        }
        if(money >= 10){
            count10 += 1;
            money -= 10;
            continue;
        }
        break;
    }

    QMessageBox msgBox;
    sprintf(result,"500 : %d, 100 : %d, 50 : %d, 10 : %d", count500, count100, count50, count10);
    msgBox.setText(result);
    msgBox.exec();

    ui->lcdNumber->display(money);
    setControl();
    return;
}

