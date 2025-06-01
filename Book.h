#include <string>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string genre;
    int year;
    int copies;
    int counter = 0;

    Book(string t, string a, string g, int y, int c);
};
