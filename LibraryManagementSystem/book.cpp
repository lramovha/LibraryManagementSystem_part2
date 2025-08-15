#include "book.h"

// Constructor that initializes a Book object
Book::Book(const QString& title, const QString& author, const QString& id, const QString& genre)
    : LibraryItem(title, author, id), genre(genre) {
}

// Displays information about the book
void Book::displayInfo() const {
    qDebug() << "Book - ID:" << getId() << "Title:" << getTitle() << "Author:" << getAuthor() << "Genre:" << genre << "Borrowed:" << (isBorrowed() ? "Yes" : "No");
}
