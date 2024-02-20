#include "bardelegate.h"
#include<QApplication>
#include<QPainter>
#include<QStyleOptionProgressBar>
#include<QBrush>
#include<QRect>




BarDelegate::BarDelegate(QObject *parent):QStyledItemDelegate(parent)
{

}

void BarDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column()==3){
        QStyleOptionProgressBar bar;
        bar.rect = option.rect;
        bar.minimum = 0;
        bar.maximum = 100;
        bar.progress = index.data().toInt();

        //daw bar
        painter->setBrush(Qt::NoBrush);
        painter->setPen(Qt::black);
        painter->drawRect(bar.rect);

        //bg color
        painter->fillRect(bar.rect, Qt::lightGray);

        //color progressbar
        QRect fillRect(bar.rect.x(), bar.rect.y(), bar.rect.width() * bar.progress / bar.maximum, bar.rect.height());
        painter->setBrush(Qt::cyan);
        painter->setPen(Qt::NoPen);
        painter->fillRect(fillRect, Qt::cyan);

    }
}

