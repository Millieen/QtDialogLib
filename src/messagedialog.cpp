#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
}

MessageDialog::~MessageDialog()
{
    delete ui;
}
