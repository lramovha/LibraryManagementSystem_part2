#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QString>  // For using QString type
#include <QDebug>   // For printing debug information


// Base class for all library items (books, magazines)
class LibraryItem {
private:
    QString title;
    QString author;
    QString id;
    bool borrowed;

public:
    // Constructor: initializes title, author, and id
    LibraryItem(const QString& title, const QString& author, const QString& id);
    virtual ~LibraryItem() = default;

    // Getters
    QString getTitle() const { return title; }
    QString getAuthor() const { return author; }
    QString getId() const { return id; }
    bool isBorrowed() const { return borrowed; }

    // Setters
    void setTitle(const QString& title) { this->title = title; }
    void setAuthor(const QString& author) { this->author = author; }
    void setId(const QString& id) { this->id = id; }
    void setBorrowed(bool borrowed) { this->borrowed = borrowed; }

    // Polymorphic display function
    virtual void displayInfo() const;
};

#endif // LIBRARYITEM_H
