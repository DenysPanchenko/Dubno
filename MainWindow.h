#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMenu>
#include <QtGui/QAction>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBox>
#include <QtGui/QMenuItem>
#include <QtGui/QScrollArea>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMessageBox>
#include <QtGui/QTableWidget>
#include <QtOpenGL/QGLWidget>

#include "helpwidget.h"
#include "FilterFactory.h"
#include "scene.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
private:
    Scene* centralWidget; //temp QGLWidget

    QWidget*     dockWidgetContents;
    QWidget*     scrollAreaWidgetContents;
    QToolBox*    toolBox;
    QDockWidget* dockWidgetPref;
    QVBoxLayout* vbLayout;
    QHBoxLayout* horizontalLayout;
    QHBoxLayout* hbLayout;
    QScrollArea* scrollArea;

    QDockWidget* dockWidgetPrev;
    QLabel* imageLabel;

    QMenuBar* mainMenu;
    QMenu* fileMenu;
        QAction* openImageAction;
        QAction* closeAction;
    QMenu* editMenu;
        QAction* showPreview;
        QAction* showPrefers;
    QMenu* helpMenu;
        QMenu* language;
        QAction* english;
        QAction* ukrainian;
        QAction* helpAction;
        QAction* aboutAction;

    FilterFactory* factory;
    HelpWidget* helpWidget;

private slots:
    void resizeMainWindow(QString);
    void openImage();
    void about();
    void help();
    void previewCheck(bool);
    void preferenceCheck(bool);
    void setDockPrevVisible();
    void setDockPrefVisible();
    void engLang();
    void ukrLang();
    void showHelp();

public:
    MainWindow(QMainWindow* prnt = 0);
    void setTitles(QString l);
};

#endif // MAINWINDOW_H
