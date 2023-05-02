#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_chercheur_clicked()
{
    this->hide();
    ch.show();
}

void menu::on_pushButton_coference_clicked()
{
     this->hide();
    C.show();
}

void menu::on_pushButton_equipement_clicked()
{
     this->hide();
    e.show();
}

void menu::on_pushButton_article_clicked()
{
     this->hide();
    a.show();
}
