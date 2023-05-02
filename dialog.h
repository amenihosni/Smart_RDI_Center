#ifndef DIALOG_H
#define DIALOG_H
#include "conference.h"
#include <QDialog>
#include "arduino.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void afficher();
     QString get_nom(){return nom;}
     void set_nom(QString n){nom=n;}
     bool  chercher_visteur(QString numstring);


private slots:
    void on_sortie_clicked();

private:
    Ui::Dialog *ui;
  QString nom,prenom;
  QString id;
    Arduino a;
    Conference c;

};

#endif // DIALOG_H
