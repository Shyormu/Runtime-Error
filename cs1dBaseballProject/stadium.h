#ifndef STADIUM_H
#define STADIUM_H

#include "Souvenir.h"

class stadium : public QObject
{
    Q_OBJECT
public:

    explicit stadium (QObject *parent = nullptr);

    QString getStadium1() const;

    void setStadium1(const QString &stadium);

    QString getStadium2() const;

    void setStadium2(QString stadium);

    QString getDistance() const;

    void setDistance(QString distance);

signals:

public slots:
private:
    QString stadium1;
    QString stadium2;
    QString distance;
};
#endif // STADIUM_H
