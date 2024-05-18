#pragma once

#include <ctime>
#include <string>

using namespace std;

class Person {
private:
    int PersonID;
    string FirstName;
    string SecondName;
    string LastName;

    //time_t birthDate;
public:
    Person(int id, string &firstname, string &secondname, string &lastname) : PersonID(id), FirstName(firstname),
                                                                        SecondName(secondname), LastName(lastname) {}

    [[nodiscard]] int getID() const {
        return PersonID;
    }

    basic_string<char> getFirstName() {
        return FirstName;
    }

    basic_string<char> getSecondName() {
        return SecondName;
    }

    basic_string<char> getLastName() {
        return LastName;
    }

    /*time_t getBirthDate() const{
        return birthDate;
    }*/
};