#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <stdexcept>

class LIBRARY {
private:
    std::string book_title;
    std::string author;
    int publication_year;
    std::string publisher;
    int book_quantity;

public:
    LIBRARY(std::string _book_title, std::string _author, int _publication_year, std::string _publisher, int _book_quantity);

    void display_information() const;

    void operator+(int quantity);

    void operator-(int quantity);

    bool search_book(const std::string& criterion, const std::string& value) const;
};

#endif


