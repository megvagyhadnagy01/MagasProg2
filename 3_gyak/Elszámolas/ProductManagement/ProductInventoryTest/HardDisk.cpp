/****************************************/
/* Benedek Zoltán-Levendovszky Tihamér: */
/* Szoftverfejlesztés C++ nyelven       */
/* c. könyv példaprogramjai             */
/* SZAK Kiadó 2007                      */
/****************************************/

#include "HardDisk.h"

HardDisk::HardDisk()
{ }

HardDisk::HardDisk(std::string name, int initialPrice, time_t dateOfAcquisition,
				 int rpm):
 Product(name, initialPrice, dateOfAcquisition),
 speedRPM(rpm)
{ }

void HardDisk::printParams(std::ostream& os) const
{
	Product::printParams(os);
	os <<", " << "SpeedRPM: " << speedRPM;speedRPM;
}

void HardDisk::loadParamsFromStream(std::istream& is)
{
	Product::loadParamsFromStream(is);
	is >> speedRPM;
}

void HardDisk::writeParamsToStream(std::ostream& os) const
{
	Product::writeParamsToStream(os);
	os << ' ' << speedRPM;
}

int HardDisk::GetCurrentPrice() const
{
	int ageInDays = GetAge();
	if (ageInDays < 30)
		return initialPrice;
	else if (ageInDays >= 30 && ageInDays < 90)
		return (int)(initialPrice * 0.9);
	else
		return (int)(initialPrice * 0.8);
}