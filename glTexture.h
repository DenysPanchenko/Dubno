#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <QImage>
#include <QtOpenGL>

class glTexture {

public:
    glTexture();
    ~glTexture();
    void createTexture(QImage*);
    void bindTexture();

private :
    int width;
    int height;
    bool created;
    GLuint texname;

};

#endif // GLTEXTURE_H
