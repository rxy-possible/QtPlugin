//plugindemo.h
#ifndef PLUGINDEMO_H
#define PLUGINDEMO_H

#include <QObject>

#include "plugininterface.h"

class PluginDemo : public QObject, PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.csm.embed.plugin.pluginInterface.1.0" FILE "plugindemo.json")
    Q_INTERFACES(PluginInterface)

public:
    explicit PluginDemo();

    QStringList interfaceList();

    QString action(QString& interface);

private:
    QStringList m_ifList;
};

#endif // PLUGINDEMO_H

