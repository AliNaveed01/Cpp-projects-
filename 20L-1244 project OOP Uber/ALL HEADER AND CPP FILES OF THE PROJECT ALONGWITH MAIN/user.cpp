#include"USER.h"

USER::USER() :name(""), DOB(0, 0, 0), email(""), phone_number(""), currenttrip(NULL)
{

}

//////////////////////////////////////////////////////////////////////
USER::USER(string name, date& DOB, string email, string phone_number)
{
	this->name = name;
	this->email = email;
	this->phone_number = phone_number;
	this->DOB = DOB;
}
//////////////////////////////////////////////////////////////////////

void USER::print()
{
	cout << " name: " << name << endl;
	cout << " DOB: " << DOB << endl;
	cout << "E-mail: " << email << endl;
	cout << "PHONE #: " << phone_number << endl;
	cout << "Total Trips: " << count << endl;
}
//////////////////////////////////////////////////////////////////////

void USER::changeName(string new_name)
{
	this->name = new_name;
}

//////////////////////////////////////////////////////////////////////
void  USER::changeDOB(date new_date)
{
	this->DOB = new_date;
}


///////////////////////////////////////////////////////////////////////
void  USER::changePhone_number(string new_phone)
{
	this->phone_number = new_phone;
}

///////////////////////////////////////////////////////////////////////
string USER::getName()
{
	return name;
}

void USER::display()
{
}
