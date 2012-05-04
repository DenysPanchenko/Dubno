#include "glTexture.h"
#include "QGLWidget"

glTexture::glTexture(){
    created = false;
}

void glTexture::createTexture(QImage* image ){

    width  = image->width ();
    height = image->height();

    if(created == true)
        glDeleteTextures(1, &texname);

    glEnable(GL_TEXTURE_2D);

    QImage t;
    t = QGLWidget::convertToGLFormat(*image);
    glGenTextures(1, &texname);
    glBindTexture(GL_TEXTURE_2D, texname);
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, width, height,0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits());

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// Linear Filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	// Linear Filtering

    created = true;

    glDisable(GL_TEXTURE_2D);
}

glTexture::~glTexture(){
    if (created) glDeleteTextures(1, &texname);
}

void glTexture::bindTexture()
{
   glBindTexture(GL_TEXTURE_2D, texname);
}
