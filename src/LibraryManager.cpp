#include "LibraryManager.h"

LibraryManager::LibraryManager(const std::string &libraryName)
    :   m_name  (libraryName)
{}

void LibraryManager::AddBook(const std::string &bookTitle, const std::string &bookAuthor, int bookPages)
{

    m_books[bookTitle] = Book(bookTitle, bookAuthor, bookPages);

}

void LibraryManager::AddBook(const std::string &bookTitle, const std::string &bookAuthor, int bookPages,
                             const std::string &bookIllustrator, const std::string &bookPublisher)
{

    m_books[bookTitle] = Book(bookTitle, bookAuthor, bookPages, bookIllustrator, bookPublisher);

}

const Book &LibraryManager::GetBook(const std::string &bookTitle)
{

    return m_books[bookTitle];

}

void LibraryManager::RemoveBook(const std::string &bookTitle)
{

    m_books.erase(bookTitle);

}