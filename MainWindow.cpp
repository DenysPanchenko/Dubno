#include <MainWindow.h>

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

    centralWidget = new Scene();

    filterFactory = new FilterFactory();
    filterFactory->fillFilterPool();

    toolBox = new QToolBox();
    toolBox->addItem((QWidget*)filterFactory->getFilter(0),"First");

    dockWidgetPref = new QDockWidget();
    dockWidgetPref->setWidget(toolBox);

    widget = new QWidget();
    dockWidgetPrev = new QDockWidget();
    dockWidgetPrev->setWidget(widget);

    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPrev);
    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPref);

    setCentralWidget(centralWidget);

    connect(openImageAction,SIGNAL(triggered()),centralWidget,SLOT(openImage()));

    setMenuBar(mainMenu);
}

void MainWindow::setTitles(){
    fileMenu->setTitle("File");
    editMenu->setTitle("Edit");
    helpMenu->setTitle("Help");
}
