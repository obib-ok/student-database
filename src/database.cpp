#include "database.hpp"
#include <iostream>

bool Database::add(const Student &s)
{
    if (_isAdded)
    {
        return false;
    }
    else
    {
        _isAdded = true;
        return true;
    }
}

void Database::display() const
{
    std::cout << show();
}

std::string Database::show() const
{
    return "";
}