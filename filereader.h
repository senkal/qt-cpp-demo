#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>

#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QStringList>

class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QObject *parent = 0);

    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)

    // method
    Q_INVOKABLE void readFile();

    // getters
    QString fileName();

    // setters
    void setFileName(const QString &fileName);


private:
    QString m_fileName;

signals:
    void fileNameChanged();

public slots:
};

#endif // FILEREADER_H
