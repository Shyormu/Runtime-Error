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

    void filterLeague(vector<stadium>* stadiums, QString selection);

    Ui::databaseViewer *ui;

    databaseManager* database;

    bool isAdmin;
};

#endif // DATABASEVIEWER_H
