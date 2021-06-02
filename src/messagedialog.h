#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QWidget>

namespace Ui {
class MessageDialog;
}

class MessageDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit MessageDialog(QWidget *parent = 0);
    ~MessageDialog();
    
private:
    Ui::MessageDialog *ui;
};

#endif // MESSAGEDIALOG_H
