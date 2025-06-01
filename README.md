# OOPDS_Hw2
# Library Management System

This is a **C++ console-based Library Management System** that allows users to add, search, list, checkout, and return books. It provides basic management functionalities for a small-scale library and is operated via a command-line interface.

## Features

- Add new books with title, author, genre, year, and available copies.
- Prevent duplicate entries by checking if the book already exists.
- Search books by **Title**, **Author**, **Genre**, or **Published Year**.
- Checkout and return books with availability tracking.
- Case-insensitive searches and sorted output.
- Friendly, interactive menu interface.

---

## How to Use

### 1. **Compile the Program**

Use a C++ compiler such as `g++`:

```bash
g++ main.cpp Library.cpp Book.cpp -o library
./library

### 2. The menu
Library Menu:
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. List All Books
6. Exit
Enter your choice (1-6):

