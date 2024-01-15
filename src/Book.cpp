#include "Book.h"

Book::Book(const std::string &title, const std::string &author, const std::string &illustrator, const std::string &publisher, int pages)
    :   m_title        (title),
        m_author       (author),
        m_illustrator  (illustrator),
        m_publisher    (publisher),
        m_pages        (pages)
{}

const std::string &Book::GetTitle() const { return m_title; }

const std::string &Book::GetAuthor() const { return m_author; }

const std::string &Book::GetIllustrator() const { return m_illustrator; }

const std::string &Book::GetPublisher() const { return m_publisher; }

int Book::GetPages() const { return m_pages; }

void Book::SetTitle(const std::string &newTitle) { m_title = newTitle; }

void Book::SetAuthor(const std::string &newAuthor) { m_author = newAuthor; }

void Book::SetIllustrator(const std::string &newIllustrator) { m_illustrator = newIllustrator; }

void Book::SetPublisher(const std::string &newPublisher) { m_publisher = newPublisher; }

Book& Book::operator=(const Book &other)
{

    m_title = other.GetTitle();
    m_author = other.GetAuthor();
    m_illustrator = other.GetIllustrator();
    m_publisher = other.GetPublisher();

    m_pages = other.GetPages();

}