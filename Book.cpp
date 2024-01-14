#include "Book.h"

Book::Book(std::string &&title, std::string &&author, std::string &&illustrator, std::string &&publisher, int pages)
    :   m_title        (title),
        m_author       (author),
        m_illustrator  (illustrator),
        m_publisher    (publisher),
        m_pages        (pages)
{}