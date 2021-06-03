#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QWidget>
#include <QEventLoop>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QWidget
{
    Q_OBJECT

public:

    enum DialogType {
        ShowMessage,
        Select
    };
    explicit MessageDialog(QString title, QString message, DialogType type = ShowMessage, QWidget *parent = 0);
    ~MessageDialog();

    int exec();
    
private slots:
    void on_pushButton_OK_clicked();

    void on_pushButton_Cancel_clicked();

private:
    Ui::MessageDialog *ui;
    QEventLoop* m_eventloop;
    int m_result;
};

#endif // MESSAGEDIALOG_H
