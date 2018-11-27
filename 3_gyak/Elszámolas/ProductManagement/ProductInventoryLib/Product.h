/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

// File: product.h
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <ctime>
#include <locale>
#include "Date.h"

class Product
{
protected:
	int initialPrice;	// Beszerzési ár
	Date dateOfAcquisition; // Beszerzés dátuma
	std::string name;	// Név
	virtual void printParams(std::ostream& os) const;
	virtual void loadParamsFromStream(std::istream& is);
	virtual void writeParamsToStream(std::ostream& os) const;
public:
	Product();
	Product(std::string name, int initialPrice, Date dateOfAcquisition);
	virtual ~Product() {};
	int GetInitialPrice() const;
	std::string GetName() const;
	Date GetDateOfAcquisition() const;
	int GetAge() const;
	virtual int GetCurrentPrice() const;
	void Print(std::ostream& os) const;
	virtual std::string GetType() const = 0;
	virtual char GetCharCode() const = 0;
	bool operator < (const Product& other)const { std::locale loc; return loc(name, other.name); }

	friend std::istream& operator>>(std::istream& is, Product& product);
	friend std::ostream& operator<<(std::ostream& os, const Product& product);
};
#endif /* PRODUCT_H */
