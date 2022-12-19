#include "mainwindow.h"
#include "client.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_loginButton_clicked()
{
    Client client;

    QString username = ui->usernameInput->text();
    QString password = ui->passwordInput->text();

    /*if(username == "test" && password == "test123") {
        QMessageBox::information(this, "Login", "Username is correct");
        client.SetSocket("localhost", 1234);
    }
    else {
        QMessageBox::warning(this, "Login", "Username or password is not correct, client could not be connected");
    }*/
}

