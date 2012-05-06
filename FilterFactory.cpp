#include "FilterFactory.h"

FilterFactory::FilterFactory(const QString &fileName){
    configFilePath = fileName;
}

int FilterFactory::getPoolSize() const{
    return filterPool.size();
}

Filter* FilterFactory::getFilter(int pos) const{
    if(pos >= 0 && pos < getPoolSize())
        return filterPool.at(pos);
}

void FilterFactory::fillFilterPool(){
    if(QFile::exists(configFilePath))
        configParser.setConfigFileName(configFilePath);
    else
        return;
    if(!configParser.parse()){
        qDebug("PIZDA2");
        QList<QString> filterList = configParser.getListOfFilters();
        int i = 1;
        qDebug() << filterList;
        foreach(QString f_name, filterList){
            qDebug(f_name.toStdString().c_str());
            QPair<QString, QString> files = configParser.getVertFragFilesForFilter(f_name);
            QVector<QPair<QString,QPair<double,double> > > params = configParser.getParamsForFilter(f_name);


            Filter* f = new Filter(f_name,files.first,files.second,params);
            qDebug() << f;
            filterPool.append(f);
            qDebug() << filterPool.size();
        }
    }
    else
        qDebug(configParser.getErrorLog().toStdString().c_str());
}
