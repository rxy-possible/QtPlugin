#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QString>
#include <QtPlugin>

class PluginInterface
{
public:
    virtual ~PluginInterface() {}		//避免编译器抱怨

    virtual QStringList interfaceList() = 0;

    virtual QString action(QString& interface) = 0;
};

QT_BEGIN_NAMESPACE
#define PluginInterface_iid "org.csm.embed.plugin.pluginInterface.1.0"
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
QT_END_NAMESPACE

#endif // PLUGININTERFACE_H

