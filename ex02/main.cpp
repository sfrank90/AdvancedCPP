#include "typelist.h"

#include <iostream>

int main() {
  typedef pair<double, pair<double, pair<char> > > l;
  typedef printer<l> p;
  typedef size<l> s;
  typedef append<l, double>::result k;
  typedef printer<k> kp;
  typedef reverse<l>::result rev_list;
  typedef printer<rev_list> rev_printer;
  std::cout << "List l contains: " << p::print_type() << std::endl;
  std::cout << "Size of List l: " << s::length << std::endl;
  std::cout << "List k contains: " << kp::print_type() << std::endl;
  std::cout << "Reverse list of l contains: " << rev_printer::print_type() << std::endl;
  return 0;
}
