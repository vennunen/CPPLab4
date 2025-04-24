#include <iostream>
#include <string>
using namespace std;

// Book Class
class Book
{
private:
    string title;
    int pages;

public:
    // Constructor
    Book(string t = "Untitled", int p = 0) : title(t), pages(p)
    {
        cout << "Book Constructor: \"" << title << "\" with " << pages << " pages\n";
    }

    // Destructor
    ~Book()
    {
        cout << "Book Destructor: \"" << title << "\" destroyed\n";
    }

    // Method to display book info
    void display() const
    {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
};

// Bookshelf Class
class Bookshelf
{
private:
    Book *books;
    int size;

public:
    // Constructor: dynamically create array and initialize it
    Bookshelf()
    {
        size = 3;
        books = new Book[size]{
            Book("C++ Fundamentals", 300),
            Book("Data Structures", 450),
            Book("Algorithms", 500)};
        cout << "Bookshelf Constructor: Shelf initialized with " << size << " books\n";
    }

    // Destructor: clean up heap memory
    ~Bookshelf()
    {
        delete[] books;
        cout << "Bookshelf Destructor: Shelf destroyed\n";
    }

    // Method to display all books
    void displayBooks() const
    {
        cout << "\nBooks on shelf:\n";
        for (int i = 0; i < size; ++i)
        {
            books[i].display();
        }
    }
};

// Main Function
int main()
{
    // Example 1: Static array of objects
    cout << "\n--- Example 1: Static Array of Books ---\n";
    Book library[3] = {
        Book("C++ Fundamentals", 300),
        Book("Data Structures", 450),
        Book("Algorithms", 500)};

    cout << "\n--- Library Contents ---\n";
    for (int i = 0; i < 3; ++i)
    {
        library[i].display();
    }
    cout << "\n--- End of Static Library ---\n";

    // Example 2: Dynamic memory using BookShelf
    cout << "\n--- Example 2: Dynamic Bookshelf ---\n";
    Bookshelf *shelf = new Bookshelf(); // created on heap
    shelf->displayBooks();
    delete shelf; // cleanup

    cout << "\n--- End of Program ---\n";
    return 0;
}
