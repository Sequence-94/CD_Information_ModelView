#include "album.h"

Album::Album() {}

Album::Album(const QString &composer, const QString &albumName, double replacementValue, int rating)
    :composer{composer},albumName{albumName},replacementValue{replacementValue},rating{rating}
{}

QString Album::getComposer() const
{
    return composer;
}

void Album::setComposer(const QString &newComposer)
{
    composer = newComposer;
}

QString Album::getAlbumName() const
{
    return albumName;
}

void Album::setAlbumName(const QString &newAlbumName)
{
    albumName = newAlbumName;
}

double Album::getReplacementValue() const
{
    return replacementValue;
}

void Album::setReplacementValue(double newReplacementValue)
{
    replacementValue = newReplacementValue;
}

int Album::getRating() const
{
    return rating;
}

void Album::setRating(int newRating)
{
    rating = newRating;
}
