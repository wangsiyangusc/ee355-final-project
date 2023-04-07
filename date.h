#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int day = 0, int month = 0, int year = 0);
    Date(const std::string &date_string);
    void set_date(int day, int month, int year);
    void set_date(const std::string &date_string);
    int get_day() const;
    int get_month() const;
    int get_year() const;
    void print_date();
    void print_date(const std::string &format);
};
#endif