# Library Management System (C++ / Qt)

A Windows desktop application for managing a small library's catalog — built with C++ and Qt Widgets. The system supports adding, searching, borrowing, and returning books and magazines, and demonstrates core OOP design, Qt's model/view framework, generic programming, and a custom Qt library.

## Application Preview

![Application Preview](https://github.com/user-attachments/assets/e3b23fa7-1025-43b2-8d0e-5b8575b6ad03)

## Overview

This project implements a library catalog system where items are represented through a small class hierarchy and managed through a Qt-based GUI, with persistence to a local data file. It was built to demonstrate object-oriented design, Qt's list/view widgets, a custom utility library, and generic (template-based) storage, alongside a working file-backed data layer.

## Features

### Class design (OOP)
A base `LibraryItem` class holds shared attributes — title, author, and ID — with member variables kept private and accessed through getters and setters. `Book` and `Magazine` derive from `LibraryItem`, adding their own attributes (genre and issue number respectively) and overriding a virtual `displayInfo()` method to demonstrate polymorphism.

### Qt lists and containers
Library items are stored as `QList<LibraryItem*>`, with sorting and filtering implemented using `std::vector` and `QList`. Item details are displayed using `QListWidget`, and search/filtering is implemented with `QListView` paired with `QSortFilterProxyModel`.

### Custom Qt library — LibraryUtils
A separate Qt library, **LibraryUtils**, handles utility logic such as data persistence, sorting, and searching, independently of the UI layer. The main application links against this library to perform book and magazine operations.

### Generics (templates)
A generic `Storage<T>` template class manages collections of `LibraryItem` objects, with member functions for adding, removing, and searching. The same `Storage<T>` is used to manage both books and magazines.

### Graphical user interface
The main window is built with Qt Widgets (`QMainWindow`, `QWidget`, `QVBoxLayout`, etc.), with input fields for adding books and magazines, buttons for searching, borrowing, and returning items, and a `QListWidget`/`QTableWidget` view of all available items.

### File-based persistence
Book and magazine data is stored in a local file (e.g. `library_data.txt`). Existing data loads automatically on startup, and new entries are saved as they're added.

## Project Structure

```
LibraryManagementSystem_part2/
├── LibraryManagementSystem/   # Main Qt Widgets application
├── LibraryUtils/              # Custom Qt library (persistence, sorting, searching)
└── README.md
```

## Tech Stack

- **Language:** C++
- **Framework:** Qt Widgets
- **Build system:** qmake
- **Platform:** Windows

## Getting Started

### Prerequisites

- Qt (with Qt Widgets module) — Qt Creator is recommended
- A C++ compiler compatible with your Qt installation (e.g. MinGW or MSVC on Windows)

### Setup

1. Clone the repository
   ```bash
   git clone https://github.com/lramovha/LibraryManagementSystem_part2.git
   ```
2. Open the project in Qt Creator by loading the `.pro` file inside `LibraryManagementSystem/`.
3. Ensure the `LibraryUtils` library is built first (or configured as a dependency/subproject) so the main application can link against it.
4. Build and run the project from Qt Creator, or build via the command line with `qmake` and `make`/`mingw32-make`.

## Author

**[lramovha](https://github.com/lramovha)**

