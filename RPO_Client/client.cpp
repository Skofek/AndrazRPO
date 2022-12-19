#include "client.h"
#include <iostream>

Client::Client (QObject *parent) :
    QObject (parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(5);
}

void Client::SetSocket (const QString &hostName, quint16 port)
{
    //make a new socket
    socket = new QTcpSocket (this);

    qDebug () << "New socket created!";

    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    //signals that start different slots

    socket->connectToHost(hostName, port);
    if(!socket->waitForConnected(3000))
    {
        qDebug () << "Client not connected at: " << hostName << " " << port;
        exit(1);
    }
    else {
        qDebug () << "Client connected at: " << hostName << " " << port;
    }
}

//asynchronous - runs separately from the thread we created
void Client::connected ()
{
    qDebug () << "Client connected event";
    qDebug () << "Enter message to send: ";

    QString line;

    socket->write("line tekst");
}

//asynchronous
void Client::disconnected ()
{
    qDebug () << "Client disconnected";
    exit (0);
}

void Client::readyRead ()
{
    qDebug () << "Reading...";
    qDebug () << socket->readAll();
}
