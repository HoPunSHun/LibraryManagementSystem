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

private:

    std::string m_name;

};
