/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEditTitleBook;
    QLineEdit *lineEditAuthorBook;
    QLineEdit *lineEditIdBook;
    QLineEdit *lineEditGenreBook;
    QLabel *label_2;
    QLineEdit *lineEditTitleMagazine;
    QLineEdit *lineEditAuthorMagazine;
    QLineEdit *lineEditIdMagazine;
    QLineEdit *lineEditIssueMagazine;
    QListWidget *listWidgetItems;
    QPushButton *pushButtonAddBook;
    QPushButton *pushButtonAddMagazine;
    QPushButton *pushButtonSearch;
    QPushButton *pushButtonBorrowReturn;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(949, 557);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEditTitleBook = new QLineEdit(centralWidget);
        lineEditTitleBook->setObjectName(QStringLiteral("lineEditTitleBook"));

        verticalLayout->addWidget(lineEditTitleBook);

        lineEditAuthorBook = new QLineEdit(centralWidget);
        lineEditAuthorBook->setObjectName(QStringLiteral("lineEditAuthorBook"));

        verticalLayout->addWidget(lineEditAuthorBook);

        lineEditIdBook = new QLineEdit(centralWidget);
        lineEditIdBook->setObjectName(QStringLiteral("lineEditIdBook"));

        verticalLayout->addWidget(lineEditIdBook);

        lineEditGenreBook = new QLineEdit(centralWidget);
        lineEditGenreBook->setObjectName(QStringLiteral("lineEditGenreBook"));

        verticalLayout->addWidget(lineEditGenreBook);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEditTitleMagazine = new QLineEdit(centralWidget);
        lineEditTitleMagazine->setObjectName(QStringLiteral("lineEditTitleMagazine"));

        verticalLayout->addWidget(lineEditTitleMagazine);

        lineEditAuthorMagazine = new QLineEdit(centralWidget);
        lineEditAuthorMagazine->setObjectName(QStringLiteral("lineEditAuthorMagazine"));

        verticalLayout->addWidget(lineEditAuthorMagazine);

        lineEditIdMagazine = new QLineEdit(centralWidget);
        lineEditIdMagazine->setObjectName(QStringLiteral("lineEditIdMagazine"));

        verticalLayout->addWidget(lineEditIdMagazine);

        lineEditIssueMagazine = new QLineEdit(centralWidget);
        lineEditIssueMagazine->setObjectName(QStringLiteral("lineEditIssueMagazine"));

        verticalLayout->addWidget(lineEditIssueMagazine);

        listWidgetItems = new QListWidget(centralWidget);
        listWidgetItems->setObjectName(QStringLiteral("listWidgetItems"));

        verticalLayout->addWidget(listWidgetItems);

        pushButtonAddBook = new QPushButton(centralWidget);
        pushButtonAddBook->setObjectName(QStringLiteral("pushButtonAddBook"));

        verticalLayout->addWidget(pushButtonAddBook);

        pushButtonAddMagazine = new QPushButton(centralWidget);
        pushButtonAddMagazine->setObjectName(QStringLiteral("pushButtonAddMagazine"));

        verticalLayout->addWidget(pushButtonAddMagazine);

        pushButtonSearch = new QPushButton(centralWidget);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        verticalLayout->addWidget(pushButtonSearch);

        pushButtonBorrowReturn = new QPushButton(centralWidget);
        pushButtonBorrowReturn->setObjectName(QStringLiteral("pushButtonBorrowReturn"));

        verticalLayout->addWidget(pushButtonBorrowReturn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 949, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Add Book by: Title, Author, Book ID and Genre", 0));
        label_2->setText(QApplication::translate("MainWindow", "Add Magazine by: Title, Author, Magazine ID and Issue Number", 0));
        pushButtonAddBook->setText(QApplication::translate("MainWindow", "Add Book", 0));
        pushButtonAddMagazine->setText(QApplication::translate("MainWindow", "Add Magazine", 0));
        pushButtonSearch->setText(QApplication::translate("MainWindow", "Search", 0));
        pushButtonBorrowReturn->setText(QApplication::translate("MainWindow", "Borrow/Return", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
