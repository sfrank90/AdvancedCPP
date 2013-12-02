#include <string>
#include <typeinfo>

struct null_type;

template<typename V, class N=null_type> class pair;


// print functions
template<typename V> struct printer;
template<typename V, class N> struct printer<pair<V,N> > { 
    static std::string print_type() {
        typedef printer<N> p;
	//typedef printer<V> v;
        return typeid(V).name() + std::string(" ") + p::print_type();
    }
};
template<> struct printer<null_type> {
    static std::string print_type() {
        return std::string("ende");
    }
};
/*template<> struct printer<double> {
    static std::string print_type() {
        return std::string("double");
    }
};

template<> struct printer<typename V> {
    static std::string print_type() {
        return typeid(V).name();
    }
};*/


template<typename V> struct size;
template <typename V, class N> struct size<pair<V,N> > {
    enum {length = 1 + size<N>::length};
};

template<> struct size<null_type> {
    enum {length = 0};
};

//append functions
template<typename V, typename _v> struct append;

template<> struct append<null_type, null_type> {
    typedef null_type result;
};

template <typename _v> struct append<null_type, _v> {
    typedef pair<_v, null_type> result;
};

template <typename V, class N> struct append<null_type, pair<V,N> > {
    typedef pair<V,N> result;
};

template <typename V, class N, typename _v> struct append<pair<V,N>, _v > {
    typedef pair<V, typename append<N,_v>::result > result;
};

//reverse functions
template<typename V> struct reverse;

/*template <typename V, class N> struct reverse<pair<V,N> > {
  typedef typename append<typename reverse<N>::result, V>::result result ;
};*/

/*template <typename V, class N> struct reverse<pair<V,N> > {
  typedef pair< V, typename reverse<N>::result> result;
};*/

template<typename V> struct reverse<pair<V,null_type> > {
    typedef V result;
};

template<> struct reverse<null_type> {
    typedef null_type result;
};

