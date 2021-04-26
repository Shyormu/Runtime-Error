#include "databaseManager.h"

databaseManager::databaseManager(const QString& filePath)
{
    // create the QSqlDatabase using the database found at the file path provided
    mainDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mainDatabase.setDatabaseName(filePath);

    // output error message if the database cannot be opened properly
    if (!mainDatabase.open())
    {
        qDebug() << "error: database could not be opened";
    }
    else
    {
        qDebug() << "database opened successfully";
    }
}

vector<QString> databaseManager::getTeamNames()
{
    vector<QString> names;

    // query database for team names
    QSqlQuery query("SELECT DISTINCT TEAM FROM MLBINFO");

    // add unique team names to vector
    while (query.next())
    {
        QString out = query.value(0).toString();
        names.push_back(out);
    }

    return names;
}

QSqlQueryModel* databaseManager::getTeamViewModel(const QString& teamName)
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    qDebug() << teamName;

    // query database for all information in row containing teamName
    query.prepare("SELECT TEAM, STADIUM, CAPACITY, LOCATION, SURFACE, LEAGUE, DATE, CENTER, TYPOLOGY, ROOF FROM MLBINFO WHERE TEAM = :TEAMNAME");
    query.bindValue(":TEAMNAME", teamName);

    query.exec();

    // set model's query to previously defined query
    model->setQuery(query);

    return model;
}

QSqlQueryModel* databaseManager::getAllByLeagueModel(const QString& leagueType)
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    qDebug() << leagueType;

    if (leagueType == "Both")
    {
        // query database for all information in row containing teamName
        query.prepare("SELECT DISTINCT TEAM, STADIUM, CAPACITY, LOCATION, SURFACE, LEAGUE, DATE, CENTER, TYPOLOGY, ROOF FROM MLBINFO");

        query.exec();

        // set model's query to previously defined query
        model->setQuery(query);
    }
    else
    {
        // query database for all information in row containing teamName
        query.prepare("SELECT TEAM, STADIUM, CAPACITY, LOCATION, SURFACE, LEAGUE, DATE, CENTER, TYPOLOGY, ROOF FROM MLBINFO WHERE LEAGUE = :LEAGUETYPE");
        query.bindValue(":LEAGUETYPE", leagueType);

        query.exec();

        // set model's query to previously defined query
        model->setQuery(query);
    }

    return model;
}
