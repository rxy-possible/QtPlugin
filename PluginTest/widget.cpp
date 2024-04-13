//widget.cpp
#include "widget.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QDir>
#include <QtGlobal>
#include <QApplication>
#include <QPluginLoader>

#include "../PluginDemo/plugininterface.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(600, 400);
    QGridLayout* layout = new QGridLayout(this);

    QLabel* ifListName = new QLabel("list: ");
    ifListInfo = new QLabel("");
    QPushButton* queryButton = new QPushButton("inqury");
    connect(queryButton, &QPushButton::clicked,
            this, &Widget::queryInterface);

    layout->addWidget(ifListName, 0, 0);
    layout->addWidget(ifListInfo, 0, 1);
    layout->addWidget(queryButton, 0, 2);
    //QPushButton

    QLabel* actionLabel = new QLabel("interface:");
    actionName = new QLineEdit();
    actionName->setPlaceholderText("input one interface of list above");
    QPushButton* actionButton = new QPushButton("action");
    connect(actionButton, &QPushButton::clicked,
            this, &Widget::doAction);

    layout->addWidget(actionLabel, 1, 0);
    layout->addWidget(actionName, 1, 1);
    layout->addWidget(actionButton, 1, 2);

    doneResult  = new QLabel("result");
    layout->addWidget(doneResult, 2, 0, 1, 3, Qt::AlignCenter);

    interfacePtr = Q_NULLPTR;
}

Widget::~Widget()
{

}

void Widget::loadPlugin()
{
    bool bRet = true;
    //路径根据系统差异来具体实现
    QDir pluginDir(qApp->applicationDirPath());
#if defined (Q_OS_WIN)
    if (pluginDir.dirName().toLower() == "debug" || pluginDir.dirName().toLower() == "release") {
        pluginDir.cdUp();
        pluginDir.cdUp();
    }
#elif defined Q_OS_LINUX //Q_OS_WIN
    pluginDir.cdUp();
#endif //Q_OS_LINUX
    pluginDir.cd("plugins");

    foreach(QString fileName, pluginDir.entryList(QDir::Files)) {
        //获取插件的具体路径
        QString file = pluginDir.absoluteFilePath(fileName);

        //实例化QPluginLoader类
        QPluginLoader pluginLoader(file);

        //返回插件实例
        QObject* plugin = pluginLoader.instance();
        if (plugin) {
            //注意此处是插件类名，而不是接口类名称哦
            QString plugName = plugin->metaObject()->className();
            if (plugName == "PluginDemo") {
                interfacePtr = qobject_cast<PluginInterface*>(plugin);
                interfaceList = interfacePtr->interfaceList();
                break;
            }
        } else {
            qDebug() << pluginLoader.errorString();
        }
    }
}

void Widget::queryInterface()
{
    qDebug() << "query";
    loadPlugin();
    QString interfaceList;
    if (interfacePtr != Q_NULLPTR) {
        foreach(auto interfaceName, interfacePtr->interfaceList()) {
            interfaceList.append(interfaceName);
            interfaceList.append(", ");
        }

        if (!interfaceList.isEmpty())
            interfaceList.remove(interfaceList.length() - 2, 2);
    }
    ifListInfo->setText(interfaceList);
}

void Widget::doAction()
{
    //qDebug() << "doAction";
    QString action = actionName->text();
    QString doneAction = interfacePtr->action(action);
    doneResult->setText(doneAction);
}

