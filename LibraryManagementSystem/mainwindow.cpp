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

    // Create and store sample items
    Book* book = new Book("The Great Gatsby", "F. Scott Fitzgerald", "B001", "Fiction");
    Magazine* magazine = new Magazine("National Geographic", "Various", "M001", 123);
    items.append(book);
    items.append(magazine);

    // Display items in the QListWidget from the .ui file
    for (const auto* item : items) {
        if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
            ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ")");
        } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
            ui->listWidgetItems->addItem(m->getTitle() + " - Issue " + QString::number(m->getIssueNumber()));
        }
        item->displayInfo();
    }
}

MainWindow::~MainWindow()
{
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
        ui->listWidgetItems->addItem(book->getTitle() + " by " + book->getAuthor() + " (Genre: " + book->getGenre() + ")");
        book->displayInfo();
        // Clear input fields
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
        ui->listWidgetItems->addItem(magazine->getTitle() + " - Issue " + QString::number(magazine->getIssueNumber()));
        magazine->displayInfo();
        // Clear input fields
        ui->lineEditTitleMagazine->clear();
        ui->lineEditAuthorMagazine->clear();
        ui->lineEditIdMagazine->clear();
        ui->lineEditIssueMagazine->clear();
    }
}

void MainWindow::on_pushButtonSearch_clicked() {
    QString searchTerm = ui->lineEditTitleBook->text(); // Use title field for search input
    ui->listWidgetItems->clear();

    if (searchTerm.isEmpty()) {
        // Show all items if search term is empty
        for (const auto* item : items) {
            if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
                ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ")");
            } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
                ui->listWidgetItems->addItem(m->getTitle() + " - Issue " + QString::number(m->getIssueNumber()));
            }
        }
    } else {
        // Filter items by title (case-insensitive)
        for (const auto* item : items) {
            if (item->getTitle().contains(searchTerm, Qt::CaseInsensitive)) {
                if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
                    ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ")");
                } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
                    ui->listWidgetItems->addItem(m->getTitle() + " - Issue " + QString::number(m->getIssueNumber()));
                }
            }
        }
    }
}
//#include "mainwindow.h"
//#include "ui_mainwindow.h"
//#include "book.h"
//#include "magazine.h"
//#include "LibraryUtils.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//    utils = new LibraryUtils();
//    ui->statusBar->showMessage(utils->getVersion());

//    // Create and store sample items
//    Book* book = new Book("The Great Gatsby", "F. Scott Fitzgerald", "B001", "Fiction");
//    Magazine* magazine = new Magazine("National Geographic", "Various", "M001", 123);
//    items.append(book);
//    items.append(magazine);

//    // Display items in the QListWidget from the .ui file , to the terminal using displayInfo().
//    for (const auto* item : items) {
//        if (Book* b = dynamic_cast<Book*>(const_cast<LibraryItem*>(item))) {
//            ui->listWidgetItems->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ")");
//        } else if (Magazine* m = dynamic_cast<Magazine*>(const_cast<LibraryItem*>(item))) {
//            ui->listWidgetItems->addItem(m->getTitle() + " - Issue " + QString::number(m->getIssueNumber()));
//        }
//        item->displayInfo();
//    }
//}

//MainWindow::~MainWindow()
//{
//    qDeleteAll(items);
//    items.clear();
//    delete ui;
//    delete utils;
//}

//void MainWindow::on_pushButtonAddBook_clicked() {
//    QString title = ui->lineEditTitleBook->text();
//    QString author = ui->lineEditAuthorBook->text();
//    QString id = ui->lineEditIdBook->text();
//    QString genre = ui->lineEditGenreBook->text();

//    if (!title.isEmpty() && !author.isEmpty() && !id.isEmpty() && !genre.isEmpty()) {
//        Book* book = new Book(title, author, id, genre);
//        items.append(book);
//        ui->listWidgetItems->addItem(book->getTitle() + " by " + book->getAuthor() + " (Genre: " + book->getGenre() + ")");
//        book->displayInfo();
//        // Clear input fields
//        ui->lineEditTitleBook->clear();
//        ui->lineEditAuthorBook->clear();
//        ui->lineEditIdBook->clear();
//        ui->lineEditGenreBook->clear();
//    }
//}

//void MainWindow::on_pushButtonAddMagazine_clicked() {
//    QString title = ui->lineEditTitleMagazine->text();
//    QString author = ui->lineEditAuthorMagazine->text();
//    QString id = ui->lineEditIdMagazine->text();
//    bool ok;
//    int issue = ui->lineEditIssueMagazine->text().toInt(&ok);

//    if (!title.isEmpty() && !author.isEmpty() && !id.isEmpty() && ok) {
//        Magazine* magazine = new Magazine(title, author, id, issue);
//        items.append(magazine);
//        ui->listWidgetItems->addItem(magazine->getTitle() + " - Issue " + QString::number(magazine->getIssueNumber()));
//        magazine->displayInfo();
//        // Clear input fields
//        ui->lineEditTitleMagazine->clear();
//        ui->lineEditAuthorMagazine->clear();
//        ui->lineEditIdMagazine->clear();
//        ui->lineEditIssueMagazine->clear();
//    }
//}
//#include "mainwindow.h"
//#include "ui_mainwindow.h"
//#include "libraryitem.h"
//#include "book.h"
//#include "magazine.h"
//#include "LibraryUtils.h"
//#include <QListWidget>

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);

//    utils = new LibraryUtils();

//    // Create sample items
//    LibraryItem* book = new Book("The Great Gatsby", "F. Scott Fitzgerald", "B001", "Fiction");
//    LibraryItem* magazine = new Magazine("National Geographic", "Various", "M001", 123);

//    // Display info in console
//    book->displayInfo();
//    magazine->displayInfo();

//    // Display version in status bar
//    ui->statusBar->showMessage(utils->getVersion());

//    // ✅ Add a QListWidget to the main window dynamically (if not in .ui)
//    QListWidget* listWidget = new QListWidget(this);
//    listWidget->setObjectName("listWidgetItems");

//    QWidget* cw = this->centralWidget();  // Get the central widget
//    if (cw && cw->layout())
//        cw->layout()->addWidget(listWidget);


//    // Add Book to QListWidget
//    Book* b = dynamic_cast<Book*>(book);
//    if (b) {
//        listWidget->addItem(b->getTitle() + " by " + b->getAuthor() + " (Genre: " + b->getGenre() + ")");
//    }

//    // Add Magazine to QListWidget
//    Magazine* m = dynamic_cast<Magazine*>(magazine);
//    if (m) {
//        listWidget->addItem(m->getTitle() + " - Issue " + QString::number(m->getIssueNumber()));
//    }

//    // Clean up sample objects
//    delete book;
//    delete magazine;
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//    delete utils;
//}

