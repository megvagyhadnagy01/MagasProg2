/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

// File: CompositeProduct.cpp
#include "CompositeProduct.h"
#include "ProductFactory.h"
#include "stlutils.h"
#include <algorithm>

using namespace std;

CompositeProduct::CompositeProduct(): 
	Product() { }


CompositeProduct::~CompositeProduct(void)
{
	for_each(parts.begin(),parts.end(),delete_ptr());
}

void CompositeProduct::AddPart(Product* product)
{
	parts.push_back(product);
}

void CompositeProduct::printParams(std::ostream& os) const
{
	Product::printParams(os);
	os << endl<< "  Items: " ;
	for (unsigned int i = 0; i < parts.size(); ++i)
	{
		os << endl << "  " << i << ". :"; 
		parts[i]->Print(os);
	}
}

void CompositeProduct::loadParamsFromStream(std::istream& is)
{
	Product::loadParamsFromStream(is);
	int itemCount;
	is >> itemCount;
	
	for (int i = 0; i < itemCount; ++i)
	{
		Product* product = ProductFactory::GetInstance()->ReadAndCreateProduct(is);
		if (product) // Ha p nem NULL
		{
			is >> *product;
			AddPart(product);
		}
	}
}

void CompositeProduct::writeParamsToStream(std::ostream& os) const
{
	Product::writeParamsToStream(os);
	os << ' ' << parts.size() ;

	for(unsigned i=0; i < parts.size(); i++)
		os << endl << *parts[i];
}

void CompositeProduct::SortProduct()
{
	sort(parts.begin(), parts.end(), compare_ptr_by_value());
}
