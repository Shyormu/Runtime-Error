#ifndef SOUVENIR_H
#define SOUVENIR_H

#include "admin.h"

class Souvenir : public QObject
{
    Q_OBJECT
public:

    explicit Souvenir(QObject *parent = nullptr);

    QString item() const;

    void setItem(const QString &item);

    QString price() const;

    void setPrice(QString price);

    QString team() const;

    void setTeam(QString Team);

signals:

public slots:
private:
    QString m_item;
    QString m_price;
    QString TeamName;
};

#endif // SOUVENIR_H
