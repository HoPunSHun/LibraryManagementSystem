#pragma once

#include <string>
#include <map>

#include "book.h"

class BookDir
{

public:

    BookDir() = default;

    explicit BookDir(const std::string &dirName, const std::string &fatherDir);

private:

    void ReadDirData();

    void ReadBookInfo(const std::string &filePath);

    void AddBookToDir(const std::string &bookTitle);

private:

    std::string m_name;
    std::string m_fatherDir;

    std::map<std::string, BookDir> m_childDir;

    std::map<std::string, Book> m_books;

};