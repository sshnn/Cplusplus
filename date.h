#ifndef DATE_H
#define DATE_H
#include <iosfwd>


namespace project
{
	class Date
	{
	public:
		enum class Weekday
		{
			Sunday,
			Monday,
			Tuesday,
			Wednesday,
			Thursday,
			Friday,
			Saturday
		};						   
		Date();					   
		Date(int d, int m, int y); 
		Date &operator=(const Date &other);	  	  
		int get_month_day() const;	  
		int get_month() const;		  
		int get_year() const;		  
		int get_year_day() const;	  
		Weekday get_week_day() const; 
		std::string week_day() const;

		Date &set_month_day(int day);		   
		Date &set_month(int month);			   
		Date &set_year(int year);			   
		Date &set(int day, int mon, int year); 
		Date &setToday();

		Date operator-(int day) const; 
		Date &operator+=(int day);	   
		Date &operator-=(int day);	   
		Date &operator++();			   
		Date operator++(int);		   
		Date &operator--();			   
		Date operator--(int);		   

		friend bool operator<(const Date &dx, const Date &dy);
		friend bool operator==(const Date &dx, const Date &dy);
		friend std::ostream &operator<<(std::ostream &os, const Date &date);
		friend std::istream &operator>>(std::istream &is, Date &date); 
		
		static constexpr bool isleap(int y) 
		{
			return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
		}
	private:
		int md, mm, my;
		std::string get_month_name() const;
		int getLeapYearDay();
	};

	bool operator<=(const Date &dx, const Date &dy); 
	bool operator>(const Date &dx, const Date &dy);	 
	bool operator>=(const Date &dx, const Date &dy); 
	bool operator!=(const Date &dx, const Date &dy); 

	int operator-(const Date &d1, const Date &d2);	 
	Date operator+(const Date &date, int n);		 
	Date operator+(int n, const Date &);			 
	Date::Weekday &operator++(Date::Weekday &r);	 
	Date::Weekday operator++(Date::Weekday &r, int); 
	Date::Weekday &operator--(Date::Weekday &r);	 
	Date::Weekday operator--(Date::Weekday &r, int); 

}
#endif