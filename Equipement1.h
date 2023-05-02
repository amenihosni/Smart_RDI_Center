#ifndef Equipement1_H
#define Equipement1_H
#include"equipements.h"
#include"arduino.h"

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class Equipement1; }
QT_END_NAMESPACE

class Equipement1 : public QMainWindow
{
    Q_OBJECT

public:
    Equipement1(QWidget *parent = nullptr);
    ~Equipement1();

private slots:
    void on_boutajouter_clicked();

    void on_boutsup_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_modif_clicked();

    void on_boutrech_clicked();

    void on_triDes_clicked();

    //void on_triDes_3_clicked();

    void on_pdf_clicked();

    void on_exel_clicked();

    void on_stat_clicked();



    void on_pushButton_20_clicked();


void update_label();
    void on_botled_clicked();

    void on_retour_clicked();

private:
    Ui::Equipement1 *ui;
    equipements e;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};
#endif // Equipement1_H
