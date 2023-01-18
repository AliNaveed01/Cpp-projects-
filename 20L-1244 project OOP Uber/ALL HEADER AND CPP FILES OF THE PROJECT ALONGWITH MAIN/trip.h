#include<iostream>
#include"date.h"

using namespace std;

// forward declaration
class passenger;
class driver;

#ifndef TRIP_H
#define TRIP_H
class trip
{
	string status;
	date* dat;
	driver* Driver;
	passenger* Passanger;
	string pickup_location;
	string dropoff_location;
	float driver_rating;
	float passanger_rating;
public:
	void change_status(string);
	void rateDriver(float);
	void ratePassanger(float);
	void set_driver(driver*);
	void set_passenger(passenger*);
	void set_pickup_location(string);
	void set_dropoff_location(string);
	friend ostream& operator<<(ostream& out, const trip&);
	string getstat();

	friend class passenger;
	friend class driver;
};
#endif