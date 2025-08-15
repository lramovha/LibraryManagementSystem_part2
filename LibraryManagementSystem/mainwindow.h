#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LibraryUtils.h"  // Needed for utils
#include "libraryitem.h"   // Include for LibraryItem declaration

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonAddBook_clicked();
    void on_pushButtonAddMagazine_clicked();
    void on_pushButtonSearch_clicked();

private:
    Ui::MainWindow *ui;
    LibraryUtils* utils;
    QList<LibraryItem*> items;

};

#endif // MAINWINDOW_H
