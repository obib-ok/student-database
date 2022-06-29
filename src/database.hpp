#pragma once
#include <vector>
#include <algorithm>
#include "student.hpp"

class Database
{
public:
    void add(const Student &s);
    void display() const;
    std::string show() const;
    std::string searchLastName(std::string s) const;
    std::string searchPesel(std::string s) const;
    void sortByPesel();

private:
    std::vector<Student> _students;
};