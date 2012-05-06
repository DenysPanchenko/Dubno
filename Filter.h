#ifndef FILTER_H
#define FILTER_H

#include <QWidget>
#include <QVector>
#include <QLayout>
#include <QDoubleSpinBox>

class Filter : public QWidget{
    Q_OBJECT
private:
    QString filter_name;
    QString vert_file;
    QString frag_file;
    QVector<int> params;
    QVector<QDoubleSpinBox*> paramsSpinBox;
public:
    explicit Filter(QWidget *parent = 0);
    Filter(QString filter_name, QString vert_filter, QString frag_filter, QVector<QPair<QString,QPair<double, double> > > ps);
    QString getVertexPath() {return vert_file;}
    QString getFragmentPath(){return frag_file;}
};

#endif // FILTER_H
