#ifndef QMLSHELLADAPTER_H
#define QMLSHELLADAPTER_H

#include <QObject>

class QmlShellAdapter : public QObject
{
    Q_OBJECT
public:
    explicit QmlShellAdapter(QObject *parent = nullptr);

signals:

public slots:
    QString cat(const QString& file);
};

#endif // QMLSHELLADAPTER_H
