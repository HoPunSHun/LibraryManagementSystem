#include "BookDir.h"

#include <filesystem>

BookDir::BookDir(const std::string &dirName, const std::string &fatherDir)
    :   m_name      (dirName),
        m_fatherDir (fatherDir)
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

            m_childDir[dirName] = BookDir(dirName, m_fatherDir + '/' + m_name);

        }
        else
        {

            ReadBookInfo(filePath.string());

        }

    }

}

void BookDir::ReadBookInfo(const std::string &filePath)
{


}

void BookDir::AddBookToDir(const std::string &bookTitle)
{

    m_books[bookTitle] = Book();
    m_books[bookTitle].AddData("Title", bookTitle);

}