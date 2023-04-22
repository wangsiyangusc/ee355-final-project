#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"


class Person{
    friend class Network;

private:
	string f_name;
	string l_name;
	Date *birthdate;
    Email *email;
    Phone *phone;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;
    vector<Person*> myfriends;

public: 
    Person();
    ~Person();
    Person(string filename);
    Person(string f_name, string l_name, string b_date, string email_type, string email_addr, string phone_type, string phone_num);
	void print_person();
	void set_person();
	void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
    void makeFriend(Person* new_friend);
};


#endif