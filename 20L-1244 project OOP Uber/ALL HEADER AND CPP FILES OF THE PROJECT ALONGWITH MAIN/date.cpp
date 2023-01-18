#include "date.h"

date::date()
{
	srand(time(0));
	SYSTEMTIME q;
	GetSystemTime(&q);
    Date = q.wDay;
	Month = q.wMonth;
	Year = q.wYear;

}
//////////////////////////////////////////

date::date(int Date, int Month, int Year):Date(Date),Month(Month),Year(Year)
{
}
//////////////////////////////////////////

void date::setdate(int Date)
{
	if(Date>0&&Date<=31)
	this->Date = Date;
}
///////////////////////////////////////////

int date::getdate()
{
	return Date;
}
//////////////////////////////////////////////

void date::setmonth(int Month)
{
	if(Month>0&&Month<=12)
	this->Month = Month;
}
///////////////////////////////////////////////
int date::getmonth()
{
	return Month;
}
/////////////////////////////////////////////////

void date::setyear(int Year)
{
	if(Year>0)
	this->Year = Year;
}
///////////////////////////////////////////////////

int date::getyear()
{
	return Year;
}
///////////////////////////////////////////////////

ostream& operator<<(ostream& o, date& d)
{
	o << d.Date << "\\" << d.Month << "\\" << d.Year;
	return o;
}
//////////////////////////////////////////////////

date::~date()
{

}
/////////////////////////////////////////////////////
