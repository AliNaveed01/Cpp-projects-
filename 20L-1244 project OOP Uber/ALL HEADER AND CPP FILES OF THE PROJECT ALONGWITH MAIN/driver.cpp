#include "driver.h"


driver::driver() :USER(), vehicle_identification_number(""), driving_license_number("")
{

}

///////////////////////////////////////////////////////////////////////////////////////

driver::driver(string name, date DOB, string email, string phone_number, string driving_license_number, string vehicle_identification_number) : USER(name, DOB, email, phone_number)
{
	this->driving_license_number = driving_license_number;
	this->vehicle_identification_number = vehicle_identification_number;
}

///////////////////////////////////////////////////////////////////////////////////////

driver::driver(string name, date DOB, string email, string phone_number) : USER(name, DOB, email, phone_number)
{

}
//////////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& obj, driver& d)
{
	d.USER::print();

	if(d.driving_license_number != "")
		obj << d.driving_license_number << endl;
	if(d.vehicle_identification_number != "")
		obj << d.vehicle_identification_number << endl;
	if (d.currenttrip == nullptr)
		obj << "Currently not riding\n";
	else
		obj << d.currenttrip->getstat() << endl;
	return obj;
}

/////////////////////////////////////////////////////////////////////////////////////////

void driver::ratePassanger(trip* t, float rating)
{
	if(rating>0&&rating<=5 && (t->status == "Complete") )
		t->ratePassanger(rating);
	else
	{
		cout << "Error Cannot rate driver. Trip is not complete." << endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

void driver::endARide()
{
	currenttrip->change_status("Complete");
	tripsHistory.push_back(currenttrip);
	//t->change_status("Completed...!");
}

///////////////////////////////////////////////////////////////////////////////////////////

void driver::pickARide(trip* PAR)
{
	
	string stat = PAR->getstat();
	if (stat == "looking for ride")
	{
		currenttrip = PAR;
		count++;
		currenttrip->change_status("InProgress");
		currenttrip->Driver = this;
	}
	else
	{
		cout << "This ride is not looking for a driver " << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

float driver::getAvgRating()
{
	int totalTrips = tripsHistory.size(), ratedRides = 0;
	float totalRating = 0;
	for (int i = 0; i < totalTrips; i++) {
		if (tripsHistory[i]->getstat() == "Complete")
		{
			totalRating += tripsHistory[i]->driver_rating;
			ratedRides++;
		}
	}

	return (totalRating * 1.0) / ratedRides;
}

////////////////////////////////////////////////////////////////////////////////////////////
void driver::printTrips()
{
	int totalTrips = tripsHistory.size();
	for (int i = 0; i < totalTrips; i++)
		cout << *tripsHistory[i];
}

//////////////////////////////////////////////////////////////////////////////////////////////
float driver::getHighestRating()
{
	float highest = 0;
	int totalTrips = tripsHistory.size();
	for (int i = 0; i < totalTrips; i++)
	{

		if (tripsHistory[i]->driver_rating > highest)
			highest = tripsHistory[i]->driver_rating;
	}

	return highest;
}

//////////////////////////////////////////////////////////////////////////////////////////////
string driver::getName()
{
	return USER::getName();
}
