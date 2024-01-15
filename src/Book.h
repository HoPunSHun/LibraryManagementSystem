#pragma once
#include <iostream>

class Book
{

public:

   Book() = default;

   Book(const std::string &title, const std::string &author, int pages);
   Book(const std::string &title, const std::string &author, int pages, const std::string &illustrator, const std::string &publisher);

   [[nodiscard]] const std::string &GetTitle() const;

   [[nodiscard]] const std::string &GetAuthor() const;

   [[nodiscard]] const std::string &GetIllustrator() const ;

   [[nodiscard]] const std::string &GetPublisher() const;

   [[nodiscard]] int GetPages() const;

   void SetTitle(const std::string &newTitle);

   void SetAuthor(const std::string &newAuthor);

   void SetIllustrator(const std::string &newIllustrator);

   void SetPublisher(const std::string &newPublisher);

   Book& operator=(const Book &other);

private:

    std::string m_title;
    std::string m_author;
    std::string m_illustrator;
    std::string m_publisher;

    int m_pages;

};