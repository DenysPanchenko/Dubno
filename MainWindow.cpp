#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow* prnt) : QMainWindow(prnt){
    mainMenu = new QMenuBar();

    openImageAction = new QAction("Load Image",this);


    fileMenu = new QMenu();

    fileMenu->addAction(openImageAction);

    editMenu = new QMenu();

    helpMenu = new QMenu();

    mainMenu->addMenu(fileMenu);
    mainMenu->addMenu(editMenu);
    mainMenu->addMenu(helpMenu);

    factory = new FilterFactory(QDir::currentPath() + "/config.txt");
    factory->fillFilterPool();


    centralWidget = new Scene(factory);
    toolBox = new QToolBox();
    //toolBox->addItem((QWidget*)factory->getFilter(0),"First");
    //toolBox->addItem((QWidget*)factory->getFilter(1),"Second");

    dockWidgetPref = new QDockWidget();
    dockWidgetPref->setWidget(toolBox);

    widget = new QWidget();
    dockWidgetPrev = new QDockWidget();
    dockWidgetPrev->setWidget(widget);

    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPrev);
    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPref);

    setCentralWidget(centralWidget);    
    setMenuBar(mainMenu);
    resize(400,300);

    connect(openImageAction,SIGNAL(triggered()),centralWidget,SLOT(openImage()));
    connect(centralWidget,SIGNAL(resizeMainWindow(QString)),this,SLOT(resizeMainWindow(QString)));

}

void MainWindow::setTitles(){
    fileMenu->setTitle("File");
    editMenu->setTitle("Edit");
    helpMenu->setTitle("Help");
}

void MainWindow::resizeMainWindow(QString image){
    QImage* curImage = new QImage(image);
    QSize size = curImage->size();
    delete curImage;
    resize(size.width()+dockWidgetPref->size().width(),size.height());
}
