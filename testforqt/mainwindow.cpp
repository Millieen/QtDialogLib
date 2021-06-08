#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialoglib.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_initialize_clicked()
{    
    qDebug() << "Initialize() return " << Initialize();
}

void MainWindow::on_pushButton_showmessagedialog_clicked()
{
    int ret = ShowMessageDialog();
    qDebug() << "ShowMessageDialog() return "<<ret;
}

void MainWindow::on_pushButton_finalize_clicked()
{
    qDebug() << "Finalize() return " << Finalize();
}
