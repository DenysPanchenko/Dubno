#include "FilterFactory.h"
#include <QGLShaderProgram>

FilterFactory::FilterFactory(){

}

FilterFactory::FilterFactory(const QString &fileName){

}

int FilterFactory::getPoolSize() const{
    return filterPool.size();
}

Filter* FilterFactory::getFilter(int pos) const{
    if(pos > 0 && pos < getPoolSize())
        return filterPool.at(pos);
}

void FilterFactory::fillFilterPool(){
    configParser.setConfigFileName(".//config.txt");
    if(!configParser.parse()){
        //Filter temp_filter = new Filter(configParser.getListOfFilters().first(),configParser.getVertFragFilesForFilter().)
        //filterPool.append();
    }
    else
        qDebug(configParser.getErrorLog().toStdString().c_str());
}
