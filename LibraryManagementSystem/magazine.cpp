#include "magazine.h"

Magazine::Magazine(const QString& title, const QString& author, const QString& id, int issueNumber)
    : LibraryItem(title, author, id), issueNumber(issueNumber) {
}

void Magazine::displayInfo() const {
    qDebug() << "Magazine - ID:" << getId() << "Title:" << getTitle() << "Author:" << getAuthor() << "Issue:" << issueNumber << "Borrowed:" << (isBorrowed() ? "Yes" : "No");
}
