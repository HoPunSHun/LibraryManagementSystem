#pragma once

#include <string>
#include <sstream>

std::string ReadTill(std::istringstream &ss, const std::string &stopper)
{

    std::string result;

    std::string input;

    while (ss >> input)
    {

        if (input == stopper) { result.pop_back(); break; }

        result += input + ' ';

    }

    return result;

}