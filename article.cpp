#include "article.h"
#include <QDate>
#include <QDebug>
#include <QSqlError>
#include <QComboBox>

//constructeurs
Article::Article()
{
 ID_ARTICLE=0; TITRE=" ";TEXTE=" ";

}
Article::Article(int ID_ARTICLE, QString TITRE, QString TEXTE, QString NOM_CHERCHEUR, QDate DATE_AJOUT)
{this->ID_ARTICLE=ID_ARTICLE; this->TITRE=TITRE; this->TEXTE=TEXTE; this->NOM_CHERCHEUR=NOM_CHERCHEUR; this->DATE_AJOUT=DATE_AJOUT;}

Article::Article(QString TITRE, QString TEXTE, QString CHERCHEUR)
{this->TITRE=TITRE; this->TEXTE=TEXTE;this->NOM_CHERCHEUR=CHERCHEUR;}

//getters
int Article::getid_article(){return ID_ARTICLE;}
QString Article::gettitre(){return TITRE;}
QString Article::gettexte(){return TEXTE;}
QString Article::getchercheur(){return NOM_CHERCHEUR;}

//setters
void Article::setid_article(int ID_ARTICLE){this->ID_ARTICLE=ID_ARTICLE;}
void Article::settitre(QString TITRE){this->TITRE=TITRE;}
void Article::settexte(QString TEXTE){this->TEXTE=TEXTE;}
void Article::setchercheur(QString CHERCHEUR){this->NOM_CHERCHEUR=CHERCHEUR;}

//fonctionnalités de base
bool Article::ajouter()
{

QSqlQuery query;
        qDebug() << "Adding new article...";
      query.prepare("INSERT INTO articles (ID_ARTICLE,TITRE,TEXTE, DATE_AJOUT, NOM_CHERCHEUR) "
                    "VALUES (NULL, :titre, :texte, :dateAjout, :chercheur )");
      query.bindValue(":titre", TITRE);
      query.bindValue(":texte", TEXTE);
      query.bindValue(":dateAjout", QDate::currentDate());
      query.bindValue(":chercheur", NOM_CHERCHEUR);

      /*if (!query.exec()) {
              qDebug() << "Error executing query:" << query.lastError().text();
              return false;
          }*/
     return query.exec();

}

QSqlQueryModel * Article::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select ID_ARTICLE,TITRE,TEXTE, DATE_AJOUT from ARTICLES order by DATE_AJOUT desc");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant Article"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Titre"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Texte"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date d'ajout"));
return model;
}

QSqlQueryModel * Article::afficherAlpha()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select ID_ARTICLE,TITRE,TEXTE, DATE_AJOUT from ARTICLES order by TITRE");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant Article"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Titre"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Texte"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date d'ajout"));
//model->insertColumn(model->columnCount(QModelIndex()));
return model;
}

QSqlQueryModel * Article::afficherAlphaDesc()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select ID_ARTICLE,TITRE,TEXTE, DATE_AJOUT from ARTICLES order by TITRE DESC");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant Article"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Titre"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Texte"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date d'ajout"));
//model->insertColumn(model->columnCount(QModelIndex()));
return model;
}

QSqlQueryModel * Article::afficherTriIden()
{
QSqlQueryModel * model=new QSqlQueryModel();

model->setQuery("select ID_ARTICLE,TITRE,TEXTE, DATE_AJOUT from ARTICLES order by DATE_AJOUT");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant Article"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Titre"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Texte"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Date d'ajout"));
//model->insertColumn(model->columnCount(QModelIndex()));
return model;
}

QSqlQueryModel * Article::rechercher(int rech)
{
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();
    query.prepare("SELECT ID_ARTICLE,TITRE,TEXTE, DATE_AJOUT FROM ARTICLES WHERE ID_ARTICLE=:rech");
    model->setQuery(query);
    query.bindValue(":rech",rech);
    if (query.exec()) {
               model->setQuery(query);
           } else {
               qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
               delete model;
               model = nullptr;
           }
    return model;
}

bool Article::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);

query.prepare("Delete from ARTICLES where ID_ARTICLE= :id");
query.bindValue(":id",res);
return query.exec();
}

bool Article::modifier(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
        query.prepare( "UPDATE ARTICLES  SET TITRE=:titre,TEXTE=:texte WHERE  ID_ARTICLE=:id");
        query.bindValue(":id",res);
        query.bindValue(":titre", TITRE);
        query.bindValue(":texte", TEXTE);
       return  query.exec();

}

QStringList Article::getDistinctChercheurs() const
{
    QStringList chercheurs;

    QSqlQuery query;
    query.prepare("SELECT DISTINCT NOM_CHERCHEUR FROM articles");
    if (query.exec()) {
        while (query.next()) {
            QString chercheur = query.value(0).toString();
            chercheurs.append(chercheur);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError();
    }

    return chercheurs;
}

int Article::nbArticlesParChercheur(const QString &nom_chercheur) const {
    int count = 0;
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Articles WHERE NOM_CHERCHEUR = :nom_chercheur;");
    query.bindValue(":nom_chercheur", nom_chercheur);
    if (query.exec() && query.next()) {
        count = query.value(0).toInt();
    }
    return count;
}
