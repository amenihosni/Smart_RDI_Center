#ifndef MENU_H
#define MENU_H
#include <QMainWindow>
#include"Conference1.h"
#include"Chercheur1.h"
#include"Equipement1.h"
#include "article1.h"
namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_chercheur_clicked();

    void on_pushButton_coference_clicked();

    void on_pushButton_equipement_clicked();

    void on_pushButton_article_clicked();

private:
    Ui::menu *ui;
   Conference1  C;
    Chercheur1 ch;
    Equipement1 e;
    article1 a;
};

#endif // MENU_H
