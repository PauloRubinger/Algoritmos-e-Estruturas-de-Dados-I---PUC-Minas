#include <iostream>
#include "classes.h"
using namespace std;

int main() {

    Vehicle *v1 = new Vehicle(2022, "KJH1234", 20000);
    v1->print();

    Auto *a1 = new Auto(2022, "KJH1234", 20000, 4, 10000);
    a1->print();

    Truck *t1 = new Truck(2022, "ABC1234", 20000, 12, 10000, "U$300.00");
    t1->print();

    Bike *b1 = new Bike(14, "BMX");
    b1->print();

    Urban *u1 = new Urban(14, "BMX", 1451231);
    u1->print();

    Eletric *e1 = new Eletric(14, "BMX", 1451231, 30);
    e1->print();

    Pedal *p1 = new Pedal(14, "BMX", 51584845, 6);
    p1->print();

    return 0;
}