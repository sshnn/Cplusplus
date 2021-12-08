#include "date.h"
#include <iostream>
#include <ostream>
#include <istream>
#include <ctime>

using namespace project;

int daysToMonth[2][12]{
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
    {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
};

int month[2][12]{
    {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31},
};

Date::Date() : md{1}, mm{1}, my{1900} {} //default ctor

Date::Date(int d, int m, int y) : md{d}, mm{m}, my{y}
{
    if (d > month[isleap(mm) ? 1 : 0][mm - 1] || m > 12)
    {
        std::cout << "gecersiz tarih..."
                  << "\n";
    }
}

Date &Date::operator=(const Date &other)
{
    md = other.md;
    mm = other.mm;
    my = other.my;
    return *this;
}

int Date::get_month_day() const //9
{
    return md;
}

int Date::get_month() const
{
    return mm;
}

int Date::get_year() const //11
{
    return my;
}

int Date::get_year_day() const //12
{
    return daysToMonth[isleap(my) ? 1 : 0][mm - 1] + md;
}

int Date::getLeapYearDay()
{
    if (isleap(my))
        return 365;
    else
        return 366;
}

Date::Weekday Date::get_week_day() const //13
{
    int d = md;
    int y = my;
    Weekday wk = static_cast<Weekday>((d += mm < 3 ? y-- : y - 2, 23 * mm / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7);
    return wk;
}

std::string Date::week_day() const
{
    switch (get_week_day())
    {
    case Weekday::Sunday:
        return "Sunday";
    case Weekday::Monday:
        return "Monday";
    case Weekday::Tuesday:
        return "Tuesday";
    case Weekday::Wednesday:
        return "Wednesday";
    case Weekday::Thursday:
        return "Thursday";
    case Weekday::Friday:
        return "Friday";
    case Weekday::Saturday:
        return "Saturday";
    default:
        throw std::invalid_argument("invalid day");
    }
}

std::string Date::get_month_name() const
{
    std::string month[]{"gg ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return month[get_month()];
}

Date &Date::set_month_day(int day) //14
{
    md = day;
    return *this;
}

Date &Date::set_month(int month) //15
{
    mm = month;
    return *this;
}

Date &Date::set_year(int year)
{
    my = year;
    return *this;
}

Date &Date::set(int day, int mon, int year)
{
    md = day;
    mm = mon;
    my = year;
    return *this;
}

Date &Date::setToday()
{
    time_t timer;
    time(&timer);
    struct tm *tptr = localtime(&timer);
    return set(tptr->tm_mday, tptr->tm_mon + 1, tptr->tm_year + 1900);
}

Date Date::operator-(int day) const //18
{
    int d = md;
    int m = mm;
    int y = my;

    if (md > day)
    {
        d -= day;
    }
    else
    {
        int temp = get_year_day();
        while (temp <= day) // yılın günü > çıkartılan gun olana kadar
        {
            --y;
            temp += isleap(y) ? 366 : 365;
        }

        int totalday = temp - day;
        for (m = 12; daysToMonth[isleap(y) ? 1 : 0][m - 1] >= temp - day && m > 0; --m)
        {
        }

        totalday -= daysToMonth[isleap(y) ? 1 : 0][m - 1];
        d = totalday;
    }
    return Date(d, m, y);
}

Date &Date::operator+=(int day) //19
{
    int dayNo = get_year_day();
    md += day;
    if (md > getLeapYearDay() - dayNo) // yılın gun sayisi - yılın gunu
    {
        md = md - (getLeapYearDay() - dayNo);
        ++my;
    }

    while (md > getLeapYearDay())
    {
        ++my;
        md -= getLeapYearDay();
    }

    int month = mm;
    for (month = 12; daysToMonth[isleap(my) ? 1 : 0][month - 1] >= md; --month)
    {
    }
    md -= daysToMonth[isleap(my) ? 1 : 0][month - 1];
    set_month(month);

    return *this;
}

Date &Date::operator-=(int day) //20
{
    if (md > day)
    {
        md -= day;
    }
    else
    {
        int temp = get_year_day();
        while (temp <= day) // yılın günü > çıkartılan gun olana kadar
        {
            --my;
            temp += isleap(my) ? 366 : 365;
        }

        md = temp - day;
        for (mm = 12; daysToMonth[isleap(my) ? 1 : 0][mm - 1] >= temp - day; --mm)
        {
        }

        md -= daysToMonth[isleap(my) ? 1 : 0][mm - 1];
    }
    return *this;
}

Date &Date::operator++() //21
{
    return operator+=(1);
}

Date Date::operator++(int)
{
    Date temp{*this};
    operator+=(1);
    return temp;
}

Date &Date::operator--()
{
    return operator-=(1);
}

Date Date::operator--(int)
{
    Date temp{*this};
    operator-=(1);
    return temp;
}

bool project::operator<=(const Date &dx, const Date &dy) //27
{
    if (operator<(dx, dy) || operator==(dx, dy))
        return 1;
    return 0;
}

bool project::operator>(const Date &dx, const Date &dy) //27
{
    return !operator<=(dx, dy);
}

bool project::operator>=(const Date &dx, const Date &dy) //27
{
    return !operator<(dx, dy);
}

bool project::operator!=(const Date &dx, const Date &dy) //27
{
    return !operator==(dx, dy);
}

int project::operator-(const Date &dx, const Date &dy)
{
    int year = dy.get_year();
    if (dx.get_year() == dy.get_year())
        return dx.get_year_day() - dy.get_year_day();
    else
    {
        int dif = dx.get_year() - dy.get_year();
        return abs((dx.get_year_day() - dy.get_year_day()) + dif * (Date::isleap(year) ? 365 : 366));
    }
}

Date project::operator+(const Date &date, int n)
{
    Date dx{date};
    return dx += n;
}

Date project::operator+(int n, const Date &date)
{
    return operator+(date, n);
}

Date::Weekday &project::operator++(Date::Weekday &wd) //30
{
    return wd = wd == Date::Weekday::Saturday ? Date::Weekday::Sunday : static_cast<Date::Weekday>(static_cast<int>(wd) + 1);
}

Date::Weekday project::operator++(Date::Weekday &wd, int) //30
{
    Date::Weekday temp{wd};
    operator++(wd);
    return temp;
}
Date::Weekday &project::operator--(Date::Weekday &wd) //30
{
    return wd = wd == Date::Weekday::Sunday ? Date::Weekday::Saturday : static_cast<Date::Weekday>(static_cast<int>(wd) - 1);
}

Date::Weekday project::operator--(Date::Weekday &wd, int)
{
    Date::Weekday temp{wd};
    operator--(wd);
    return temp;
}

namespace project
{
    std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        return os << date.get_month_day() << " " << date.get_month_name() << " " << date.my;
    }

    std::istream &operator>>(std::istream &is, Date &date) //32
    {
        int d, m, y;
        is >> d >> m >> y;
        date = Date{d, m, y};
        return is;
    }

    bool operator<(const Date &dx, const Date &dy) //27
    {
        if (dx.my < dy.my)
            return dx.my < dy.my;
        else if (dx.my == dy.my && dx.mm != dy.mm)
            return dx.mm < dy.mm;
        else if (dx.mm == dy.mm)
            return dx.md < dy.md;
        return 0;
    }

    bool operator==(const Date &dx, const project::Date &dy) //27
    {
        if (dx.my == dy.my && dx.mm == dy.mm && dx.md == dy.md)
            return 1;
        return 0;
    }

}