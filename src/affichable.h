#pragma once 
#include <iostream>
using namespace std; 

class affichable{
    public:
    virtual void(std::ostream& f=std::cout) const = 0;
    ~virtual affichable() = default; //règle d'or polymorphisme 

};