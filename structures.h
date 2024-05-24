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

public:
    ~Person() = default;

    Person() = default;

    Person(int id, string &firstname, string &secondname, string &lastname) : PersonID(id), FirstName(firstname),
                                                                              SecondName(secondname),
                                                                              LastName(lastname) {}

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

    bool operator==(const Person &person) const {
        return PersonID == person.PersonID;
    }

    bool operator!=(const Person &person) const {
        return this->getID() != person.PersonID;
    }

    bool operator<(const Person &person) const {
        if (this->getID() >= person.PersonID) {
            return false;
        }
        return true;
    }

    bool operator>(const Person &person) const {
        if (this->getID() <= person.PersonID) {
            return false;
        }
        return true;
    }

    bool operator>=(const Person &person) const {
        if (this->getID() < person.PersonID) {
            return false;
        }
        return true;
    }

    bool operator<=(const Person &person) const {
        if (this->getID() > person.PersonID) {
            return false;
        }
        return true;
    }

    int operator++(int) {
        return PersonID++;
    }

    int operator++() {
        return ++PersonID;
    }

    friend std::istream &operator>>(std::istream &istream, Person &person) {
        cout << "\nPerson ID: ";
        istream >> person.PersonID;
        cout << "\nFirst name: ";
        istream >> person.FirstName;
        cout << "\nSecond name: ";
        istream >> person.SecondName;
        cout << "\nLast name: ";
        istream >> person.LastName;
        return istream;
    }

    friend std::ostream &operator<<(std::ostream &ostream, const Person person) {
        ostream << "Person ID is: " << person.PersonID << ", First name is:: " << person.FirstName << ", Second name is: "
                << person.SecondName << ", Last name: " << person.LastName << ";\n";
        return ostream;
    }
};