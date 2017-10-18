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


static QObject *provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    QmlShellAdapter* object = new QmlShellAdapter();

    return object;
}

void init()
{
    qmlRegisterSingletonType<QmlShellAdapter>("Shell", 1, 0, "Shell", provider);
}

Q_COREAPP_STARTUP_FUNCTION(init)
