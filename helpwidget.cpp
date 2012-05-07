#include "helpwidget.h"
#include <QTextStream>

HelpWidget::HelpWidget(const QString &path, const QString &page, QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    mainLayout = new QVBoxLayout;
        textBrowser = new QTextBrowser;
        topLayout = new QHBoxLayout;
            homePushButton = new QPushButton(trUtf8("Домой"));
            backPushButton = new QPushButton(trUtf8("Назад"));
            cancelPushButton = new QPushButton(trUtf8("Выход"));
            cancelPushButton->setShortcut(QKeySequence("Esc"));
        topLayout->addWidget(backPushButton);
        topLayout->addStretch();
        topLayout->addWidget(cancelPushButton);
    mainLayout->addLayout(topLayout);
    mainLayout->addWidget(textBrowser);
    setLayout(mainLayout);

    textBrowser->setSearchPaths(QStringList(path));
    textBrowser->setSource(page);

    connect(homePushButton,SIGNAL(clicked()),textBrowser,SLOT(home()));
    connect(backPushButton,SIGNAL(clicked()),textBrowser,SLOT(backward()));
    connect(cancelPushButton,SIGNAL(clicked()),SLOT(close()));
    connect(textBrowser,SIGNAL(sourceChanged(QUrl)),SLOT(updateWindowTitle()));
}

void HelpWidget::updateWindowTitle()
{
    setWindowTitle(trUtf8("Спарвка %1").arg(textBrowser->documentTitle()));
}

void HelpWidget::showPage(const QString &page)
{
    QString path = QDir::currentPath() + QDir::separator() + "help";
    HelpWidget *browser = new HelpWidget(path,page);
    browser->resize(500,400);
    browser->show();
}
