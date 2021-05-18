#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"

namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(Controller *controller, graph *Graph, QWidget *parent = nullptr);

    ~MainWindow();

    void resetDataMembers();

    void refreshWidgets();

    void sortStadiums();

    void recursiveStadiumSort(QString current, QVector<QString> &selected);

    int nextStadium(QVector<int> dist, QVector<QString> &selected);

private slots:

    void on_ClearBtn_clicked();

    void on_Loginbtn_clicked();

    void keyPressEvent(QKeyEvent* pe);

    void on_gotodisplaybtn_clicked();

    void on_teamcombobox_currentTextChanged(const QString &arg1);

    void on_displaystadiumteambtn_clicked();

    void on_disstadiumstadiumbtn_clicked();

    void on_disAmericanTeam_clicked();

    void on_disteamopenroof_clicked();

    void on_disstaddatebtn_clicked();

    void on_loadTeamInfo_clicked();

    void on_loadSouvenirInfo_clicked();

    void on_Backtoadmin_clicked();

    void on_loadstadiumsbtn_clicked();

    void on_backtopass_clicked();

    void on_AddSouv_clicked();

    void on_BacktoAdmin_clicked();

    void on_TeamCombosouv_activated(const QString &arg1);

    void on_deleteSouvbtn_clicked();

    void on_Souveniralltable_activated(const QModelIndex &index);

    void on_Editsouvbtn_clicked();

    void on_stadiumcombobox_activated(const QString &arg1);

    void on_editstadium_clicked();

    void on_DFSbtn_clicked();

    void on_BFSbtn_clicked();

    void on_MSTbtn_clicked();

    void on_add_button_clicked();

    void on_delete_button_clicked();

    void on_calculatesouvbtn_clicked();

    void on_clearsouvbtn_clicked();

    void on_backtotrip_clicked();

    void on_addtocart_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Controller *m_controller;
    graph *m_graph;
    int page = 0;

    enum tripType
    {
        Dodgers,
        Start,
        Marlins,
        Custom,
        None
    };
    QVector<QString> selectedStadiums;
    QVector<QString> sortedStadiums;
    double totalDistance = 0;
    tripType trip = None;
};
#endif // MAINWINDOW_H
