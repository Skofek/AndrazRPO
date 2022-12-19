#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client (QObject *parent = nullptr);
    void SetSocket (const QString &hostName, quint16 port);

signals:

public slots:
    void connected();
    void disconnected();
    void readyRead();

    // void taskResult (int Number);

private:
   QTcpSocket *socket;

};

#endif // CLIENT_H
