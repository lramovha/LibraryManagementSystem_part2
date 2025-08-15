#include "libraryutils.h"
#include "book.h"
#include "magazine.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

LibraryUtils::LibraryUtils() {
}

QString LibraryUtils::getVersion() const {
    return QString("LibraryUtils v1.0");
}

// Saves a list of LibraryItem pointers (books or magazines) to a text file
bool LibraryUtils::saveItems(const QList<LibraryItem*>& items, const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open" << filename << "for writing";
        return false;
    }

    QTextStream out(&file);

    // Iterate through each library item and write details to the file
    for (const auto* item : items) {
        // Ussing dynamic_cast to determine the actual type (Book or Magazine)
        if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
            out << "Book," << b->getId() << "," << b->getTitle() << "," << b->getAuthor() << "," << b->getGenre() << "," << b->isBorrowed() << "\n";
        } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
            out << "Magazine," << m->getId() << "," << m->getTitle() << "," << m->getAuthor() << "," << m->getIssueNumber() << "," << m->isBorrowed() << "\n";
        }
    }
    file.close();
    return true;
}

// Loads library items from a file and returns a list of LibraryItem pointers
QList<LibraryItem*> LibraryUtils::loadItems(const QString& filename) {
    QList<LibraryItem*> loadedItems;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open" << filename << "for reading";
        return loadedItems;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        // Expecting at least 6 fields: type, id, title, author, genre/issue, borrowed
        if (fields.size() >= 6) {
            QString type = fields[0];
            QString id = fields[1];
            QString title = fields[2];
            QString author = fields[3];
            bool borrowed = (fields[5] == "true" || fields[5] == "1");

            if (type == "Book") {
                QString genre = fields[4];
                Book* book = new Book(title, author, id, genre);
                book->setBorrowed(borrowed);
                loadedItems.append(book);
            } else if (type == "Magazine") {
                bool ok;
                int issue = fields[4].toInt(&ok);
                if (ok) {
                    Magazine* magazine = new Magazine(title, author, id, issue);
                    magazine->setBorrowed(borrowed);
                    loadedItems.append(magazine);
                }
            }
        }
    }
    file.close();
    return loadedItems;
}
