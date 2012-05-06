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
    Scene(QWidget *parent = 0);

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

    QString imageName;
    GLuint textname;
    QGLShaderProgram* currentFilter;
    FilterFactory* factory;
};



#endif // SCENE_H
