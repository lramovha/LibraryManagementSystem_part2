#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include "magazine.h"
#include "LibraryUtils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    utils = new LibraryUtils();
    ui->statusBar->showMessage(utils->getVersion());

    // Load existing items from file
    QString filename = "library_data.txt";
    items = utils->loadItems(filename);

    if (items.isEmpty()) {
        // Create sample items if no data is loaded
        Book* book = new Book("The Great Gatsby", "F. Scott Fitzgerald", "B001", "Fiction");
        Magazine* magazine = new Magazine("National Geographic", "Various", "M001", 123);
        items.append(book);
        items.append(magazine);
    }

    // Display items in the QListWidget
    for (const auto* item : items) {
        if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
            ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ") - " + (b->isBorrowed() ? "Borrowed" : "Available"));
        } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
            ui->listWidgetItems->addItem(m->getTitle() + " by " + m->getAuthor() + " - Issue " + QString::number(m->getIssueNumber()) + " - " + (m->isBorrowed() ? "Borrowed" : "Available"));
        }
        item->displayInfo();
    }
}

MainWindow::~MainWindow()
{
    // Save items to file before cleanup
    QString filename = "library_data.txt";
    utils->saveItems(items, filename);

    qDeleteAll(items);
    items.clear();
    delete ui;
    delete utils;
}

void MainWindow::on_pushButtonAddBook_clicked() {
    QString title = ui->lineEditTitleBook->text();
    QString author = ui->lineEditAuthorBook->text();
    QString id = ui->lineEditIdBook->text();
    QString genre = ui->lineEditGenreBook->text();

    if (!title.isEmpty() && !author.isEmpty() && !id.isEmpty() && !genre.isEmpty()) {
        Book* book = new Book(title, author, id, genre);
        items.append(book);
        ui->listWidgetItems->addItem(book->getTitle() + " by " + book->getAuthor() + " (Genre: " + book->getGenre() + ") - " + (book->isBorrowed() ? "Borrowed" : "Available"));
        book->displayInfo();
        // Save immediately after adding
        utils->saveItems(items, "library_data.txt");
        ui->lineEditTitleBook->clear();
        ui->lineEditAuthorBook->clear();
        ui->lineEditIdBook->clear();
        ui->lineEditGenreBook->clear();
    }
}

void MainWindow::on_pushButtonAddMagazine_clicked() {
    QString title = ui->lineEditTitleMagazine->text();
    QString author = ui->lineEditAuthorMagazine->text();
    QString id = ui->lineEditIdMagazine->text();
    bool ok;
    int issue = ui->lineEditIssueMagazine->text().toInt(&ok);

    if (!title.isEmpty() && !author.isEmpty() && !id.isEmpty() && ok) {
        Magazine* magazine = new Magazine(title, author, id, issue);
        items.append(magazine);
        ui->listWidgetItems->addItem(magazine->getTitle() + " by " + magazine->getAuthor() + " - Issue " + QString::number(magazine->getIssueNumber()) + " - " + (magazine->isBorrowed() ? "Borrowed" : "Available"));
        magazine->displayInfo();
        // Save immediately after adding
        utils->saveItems(items, "library_data.txt");
        ui->lineEditTitleMagazine->clear();
        ui->lineEditAuthorMagazine->clear();
        ui->lineEditIdMagazine->clear();
        ui->lineEditIssueMagazine->clear();
    }
}

void MainWindow::on_pushButtonSearch_clicked() {
    QString searchTerm = ui->lineEditTitleBook->text();
    ui->listWidgetItems->clear();

    if (searchTerm.isEmpty()) {
        for (const auto* item : items) {
            if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
                ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ") - " + (b->isBorrowed() ? "Borrowed" : "Available"));
            } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
                ui->listWidgetItems->addItem(m->getTitle() + " by " + m->getAuthor() + " - Issue " + QString::number(m->getIssueNumber()) + " - " + (m->isBorrowed() ? "Borrowed" : "Available"));
            }
        }
    } else {
        for (const auto* item : items) {
            if (item->getTitle().contains(searchTerm, Qt::CaseInsensitive)) {
                if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
                    ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ") - " + (b->isBorrowed() ? "Borrowed" : "Available"));
                } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
                    ui->listWidgetItems->addItem(m->getTitle() + " by " + m->getAuthor() + " - Issue " + QString::number(m->getIssueNumber()) + " - " + (m->isBorrowed() ? "Borrowed" : "Available"));
                }
            }
        }
    }
}

void MainWindow::on_pushButtonBorrowReturn_clicked() {
    if (ui->listWidgetItems->currentItem()) {
        QString selectedText = ui->listWidgetItems->currentItem()->text();
        for (auto* item : items) {
            QString displayText;
            if (Book* b = dynamic_cast<Book*>(item)) {
                displayText = b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ") - " + (b->isBorrowed() ? "Borrowed" : "Available");
            } else if (Magazine* m = dynamic_cast<Magazine*>(item)) {
                displayText = m->getTitle() + " by " + m->getAuthor() + " - Issue " + QString::number(m->getIssueNumber()) + " - " + (m->isBorrowed() ? "Borrowed" : "Available");
            }
            if (displayText == selectedText) {
                item->setBorrowed(!item->isBorrowed());
                ui->listWidgetItems->clear();
                for (const auto* i : items) {
                    if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(i))) {
                        ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ") - " + (b->isBorrowed() ? "Borrowed" : "Available"));
                    } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(i))) {
                        ui->listWidgetItems->addItem(m->getTitle() + " by " + m->getAuthor() + " - Issue " + QString::number(m->getIssueNumber()) + " - " + (m->isBorrowed() ? "Borrowed" : "Available"));
                    }
                }
                // Save after borrow/return
                utils->saveItems(items, "library_data.txt");
                break;
            }
        }
    }
}
