/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

#ifndef DATE_H
#define DATE_H

#include <locale>
#include <iostream>
#include <iterator>

class Date
{
	std::tm time;	

	template <class charT, class Traits>			
	friend std::basic_istream<charT, Traits>& operator >> (std::basic_istream<charT, Traits>&, Date&);
	template <class charT, class Traits>
	friend std::basic_ostream<charT, Traits>& operator << (std::basic_ostream<charT, Traits>&, const Date &);

public:
	// Inicializálás az aktuális helyi dátummal
	Date()
	{
		memset(&time,0, sizeof(std::tm));
		time_t now = std::time(NULL);
		time = *localtime(&now);
	}

	
	Date(const std::tm & time):time(time){};	
	Date(time_t t)
	{
		time=*localtime(&t);
	}

	int GetElapsedDays ()const 
	{
		time_t currentTime;
		std::time(&currentTime);

		time_t dt = mktime(const_cast<tm*>(&time));

		double timeDiffInSec = difftime(currentTime, dt);
		return (int)(timeDiffInSec/(3600*24));
	}
};

template <class charT, class Traits>
std::basic_istream<charT, Traits>& operator >> (std::basic_istream<charT, Traits>& is, Date & t)
{

	std::basic_istream<charT, Traits>::sentry sntr(is);
	if(!sntr) return is;

	std::ios_base::iostate state = std::ios_base::iostate();
	std::tm temp;
	memset(&temp,0, sizeof(std::tm));
	temp.tm_isdst = -1;

	std::use_facet<std::time_get<charT, std::istreambuf_iterator<charT,Traits> > >
		(is.getloc()).get_date(is, std::istreambuf_iterator<charT,Traits>(), is, state, &temp);
	
	if(state & std::ios::failbit)
	{
		is.setstate(std::ios::failbit);
	}
	else
	{
		t.time=temp;
	}
		
	is.width(0);
	return is;
}


template <class charT, class Traits>
std::basic_ostream<charT, Traits>& operator << (std::basic_ostream<charT, Traits>& os, const Date & t)
{
	std::basic_ostream<charT, Traits>::sentry sntr(os);
	if(!sntr) return os;

	char *pattern = "%Y/%m/%d";

	std::use_facet<std::time_put<charT, std::ostreambuf_iterator<charT,Traits> > >
		(os.getloc()).put(os,os,os.fill(),&t.time,pattern, pattern + strlen(pattern));

	os.width(0);
	return os;	
}

#endif /* DATE_H */
