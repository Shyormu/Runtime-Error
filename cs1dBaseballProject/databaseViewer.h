#ifndef DATABASEVIEWER_H
#define DATABASEVIEWER_H

#include <QDialog>
#include <QMessageBox>
#include "databaseManager.h"

namespace Ui {
class databaseViewer;
}

class databaseViewer : public QDialog
{
    Q_OBJECT

    typedef unsigned long long ulong; // used for safe comparisons with vector sizes

public:
    explicit databaseViewer(QWidget *parent = nullptr, bool adminUser = false, databaseManager* dbManager = nullptr);
    ~databaseViewer();

private slots:

    void on_modifyStadiumButton_clicked();

    void on_addStadiumButton_clicked();

    void on_closeDatabaseButton_clicked();

    void on_displayTeamButton_clicked();

    void on_displayAllButton_clicked();


private:

    void filterLeague(vector<stadium>* stadiums, int index);

    void filterGreatestDistance(vector<stadium>* stadiums);

    void filterSmallestDistance(vector<stadium>* stadiums);

    void filterRoofType(vector<stadium>* stadiums);

    void sortByStadium(vector<stadium>* stadiums);

    void sortByTeam(vector<stadium>* stadiums);

    void sortByParkTypology(vector<stadium>* stadiums);

    void sortByDateOpened(vector<stadium>* stadiums);

    void sortByCapacity(vector<stadium>* stadiums);

    long totalCapacity(vector<stadium>* stadiums);

    Ui::databaseViewer *ui;

    databaseManager* database;

    bool isAdmin;
};

#endif // DATABASEVIEWER_H
