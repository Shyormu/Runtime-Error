#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableView>
#include <vector>
#include <algorithm>

using namespace std;

class databaseManager
{
public:
    //!
    //! \brief dbManager
    //! \param path file path to external SQLite database
    //!
    databaseManager(const QString& filePath);

    //!
    //! \brief getTeamNames
    //! \return QString vector of all team names
    //!
    vector<QString> getTeamNames();

    //!
    //! \brief getTeamViewModel
    //! \param teamName name of team to get information from
    //! \return model containing all information related to the baseball team
    //!
    QSqlQueryModel* getTeamViewModel(const QString& teamName);

private:
    //!
    //! \brief mainDatabase
    //! QSQLDatabase object which manages the SQLite database of team and stadium information
    //!
    QSqlDatabase mainDatabase;
};

#endif // DATABASEMANAGER_H
