#include "team.h"


void Team :: setTeamName(QString name)
{
    teamName = name;
}

QString Team :: getTeamName()
{
    return teamName;
}
void Team::setShapeBuffer(ShapeBuffer & temp)
{
    Shape::setShapeBuffer(temp);
    temp.one = one;
    temp.two = two;
}

QPoint Team::getQPointOne() const
{
    return one;
}

QPoint Team::getQPointTwo() const
{
 return two;
}

void Team::draw(const int, const int)
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    getQPainter()->drawTeam(one,two);
}

void Team::draw()
{
    getQPainter()->setPen(getPen());
    getQPainter()->setBrush(getBrush());
    drawID();
    getQPainter()->drawTeam(one,two);
    passQPainter(nullptr);
}

void Team::move(int x, int y)
{
    QPoint offset (two-one);
    QPoint tempOne(QPoint(x,y));
    QPoint tempTwo(QPoint(x,y)+offset);
    if(tempOne.x()<1000 &&tempOne.y()<500 && tempTwo.x()<1000 && tempTwo.y()<500)
    {
        one = tempOne;
        two = tempOne+offset;
    }
}
void Team :: setStadiumName(QString stadium)
{
    stadiumName = stadium;
}

QString Team :: getStadiumName()
{
    return stadiumName;
}

void Team :: setSeatingCapacity(QString capacity)
{
    seatingCapacity = capacity;
}


QString Team :: getSeatingCapacity()
{
    return seatingCapacity;
}

void Team :: setLocation(QString location)
{
    teamLocation = location;
}

QString Team :: getLocation()
{
    return teamLocation;
}

void Team :: setPlayingSurface(QString surface)
{
    playingSurface = surface;
}

QString Team :: getroofType()
{
    return teamRoofType;
}


