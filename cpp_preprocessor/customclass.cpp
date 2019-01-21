#include "customclass.h"
#include <iostream>

CustomClass::CustomClass()
{
    std::cout<<"Un nuevo objeto de clase Custom"<<std::endl;
}

CustomClass::~CustomClass()
{
}

void CustomClass::display() const
{
    /*Un uso adicional del preprocesador:
     *Construyendo cadenas de caracteres con directiva
     * #define y el operador #
     * y concatenando con operador ##
     */
#define str(x) #x
#define concatena(a,b) a##b
    std::concatena(co,ut)<<str(Hola este es un objeto Custom)<<std::endl;
}
