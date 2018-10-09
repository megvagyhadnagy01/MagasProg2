/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

// File: ProductInventory.cpp
#include <stdexcept>
#include "ProductInventory.h"
#include "ProductFactory.h"
using namespace std;

ProductInventory::~ProductInventory()
{
	emptyProducts();
}

void ProductInventory::emptyProducts()
{
	for(unsigned i=0; i < products.size(); i++)
		delete products[i];
	products.clear();
}

void ProductInventory::PrintProducts(ostream& os) const
{
	for(unsigned i=0; i < products.size(); i++)
	{
		os << i << ".: ";
		products[i]->Print(os) ;
		os << endl;
	}
}

void ProductInventory::ReadInventory(istream& is) 
{
	is >> ws;	// Whitespace (space, tab) karakterek beolvasása
	while (is.good())
	{
		Product* product = ProductFactory::GetInstance()->ReadAndCreateProduct(is);

		if (product) // Ha p nem NULL
		{
			is >> *product;
			AddProduct(product);
		}
	}
	cout << "End of reading product items.";
}

void ProductInventory::WriteInventory(ostream& os) const
{
	for(unsigned i=0; i < products.size(); i++)
		os << *products[i] << endl;
}



void ProductInventory::AddProduct(Product* product)
{
	if (product == NULL)
		throw invalid_argument("ProductInventory::AddProduct - The product parameter can not be null.");
	products.push_back( product );
}
