OOPDS_Hw2
📚 Library Management System
This is a C++ console-based Library Management System that allows users to add, search, list, checkout, and return books. It provides basic management functionalities for a small-scale library and is operated via a command-line interface.

✅ Features
Add new books with title, author, genre, year, and available copies.

Prevent duplicate entries by checking if the book already exists.

Search books by Title, Author, Genre, or Published Year.

Checkout and return books with availability tracking.

Case-insensitive searches and sorted output.

Friendly, interactive menu interface.

🛠 How to Use
1. Compile and Run the Program
Use a C++ compiler such as g++:

bash
複製
編輯
g++ main.cpp Library.cpp Book.cpp -o library
./library
2. Menu Options
Once the program starts, you'll see:

markdown
複製
編輯
Library Menu:
1. Add Book
2. Search Book
3. Checkout Book
4. Return Book
5. List All Books
6. Exit
Enter your choice (1-6):
Enter a number 1 to 6 to perform the corresponding operation.

📥 Input Format
1. Add Book
You will be prompted to enter the following:

yaml
複製
編輯
Title: <book title>
Author: <author name>
Genre: <genre>
Published Year: <4-digit year, e.g., 2023>
Available Copies: <positive integer>
If the book already exists (same title, author, genre, and year), you’ll be asked:

pgsql
複製
編輯
Would you like to update the number of available copies? (Y/N):
2. Search Book
You will be prompted to select a search method:

markdown
複製
編輯
Search Book by:
1. Book Title
2. Author
3. Genre
4. Year
5. Finish and Exit
Enter your choice:
Then input your search keyword (e.g., harry potter).
The system will list exact matches and similar matches.

3. Checkout Book
css
複製
編輯
Enter book title to checkout: <title>
If the book exists and copies are available, checkout is successful and copies will be decreased by 1. Otherwise, an error message is displayed.

4. Return Book
kotlin
複製
編輯
Enter book title to return: <title>
Returns the book and increases the copy count. Only accepted if the book was checked out before.

5. List All Books
Displays all books in a nicely formatted table, sorted by title. Example:

markdown
複製
編輯
No.  Title                          Author              Genre               Year  Copies
------------------------------------------------------------------------------------------
1    THE HOBBIT                     J.R.R. TOLKIEN      Fantasy             1937  5
2    TO KILL A MOCKINGBIRD          HARPER LEE          Fiction             1960  2
📂 Project Structure
kotlin
複製
編輯
.
├── Book.h        # Book class declaration
├── Book.cpp      # Book class implementation
├── Library.h     # Library class declaration
├── Library.cpp   # Library class implementation
├── main.cpp      # Entry point with menu loop
📌 Requirements
C++11 or newer

Standard C++ libraries: iostream, string, vector, iomanip, etc.

No external dependencies

