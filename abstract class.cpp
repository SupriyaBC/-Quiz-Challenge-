#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void getName() {
        cout << "Enter the name: ";
        cin >> name;
    }

    void putName() {
        cout << "Name is: " << name << endl;
    }

    virtual void getData() = 0;
    virtual bool isOutstanding() = 0;
};

class Student : public Person {
protected:
    float gpa;
public:
    void getData() {
        Person::getName();
        cout << "Enter GPA: ";
        cin >> gpa;
    }

    bool isOutstanding() {
        return (gpa > 3.5);
    }
};

class Professor : public Person {
protected:
    int publications;
public:
    void getData() {
        Person::getName();
        cout << "Enter number of publications: ";
        cin >> publications;
    }

    bool isOutstanding() {
        return (publications > 25);
    }
};

int main() {
    Student s;
    Professor p;
    Person* ptrPerson;

    // Work with Student
    ptrPerson = &s;
    ptrPerson->getData();
    if (ptrPerson->isOutstanding()) {
        cout << "Student is outstanding" << endl;
    } else {
        cout << "Student is not outstanding" << endl;
    }

    // Work with Professor
    ptrPerson = &p;
    ptrPerson->getData();
    if (ptrPerson->isOutstanding()) {
        cout << "Professor is outstanding" << endl;
    } else {
        cout << "Professor is not outstanding" << endl;
    }

    // Dynamic allocation for array of Persons
    Person* personArray[2];
    personArray[0] = new Student();
    personArray[1] = new Professor();

    for (int i = 0; i < 2; i++) {
        personArray[i]->getData();
        if (personArray[i]->isOutstanding()) {
            cout << "Is outstanding" << endl;
        } else {
            cout << "Is not outstanding" << endl;
        }
    }

    // Cleanup dynamic memory
    for (int i = 0; i < 2; i++) {
        delete personArray[i];
    }

    return 0;
}
