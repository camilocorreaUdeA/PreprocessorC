#include "fooclass.h"
#include <iostream>

FooClass::FooClass()
{
    std::cout<<"Un nuevo objeto de clase Foo"<<std::endl;
}

FooClass::~FooClass()
{

}

void FooClass::display() const
{
    std::cout<<"Hola, este es un objeto Foo!"<<std::endl;
}


