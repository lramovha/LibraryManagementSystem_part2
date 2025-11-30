#Assignment Description:

You are required to develop a Windows based Library Management System using C++ and
Qt. The system should allow users to perform operations such as adding books, searching for
books, borrowing books, and returning books, with the use of Qt Lists, Qt Libraries, generics,
and standard containers to enhance functionality.
Requirements:

1. Class Design (OOP Concepts)
  o Create a base class LibraryItem that contains attributes like title, author, and id.
  o Create derived classes Book and Magazine that inherit from LibraryItem and add relevant attributes (e.g., genre for Book, issueNumber for Magazine).
  o Implement encapsulation by making member variables private and using getter and setter methods.
  o Implement polymorphism by creating a virtual function displayInfo() in the base class and overriding it in derived classes.

3. Use of Qt Lists and Containers
  o Store the list of books and magazines using QList<LibraryItem*>.
  o Implement sorting and filtering operations using std::vector or QList.
  o Display book/magazine details in a QListWidget.
  o Implement searching and filtering using QListView and QSortFilterProxyModel.

4. Use of Custom Qt Library 
  o Create a separate Qt library (LibraryUtils) for utility functions such as data persistence, sorting, and searching.
  o Use this library in your main application to handle book operations.

6. Implementation of Generics (Templates)
  o Create a generic template class Storage<T> to store and manage LibraryItem objects.
  o Implement member functions for adding, removing, and searching within the storage.
  o Demonstrate the use of this class for managing books and magazines.

8. Graphical User Interface using Qt Widgets
  o Design a main window using Qt Widgets (QMainWindow, QWidget, QVBoxLayout, etc.).
  o Include input fields to add books and magazines.
  o Provide buttons to search, borrow, and return books.
  o Display a list of available books/magazines using QListWidget or QTableWidget.

10. File Handling for Data Persistence
  o Store book and magazine data in a file (e.g., library_data.txt).
  o Load the data when the application starts.
  o Save new entries when a book or magazine is added.
