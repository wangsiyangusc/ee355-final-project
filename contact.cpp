#include "contact.h"
#include <iostream>
#include <string>
// TODO: Add needed libraries! 
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

// 
Email::Email(string type, string email_addr){
    // TODO: Complete me!
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
    cout << "Enter the type of email address: ";
    // some code here
    cin >> type;
    cout << "Enter email address: ";
    // some code here
    cin >> email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    // Remove hyphens from the phone number
    /*num.erase(remove(num.begin(), num.end(), '-'), num.end());*/
    
    string num_no_hyphen;
    string new_phone;
    for (size_t i = 0; i < num.length(); ++i) {
        if (num[i] != '-') {
            num_no_hyphen += num[i];
        }
    }
    
    // Convert the phone number to an integer
    num_no_hyphen.insert(3, "-");
    num_no_hyphen.insert(7, "-");
    cout << "Phone number: " << num_no_hyphen << endl;

    
    this->type = type;
    this->phone_num = num_no_hyphen;
   
    
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    cin >> type;
	cout << "Enter the phone number: ";
    cin >> phone_num;
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    if (style=="full")
        return "(" + type + ") " + phone_num;
    else 
        return phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}
