#include "network.h"
#include <limits>
#include "misc.h"
#include <dirent.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "network.h"

using namespace std;

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}

Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network(){ 
    Person* personPtr = head;
    Person* nextPtr = NULL;
    while(personPtr != NULL){
        nextPtr = personPtr->next;
        delete personPtr;
        personPtr = nextPtr;
    }
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* tempPerson = head;
    Person* searchResult = NULL;
    while (tempPerson != NULL){
        if (searchEntry == tempPerson){
            searchResult = tempPerson;
            break;
        }
        tempPerson = tempPerson->next;
    }
    return searchResult;
}

Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person* tempPerson = head;
    Person* searchResult = NULL;
    string pfname;
    string plname;
    while (tempPerson != NULL){
        pfname = tempPerson->f_name;
        plname = tempPerson->l_name;
        if ((pfname == fname) && (plname == lname)){
            searchResult = tempPerson;
            break;
        }
        tempPerson = tempPerson->next;
    }
    return searchResult;
}

void Network::loadDB(string file_name){
    // TODO: Complete this method
    std::ifstream file_in(file_name.c_str());
    string line;
    while(getline(file_in, line)){
        // first line is first name
        string first_name = line; 

        // second line last name
        string last_name;
        getline(file_in, last_name);

        // third line dob
        string dob;
        getline(file_in, dob); 

        // forth line email (type and addr)
        getline(file_in, line);  
        int email_idx = line.find(" ");
        string email_type;
        string email_addr;
        email_type = line.substr(1, email_idx-1);  // get <type> string without parenthesis
        email_addr = line.substr(email_idx + 1);  // get email after the whitespace

        // fifth line phone number
        getline(file_in, line);  
        string phone_type;
        string phone_num;
        int phone_idx = line.find(" ");
        phone_type = line.substr(1, phone_idx-1);
        phone_num = line.substr(phone_idx + 1);

        getline(file_in, line); // get rid of the dash

        // create a new Person object with obtained attribute values and add it to the network
        Person* newPerson;
        newPerson = new Person(first_name, last_name, dob, email_type, email_addr, phone_type, phone_num);
        push_back(newPerson); // add new person to the end of network
        newPerson->print_person();
    }
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    Person* personPtr = head;
    int cnt = 0;
    std::ofstream outfile(filename.c_str());
    cout << count << "\n";
    while(cnt < count){
        outfile << personPtr->f_name << "\n";
        outfile << personPtr->l_name << "\n";
        outfile << personPtr->birthdate->get_month() << "/" << personPtr->birthdate->get_day() << "/" << personPtr->birthdate->get_year() << "\n";
        outfile << personPtr->email->get_contact() << "\n";
        outfile << personPtr->phone->get_contact() << "\n";
        outfile << "--------------------\n";
        personPtr = personPtr->next;
        cout << "connection: " << cnt << " saved!" << "\n";
        cnt++;
    }
}

void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}

void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}

void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    newEntry->next = NULL;
    newEntry->prev = tail;

    if (tail != NULL) 
        tail->next = newEntry;
    else 
        head = newEntry;
    tail = newEntry;
    count++;
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
    // need search name first
    Person* delPerson;
    bool removed = false;
    while((delPerson=search(fname, lname)) != NULL){
        delPerson->prev->next = delPerson->next;  // link next of prev node to the next node
        delPerson->next->prev = delPerson->prev;  // link prev of next node to the prev node
        removed = true;
    }
    return removed;
}

void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new connection \n";
        cout << "4. Remove a connection \n";
        cout << "5. Search \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        int findFile = 0;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            
            ///*
            DIR* dir = opendir(".");
            if (!dir) {
                std::cerr << "Could not open current directory" << std::endl;
            }
            
            // Loop through all files in the directory
            struct dirent* entry;
            while ((entry = readdir(dir))) {
                // Check if the file name matches the format "networkDB.txt"
                std::string fileName(entry->d_name);
                if (fileName.size() == 13 && fileName.substr(0, 10) == "networkDB." && fileName.substr(10, 3) == "txt") {
                    // Print the file name
                    findFile = 1;
                    std::cout << fileName << std::endl;
                }
            }
            // Close the directory
            closedir(dir);
            //*/

            // Take a look into sample_files.cpp 
            cout << "Enter the name of the load file: "; 
            cin >> fileName;
            loadDB(fileName);
            // If file with name FILENAME does not exist: 
            if (findFile == 0) cout << "File FILENAME does not exist!" << endl;
            // If file is loaded successfully, also print the count of connections in it: 
            cout << "Network loaded from " << fileName << " with " << count << " connections \n";
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Connection ONLY if it does not exists!
            cout << "Adding a new connection \n";
            Person* newPerson;
            newPerson = new Person();  //parenthesis?
            push_front(newPerson);
        }
        else if (opt == 4){
            // TODO: Complete me!
            cout << "Removing a connection \n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            // if found, cout << "Remove Successful! \n";
            if (remove(fname, lname)) cout << "Remove Successful! \n";
            // if not found: cout << "Connection not found! \n";
            else cout << "Connection not found! \n";
        }
        else if (opt==5){
            // TODO: Complete me!
            cout << "Searching: \n";
            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";
            cin >> lname;
            // if found: print connection
            Person* searchRes = search(fname, lname);
            if (searchRes != NULL) {
                cout << "found" << "\n";
                searchRes->print_person();
            }
            else {
                cout << "Not found! \n";
            }
            // if not, cout << "Not found! \n";
        }
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
