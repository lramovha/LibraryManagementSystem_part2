#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>     // Base class for the main application window
#include "LibraryUtils.h"  //Utility class for library operations (add/search/borrow items)
#include "libraryitem.h"   // Declaration of LibraryItem, the base class for Book and Magazine

namespace Ui {
class MainWindow;
}

// MainWindow handles the GUI and connects user actions to library operations
class MainWindow : public QMainWindow
{
    Q_OBJECT    // Enables Qt's signals and slots mechanism

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonAddBook_clicked();        // Triggered when "Add Book" button is clicked
    void on_pushButtonAddMagazine_clicked();
    void on_pushButtonSearch_clicked();
    void on_pushButtonBorrowReturn_clicked();

private:
    Ui::MainWindow *ui;         // Pointer to UI elements created in Qt Designer
    LibraryUtils* utils;        // Handles backend library operations
    QList<LibraryItem*> items;  // Stores all library items (books and magazines)
};

#endif // MAINWINDOW_H
