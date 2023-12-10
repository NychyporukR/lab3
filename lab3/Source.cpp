#include <iostream>
#include <string>
#include <stdexcept>
#include "Library.h"

using namespace std;


int main() {
    try {
        LIBRARY book("The Great Gatsby", "F. Scott Fitzgerald", 1925, "Publisher2", 75);

        book.display_information();

        book + 25;  
        book.display_information();

        book - 10;  
        book.display_information();

        if (book.search_book("author", "F. Scott Fitzgerald")) {
            cout << "Book found!" << endl;
        }
        else {
            cout << "Book not found!" << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}