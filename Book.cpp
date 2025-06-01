#include <cctype>
#include "Book.h"

Book::Book(string t, string a, string g, int y, int c)
{
    title = t;
    author = a;
    genre = g;
    year = y;
    copies = c;
}
