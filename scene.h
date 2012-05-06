#ifndef SCENE_H
#define SCENE_H

#include <QtOpenGL>
#include <QFileDialog>
#include <QString>
#include <QtDebug>
#include <QImage>
#include "FilterFactory.h"
#include "Filter.h"

class Scene : public QGLWidget
{
    Q_OBJECT

public:
    Scene(FilterFactory* ff, QWidget *parent = 0);
    void openImage(QString fileName);
protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void resizeMainWindow(QString);

public slots:
    void changeFilter(int);
    void changeParameters(QVector<QPair<QString,double> >);


private:
    void draw();
    void genTexCoordOffsets(GLuint width, GLuint height, GLfloat step = 1.0f);

    GLfloat texCoordOffsets[25*2];
    FilterFactory* factory;
    QString imageName;
    GLuint textname;
    QGLShaderProgram* currentFilter;
    QImage* image;
    int width;
    int height;
    int curFilerNum;

};



#endif // SCENE_H
