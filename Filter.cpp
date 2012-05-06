#include "Filter.h"

Filter::Filter(QWidget *parent) : QWidget(parent){

}

Filter::Filter(QString f_name, QString v_file, QString f_file, QVector<QPair<QString, QPair<double, double> > > ps){
    mainLayout = new QVBoxLayout();
    filter_name = f_name;
    vert_file = v_file;
    frag_file = f_file;
    QDoubleSpinBox* pntr;
    for(int i = 0; i < ps.size(); i++){
        pntr = new QDoubleSpinBox();
        pntr->setMinimum(ps[i].second.first);
        pntr->setMaximum(ps[i].second.second);
        QPair<QString,QDoubleSpinBox*> p;
        p.first = ps[i].first;
        p.second = pntr;
        paramsSpinBox.append(p);
        mainLayout->addWidget(pntr);
    }
    setLayout(mainLayout);
}

QVector<QPair<QString, double> > Filter::getParam() const{
    QVector<QPair<QString, double> > result;
    for(int i = 0; i < paramsSpinBox.size(); i++){
        QPair<QString,double> t;
        t.first = paramsSpinBox[i].first;
        t.second = paramsSpinBox[i].second->value();
    }
    return result;
}
