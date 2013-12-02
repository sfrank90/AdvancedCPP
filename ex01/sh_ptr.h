#ifndef __SH_PTR__
#define __SH_PTR__
#include <iostream>

namespace acpp {

template<typename T> class smart_ptr {
private:
    int* _ref; 
    T* _obj;

    void clear() {
        if(_ref && !--*_ref) {
            delete _obj;
            delete _ref;
        }
    }
public:
    smart_ptr() : _obj(0), _ref(0) {}
    explicit smart_ptr(T* obj) : _obj(obj), _ref(new int(1)) {}
    
    smart_ptr(const smart_ptr<T> &other) : _obj(other._obj), _ref(other._ref) {
        ++*_ref;
    }

    template<typename A>
    smart_ptr(const smart_ptr<A>& other) : _ref(other.getRef()) {
        _obj = dynamic_cast<T*>(other.get());
        ++*_ref;
    }
    
    ~smart_ptr() {
        std::cout << "Deleting smart pointer..." << std::endl;
        clear();
    }

    T& operator*() { return *_obj; }
    const T& operator*() const { return *_obj; }
    
    T* operator->() { return _obj; }
    const T* operator->() const { return _obj; }

  

    smart_ptr<T>& operator=(const smart_ptr<T> &other) {
        if(this != &other) {
           clear();
           _obj = other._obj;
           _ref = other._ref;
           ++*_ref;
        }
        return *this;
    }

    smart_ptr<T>& operator=(T *obj) {
        if(_obj != obj) {
           clear();
           _obj = obj;
           *_ref = 1;
        }
        return *this;
    }

    int ref_counter() {
      if(_ref) return *_ref;
    }

   T* get() const { return _obj; }
   int* getRef() const { return _ref; }   
};

}

#endif
