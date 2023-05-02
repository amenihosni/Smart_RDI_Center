#ifndef Conference1_H
#define Conference1_H
#include "arduino.h"
#include <QMainWindow>
#include <QTextDocument>
#include<QTextFrame>
#include <QSqlQuery>
#include <QMessageBox>
#include<QTextTable>
#include<QtCharts>
#include<QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include "conference.h"
#include "image.h"
#include  "dialog.h"
#include<QMediaRecorder>
#include<QCamera>
QT_BEGIN_NAMESPACE
namespace Ui { class Conference1; }
QT_END_NAMESPACE

class Conference1 : public QMainWindow
{
    Q_OBJECT

public:
    Conference1(QWidget *parent = nullptr);
    ~Conference1();
    bool verificationsys();



private slots:
    void on_confirmer_clicked();

    void on_supprimer2_clicked();

    void on_tab_conference_activated(const QModelIndex &index);

    void on_confirmer_modifier_clicked();

    void on_recherche_clicked();

    void on_l_annee_clicked();

    void on_le_mois_clicked();

    void on_pdf_clicked();

    void on_pushButton_2_clicked();


    void on_excel_clicked();


    void on_calendarWidget_clicked(const QDate &date);



    void on_video2_clicked();


     void on_PauseButton_clicked();

     void on_historique_button_clicked();



     void on_op_clicked();

     void update_label();



     void on_pushButton_3_clicked();

     void on_arret_clicked();

    // void on_redemarer_clicked();*/




     void on_retour_clicked();

private:
    Ui::Conference1 *ui;
    Conference c;
    image i;
    int n=0;
    QMediaRecorder* recorder;
    QBuffer* buffer;
    Arduino a;
    Dialog d;


};
#endif // Conference1_H
