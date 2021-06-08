#include "messagedialog.h"
#include "ui_messagedialog.h"

#include <QDialog>
#include <QImage>
#include <QDebug>

MessageDialog::MessageDialog(QString title, QString message, DialogType type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    switch(type)
    {
    case ShowMessage:
        break;

    case Select:
        break;
    }
    Qt::WindowFlags flags = Qt::Dialog;
    flags = flags | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    if(title.isEmpty())
        title = tr("Default Title");
    if(message.isEmpty())
        message = tr("Default Message");

    setWindowTitle(title);
    ui->label_message->setText(message);

    QImage image(":/dialoglib/icon-default.png");
    ui->label_image->setMinimumSize(image.size());
    qDebug() << ui->label_image->size();
    adjustSize();
    qDebug() << ui->label_image->size();
}

MessageDialog::~MessageDialog()
{
    delete ui;
}

int MessageDialog::exec()
{
    setAttribute(Qt::WA_ShowModal, true);
    show();
    m_eventloop = new QEventLoop();
    m_eventloop->exec();
    m_eventloop = NULL;
    return m_result;
}

void MessageDialog::on_pushButton_OK_clicked()
{
    m_result = QDialog::Accepted;
    if(m_eventloop)
    {
        m_eventloop->exit();
    }
}

void MessageDialog::on_pushButton_Cancel_clicked()
{
    m_result = QDialog::Rejected;
    if(m_eventloop)
    {
        m_eventloop->exit();
    }
}
