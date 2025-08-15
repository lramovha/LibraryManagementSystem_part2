#include "Book.h"

Book::Book(const QString& title, const QString& author, const QString& id, const QString& genre)
    : LibraryItem(title, author, id), genre(genre) {
}

void Book::displayInfo() const {
    qDebug() << "Book - ID:" << getId() << "Title:" << getTitle() << "Author:" << getAuthor() << "Genre:" << genre;
}
