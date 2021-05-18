#include "Souvenir.h"

QString Souvenir::item() const
{
    return m_item;
}

void Souvenir::setItem(const QString &item)
{
    m_item = item;
}

void Souvenir::draw()
{
    Ellipse::draw();
}

void Souvenir::move(const int x, const int y)
{
    Ellipse::move(x,y);
}

double Souvenir::perimeter() const
{
    return 2 * M_PI * radius1;
}

double Souvenir::area() const
{
    return M_PI * radius1 * radius1;
QString Souvenir::price() const
{
    return m_price;
}

void Souvenir::setPrice(QString price)
{
    m_price = price;
}

void Souvenir::setTeam(QString team)
{
    TeamName = team;
}
QString Souvenir :: team() const
{
    return TeamName;
}
