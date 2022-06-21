#include "database.hpp"

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