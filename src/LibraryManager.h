#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "Book.h"
#include "BookDir.h"

class LibraryManager
{

public:

    LibraryManager() = default;

    void Init();

private:

    void ReadConfig();

    void InitBookDir();

private:

    std::string m_name;

    std::string m_initialBookDirPath;
    std::string m_initialBookDirName;

    BookDir m_initialBookDir;

    std::string m_dataStop;

};
