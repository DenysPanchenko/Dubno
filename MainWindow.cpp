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
    showPreview = new QAction(this);
    showPreview->setCheckable(true);
    showPreview->setChecked(true);
    editMenu->addAction(showPreview);
    showPrefers = new QAction(this);
    showPrefers->setCheckable(true);
    showPrefers->setChecked(true);
    editMenu->addAction(showPrefers);

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
        connect(factory->getFilter(i),SIGNAL(paramsChange(QVector<QPair<QString,double> >)),centralWidget,SLOT(changeParameters(QVector<QPair<QString,double> >)));
    }

    dockWidgetPref = new QDockWidget();
    dockWidgetContents = new QWidget();
    hbLayout = new QHBoxLayout(dockWidgetContents);
    scrollArea = new QScrollArea(dockWidgetContents);
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    vbLayout = new QVBoxLayout(scrollAreaWidgetContents);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->addWidget(toolBox);
    vbLayout->addLayout(horizontalLayout);
    scrollArea->setWidget(scrollAreaWidgetContents);
    hbLayout->addWidget(scrollArea);
    dockWidgetPref->setWidget(dockWidgetContents);

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setScaledContents(true);
    dockWidgetPrev = new QDockWidget();
    dockWidgetPrev->setWidget(imageLabel);

    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPrev);
    this->addDockWidget(Qt::RightDockWidgetArea,dockWidgetPref);

    setCentralWidget(centralWidget);    
    setMenuBar(mainMenu);
    setMinimumSize(400,300);
    resize(400,300);

    connect(openImageAction,SIGNAL(triggered()),SLOT(openImage()));
    connect(centralWidget,SIGNAL(resizeMainWindow(QString)),this,SLOT(resizeMainWindow(QString)));
    connect(helpAction,SIGNAL(triggered()),this,SLOT(help()));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(about()));
    connect(closeAction,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(toolBox,SIGNAL(currentChanged(int)),centralWidget,SLOT(changeFilter(int)));
    connect(dockWidgetPrev,SIGNAL(visibilityChanged(bool)),SLOT(previewCheck(bool)));
    connect(dockWidgetPref,SIGNAL(visibilityChanged(bool)),SLOT(preferenceCheck(bool)));
    connect(showPreview,SIGNAL(triggered()),SLOT(setDockPrevVisible()));
    connect(showPrefers,SIGNAL(triggered()),SLOT(setDockPrefVisible()));
}

void MainWindow::setDockPrevVisible(){
    if(dockWidgetPrev->isVisible()){
        showPreview->setChecked(false);
        dockWidgetPrev->hide();
    }
    else{
        showPreview->setChecked(true);
        dockWidgetPrev->show();
    }
}

void MainWindow::setDockPrefVisible(){
    if(dockWidgetPref->isVisible()){
        showPrefers->setChecked(false);
        dockWidgetPref->hide();
    }
    else{
        showPrefers->setChecked(true);
        dockWidgetPref->show();
    }
}

void MainWindow::previewCheck(bool b){
    if(!b)
        showPreview->setChecked(false);
    else
        showPreview->setChecked(true);
}

void MainWindow::preferenceCheck(bool b){
    if(!b)
        showPrefers->setChecked(false);
    else
        showPrefers->setChecked(true);
}

void MainWindow::setTitles(){
    fileMenu->setTitle("File");
    editMenu->setTitle("Edit");
    showPreview->setText("Show preview");
    showPrefers->setText("Show filters");
    helpMenu->setTitle("Help");
}

void MainWindow::resizeMainWindow(QString image){
    QImage* curImage = new QImage(image);
    QSize size = curImage->size();
    delete curImage;
    resize(size.width()+dockWidgetPref->size().width(),size.height());
}

void MainWindow::openImage(){
    QString imageName = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                             "/home",
                                             tr("Images (*.png *.jpeg *.jpg *.gif)"));
    QPixmap image(imageName);
    imageLabel->setPixmap(image);
    imageLabel->setFixedWidth(190);
    imageLabel->setFixedHeight(image.height() * 190 / image.width());
    centralWidget->openImage(imageName);
}

void MainWindow::about(){
    QMessageBox::about(this,"About Dubno","<img src=\"logo.png\"> <h1>Dubno</h1>ver. 1.0.0\n"
                       "Authors: Panchenko Denys\n"
                       "Grytsun Vladyslav");
}

void MainWindow::help(){

}
