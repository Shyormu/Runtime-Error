#ifndef TEAM_H
#define TEAM_H

#include "stadium.h"

class Team : public QObject
{
    Q_OBJECT
public:

    explicit Team (QObject *parent = nullptr);

    void setTeamName(QString name);

    QString getTeamName();

    void setStadiumName(QString stadium);

    QString getStadiumName();

    void setSeatingCapacity(QString capacity);

    QString getSeatingCapacity();

    void setLocation(QString location);

    QString getLocation();

    void setPlayingSurface(QString surface);

    QString getPlayingSurface();

    void setLeague(QString League);

    QString getLeague();

    void setDateOpened(QString date);

    QString getDateOpened();

    void setDTC(QString dtc);

    QString getDTC();

    void setBallparkTypology(QString typology);

    QString getBallparkTypology();

    void setRoofType(QString rooftype);

    QString getroofType();

private:
    QString teamName;
    QString stadiumName;
    QString seatingCapacity;
    QString teamLocation;
    QString playingSurface;
    QString league;
    QString dateOpened;
    QString distanceToCenter;
    QString ballparkTypology;
    QString teamRoofType;
};

#endif // TEAM_H
