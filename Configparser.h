#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <QMap>
#include <QPair>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QString>
#include <QVector>

class ConfigParser
{
private:
    QMap<QString,QPair<QPair<QString,QString>,QVector<QPair<QString,QPair<double,double> > > > > params;
    QString configFileName;
    QString errorLog;
public:
    ConfigParser();
    QString getConfigFileName() const;
    void setConfigFileName(const QString& fn);
    int parse();
    int getSize() const;
    QList<QString> getListOfFilters() const;
    QString getErrorLog() const;
    QVector<QPair<QString,QPair<double,double> > > getParamsForFilter(const QString& filterName) const;
    QPair<QString,QString> getVertFragFilesForFilter(const QString& filterName) const;
};

#endif // CONFIGPARSER_H
