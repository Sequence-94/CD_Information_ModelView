#ifndef ALBUM_H
#define ALBUM_H

#include<QString>

class Album
{
public:
    Album();
    Album(const QString &composer, const QString &albumName, double replacementValue, int rating);

    QString getComposer() const;
    void setComposer(const QString &newComposer);

    QString getAlbumName() const;
    void setAlbumName(const QString &newAlbumName);

    double getReplacementValue() const;
    void setReplacementValue(double newReplacementValue);

    int getRating() const;
    void setRating(int newRating);

private:
    QString composer;
    QString albumName;
    double replacementValue;
    int rating;
};

#endif // ALBUM_H
