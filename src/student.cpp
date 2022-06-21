#include "student.hpp"

Student::Student(std::string name,
                 std::string lastName,
                 std::string address,
                 int indexNumber,
                 std::string pesel,
                 Gender gender) : _name(name),
                                  _lastName(lastName), _addres(address), _indexNumber(indexNumber), _pesel(pesel), _gender(gender)
{
}

std::string Student::show() const
{
    return _name + " " + _lastName + "; " + _addres + "; " + std::to_string(_indexNumber) + "; " + _pesel + "; " + "Male";
}

std::string Student::getter(Credentials w) const
{
    switch (w)
    {
    case Credentials::name:
        return _name;
    case Credentials::lastName:
        return _lastName;
    case Credentials::address:
        return _addres;
    case Credentials::indexNumber:
        return std::to_string(_indexNumber);
    case Credentials::pesel:
        return _pesel;
    case Credentials::gender:
        return "Male";
    }
}