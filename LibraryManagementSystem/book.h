#ifndef BOOK_H
#define BOOK_H

#include "libraryitem.h"

class Book : public LibraryItem {
private:
    QString genre;

public:
    Book(const QString& title, const QString& author, const QString& id, const QString& genre);
    QString getGenre() const { return genre; }
    void setGenre(const QString& genre) { this->genre = genre; }
    void displayInfo() const override;
};

#endif // BOOK_H
