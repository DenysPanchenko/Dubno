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
        connect(pntr,SIGNAL(valueChanged(double)),SLOT(getChangeSlot()));
        QPair<QString,QDoubleSpinBox*> p;
        p.first = ps[i].first;
        p.second = pntr;
        paramsSpinBox.append(p);
        QLabel* parLabel = new QLabel(ps[i].first);
        QHBoxLayout* hb = new QHBoxLayout();
        hb->addWidget(parLabel);
        hb->addWidget(pntr);
        mainLayout->addLayout(hb);
    }
    mainLayout->addStretch();
    setLayout(mainLayout);
}

void Filter::getChangeSlot(){
    QVector<QPair<QString,double> > new_params = getParam();
    emit paramsChange(new_params);
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

const QString Filter::getFilterName() const{
   return this->filter_name;
}
