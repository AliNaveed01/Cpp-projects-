
#include<iostream>
#include"date.h"
#include"payment.h"
#include"trip.h"
#include<vector>

using namespace std;
#ifndef USER_H
#define USER_H
class USER
{
	string name;
	string email;
	string phone_number;
	date DOB;
	
protected:
	vector< trip* > tripsHistory;
	trip* currenttrip;
	int count = 0;
public:
	USER();
	USER(string, date&, string, string);
	void print();

	void changeName(string newName);
	void changeDOB(date newDate);
	void changePhone_number(string newPhone);

	virtual float getAverageRating() {
		return 0;
	}

	virtual void printTrips() {
	}

	virtual float getHighestRating() {
		return 0;
	}

	string getName();

	void display();

};
#endif