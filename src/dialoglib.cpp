#include "dialoglib.h"

#include <QFile>
#include <QApplication>
#include <QResource>
#include <QObject>
#include <QApplication>
#include <QDebug>

#include "messagedialog.h"

static QString m_resourcefilename;
static QApplication* libApp = NULL;
static int argc = 1;
static char* argv[] = {"", NULL};

int WINAPI Initialize(const char* resourcefilename)
{
    //check application
    libApp = qApp;
    if(libApp == NULL)
    {
        libApp = new QApplication(argc, argv);
        libApp->setQuitOnLastWindowClosed(false);
    }

    if(resourcefilename == NULL || strlen(resourcefilename) <= 0)
    {
        Q_INIT_RESOURCE(dialoglib);
    }
    else
    {
        Q_CLEANUP_RESOURCE(dialoglib);
        m_resourcefilename = resourcefilename;
        if(!QFile(m_resourcefilename).exists())
        {
            m_resourcefilename = QCoreApplication::applicationDirPath() + "/" + resourcefilename;
        }
        qDebug() << m_resourcefilename << " exists:"<<QFile(m_resourcefilename).exists();
        QResource::registerResource(m_resourcefilename);
    }

    //load translation

    //load stylesheet
    QFile stylefile(":/dialoglib/stylesheet.qss");
    stylefile.open(QFile::ReadOnly);
    QString stylesheet = stylefile.readAll();
    libApp->setStyleSheet(stylesheet);
    stylefile.close();


    return UI_SUCCESSED;
}

int WINAPI Finalize()
{
    if(m_resourcefilename.isEmpty())
    {
        Q_CLEANUP_RESOURCE(dialoglib);
    }
    else
    {
        QResource::unregisterResource(m_resourcefilename);
    }
    return UI_SUCCESSED;
}

int WINAPI ShowMessageDialog(const char *title, const char *message)
{
    qDebug() << "input title = "<<title<<", message = "<< message;
    QString msgstr = QString::fromUtf8(message);
    qDebug() << "utf8 message = "<< msgstr;
    MessageDialog msgdlg(title, msgstr, MessageDialog::ShowMessage);
    return msgdlg.exec();
}
