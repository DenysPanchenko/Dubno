#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow* prnt) : QMainWindow(prnt){
    mainMenu = new QMenuBar();

    openImageAction = new QAction("Load Image",this);
    aboutAction = new QAction("About",this);
    helpAction = new QAction("Help",this);
    closeAction = new QAction("Close",this);

    fileMenu = new QMenu();
    fileMenu->addAction(openImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAction);

    editMenu = new QMenu();

    helpMenu = new QMenu();
    helpMenu->addAction(helpAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutAction);

    mainMenu->addMenu(fileMenu);
    mainMenu->addMenu(editMenu);
    mainMenu->addMenu(helpMenu);

    factory = new FilterFactory(QDir::currentPath() + "/config.txt");
    factory->fillFilterPool();

    centralWidget = new Scene(factory);
    toolBox = new QToolBox();
    for(int i = 0; i < factory->getPoolSize(); i++){
        toolBox->addItem(factory->getFilter(i),factory->getFilter(i)->getFilterName());
        //connect(factory->getFilter(i),SIGNAL(paramsChange(QVector<QPair<QString,double> >)),centralWidget,SLOT);
    }

    dockWidgetPref = new QDockWidget();
    dockWidgetPref->setWidget(toolBox);

    widget = new QWidget();
    dockWidgetPrev = new QDockWidget();
    dockWidgetPrev->setWidget(widget);

    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPrev);
    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPref);

    setCentralWidget(centralWidget);    
    setMenuBar(mainMenu);
    setMinimumSize(400,300);
    resize(400,300);

    connect(openImageAction,SIGNAL(triggered()),centralWidget,SLOT(openImage()));
    connect(centralWidget,SIGNAL(resizeMainWindow(QString)),this,SLOT(resizeMainWindow(QString)));
    connect(helpAction,SIGNAL(triggered()),this,SLOT(help()));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));
    connect(closeAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(toolBox,SIGNAL(currentChanged(int)),centralWidget,SLOT(changeFilter(int)));
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

void MainWindow::about(){
    QMessageBox::about(this,"About ImageProcessing","test");
}

void MainWindow::help(){

}
