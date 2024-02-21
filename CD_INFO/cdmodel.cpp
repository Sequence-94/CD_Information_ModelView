#include "cdmodel.h"
#include"album.h"
#include"widget.h"
#include<QMessageBox>
#include<QDebug>

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

bool CDModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && index.column()==2 && role==Qt::EditRole){
        double val = value.toDouble();
        bool isGreaterThan200 =false;
        if(val>=200){
            isGreaterThan200 = true;
            emit costExceeded(index.row(),isGreaterThan200);
            qDebug() << "cost exceeded signal emitted for row" << index.row() << "value" << val;
        }else{
            emit costExceeded(index.row(),isGreaterThan200);
            qDebug() << "cost subceeded signal emitted for row" << index.row() << "value" << val;
        }
        return true;
    }
    qDebug() << "after if function";
    return false;
}


void CDModel::addAlbum(const QString &composer, const QString &albumName, double replacementValue, int rating)
{

    Album album(composer, albumName, replacementValue, rating);

    //add album to list
    albums.append(album);

    //add album to model
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

