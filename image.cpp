#include "image.h"

image::image()
{

    nom="";
    ima=NULL;
}
image::image(QString n,QByteArray byte)
{nom=n;
ima=byte;
}
 void  image::selectioneimage()
 {
        QSqlQuery query;
        query.prepare("SELECT  * FROM IMAGE ");
        if (!query.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();}
         QList<QString> imageNames;
            //QList<QByteArray> images;

            while (query.next()) {

                imageNames << query.value(0).toString();
                //images << query.value(1).toByteArray();
            }

            int index = qrand() % imageNames.size();
            nom = imageNames.at(index);
            //ima = images.at(index);

 }
