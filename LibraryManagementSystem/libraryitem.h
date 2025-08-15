#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <QString>
#include <QDebug>

class LibraryItem {
private:
    QString title;
    QString author;
    QString id;

public:
    LibraryItem(const QString& title, const QString& author, const QString& id);
    virtual ~LibraryItem() = default;

    // Getters
    QString getTitle() const { return title; }
    QString getAuthor() const { return author; }
    QString getId() const { return id; }

    // Setters
    void setTitle(const QString& title) { this->title = title; }
    void setAuthor(const QString& author) { this->author = author; }
    void setId(const QString& id) { this->id = id; }

    // Polymorphic display function
    virtual void displayInfo() const;
};

#endif // LIBRARYITEM_H
