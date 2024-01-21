#include "BookDir.h"

#include <filesystem>
#include <fstream>
#include <sstream>

#include "Tools.h"

BookDir::BookDir(const std::string &dirName, const std::string &path, const std::string &dataStop)
    :   m_name      (dirName),
        m_path      (path),
        m_dataStop  (dataStop)
{

    ReadDirData();

}

void BookDir::ReadDirData()
{

    namespace fs = std::filesystem;

    for (const auto &file : fs::directory_iterator(m_path))
    {

        const fs::path& filePath = file.path();

        if (fs::is_directory(filePath))
        {

            std::string dirName = filePath.string().erase(0, m_path.length() + 1);

            m_childDir[dirName] = BookDir(dirName, filePath.string(), m_dataStop);

        }
        else
        {

            ReadBookInfo(filePath.string());

        }

    }

}

void BookDir::ReadBookInfo(const std::string &filePath)
{

    std::fstream file;
    file.open(filePath, std::ios::in);

    if (file.is_open())
    {

        std::string line;

        while (std::getline(file, line))
        {

            std::string dataName;
            std::map<std::string, std::string> data;

            std::istringstream ss;
            ss.str(line);

            std::string bookTitle = ReadTill(ss, m_dataStop);
            data["Title"] = bookTitle;

            while (ss >> dataName)
            {

                std::string value = ReadTill(ss, m_dataStop);

                data[dataName] = value;

            }

            m_books[bookTitle] = data;

        }

    }

    file.close();

}

void BookDir::AddBookToDir(const std::string &bookTitle)
{

    m_books[bookTitle] = Book();
    m_books[bookTitle].AddData("Title", bookTitle);

}