#pragma once

#include <string>
#include <map>

#include "book.h"

class BookDir
{

public:

    BookDir() = default;

private:

    std::map<std::string, BookDir> m_childDir;

    std::map<std::string, Book> m_books;

};