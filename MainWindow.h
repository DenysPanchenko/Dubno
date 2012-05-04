#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtOpenGL/QGLWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QMenu>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QScrollArea>
#include <QtGui/QTableWidget>
#include <QtGui/QMenuBar>
#include <QtGui/QMenuItem>
#include <QtGui/QToolBox>
#include <QtGui/QMainWindow>
#include <QAction>

#include "FilterFactory.h"
#include "scene.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
private:
    Scene* centralWidget; //temp QGLWidget

    QDockWidget* dockWidgetPref;
    QToolBox* toolBox;

    QDockWidget* dockWidgetPrev;
    QWidget* widget;

    QMenuBar* mainMenu;
    QMenu* fileMenu;
    QAction* openImageAction;
    QMenu* editMenu;
    QMenu* helpMenu;

    FilterFactory* filterFactory;
public:
    MainWindow(QMainWindow* prnt = 0);

    void setTitles();
};

#endif // MAINWINDOW_H
