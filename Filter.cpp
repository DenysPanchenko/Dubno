#include "Filter.h"

Filter::Filter(QWidget *parent) : QWidget(parent){

}

Filter::Filter(QString f_name, QString v_file, QString f_file, QVector<QPair<QString, QPair<double, double> > > ps){
    filter_name = f_name;
    vert_file = v_file;
    frag_file = f_file;
    QDoubleSpinBox* pntr;
    for(int i = 0; i < ps.size(); i++){
        pntr = new QDoubleSpinBox();
        pntr->setMinimum(ps[i].second.first);
        pntr->setMaximum(ps[i].second.second);
        paramsSpinBox.append(pntr);
        layout()->addWidget(pntr);
    }

}
