#include<iostream>
#include"user.h"
#include<vector>
using namespace std;

#ifndef DRIVER_H
#define DRIVER_H
class driver :public USER
{
	string driving_license_number;
	string vehicle_identification_number;
public:
	driver();
	driver(string, date DOB, string, string, string, string);
	driver(string, date DOB, string, string);
	friend ostream& operator<<(ostream&, driver&);
	void ratePassanger(trip*, float);
	void endARide();
	void pickARide(trip*);

	float getAvgRating();
	float getHighestRating();
	void printTrips();

	string getName();
};
#endif