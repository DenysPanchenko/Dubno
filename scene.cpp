#include <QtGui>
#include "scene.h"

Scene::Scene(QWidget *parent): QGLWidget(parent)
{
    setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
}

void Scene::initializeGL()
{
    qglClearColor(Qt::white);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);
}

void Scene::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat x = GLfloat(width) / height;
    glFrustum(-x, +x, -1.0, +1.0, 4.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
}

void Scene::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw();
}

void Scene::mousePressEvent(QMouseEvent *event)
{

}

void Scene::mouseMoveEvent(QMouseEvent *event)
{

}

void Scene::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void Scene::draw()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glBindTexture(GL_TEXTURE_2D,textname);

    glBegin(GL_QUADS);
        glVertex3f(-1.0f, -1.0f,  0.0f);
        glTexCoord2f(1.0, 1.0);
        glVertex3f( 1.0f, -1.0f,  0.0f);
        glTexCoord2f(1.0, 0.0);
        glVertex3f( 1.0f,  1.0f,  0.0f);
        glTexCoord2f(0.0, 0.0);
        glVertex3f(-1.0f,  1.0f,  0.0f);
        glTexCoord2f(0.0, 1.0);
   glEnd();

}

void Scene::openImage(){
    imageName = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                             "/home",
                                             tr("Images (*.png *.jpeg *.jpg *.gif)"));
    textname = bindTexture(imageName,GL_TEXTURE_2D,GL_RGBA);
    updateGL();
}
