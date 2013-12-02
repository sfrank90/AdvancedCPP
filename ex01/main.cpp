#include "sh_ptr.h"

class B {
public:
    int i;
};

class A : public B {
};

int main() {
    /*acpp::smart_ptr<int> sp_i(new int(42));
    std::cout << "ref_counter i: " << sp_i.ref_counter() << std::endl;
    acpp::smart_ptr<int> sp_j(sp_i);
    std::cout << "ref_counter i: " << sp_i.ref_counter() << std::endl;
    acpp::smart_ptr<int> sp_k;
    sp_k = sp_j;
    std::cout << "ref_counter i: " << sp_i.ref_counter() << std::endl;

    std::cout << "i: " << *sp_i << std::endl;
    std::cout << "j: " << *sp_j << std::endl;
    std::cout << "k: " << *sp_k << std::endl << std::endl;

    *sp_k = 25;

    std::cout << "i: " << *sp_i << std::endl;
    std::cout << "j: " << *sp_j << std::endl;
    std::cout << "k: " << *sp_k << std::endl << std::endl;

    {
        acpp::smart_ptr<int> sp_l(new int(3));
        std::cout << "ref_counter j: " << sp_j.ref_counter() << std::endl;
        std::cout << "Assing sp_l to sp_j..." << std::endl;
        sp_j = sp_l;
        std::cout << "ref_counter j: " << sp_j.ref_counter() << std::endl;
        std::cout << "Deleting sp_l" << std::endl;
    }
    std::cout << "ref_counter j: " << sp_j.ref_counter() << std::endl;
    std::cout << "i: " << *sp_i << std::endl;
    std::cout << "j: " << *sp_j << std::endl;
    std::cout << "k: " << *sp_k << std::endl << std::endl;*/

    acpp::smart_ptr<int> p(new int(42));
    acpp::smart_ptr<int> q(p);
    p = q;

    //acpp::smart_ptr<const int> cp = p;
    q = cp;
    //acpp::smart_ptr<int> &t = *p;
    //const acpp::smart_ptr<int> &ct = *cp;
    //acpp::smart_ptr<int> &p2 = *cp;
    acpp::smart_ptr<A> pa(new A);
    acpp::smart_ptr<B> pb = pa;
    std::cout << "ref_counter pb: " << pb.ref_counter() << std::endl;  
    return 0;
}
