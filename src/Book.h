#pragma once

#include <string>
#include <map>

class Book
{

public:

   Book() = default;

   void AddData(const std::string &dataName, const std::string &data);

   bool DataExist(const std::string &dataName) const;

   std::string GetData(const std::string &dataName) const;
   std::map<std::string, std::string> &&GetData() const;

   void RemoveData(const std::string &dataName);
   void RemoveData();

   Book &operator=(const Book &other);

private:

    mutable std::map<std::string, std::string> m_data;

};