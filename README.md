# OOPDS_Hw2  
## Library Management System

This is a **C++ console-based Library Management System** that allows users to add, search, list, checkout, and return books. It provides basic management functionalities for a small-scale library and is operated via a command-line interface.

---

## Features

- Add new books with title, author, genre, year, and available copies.
- Prevent duplicate entries by checking if the book already exists.
- Search books by **Title**, **Author**, **Genre**, or **Published Year**.
- Checkout and return books with availability tracking.
- Case-insensitive searches and sorted output.
- Friendly, interactive menu interface.

---

## How to Use

### 1. Compile and Run the Program
This project is written in C++ and requires a C++ compiler that supports C++11 or later. A commonly used compiler is **g++**, which is part of the GNU Compiler Collection (GCC).

To compile the source files (`main.cpp`, `Library.cpp`, and `Book.cpp`), open your terminal or command prompt and run the following command:
```bash
g++ main.cpp Library.cpp Book.cpp -o library
./library
```
### 2. Library Menu
Once the program starts, users can interact with the following menu:
```plaintext
Library Menu:
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. List All Books
6. Exit
Enter your choice (1-6):
```
Users should enter a valid numeric option (1-6) to proceed.

## Input Formats
### 1. Add a Book
Users will be prompted to enter book details:

```plaintext
Title: <book title>
Author: <author name>
Genre: <genre>
Published Year: <4-digit year, e.g., 2023>
Available Copies: <positive integer>
```
If a book with the same title, author, genre, and year exists, the system will ask:

```plaintext
Would you like to update the number of available copies? (Y/N):
```
### 2. Search a Book
Users can search books by **title**, **author**, **genre**, or **year** using the Search Book option. The search supports **partial and case-insensitive matches** — you don't need to type the exact full name to find results.  

When selecting Search Book, users interact with this menu:
```plaintext
Search Book by:
1. Book Title
2. Author
3. Genre
4. Year
5. Finish and Exit
Enter your choice (1-5): 
```
Users enter a number (1-5) to choose how they want to search. After finishing, the system returns to the main menu.

Example of search by title:
```plaintext
Enter the title: Potter
Exact matches:
--------------------------------------------------
Title  : Harry Potter
Author : J.K. Rowling
Genre  : Magic
Year   : 2001
Copies : 2
--------------------------------------------------
Similar title found:
--------------------------------------------------
Title  : The Potter's Craft
Author : Charles Freeman
Genre  : Art
Year   : 1920
Copies : 1
--------------------------------------------------
```

### 3. Checkout a Book
Users can borrow a book by entering its title.

```plaintext
Enter book title to checkout: Harry Potter
Book checked out successfully.
Now Available: 1
```
If no copies are available:
```plaintext
Book is not available now.
```
### 4. Return a Book
Users can return a borrowed book by entering its title.
```plaintext
Enter book title to return: Harry Potter
Book returned successfully.
Now Available: 2
```
If the book was never checked out:
```plaintext
This book is not lended, so it's impossible to return.
```
### 5. List All Books
Displays all books in the library sorted alphabetically:

```plaintext
============================================ Book List ============================================
No.   Title                          Author              Genre             Year   Copies
----------------------------------------------------------------------------------------------------
1     Harry Potter                   J.K. Rowling        Magic             2001   2
2     Les Miserables                 Victor Hugo         Tragedy           1862   1
3     The Old Man and the Sea        Hemingway           Novel             1952   10
====================================================================================================
```
## Error Handling

### 1. Input Length and Format Validation
User inputs must follow the correct format, such as a 4-digit year.
```plaintext
Enter published year: 23
Invalid input. Please enter a 4-digit year (e.g., 2023).
```
### 2. Case-Insensitive Searching
Search ignores uppercase/lowercase differences for convenience.
```plaintext
Enter the title: HARRY POTTER
Exact matches:
--------------------------------------------------
Title  : Harry Potter
Author : J.K. Rowling
Genre  : Magic
Year   : 2001
Copies : 2
--------------------------------------------------
```

### 3. Handling Unavailable Books During Checkout
Prevent borrowing when no copies are available.
```plaintext
Enter book title to checkout: The Great Gatsby
Book is not available now.
```
### 4. Duplicate Book Detection and Updating Copies
If the same book already exists, the system will ask if you want to update the number of available copies instead of adding a duplicate.
```plaintext
This book already exists.
Would you like to update the number of available copies? (Y/N):
```

## Project Structure
```plaintxt
.
├── Book.h        # Book class declaration
├── Book.cpp      # Book class implementation
├── Library.h     # Library class declaration
├── Library.cpp   # Library class implementation
├── main.cpp      # Entry point with menu loop
```
## Requirements
C++11 or newer

Standard C++ libraries: iostream, string, vector, iomanip, etc.

No external dependencies

