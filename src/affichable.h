#pragma once 
#include <iostream>

using namespace std; 

//Template Method
class affichable{
public:
    virtual ~affichable() = default;
    virtual void afficher(std::ostream& f=std::cout ) const=0;
};