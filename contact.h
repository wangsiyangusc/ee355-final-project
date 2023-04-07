
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
// TODO: You may need to add other libraries here!
using namespace std;


class Contact {
    // TODO: private or protected? Look at your children!	
protected: // as both Email and Phone classes need access to it
	string type;
public:
	virtual void print() = 0;
    virtual string get_contact(string style="full") = 0;
	virtual void set_contact() = 0;
};


class Email: public Contact{
private:
    string email_addr;
public:
    Email(string type, string email_addr);
    // TODO: Complete me!
    void print() override;
    string get_contact(string style="full") override;
    void set_contact() override;  
};


class Phone: public Contact{
private:
    // TODO: modify dataType! Can int store 10 digit phone-number? 
	string phone_num; // changed to string
public:
    Phone(string type, string phone_number);
    // TODO: Complete me!
    void print() override;
    string get_contact(string style="full") override;
    void set_contact() override;
};

#endif