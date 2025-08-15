#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "libraryitem.h"

// Magazine class inherits from LibraryItem
class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
     // Constructor: initializes a Magazine object with title, author, id, and issue number
    Magazine(const QString& title, const QString& author, const QString& id, int issueNumber);

    //Getter and Setter for issue number
    int getIssueNumber() const { return issueNumber; }
    void setIssueNumber(int issueNumber) { this->issueNumber = issueNumber; }

     // Override the displayInfo function from LibraryItem to show magazine-specific details
    void displayInfo() const override;
};

#endif // MAGAZINE_H
