#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "Book.h"

class LibraryManager
{

public:

    LibraryManager() = default;

private:

    std::map<std::string, Book> m_books;

};
