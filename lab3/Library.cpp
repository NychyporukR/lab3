#include "Library.h"
#include <iostream>
#include <stdexcept>

LIBRARY::LIBRARY(std::string _book_title, std::string _author, int _publication_year, std::string _publisher, int _book_quantity)
    : book_title(_book_title), author(_author), publisher(_publisher) {
    if (_publication_year < 0) {
        throw std::invalid_argument("Invalid publication year.");
    }
    if (_book_quantity < 0) {
        throw std::invalid_argument("Invalid book quantity.");
    }
    publication_year = _publication_year;
    book_quantity = _book_quantity;
}

void LIBRARY::display_information() const {
    std::cout << "Book Title: " << book_title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Publication Year: " << publication_year << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Book Quantity: " << book_quantity << std::endl;
}

void LIBRARY::operator+(int quantity) {
    if (quantity < 0) {
        throw std::invalid_argument("Quantity for addition must be non-negative.");
    }
    book_quantity += quantity;
}

void LIBRARY::operator-(int quantity) {
    if (quantity < 0 || quantity > book_quantity) {
        throw std::invalid_argument("Invalid quantity for subtraction.");
    }
    book_quantity -= quantity;
}

bool LIBRARY::search_book(const std::string& criterion, const std::string& value) const {
    if (criterion == "title" && book_title == value) {
        return true;
    }
    else if (criterion == "author" && author == value) {
        return true;
    }
    else if (criterion == "year" && std::to_string(publication_year) == value) {
        return true;
    }
    else if (criterion == "publisher" && publisher == value) {
        return true;
    }
    return false;
}
