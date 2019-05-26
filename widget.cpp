#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdio.h>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money=money+diff;
    if(money <= 0){
        QMessageBox msg;
        msg.information(nullptr, "message","plz enter the coin");
        money =money-diff;
    }
    if(money < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCola->setEnabled(false);
    }
    if (money >=100 && money<150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbCola->setEnabled(false);
    }
    if (money>=150 && money<200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCola->setEnabled(false);
    }
    if (money>=200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCola->setEnabled(true);
    }
    ui->lcdNumber->display(money);

}


void Widget::on_pb10_clicked()
{
    QMessageBox msg;
    msg.information(nullptr, "message","+ 10 won");
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    QMessageBox msg;
    msg.information(nullptr, "message","+ 50 won");
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    QMessageBox msg;
    msg.information(nullptr, "message","+ 100 won");
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    QMessageBox msg;
    msg.information(nullptr, "message","+ 500 won");
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    QMessageBox msg;
    msg.information(nullptr, "message","select Coffee");
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    QMessageBox msg;
    msg.information(nullptr, "message","select Tea");
    changeMoney(-150);
}

void Widget::on_pbCola_clicked()
{
    QMessageBox msg;
    msg.information(nullptr, "message","select Cola");
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    ui->lcdNumber->display(0);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCola->setEnabled(false);

    int c10, c50, c100, c500;
    c10=c50=c100=c500=0;

    c500 = money / 500;
    if(c500) money = money-500*c500;

    c100 = money / 100;
    if(c100) money = money-100*c100;

    c50 = money / 50;
    if(c50) money = money-50*c50;

    c10 = money / 10;

    char str[100] = "\n";

    sprintf(str ,"500WON : %d\n100WON : %d\n50WON : %d\n10WON : %d\n",c500,c100,c50,c10);

    QMessageBox msgBox;
    msgBox.information(nullptr, "ChangeMoney", str);
    money = 0;
}

