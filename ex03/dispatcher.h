#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "typelist.h"

class triangle;
class circle;
class rectangle;
class square;

typedef pair<triangle, pair<circle, pair<rectangle, pair<square> > > > hierarchy;

template<class T>
class IDispatcher {
public:
  virtual void dispatch(T &s) = 0;
};

template<typename V> class _dispatcher {};

template <typename V, class N>
class _dispatcher<pair<V, N> > : public _dispatcher<N>,  public IDispatcher<V>
{
public:
	using _dispatcher<N>::dispatch;    //dunno...
	using IDispatcher<V>::dispatch;    //with snippet
	//virtual void dispatch(V &s) = 0; //without snippet
};


template <typename V>
class _dispatcher<pair<V,null_type> > : public IDispatcher<V>
{
public:
	using IDispatcher<V>::dispatch;    //with snippet
	//virtual void dispatch(V &s) = 0; //without snippet
};

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
    void dispatch(square &s);
};

class area : public dispatcher  {
public:
    float value;
    area() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
    void dispatch(square &s);
};

class diameter : public dispatcher  {
public:
    float value;
    diameter() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
    void dispatch(square &s);
};

class perimeter : public dispatcher  {
public:
    float value;
    perimeter() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
    void dispatch(square &s);
};
#endif

