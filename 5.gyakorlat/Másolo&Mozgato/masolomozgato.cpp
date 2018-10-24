#include <iostream>
using namespace std;
 
class Java
{
    public:
        const char* majom;
        Java(const char* majom){this->majom=majom;}
        // copy ctor
        Java(const Java &A2){
            majom=A2.majom;
            cout << "copy" << endl;
        }
 
 
        // move assign  ctor
        Java& operator= (Java&& A2){
                majom = A2.java;
                A2.majom = nullptr;
                cout << "move" << endl;
                return *this;
        }
       
};
 
int main(){
    Java a("Java Java Java Java ");
    cout <<a.majom <<endl;
    Java a2(a);
    cout << a2.majom  << endl;
    a = move(a2) ;
    return 0;
 
}