#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include<QSqlQueryModel>
#include <QString>
#include<QSqlQuery>

class equipements
{
public:
    equipements();
    equipements(int,QString,QString,int,int,int);
    equipements(QString,QString,int,int,int);
    equipements(int);
    int getquantite();
    int getetat();
    int getid();
    QString getnomeq();
    QString getdomaineq();
    int getprix();
    void setquantite (int);
    void setetat (int);
    void seteid (int);
    void setnomeq(QString);
    void setdomaineq(QString);
    void setprix(int);
    bool ajouter( QByteArray IMAGE);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    bool veriefier();
    QSqlQueryModel * recherche(int ID,QString NOM_EQ,QString DOMAINE_EQUIPEMENTS,int ETAT );
    QSqlQueryModel* TrierDesc();
    void insertionimage(QByteArray base64Data,int);
    QByteArray afficherimage();
    bool modifierArd(int ID);
    QString rech(int id);

private:
    int QUANTITE , ETAT , PRIX , ID;
    QString NOM_EQ, DOMAINE_EQUIPEMENTS;
};



#endif // EQUIPEMENTS_H
