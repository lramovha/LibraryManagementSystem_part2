#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "libraryitem.h"

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(const QString& title, const QString& author, const QString& id, int issueNumber);
    int getIssueNumber() const { return issueNumber; }
    void setIssueNumber(int issueNumber) { this->issueNumber = issueNumber; }
    void displayInfo() const override;
};

#endif // MAGAZINE_H
