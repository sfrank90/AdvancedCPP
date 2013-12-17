#include "dispatcher.h"
#include "shape.h"
#include <iostream>

#include <cmath>

#define PI 3.14159

void print::dispatch(triangle &s) {
	std::cout << "Triangle" << std::endl;
}
void print::dispatch(circle &s) {
        std::cout << "Circle" << std::endl;
}
void print::dispatch(rectangle &s) {
        std::cout << "Rectangle" << std::endl;
}
void print::dispatch(square &s) {
        std::cout << "Square" << std::endl;
}
// Area
void area::dispatch(triangle &s) {
  float h = (s.a+s.b+s.c) / 2.0f;
  value = sqrt(h*(h-s.a)*(h-s.b)*(h-s.c));
}
void area::dispatch(circle &s) {
  value = s.r * s.r * PI;
}
void area::dispatch(rectangle &s) {
  value = s.a*s.b;
}
void area::dispatch(square &s) {
  value = s.a*s.a;
}

// Diameter
void diameter::dispatch(triangle &s) {
  float h = (s.a+s.b+s.c) / 2.0f;
  float area = sqrt(h*(h-s.a)*(h-s.b)*(h-s.c));
  value = s.a*s.b*s.c / (4.0f*area);
}
void diameter::dispatch(circle &s) {
  value = s.r*2.0f;
}
void diameter::dispatch(rectangle &s) {
  value = sqrt(s.a*s.a + s.b*s.b);
}
void diameter::dispatch(square &s) {
  value = sqrt(s.a*s.a*2.0f);
}

// Perimeter
void perimeter::dispatch(triangle &s) {
  value = s.a+s.b+s.c;
}
void perimeter::dispatch(circle &s) {
  value = 2.0f * PI * s.r;
}
void perimeter::dispatch(rectangle &s) {
  value = 2.0f*(s.a+s.b);
}

void perimeter::dispatch(square &s) {
  value = 4.0f*(s.a);
}

