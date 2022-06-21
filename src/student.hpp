#pragma once
#include <string>

enum class Gender
{
    Male,
    Female
};

class Student
{
public:
    Student(std::string name,
            std::string lastName,
            std::string address,
            int indexNumber,
            std::string pesel,
            Gender gender);

    std::string show() const;

private:
    std::string _name;
    std::string _lastName;
    std::string _addres;
    int _indexNumber;
    std::string _pesel;
    Gender _gender;
};