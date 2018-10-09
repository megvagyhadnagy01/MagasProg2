/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

#include <stdexcept>
#include "ProductFactory.h"

using namespace std;

ProductFactory* ProductFactory::instance = NULL;

void ProductFactory::Init(ProductFactory* pf)
{
	instance = pf;
}

ProductFactory* ProductFactory::GetInstance()
{
	return instance;
}

Product* ProductFactory::ReadAndCreateProduct(istream& is)
{
	if (!is.good())
		return NULL;

	char typeCode;
	is >> typeCode;
	
	// Ha nincs semmi hiba és fájlvége sem
	if (!is.good())	
	{
		if (is.eof()) return NULL;

		cout << "There was an error reading the product items!" << endl;
		return NULL;
	}

	Product* product = CreateProduct( typeCode );
	if (product == NULL) // Ha p NULL
	{
		cout << "Unknown product type." << endl;
	}
	return product;
}
