#include "shape.h"
#include <iostream>


void triangle::visit(dispatcher& D) {
    D.dispatch((triangle&)*this);
}
void circle::visit(dispatcher& D) {
    D.dispatch(*this);
}
void rectangle::visit(dispatcher& D) {
    D.dispatch(*this);
}


