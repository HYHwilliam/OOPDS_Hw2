#include <vector>
#include "Book.h"

class Library
{
private:
    vector<Book> books;
    void sortByTitle(vector<Book> &arr);

public:
    void toLower(string &s);
    void toUpper(string &s);
    void addBook();
    int findBookExist(string &title, string &author, int year, string &genre);
    void print(vector<Book> result);
    void searchByTitle();
    void searchByAuthor();
    void searchByGenre();
    void searchByYear();
    void searchBook();
    void checkoutBook();
    void returnBook();
    void listBooks();
    void run();
};
