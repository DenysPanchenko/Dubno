#ifndef SCENE_H
#define SCENE_H

#include <QtOpenGL>
#include <QFileDialog>
#include <QString>
#include <QtDebug>
#include "FilterFactory.h"
#include "Filter.h"

class Scene : public QGLWidget
{
    Q_OBJECT

public:
    Scene(FilterFactory* ff, QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

public slots:
    void changeFilter(QString);
    void changeFilter(int);

private slots :
    void openImage();

private:
    void draw();

    FilterFactory* factory;
    QString imageName;
    GLuint textname;
    QGLShaderProgram* currentFilter;

};



#endif // SCENE_H
