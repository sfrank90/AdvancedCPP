#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "typelist.h"

class triangle;
class circle;
class rectangle;

typedef pair<triangle, pair<circle, pair<rectangle> > > hierarchy;

template<class T>
class IDispatcher {
public:
  virtual void dispatch(T &s) = 0;
};

template<typename V> class _dispatcher {};

template <typename V, class N>
class _dispatcher<pair<V, N> > : public IDispatcher<V>, public _dispatcher<N>
{};


template <>
class _dispatcher<null_type>
{};

class dispatcher : public _dispatcher<hierarchy>
{};

class print : public dispatcher {
public:
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};

class area : public dispatcher  {
public:
    float value;
    area() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};

class diameter : public dispatcher  {
public:
    float value;
    diameter() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};

class perimeter : public dispatcher  {
public:
    float value;
    perimeter() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};
#endif

