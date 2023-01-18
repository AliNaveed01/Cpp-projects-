#include"user.h"
#include"payment.h"
#include <vector>
using namespace std;

#ifndef PASSENGER_H
#define PASSENGER_H
class passenger :public USER
{
	vector<payment> pay;
	payment p;
public:
	passenger();
	passenger(string, date, string, string, payment);
	passenger(string, date, string, string);
	friend ostream& operator<<(ostream&, passenger&);
	trip* bookRide(string, string);
	void rateDriver(trip*, float);
	void cancelRide();
	float getAvgRating();
	float getHighestRating();

	void printTrips();
	string getName();
	
};
#endif