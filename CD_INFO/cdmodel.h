#ifndef CDMODEL_H
#define CDMODEL_H

#include <QStandardItemModel>
#include <QObject>

class CDModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit CDModel(QObject *parent = nullptr);
};

#endif // CDMODEL_H
