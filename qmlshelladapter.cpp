#include <QtShell>
#include <QtQml>
#include <QQmlEngine>
#include "qmlshelladapter.h"

QmlShellAdapter::QmlShellAdapter(QObject *parent) : QObject(parent)
{

}

QString QmlShellAdapter::cat(const QString &file)
{
    return QtShell::cat(file);
}

QString QmlShellAdapter::pwd() const
{
    return QtShell::pwd();
}

QStringList QmlShellAdapter::find(QVariantMap arguments)
{
    QStringList res;

    QString path = arguments["0"].toString();
    QStringList filters;

    if (arguments.contains("1")) {
        QVariant arg1 = arguments["1"];
        if (arg1.type() == QVariant::String) {
            filters << arg1.toString();
        } else {
            filters = arg1.toStringList();
        }
    }

    res = QtShell::find(path, filters);

    return res;
}

QString QmlShellAdapter::realpath_strip(QVariantMap arguments)
{
    QString res;

    int i = 0;

    while (arguments.contains(QString::number(i))) {
        QString arg = arguments[QString::number(i)].toString();
        if (i == 0) {
            res = QtShell::realpath_strip(arg);
        } else {
            res = QtShell::realpath_strip(res, arg);
        }
        i++;
    }

    return res;
}

static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    QmlShellAdapter* object = new QmlShellAdapter();

    return object;
}

void init()
{
    qmlRegisterSingletonType<QmlShellAdapter>("Shell.Private", 1, 0, "ShellAdapter", provider);
}

Q_COREAPP_STARTUP_FUNCTION(init)
