#include<iostream>
#include<ctime>
#include<Windows.h>
using namespace std;

#ifndef DATE_H
#define DATE_H
class date
{
	int Date;
	int Month;
	int Year;
public:
	date();
	~date();
	date(int, int, int);
	void setdate(int);
	int getdate();
	void setmonth(int);
	int getmonth();
	void setyear(int);
	int getyear();
	friend ostream& operator<<(ostream&, date&);


};
#endif