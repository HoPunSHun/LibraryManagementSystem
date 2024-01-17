#pragma once

#include <string>
#include <map>

#include "book.h"

class BookDir
{

public:

    BookDir() = default;

    explicit BookDir(const std::string &dirName, const std::string &fatherDir, const std::string &dataStop);

private:

    void ReadDirData();

    void ReadBookInfo(const std::string &filePath);

    static std::string ReadTillDataStop(std::istringstream &ss);

    void AddBookToDir(const std::string &bookTitle);

private:

    std::string m_name;
    std::string m_fatherDir;

    std::string m_dataStop;

    std::map<std::string, BookDir> m_childDir;

    std::map<std::string, Book> m_books;

};