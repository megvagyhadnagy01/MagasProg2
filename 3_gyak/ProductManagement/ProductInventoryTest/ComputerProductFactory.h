/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

#ifndef COMPUTERPRODUCTFACTORY_H
#define COMPUTERPRODUCTFACTORY_H

#include "../ProductInventoryLib/ProductFactory.h"

class ComputerProductFactory: public ProductFactory
{
public:
	Product* CreateProduct(char typeCode) const;
};

#endif /* COMPUTERPRODUCTFACTORY_H */
