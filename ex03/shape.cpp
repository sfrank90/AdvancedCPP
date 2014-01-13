#include "shape.h"
#include <iostream>


void triangle::visit(dispatcher& D) {
    D.dispatch(*this);
}
void circle::visit(dispatcher& D) {
    D.dispatch(*this);
}
void rectangle::visit(dispatcher& D) {
    D.dispatch(*this);
}

void square::visit(dispatcher& D) {
    D.dispatch(*this);
}

