#include "libraryitem.h"

LibraryItem::LibraryItem(const QString& title, const QString& author, const QString& id)
    : title(title), author(author), id(id), borrowed(false) {
}

void LibraryItem::displayInfo() const {
    qDebug() << "ID:" << id << "Title:" << title << "Author:" << author << "Borrowed:" << (borrowed ? "Yes" : "No");
}
