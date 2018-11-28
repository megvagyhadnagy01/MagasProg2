#include <iostream>

class Moz {

public:

  double* d;

  Moz(double c)
      : d(new double(c)) { }

  // copy ctor
  Moz() {
    d = nullptr;
  }

  Moz(const Moz &a) {
    d = a.d;
    std::cout << "copy ctor" << std::endl;
  }


  // move ctor
  Moz(Moz&& a) {
    a = std::move(a);
    std::cout << "move ctor" << std::endl;
  }

  //move assign
  Moz& operator= (Moz&& a) {
    if (this != &a) {
      d = a.d;
      a.d = nullptr;
      std::cout << "move assign" << std::endl;
    }
    return *this;
  }

  //copy assign
  Moz& operator=(const Moz& a) {
    if (this != &a) {
      delete d;
      d = a.d;
      std::cout << "copy assign" << std::endl;
    }
    return *this;
  }

  //dtor
  ~Moz() {
    delete d;
  }

};

Moz f(Moz a) {
  return a;
}

int main(){

    Moz a(3.14);
    Moz b = a;
    if (a.d == b.d) {
      std::cout << "copy ctor helyes3" << std::endl;
    } else {
      std::cout << "copy ctor helytelen4" << std::endl;
    }
    Moz c(2.12);
    a = c;
    if (a.d == c.d) {
      std::cout << "copy assign helyes" << std::endl;
    } else {
      std::cout << "copy assign helytelen" << std::endl;
    }
    Moz d(f(Moz(1.2)));
    Moz e;
    e = std::move(a);
    if (e.d == c.d && a.d == nullptr) {
      std::cout << "move assign helyes" << std::endl;
    } else {
      std::cout << "move assign helytelen" << std::endl;
    }
    return 0;

}
