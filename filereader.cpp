#include "filereader.h"

FileReader::FileReader(QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(gotError(QString)),
            this,SLOT(handleError(QString)));

    connect(this, SIGNAL(outputChanged(QString)),
            this, SLOT(handleOutput(QString)));
}

void FileReader::readFile()
{
    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        gotError("Can not read file");
    } else {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString content = in.readAll();
            outputChanged(content);
            file.close();
            file.flush();
            //process_line(line);
        }

        textChanged();
    }

}

QString FileReader::output()
{
   return m_output;
}

QString FileReader::fileName()
{
    return m_fileName;
}

QString FileReader::errorString()
{
   return m_errorString;
}

void FileReader::setFileName(const QString &fileName)
{
    if (fileName == m_fileName)
        return;

    m_fileName = fileName;
    emit fileNameChanged();
}

void FileReader::handleOutput(QString output)
{
   if (output == m_output)
       return;

   m_output = output;
}

void FileReader::handleError(QString errorMsg)
{
   if(errorMsg == m_errorString)
       return;
   m_errorString = errorMsg;
   emit error();
}
