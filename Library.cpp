#include <iostream>
#include <cctype>
#include <iomanip>
#include "Library.h"

using namespace std;

void Library::toLower(string &s)
{
    for (char &c : s)
    {
        c = tolower(c);
    }
}

void Library::toUpper(string &s)
{
    bool key = true;
    for (char &c : s)
    {
        if (isalpha(c))
        {
            if (key)
            {
                c = toupper(c);
                key = false;
            }
        }
        else
        {
            key = true;
        }
    }
}

void Library::sortByTitle(vector<Book> &vec)
{
    for (auto i = 0; i < vec.size(); i++)
    {
        for (auto j = 0; j + 1 < vec.size(); j++)
        {
            toLower(vec[j].title);
            toLower(vec[j + 1].title);
            if (vec[j].title > vec[j + 1].title)
            {
                Book temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int Library::findBookExist(string &title, string &author, int year, string &genre)
{
    string ltitle = title;
    string lauthor = author;
    string lgenre = genre;
    toLower(ltitle);
    toLower(lauthor);
    toLower(lgenre);

    for (int i = 0; i < books.size(); ++i)
    {
        string btitle = books[i].title;
        string bauthor = books[i].author;
        string bgenre = books[i].genre;
        toLower(btitle);
        toLower(bauthor);
        toLower(bgenre);

        if (btitle == ltitle && bauthor == lauthor && books[i].year == year && books[i].genre == lgenre)
        {
            return i;
        }
    }
    return -1;
}

void Library::print(vector<Book> result)
{
    // cout << "Exact matches: " << endl;
    sortByTitle(result);
    cout << "\n============================================ Book List ============================================\n";
    cout << left << setw(5) << "No.";
    cout << setw(30) << "Title";
    cout << setw(20) << "Author";
    cout << setw(20) << "Genre";
    cout << setw(6) << "Year";
    cout << setw(8) << "Copies" << endl;
    cout << "----------------------------------------------------------------------------------------------------\n";

    int index = 1;
    for (const auto &b : result)
    {
        string utitle = b.title;
        toUpper(utitle);
        string uauthor = b.author;
        toUpper(uauthor);

        cout << left << setw(5) << index++;
        cout << left << setw(30) << utitle;
        cout << left << setw(20) << uauthor;
        cout << left << setw(20) << b.genre;
        cout << left << setw(6) << b.year;
        cout << left << setw(8) << b.copies << endl;
    }
    cout << "====================================================================================================\n";
}

void Library::addBook()
{
    string title, author, genre;
    string tyear, tcopies;
    int year, copies;

    cout << "Title: ";
    cin.ignore();
    getline(cin, title);

    cout << "Author: ";
    getline(cin, author);

    cout << "Genre: ";
    getline(cin, genre);

    while (true)
    {
        cout << "Published Year: ";
        cin >> tyear;
        try
        {
            if (tyear.length() != 4)
            {
                throw invalid_argument("Invalid year format. Please enter only 4-digit.");
            }
            year = stoi(tyear);
            break;
        }
        catch (const exception &e)
        {
            cout << "Invalid year. Please enter a 4-digit number." << endl;
        }
    }
    while (true)
    {
        cout << "Available Copies: ";
        cin >> tcopies;

        try
        {
            copies = stoi(tcopies);
            break;
        }
        catch (const exception &e)
        {
            cout << "Invalid number of copies. Please enter an integer." << endl;
        }
    }

    int key = findBookExist(title, author, year, genre);

    if (key != -1)
    {
        cout << "The book has same title, author, published year and genre is already exists in the system.\n";
        cout << "Would you like to update the number of available copies? (Y/N): ";
        string cmd;
        cin >> cmd;
        if (cmd == "Y" || cmd == "y")
        {
            books[key].copies += copies;
            cout << "Copies updated successfully. Total copies: " << books[key].copies << endl;
        }
        else
        {
            cout << "Book addition canceled." << endl;
        }
        return;
    }
    else
    {
        books.push_back(Book(title, author, genre, year, copies));
        cout << "Book added successfully." << endl;
    }
}

void Library::searchByTitle()
{
    string title;
    cout << "Enter the title: ";
    cin.ignore();
    getline(cin, title);
    toLower(title);

    vector<Book> result_part;
    vector<Book> result_exact;
    for (Book &b : books)
    {
        string ltitle = b.title;
        toLower(ltitle);

        if (ltitle == title)
        {
            result_exact.push_back(b);
        }
        else if (ltitle.find(title) != string::npos)
        {
            result_part.push_back(b);
        }
    }

    if (result_exact.empty() && result_part.empty())
    {
        cout << "No book has that title." << endl;
        return;
    }

    if (!result_exact.empty())
    {
        cout << "Exact matches: " << endl;
        print(result_exact);
    }

    if (!result_part.empty())
    {
        cout << "Similar title found: " << endl;
        print(result_part);
    }
}

void Library::searchByAuthor()
{
    string author;
    cout << "Enter the author of the book: ";
    cin.ignore();
    getline(cin, author);
    toLower(author);

    vector<Book> result_part;
    vector<Book> result_exact;
    for (Book &b : books)
    {
        string lauthor = b.author;
        toLower(lauthor);

        if (lauthor == author)
        {
            result_exact.push_back(b);
        }
        else if (lauthor.find(author) != string::npos)
        {
            result_part.push_back(b);
        }
    }

    if (result_exact.empty() && result_part.empty())
    {
        cout << "No book was written by the author." << endl;
        return;
    }

    if (!result_exact.empty())
    {
        cout << "Exact matches: " << endl;
        print(result_exact);
    }

    if (!result_part.empty())
    {
        cout << "Similar title found: " << endl;
        print(result_part);
    }
}

void Library::searchByGenre()
{
    string genre;
    cout << "Enter the genre: ";
    cin.ignore();
    getline(cin, genre);
    toLower(genre);

    vector<Book> result_part;
    vector<Book> result_exact;
    for (Book &b : books)
    {
        string lgenre = b.genre;
        toLower(lgenre);

        if (lgenre == genre)
        {
            result_exact.push_back(b);
        }
        else if (lgenre.find(genre) != string::npos)
        {
            result_part.push_back(b);
        }
    }

    if (result_exact.empty() && result_part.empty())
    {
        cout << "No book matches that genre." << endl;
        return;
    }

    if (!result_exact.empty())
    {
        cout << "Exact matches: " << endl;
        print(result_exact);
    }

    if (!result_part.empty())
    {
        cout << "Similar title found: " << endl;
        print(result_part);
    }
}

void Library::searchByYear()
{
    string tyear;
    int year;
    cout << "Enter published year: ";

    while (true)
    {
        cin >> tyear;
        try
        {
            if (tyear.length() != 4)
            {
                throw invalid_argument("Invalid year format. Please enter only 4-digit.");
            }
            year = stoi(tyear);
            break;
        }
        catch (const exception &e)
        {
            cout << "Invalid year. Please enter a 4-digit number." << endl;
        }
    }

    vector<Book> result;
    for (Book &b : books)
    {
        if (b.year == year)
        {
            result.push_back(b);
        }
    }

    if (result.empty())
    {
        cout << "No book were published in that year." << endl;
        return;
    }

    if (!result.empty())
    {
        cout << "Exact matches: " << endl;
        print(result);
    }
}

void Library::searchBook()
{
    string choice;
    while (true)
    {
        cout << "\nSearch Book by:\n";
        cout << "1. Book Title\n";
        cout << "2. Author\n";
        cout << "3. Genre\n";
        cout << "4. Year\n";
        cout << "5. Finish and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice.length() != 1)
        {
            cout << "Invalid input. Please enter a single character." << endl;
            continue;
        }

        switch (choice[0])
        {
        case '1':
            searchByTitle();
            break;
        case '2':
            searchByAuthor();
            break;
        case '3':
            searchByGenre();
            break;
        case '4':
            searchByYear();
            break;
        case '5':
            cout << "Finish Searching, now exit..." << endl;
            return;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

void Library::checkoutBook()
{
    string title;
    cout << "Enter book title to checkout: ";
    cin.ignore();
    getline(cin, title);

    toLower(title);

    for (Book &b : books)
    {
        string ltitle = b.title;
        toLower(ltitle);

        if (ltitle == title)
        {
            if (b.copies > 0)
            {
                b.copies--;
                cout << "Book checked out successfully." << endl;
                cout << "Now Available: " << b.copies << endl;
                b.counter++;
            }
            else
            {
                cout << "Book is not available now." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Library::returnBook()
{
    string title;
    cout << "Enter book title to return: ";
    cin.ignore();
    getline(cin, title);

    toLower(title);

    for (Book &b : books)
    {
        string ltitle = b.title;
        toLower(ltitle);

        if (ltitle == title)
        {
            if (b.counter != 0)
            {
                b.copies++;
                cout << "Book returned successfully." << endl;
                cout << "Now Availanle: " << b.copies << endl;
                b.counter--;
            }
            else
            {
                cout << "This book is not lended, so it's impossible to return." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
    return;
}

void Library::listBooks()
{
    if (books.empty())
    {
        cout << "No books in the library." << endl;
        return;
    }

    vector<Book> allbooks = books;
    print(allbooks);
}

void Library::run()
{
    string choice;
    while (true)
    {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. List All Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (choice.length() != 1)
        {
            cout << "Invalid input. Please enter a single character." << endl;
            continue;
        }

        switch (choice[0])
        {
        case '1':
            addBook();
            break;
        case '2':
            searchBook();
            break;
        case '3':
            checkoutBook();
            break;
        case '4':
            returnBook();
            break;
        case '5':
            listBooks();
            break;
        case '6':
            cout << "Exiting..." << endl;
            return;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}
