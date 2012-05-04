#include "FilterFactory.h"

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
    configParser.setConfigFileName("config");
    if(!configParser.parse()){
        //this->filterPool.append(new Filter(configParser.));
    }
    else
        qDebug(configParser.getErrorLog().toStdString().c_str());
}
