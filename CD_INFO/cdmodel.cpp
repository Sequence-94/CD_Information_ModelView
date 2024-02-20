#include "cdmodel.h"
#include"album.h"
#include"widget.h"
#include<QMessageBox>

CDModel::CDModel(QObject *parent)
    : QStandardItemModel{parent}
{
    QStringList headers;
    headers.append("Composer");
    headers.append("Album title");
    headers.append("Replacement cost");
    headers.append("Rating");
    setHorizontalHeaderLabels(headers);






}

QList<Album> CDModel::getAlbums() const
{
    return albums;
}

void CDModel::setAlbums(const QList<Album> &newAlbums)
{
    albums = newAlbums;
}

void CDModel::addAlbum(const QString &composer, const QString &albumName, double replacementValue, int rating)
{
    // Create an Album object
    Album album(composer, albumName, replacementValue, rating);

    // Add the album to the internal list
    albums.append(album);

    // Add the album data to the model
    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem(composer)
             << new QStandardItem(albumName)
             << new QStandardItem(QString::number(replacementValue))
             << new QStandardItem(QString::number(rating));
    appendRow(rowItems);
}

void CDModel::deleteAlbum(const QModelIndexList& selectedIndexes)
{
    for (const QModelIndex& index : selectedIndexes) {
        this->removeRow(index.row());
    }
}

