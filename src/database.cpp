#include "database.hpp"
#include <iostream>

void Database::add(const Student &s)
{
    _students.push_back(s);
}

void Database::display() const
{
    std::cout << show();
}

std::string Database::show() const
{
    std::string result = "";
    for (auto &&student : _students)
        result += student.show();

    return result;
}

std::string Database::searchLastName(std::string s) const
{
    for (auto &&student : _students)
    {
        if (student.getter(Credentials::lastName) == s)
            return student.show();
        else
            return "";
    }
}

std::string Database::searchPesel(std::string s) const
{
    for (auto &&student : _students)
    {
        if (student.getter(Credentials::pesel) == s)
            return student.show();
        else
            return "";
    }
}