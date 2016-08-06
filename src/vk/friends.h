#ifndef FRIENDS_H
#define FRIENDS_H

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QList>
#include <QObject>
#include <QString>
#include <QUrlQuery>

#include "apirequest.h"
#include "objects/friend.h"

#include <QDebug>

class Friends : public QObject
{
    Q_OBJECT

public:
    explicit Friends(QObject *parent = 0);
    ~Friends();

    void setAccessToken(QString value);

    Q_INVOKABLE void get(int userId);

signals:
    void gotFriendsList(QList<QObject*> friendsList);

public slots:
    void gotResponse(QJsonValue value, ApiRequest::TaskType type);

private:
    QString _accessToken;
};

#endif // FRIENDS_H
