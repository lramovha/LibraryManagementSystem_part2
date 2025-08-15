#ifndef LIBRARYUTILS_H
#define LIBRARYUTILS_H

#include <QString>
#include <QList>
#include "libraryitem.h"

// Utility class for handling library-related operations
class LibraryUtils {
public:
    LibraryUtils();
    QString getVersion() const;

    // Data persistence methods
    bool saveItems(const QList<LibraryItem*>& items, const QString& filename);
    QList<LibraryItem*> loadItems(const QString& filename);
};

#endif // LIBRARYUTILS_H
