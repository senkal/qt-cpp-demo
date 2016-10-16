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
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString output READ output)
    Q_PROPERTY(QString errorString READ errorString)

public:
    explicit FileReader(QObject *parent = 0);

    // method
    Q_INVOKABLE void readFile();

    // getters
    QString fileName();
    QString output();
    QString errorString();

    // setters
    void setFileName(const QString &fileName);

protected slots:
    void handleOutput(QString output);
    void handleError(QString error);

private:
    QString m_fileName;
    QString m_output;
    QString m_errorString;

signals:
    void fileNameChanged();
    void outputChanged(QString);
    void gotError(QString);
    void error();
    void textChanged();

public slots:

};

#endif // FILEREADER_H
