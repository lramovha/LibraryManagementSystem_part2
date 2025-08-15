#ifndef BOOK_H
#define BOOK_H

#include "libraryitem.h"

// The Book class inherits from LibraryItem
class Book : public LibraryItem {
private:
    QString genre;  // Stores the genre of the book (e.g., Fiction, Science)

public:
    // Constructor: initializes a Book object with title, author, id, and genre
    Book(const QString& title, const QString& author, const QString& id, const QString& genre);

    //getter and setter for genre
    QString getGenre() const { return genre; }
    void setGenre(const QString& genre) { this->genre = genre; }

    // Override the displayInfo function from LibraryItem to show book-specific details
    void displayInfo() const override;
};

#endif // BOOK_H
