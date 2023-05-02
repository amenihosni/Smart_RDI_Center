#ifndef ARTICLE_H
#define ARTICLE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QComboBox>

class Article
{
private:
    int ID_ARTICLE;
    QString TITRE;
    QString TEXTE;
    QString NOM_CHERCHEUR;
    QDate DATE_AJOUT;

public:
    //constructeurs
    Article();
    Article(int, QString, QString, QString, QDate);
    Article(QString, QString,QString);
    //getters
    int getid_article();
    QString gettitre();
    QString gettexte();
    QString getchercheur();
    //setters
    void setid_article(int);
    void settitre(QString);
    void settexte(QString);
    void setchercheur(QString);
    //fonctionnalites de base
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherAlpha();
    QSqlQueryModel * afficherAlphaDesc();
    QSqlQueryModel * afficherTriIden();
    QSqlQueryModel * rechercher(int);
    bool modifier(int);
    bool supprimer(int);
    QStringList getDistinctChercheurs() const;
    int nbArticlesParChercheur(const QString &nomChercheur) const;

};

#endif // ARTICLE_H
