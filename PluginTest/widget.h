//widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringList>

class QLineEdit;
class QLabel;
class PluginInterface;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();

    void loadPlugin();

public slots:
    void queryInterface();

    void doAction();

private:
    QLabel* ifListInfo;				//显示接口列表
    QLabel* doneResult;
    QLineEdit* actionName ;			//输入接口名称
    PluginInterface* interfacePtr;  //保存接口指针
    QStringList interfaceList;		//保存运行结果
};
#endif // WIDGET_H
