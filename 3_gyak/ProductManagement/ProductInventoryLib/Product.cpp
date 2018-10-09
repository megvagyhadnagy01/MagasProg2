/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

// File: product.cpp
#include <string>
#include "Product.h"

using namespace std;

Product::Product() { }

Product::Product(string name, int initialPrice, Date dateOfAcquisition):
	name(name), initialPrice(initialPrice), dateOfAcquisition(dateOfAcquisition)
{ }

void Product::printParams(ostream& os) const
{ 
	

	os << ", " << "InitialPrice: " << initialPrice 
		<< ", " << "DateOfAcquisition: " << dateOfAcquisition
		<< ", " << "Age: " << GetAge()
		<< ", " << "Current price: " << GetCurrentPrice();
}

void Product::loadParamsFromStream(istream& is)
{
	is >> name;
	is >> initialPrice;
	is >> dateOfAcquisition;
}

void Product::writeParamsToStream(std::ostream& os) const
{
	
	os << ' ' << name << ' ' << initialPrice << ' ' << dateOfAcquisition;
}

int Product::GetInitialPrice() const {	return initialPrice; }

string Product::GetName() const { return name; }

Date Product::GetDateOfAcquisition() const {	return dateOfAcquisition;}

int Product::GetAge() const
{
	return dateOfAcquisition.GetElapsedDays();
}

int Product::GetCurrentPrice() const {	return initialPrice; }

void Product::Print(ostream& os) const
{
	os << "Type: " << GetType() << ", ";
	os << "Name: " << GetName();
	printParams( os );
}

// Globális operátorok
istream& operator>>(istream& is, Product& product) 
{
	product.loadParamsFromStream( is );
	return is;
}

ostream& operator<<(ostream& os, const Product& product) 
{
	os << product.GetCharCode();
	product.writeParamsToStream(os);
	return os;
}
