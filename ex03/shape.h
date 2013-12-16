#ifndef SHAPE_H
#define SHAPE_H

#include "dispatcher.h"

#include <string>

class shape {
private:
public:
  virtual void visit(dispatcher& D) = 0;
};


class triangle : public shape {
public:
  float a,b,c;

  triangle(float _a, float _b, float _c) : a(_a), b(_b), c(_c) {}
  void visit(dispatcher& D);
};

class circle : public shape {
public:
  float r;

  circle(float _r) :  r(_r) {}
  void visit(dispatcher& D);
};

class rectangle : public shape {
public:
  float a,b;

  rectangle(float _a, float _b) : a(_a), b(_b) {}
  void visit(dispatcher& D);
};
#endif

