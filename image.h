#ifndef IMAGE_H
#define IMAGE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
class image
{
 private :
   QString nom;
   QByteArray ima;
public:
    image();
     image(QString,QByteArray);
    void selectioneimage();
    QByteArray getima(){return ima;}
    QString getnom(){return nom;}
    ~image(){}
};

#endif // IMAGE_H
