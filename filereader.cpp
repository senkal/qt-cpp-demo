#include "filereader.h"

FileReader::FileReader(QObject *parent) : QObject(parent)
{

}

void FileReader::readFile()
{
    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //process_line(line);
    }
    file.close();
    file.flush();
}

QString FileReader::fileName()
{
    return m_fileName;
}

void FileReader::setFileName(const QString &fileName)
{
    if (fileName == m_fileName)
        return;

    m_fileName = fileName;
    emit fileNameChanged();
}
