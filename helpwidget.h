/******************************************
**Класс представляющий виджет, отображающий
**справочное руководство.
*Наследник QTextBrowser
******************************************/

#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QtGui/QTextBrowser>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtCore/QDir>
#include <QtCore/QTextCodec>
#include <QtCore/QString>

class HelpWidget : public QWidget
{
    Q_OBJECT
public:
    HelpWidget(const QString& path, const QString& page, QWidget *parent = 0);
    static void showPage(const QString& page);
private:
    QVBoxLayout *mainLayout;
        QHBoxLayout *topLayout;
            QPushButton *homePushButton;
            QPushButton *cancelPushButton;
            QPushButton *backPushButton;
        QTextBrowser *textBrowser;
private slots:
    void updateWindowTitle();
};

#endif
