# Assignment Description:

You are required to develop a Windows based Library Management System using C++ and
Qt. The system should allow users to perform operations such as adding books, searching for
books, borrowing books, and returning books, with the use of Qt Lists, Qt Libraries, generics,
and standard containers to enhance functionality.
Requirements:

## 1. Class Design (OOP Concepts)
  - Create a base class LibraryItem that contains attributes like title, author, and id.
  - Create derived classes Book and Magazine that inherit from LibraryItem and add relevant attributes (e.g., genre for Book, issueNumber for Magazine).
  - Implement encapsulation by making member variables private and using getter and setter methods.
  - Implement polymorphism by creating a virtual function displayInfo() in the base class and overriding it in derived classes.

## 2. Use of Qt Lists and Containers
  -  Store the list of books and magazines using QList<LibraryItem*>.
  - Implement sorting and filtering operations using std::vector or QList.
  - Display book/magazine details in a QListWidget.
  - Implement searching and filtering using QListView and QSortFilterProxyModel.

## 3. Use of Custom Qt Library 
  - Create a separate Qt library (LibraryUtils) for utility functions such as data persistence, sorting, and searching.
  - Use this library in your main application to handle book operations.

## 4. Implementation of Generics (Templates)
  - Create a generic template class Storage<T> to store and manage LibraryItem objects.
  - Implement member functions for adding, removing, and searching within the storage.
  - Demonstrate the use of this class for managing books and magazines.

## 5. Graphical User Interface using Qt Widgets
  - Design a main window using Qt Widgets (QMainWindow, QWidget, QVBoxLayout, etc.).
  - Include input fields to add books and magazines.
  - Provide buttons to search, borrow, and return books.
  o Display a list of available books/magazines using QListWidget or QTableWidget.

## 6. File Handling for Data Persistence
  - Store book and magazine data in a file (e.g., library_data.txt).
  - Load the data when the application starts.
  - Save new entries when a book or magazine is added.

# Application Preview
<img width="1692" height="892" alt="Screenshot 2025-11-30 110958" src="https://github.com/user-attachments/assets/e3b23fa7-1025-43b2-8d0e-5b8575b6ad03" />


