#ifndef QMLSHELLADAPTER_H
#define QMLSHELLADAPTER_H

#include <QObject>
#include <QVariantMap>

class QmlShellAdapter : public QObject
{
    Q_OBJECT
public:
    explicit QmlShellAdapter(QObject *parent = nullptr);

signals:

public slots:
    QString cat(const QString& file);

    QString pwd() const;

    QStringList find(QVariantMap arguments);
};

#endif // QMLSHELLADAPTER_H
