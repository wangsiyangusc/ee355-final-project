#include "person.h"
#include "date.h"
#include "misc.h"
Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete email;
    delete phone;
}


Person::Person(string f_name, string l_name, string b_date, string email_type, string email_addr, string phone_type, string phone_num){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this->f_name = f_name;
    this->l_name = l_name;
    this->birthdate = new Date(b_date);
    this->email = new Email(email_type, email_addr);
    this->phone = new Phone(phone_type, phone_num);
}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!

    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    std::getline(std::cin,type);
    cout << "Email address: ";
    // code here
    std::getline(std::cin,temp);
    email = new Email(type, temp);

    cout << "Type of phone number: ";
    std::getline(std::cin,type);
    // code here
    cout << "Phone number: ";
    std::getline(std::cin,temp);
    phone = new Phone(type, temp);
    // code here
    // code here
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    // Note: You should use fstream library to read from a file
    // Note: You should use getline to read a line from a file
    // Note: You should use string::find to find a substring in a string
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    std::getline(std::cin,type);
    cout << "Email address: ";
    // code here
    std::getline(std::cin,temp);
    email = new Email(type, temp);

    cout << "Type of phone number: ";
    std::getline(std::cin,type);
    // code here
    cout << "Phone number: ";
    std::getline(std::cin,temp);
    phone = new Phone(type, temp);
    // code here
    // code here
}

bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    if (f_name == rhs.f_name && l_name == rhs.l_name && birthdate == rhs.birthdate){
        return true;
    }
    else{
        return false;
    }
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    if (f_name == rhs.f_name && l_name == rhs.l_name && birthdate == rhs.birthdate){
        return false;
    }
    else{
        return true;
    }
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
    string fname;
    string lname;
    string f_id;
    if (!(this->myfriends.empty())){
        int friend_num = this->myfriends.size();
        for (int i=0; i<friend_num; i++){
            //cout << "friends are : \n";
            fname = this->myfriends[i]->f_name;
            //cout << fname << "; ";
            lname = this->myfriends[i]->l_name;
            //cout << lname << "\n";
            f_id = codeName(fname, lname);
            cout << f_id << "\n";
        }
    }
    /*for (int i=0; i<(this->myfriends.size()); i++){
        fname = this->myfriends[i]->f_name;
        lname = this->myfriends[i]->l_name;
        f_id = codeName(f_name, l_name);
        cout << f_id << "\n";
    }*/
}

void Person::makeFriend(Person* newFriend){
    myfriends.push_back(newFriend);
}