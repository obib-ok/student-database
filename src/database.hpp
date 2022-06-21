#pragma once
#include <vector>
#include "student.hpp"

class Database
{
public:
    void add(const Student &s);
    void display() const;
    std::string show() const;
    std::string searchLastName(std::string s) const;

private:
    std::vector<Student> _students;
};