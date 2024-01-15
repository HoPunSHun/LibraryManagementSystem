#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "Book.h"

class LibraryManager
{

public:

    LibraryManager() = default;

    LibraryManager(const std::string &libraryName);

    void AddBook(const std::string &bookTitle, const std::string &bookAuthor, int bookPages);
    void AddBook(const std::string &bookTitle, const std::string &bookAuthor, int bookPages, const std::string &bookIllustrator, const std::string &bookPublisher);

    [[nodiscard]] const Book& GetBook(const std::string &bookTitle);

    void RemoveBook(const std::string &bookTitle);

private:

    std::string m_name;

    std::map<std::string, Book> m_books;

};
