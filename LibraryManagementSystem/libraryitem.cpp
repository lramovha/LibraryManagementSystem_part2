#include "libraryitem.h"

// Constructor that initializes a LibraryItem object
LibraryItem::LibraryItem(const QString& title, const QString& author, const QString& id)
    : title(title), author(author), id(id), borrowed(false) {
}

// This Method to displays basic information about the library item
void LibraryItem::displayInfo() const {
    qDebug() << "ID:" << id << "Title:" << title << "Author:" << author << "Borrowed:" << (borrowed ? "Yes" : "No");
}
