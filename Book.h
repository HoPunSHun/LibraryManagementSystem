#pragma once
#include <iostream>

class Book
{

public:

   Book() = default;

   Book(std::string &&title, std::string &&author, std::string &&illustrator, std::string &&publisher, int pages);

private:

    std::string m_title;
    std::string m_author;
    std::string m_illustrator;
    std::string m_publisher;

    int m_pages;

};