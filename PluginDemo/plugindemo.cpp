//plugindemo.cpp
#include "plugindemo.h"

#include <QDebug>

PluginDemo::PluginDemo()
{
    m_ifList.append("interface1");
    m_ifList.append("interface2");
}

QStringList PluginDemo::interfaceList()
{
    return m_ifList;
}

QString PluginDemo::action(QString &interface)
{
    QString actionName;
    if(m_ifList.contains(interface)) {
        actionName =  interface + " done...";
    } else {
        actionName =  interface + " is not exists";
    }
    qDebug() << actionName;
    return actionName;
}
