#include "date.h"

Date::Date(int day, int month, int year) {
    set_date(day, month, year);
}

Date::Date(const std::string& date_string) {
    set_date(date_string);
}

void Date::print_date(const string &format)
{
    const char *month_names_cstr[] = {"January", "February", "March", "April", "May", "June",
                                      "July", "August", "September", "October", "November", "December"};
    vector<string> month_names(month_names_cstr, month_names_cstr + sizeof(month_names_cstr) / sizeof(month_names_cstr[0]));

    if (format == "Month D, YYYY") {
        std::cout << month_names[month - 1] << " " << day << ", " << year << std::endl;
    }
}

void Date::print_date()
{
    cout << year << "-" << month << "-" << day << endl;
}

void Date::set_date(const string &date_string)
{
    char delimiter;

    istringstream iss(date_string);
    string token;
    getline(iss, token , '/');
    month = stoi(token);
    getline(iss, token , '/');
    day = stoi(token);
    getline(iss, token , '/');
    year = stoi(token);
}

void Date::set_date(int day, int month, int year)
{
    if (year < 0)
    {
        throw invalid_argument("Year must be positive.");
    }
    if (month < 1 || month > 12)
    {
        throw invalid_argument("Month must be between 1 and 12.");
    }
    if (day < 1 || day > 31)
    {
        throw invalid_argument("Day must be between 1 and 31.");
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::get_day() const
{
    return day;
}

int Date::get_month() const
{
    return month;
}

int Date::get_year() const
{
    return year;
}

