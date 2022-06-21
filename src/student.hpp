#pragma once
#include <string>

enum class Credentials
{
    name,
    lastName,
    address,
    indexNumber,
    pesel,
    gender
};

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
    std::string getter(Credentials w) const;

private:
    std::string _name;
    std::string _lastName;
    std::string _addres;
    int _indexNumber;
    std::string _pesel;
    Gender _gender;
};