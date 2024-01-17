#include "BookDir.h"

#include <filesystem>
#include <fstream>
#include <sstream>

BookDir::BookDir(const std::string &dirName, const std::string &fatherDir, const std::string &dataStop)
    :   m_name      (dirName),
        m_fatherDir (fatherDir),
        m_dataStop  (dataStop)
{

    ReadDirData();

}

void BookDir::ReadDirData()
{

    namespace fs = std::filesystem;

    std::string currentPath = fs::current_path().string() + '/' + m_fatherDir + '/' + m_name;

    for (const auto &file : fs::directory_iterator(currentPath))
    {

        const fs::path& filePath = file.path();

        if (fs::is_directory(filePath))
        {

            std::string dirName = filePath.string().erase(0, currentPath.length());

            m_childDir[dirName] = BookDir(dirName, m_fatherDir + '/' + m_name, m_dataStop);

        }
        else
        {

            ReadBookInfo(filePath.string());

        }

    }

}

void BookDir::ReadBookInfo(const std::string &filePath)
{

    std::fstream file(filePath);

    if (file.is_open())
    {

        std::string line;

        while (std::getline(file, line))
        {

            std::string dataName;
            std::map<std::string, std::string> data;

            std::istringstream ss;
            std::getline(file, line);
            ss.str(line);

            std::string bookTitle = ReadTillDataStop(ss);
            data["Title"] = bookTitle;

            while (ss >> dataName)
            {

                std::string value = ReadTillDataStop(ss);

                data[dataName] = value;

            }

            m_books[bookTitle] = data;

        }

    }

    file.close();

}

std::string BookDir::ReadTillDataStop(std::istringstream &ss)
{

    std::string data;
    std::string tmp;

    while (ss >> tmp)
    {

        if (tmp == "|") { break; }

        data += ' ' + tmp;

    }

    return data;

}

void BookDir::AddBookToDir(const std::string &bookTitle)
{

    m_books[bookTitle] = Book();
    m_books[bookTitle].AddData("Title", bookTitle);

}