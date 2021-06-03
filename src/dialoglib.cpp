#include "dialoglib.h"

#include <QFile>
#include <QApplication>
#include <QResource>
#include <QObject>

#include "messagedialog.h"

QString m_resourcefilename;
DialogLibErroCode WINAPI Initialize(const char* resourcefilename)
{
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
        QResource::registerResource(m_resourcefilename);
    }
    return UI_SUCCESSED;
}

DialogLibErroCode WINAPI Finalize()
{
    if(m_resourcefilename.isEmpty())
    {
        Q_CLEANUP_RESOURCE(dialoglib);
    }
    else
    {
        Q_CLEANUP_RESOURCE(m_resourcefilename);
    }
    return UI_SUCCESSED;
}

int WINAPI ShowMessageDialog(const char *title, const char *message)
{
    MessageDialog msgdlg(title, message, MessageDialog::ShowMessage);
    return msgdlg.exec();
}
