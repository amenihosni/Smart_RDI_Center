#ifndef Chercheur1_H
#define Chercheur1_H

#include <QMainWindow>
#include "chercheur.h"
#include <QListView>
#include <QNetworkReply>
#include <QList>
#include <QString>
#include <QDate>
QT_BEGIN_NAMESPACE
struct Position {
    int x;
    int y;
};

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
namespace Ui { class Chercheur1; }
QT_END_NAMESPACE

class Chercheur1 : public QMainWindow
{
    Q_OBJECT

public:
    Chercheur1(QWidget *parent = nullptr);
    ~Chercheur1();

private slots:
    void on_pb_ajout_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modify_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pb_chercher_clicked();



    void on_stastique_clicked();

    void on_pdf_clicked();

    void on_tri_clicked();

    void on_tri_2_clicked();

    void on_refrech_clicked();

    void on_excel_clicked();



    void on_comboBox_activated(int index);

  QSqlQueryModel*afficherHistorique(QString query);

    void on_imprimer_clicked();


    void on_comboBox_3_activated(const QString &arg1);

    void on_pb_supprimer_historique_clicked();


    void on_retour_clicked();

private:

    Ui::Chercheur1 *ui;
    Chercheur C;
    QCamera *mCamera;
    QCameraViewfinder *CameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpcionesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;


    struct Conference {
        QString name;
        QDate date;
        QString location;
    };
QImage generateBarcode(const QList<Conference>& conferences);

    };


#endif // Chercheur1_H
