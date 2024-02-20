#ifndef CDMODEL_H
#define CDMODEL_H
#include "album.h"
#include"cdmodel.h"
#include<QList>
#include<QModelIndexList>

#include <QStandardItemModel>
#include <QObject>

class CDModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit CDModel(QObject *parent = nullptr);

    QList<Album> getAlbums() const;
    void setAlbums(const QList<Album> &newAlbums);



public slots:
    void addAlbum(const QString &composer, const QString &albumName, double replacementValue, int rating);
    void deleteAlbum(const QModelIndexList& selectedIndexes);

private:
    QList<Album> albums;
};

#endif // CDMODEL_H
