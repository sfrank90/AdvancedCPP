//#include "typelist.h"

#include "shape.h"
#include "dispatcher.h"

#include <iostream>

int main() {
  /*typedef pair<double, pair<double, pair<char> > > l;
  typedef printer<l> p;
  typedef size<l> s;
  typedef append<l, double>::result k;
  typedef printer<k> kp;
  typedef reverse<l>::result rev_list;
  typedef printer<rev_list> rev_printer;
  std::cout << "List l contains: " << p::print_type() << std::endl;
  std::cout << "Size of List l: " << s::length << std::endl;
  std::cout << "List k contains: " << kp::print_type() << std::endl;
  std::cout << "Reverse list of l contains: " << rev_printer::print_type() << std::endl;*/

  //typedef pair<triangle, pair<circle, pair<rectangle> > > hierarchy;
  
  shape *t = new triangle(2.f,2.f,2.f);
  shape *c = new circle(1.f);
  shape *r = new rectangle(2.f, 4.f);
  
  print p;

  area a;
  t->visit(a);
  std::cout << "Area "; t->visit(p); std::cout << ": " << a.value << std::endl;
  c->visit(a);
  std::cout << "Area "; c->visit(p); std::cout << ": " << a.value << std::endl;
  r->visit(a);
  std::cout << "Area "; r->visit(p); std::cout << ": " << a.value << std::endl;


  diameter d;
  t->visit(d);
  std::cout << "Diameter "; t->visit(p); std::cout << ": " << d.value << std::endl;
  c->visit(d);
  std::cout << "Diameter "; c->visit(p); std::cout << ": " << d.value << std::endl;
  r->visit(d);
  std::cout << "Diameter "; r->visit(p); std::cout << ": " << d.value << std::endl;

  perimeter pe;
  t->visit(pe);
  std::cout << "Perimeter "; t->visit(p); std::cout << ": " << pe.value << std::endl;
  c->visit(pe);
  std::cout << "Perimeter "; c->visit(p); std::cout << ": " << pe.value << std::endl;
  r->visit(pe);
  std::cout << "Perimeter "; r->visit(p); std::cout << ": " << pe.value << std::endl;

  std::cin.get();

  return 0;
}
