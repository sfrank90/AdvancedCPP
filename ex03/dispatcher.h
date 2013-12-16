#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "typelist.h"

class triangle;
class circle;
class rectangle;

typedef pair<triangle, pair<circle, pair<rectangle> > > hierarchy;

template<class T>
class IDispatcher {
  virtual void dispatch(T &s) = 0;
};

template <class V, class N>
class dispatcher<pair<V, N> > : public IDispatcher<V>, public dispatcher<N> {
public:
};

template <class V>
class dispatcher : public IDispatcher<V>, public dispatcher<N> {
public:
};

template <class T>
class dispatcher<null_type> {}

class print : public dispatcher {
public:
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};

class area : public dispatcher {
public:
    float value;
    area() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};

class diameter : public dispatcher {
public:
    float value;
    diameter() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};

class perimeter : public dispatcher {
public:
    float value;
    perimeter() : value(0.0f) {}
    void dispatch(triangle &s);
    void dispatch(circle &s);
    void dispatch(rectangle &s);
};
#endif

