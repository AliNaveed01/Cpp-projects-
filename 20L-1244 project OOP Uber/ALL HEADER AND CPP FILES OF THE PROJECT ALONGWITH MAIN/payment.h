#include<iostream>

using namespace std;
#ifndef PAYMENT_H
#define PAYMENT_H
class payment
{
	string type;
	string card_number;
	double cash;
public:
	payment();
	payment(string, string);
	payment(double, string);
	payment(const payment&);
	string get_card_number();
	void set_card_number(string);
	friend ostream& operator<<(ostream&, const payment& A);
};
#endif