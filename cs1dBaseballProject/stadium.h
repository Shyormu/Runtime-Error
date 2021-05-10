#ifndef STADIUM_H
#define STADIUM_H

#include <QString>

/*! \file stadium.h
 *  \brief A file outlining the stadium class methods.
 */

using namespace std;

/*!
 * \brief The stadium class defines functions to retrieve and modify member information associated with a stadium object.
 */

class stadium
{
public:

     /*****************************
     *** CONSTRUCTOR/DESTRUCTOR ***
     *****************************/

    stadium();

    stadium(QString tName, QString sName, QString pType, QString rType, QString pSurface,
            QString bLeague, int cap, int opened, int dist);

    ~stadium();

     /****************
     *** ACCESSORS ***
     ****************/

    /*!
     * \brief Function returns the team name associated with this stadium. Function is constant.
     * \return QString containing the current object's team name.
     */

    QString getTeamName()     const;

    /*!
     * \brief Function returns the stadium name of this object. Function is constant.
     * \return QString containing the current object's stadium name.
     */

    QString getStadiumName()  const;

    /*!
     * \brief Function returns the location of this stadium. Function is constant.
     * \return QString containing the current object's location.
     */

    QString getLocation()     const;

    /*!
     * \brief Function returns the park typology of this stadium. Function is constant.
     * \return QString containing the current object's park typology.
     */

    QString getParkType()     const;

    /*!
     * \brief Function returns the roof type of this stadium. Function is constant.
     * \return QString containing the current object's roof type.
     */

    QString getRoofType()     const;

    /*!
     * \brief Function returns the playing surface of this stadium. Function is constant.
     * \return QString containing the current object's playing surface.
     */

    QString getSurface()      const;

    /*!
     * \brief Function returns the baseball league of this stadium. Function is constant.
     * \return QString containing the current object's baseball league.
     */

    QString getLeague()       const;

    /*!
     * \brief Function returns the seating capacity of this stadium. Function is constant.
     * \return QString containing the current object's seating capacity.
     */

    int getCapacity()         const;

    /*!
     * \brief Function returns the date of opening of this stadium. Function is constant.
     * \return QString containing the current object's date of opening.
     */

    int getDate()             const;

    /*!
     * \brief Function returns the distance to center field on this stadium. Function is constant.
     * \return QString containing the current object's distance to center field.
     */

    int getDistanceToCenter() const;


    /***************
    *** MUTATORS ***
    ***************/

    /*!
     * \brief Function accepts a QString argument and assigns it to this stadium object's teamName member variable.
     * \param name is a QString which holds the team name to assign to this stadium object.
     */

    void setTeamName(QString name);

    /*!
     * \brief Function accepts a QString argument and assigns it to this stadium object's stadiumName member variable.
     * \param name is a QString which holds the stadium name to assign to this stadium object.
     */

    void setStadiumName(QString name);

    /*!
     * \brief Function accepts a QString argument and assigns it to this stadium object's location member variable.
     * \param name is a QString which holds the location to assign to this stadium object.
     */

    void setLocation(QString name);

    /*!
     * \brief Function accepts a QString argument and assigns it to this stadium object's parkType member variable.
     * \param type is a QString which holds the park typology to assign to this stadium object.
     */

    void setParkType(QString type);

    /*!
     * \brief Function accepts a QString argument and assigns it to this stadium object's roofType member variable.
     * \param type is a QString which holds the roof type to assign to this stadium object.
     */

    void setRoofType(QString type);

    /*!
     * \brief Function accepts a QString argument and assigns it to this stadium object's surfaceType member variable.
     * \param type is a QString which holds the playing surface to assign to this stadium object.
     */

    void setSurface(QString type);

    /*!
     * \brief Function accepts a QString argument and assigns it to this stadium object's league member variable.
     * \param name is a QString which holds the baseball league to assign to this stadium object.
     */

    void setLeague(QString name);

    /*!
     * \brief Function accepts an integer argument and assigns it to this stadium object's capacity member variable.
     * \param cap is an integer which holds the seating capacity to assign to this stadium object.
     */

    void setCapacity(int cap);

    /*!
     * \brief Function accepts an integer argument and assigns it to this stadium object's date member variable.
     * \param date is an integer which holds the opening date to assign to this stadium object.
     */

    void setDate(int date);

    /*!
     * \brief Function accepts an integer argument and assigns it to this stadium object's distanceToCenter member variable.
     * \param distance is an integer which holds the distance to center field to assign to this stadium object.
     */

    void setDistanceToCenter(int distance);

private:
    QString teamName;
    QString stadiumName;
    QString location;
    QString parkType;
    QString roofType;
    QString surface;
    QString league;
    int     capacity;
    int     date;
    int     distanceToCenter;

};

#endif // STADIUM_H
