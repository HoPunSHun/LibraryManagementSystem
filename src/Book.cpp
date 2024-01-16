#include "Book.h"

#include <utility>

void Book::AddData(const std::string &dataName, const std::string &data)
{

    m_data[dataName] = data;

}

bool Book::DataExist(const std::string &dataName) const
{

    if (m_data.find(dataName) != m_data.end())
    {

        return true;

    }

    return false;

}

std::string Book::GetData(const std::string &dataName) const
{

    if (DataExist(dataName))
    {
       
        return m_data[dataName];
        
    }

    return "Data not found";

}

std::map<std::string, std::string> &&Book::GetData() const
{

    return std::move(m_data);

}

void Book::RemoveData(const std::string &dataName)
{

    m_data.erase(dataName);

}

void Book::RemoveData()
{

    m_data.clear();

}

Book &Book::operator=(const Book &other)
{

    m_data = other.GetData();

    return *this;

}