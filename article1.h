#ifndef article1_H
#define article1_H

#include <QMainWindow>
#include <article.h>
#include <QDate>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class article1; }
QT_END_NAMESPACE

class article1 : public QMainWindow
{
    Q_OBJECT

public:
    article1(QWidget *parent = nullptr);
    ~article1();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifbutton_clicked();



    void on_affichage_activated(const QModelIndex &index);

    void on_retourMenu_clicked();

    void on_retourMenu_2_clicked();

    void on_retourMenu_4_clicked();

    void on_retourMenu_5_clicked();

    void on_retourMenu_6_clicked();


    void on_triAlpha_clicked();

    void on_triAlphaDesc_clicked();

    void on_triIdentifiant_clicked();

    void on_telecharger_clicked();

    void on_boutonRech_clicked();

    void on_qrcodepb_clicked();

    void on_statistiques_clicked();

    void on_uploadbtn_clicked();

    void on_retour_clicked();

    void on_chercheurArticle_activated(const QModelIndex &index);

    void on_selectionnerChercheur_clicked();

private:
    Ui::article1 *ui;
    Article Atmp;

};
#endif // article1_H
