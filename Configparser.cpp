#include "Configparser.h"

ConfigParser::ConfigParser(){

}

QString ConfigParser::getConfigFileName() const{
    return configFileName;
}

QList<QString> ConfigParser::getListOfFilters() const{
    return params.keys();
}

QVector<QPair<QString, QPair<double,double> > > ConfigParser::getParamsForFilter(const QString& fname) const{
    return params.value(fname).second;
}

int ConfigParser::getSize() const{
    return params.size();
}

void ConfigParser::setConfigFileName(const QString &fn){
    configFileName = fn;
}

int ConfigParser::parse(){
    QFile inputFile(configFileName);
    if(inputFile.open(QFile::ReadOnly)){
        QTextStream in(&inputFile);
        QString text = in.readAll();
        QStringList filterBlock = text.split("#");
        foreach(QString f, filterBlock){
            QString filterName;
            QString vertFile;
            QString fragFile;
            QVector<QPair<QString,QPair<double,double> > > t_params;
            int paramsQuant = 0;
            QStringList line = f.split(";");
            QString cur;
            if(line.size() > 2){
                cur = line.at(0);
                cur.remove("\n");
                QStringList token = line.at(0).split(":");
                if(token.at(0) != QString("FILTER_NAME")){
                    errorLog.append("Parsing error, expected identificator FILTER_NAME but get " + token.at(0) + "\n");
                    return -1;
                }
                else
                    filterName = token.at(1);
                //qDebug(filterName.toStdString().c_str());
                cur = line.at(1);
                cur.remove("\n");
                token = cur.split(":");
                if(token.at(0) != QString("VERT_FILE")){
                    errorLog.append("Parsing error, expected identificator VERT_FILE but get " + token.at(0) + "\n");
                    return -1;
                }
                else
                    vertFile = token.at(1);

                cur = line.at(2);
                cur.remove("\n");
                token = cur.split(":");
                if(token.at(0) != QString("FRAG_FILE")){
                    errorLog.append("Parsing error, expected identificator FRAG_FILE but get " + token.at(0) + "\n");
                    return -1;
                }
                else
                    fragFile = token.at(1);

                cur = line.at(3);
                cur.remove("\n");
                token = cur.split(":");
                if(token.at(0) != QString("PARAMS")){
                    errorLog.append("Parsing error, expected identificator PARAMS but get " + token.at(0) + "\n");
                    return -1;
                }
                else
                    paramsQuant = token.at(1).toInt();

                for(int i = 1; i < paramsQuant + 1; i++){
                    cur = line.at(3 + i);
                    cur.remove("\n");
                    token = cur.split(":");
                    QPair<QString,QPair<double,double> > t_p;
                    if(token.size() > 1){
                        t_p.first = token.at(0);
                        t_p.second.first = token.at(1).toDouble();
                        t_p.second.second = token.at(2).toDouble();
                        t_params.append(t_p);
                    }
                    else{
                        errorLog.append("Parsing error, wrong parameter in " + filterName + " filter\n");
                        return -1;
                    }
                }
            }
            QPair<QPair<QString,QString>, QVector<QPair<QString,QPair<double,double> > > > secondPart;
            secondPart.first.first = vertFile;
            secondPart.first.second = fragFile;
            secondPart.second = t_params;
            params.insert(filterName,secondPart);
        }
    }
    else{
        errorLog.append("Cannot open config file " + configFileName + "\n");
        return -1;
    }
    return 0;
}

QString ConfigParser::getErrorLog() const{
    return errorLog;
}
