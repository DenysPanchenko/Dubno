#ifndef SCENE_H
#define SCENE_H

#include <QtOpenGL>
#include <QFileDialog>
#include <QString>
#include <QtDebug>

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

private slots :
    void openImage();

private:
    void draw();

    QString imageName;
    GLuint textname;
    QGLShaderProgram* filter;
    QGLShader* fragmentShader;
    QGLShader* vertexShader;
};



#endif // SCENE_H
