#include"trip.h"

void trip::change_status(string status)
{
	this->status = status;
}

///////////////////////////////////////////


void trip::rateDriver(float n)
{
	if (status == "Complete")
	{
		driver_rating = n;
	}
	else
		cout << "Can't  rate \n" << endl;
}

/////////////////////////////////////////////////////

void trip::ratePassanger(float n)
{
	if (status == "Complete")
	{
		passanger_rating = n;
	}
	else
		cout << "Error in rating " << endl << endl;
}

/////////////////////////////////////////////////////

void trip::set_driver(driver* D)
{
	Driver = D;
}
/////////////////////////////////////////////////////

void trip::set_passenger(passenger* P)
{
	Passanger = P;
}

/////////////////////////////////////////////////////

void trip::set_pickup_location(string pick)
{
	pickup_location = pick;
}

/////////////////////////////////////////////////////

void trip::set_dropoff_location(string drop)
{
	dropoff_location = drop;
}


/////////////////////////////////////////////////////


string trip::getstat()
{
	return status;
}
/////////////////////////////////////////////////////
