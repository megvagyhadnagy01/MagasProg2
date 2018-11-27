#include <iostream>

using namespace std;

class Szulo {
public:
	string pelda1() { return "pelda1"; }
	string pelda2() { return "pelda2"; }
	string pelda3() { return "pelda3"; }
};

class Gyerek: public Szulo {
public:
	string pelda3() { return "valami más"; }
};

class Szulo_virtual {
public:
	string pelda1() { return "pelda1"; }
	string pelda2() { return "pelda2"; }
	virtual string pelda3() { return "pelda3"; }
};

class Gyerek_virtual: public Szulo_virtual {
public:
	string pelda3() { return "valami más"; }
};

int main(int argc, char** argv){

	Szulo *szulo; 
    Gyerek gyerek; 
    szulo = &gyerek; 

	Szulo_virtual *szulo_v; 
    Gyerek_virtual gyerek_v; 
    szulo_v = &gyerek_v; 

	cout << "Sima" << endl << szulo->pelda1() << endl << szulo->pelda2() << endl << szulo->pelda3() << endl;
	cout << endl << "Virtual" << endl << szulo_v->pelda1() << endl << szulo_v->pelda2() << endl << szulo_v->pelda3() << endl;

	return 0;
}