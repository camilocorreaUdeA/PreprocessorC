/*Ejemplo uso de las directivas del preprocesador en C/C++
 * Para el bootcamp OTT de la empresa Globant
 * Autor: Juan Camilo Correa Chica
 * Instructor: Manuela Quesada
 */

/* La directiva de preprocesador #include permite
 * que el compilador incluya el contenido de un archivo header.
 * Usando < > se pueden incluir archivos presentes en los
 * directorios estandar definidos en la implementacion, y usando " "
 * se buscan los archivos en el directorio del proyecto
 */

#include <iostream>  //Incluyendo un header estandar de la implementacion
/*Incluyendo headers presentes en el directorio del proyecto */
#include "fooclass.h"
#include "customclass.h"
#include "comp_switchs.h"

/* La directiva #define se usa para definir macros (constantes), reemplazando
 * la ocurrencia de un identificador con una expresion de reemplazo.
 * Las macros definidas con #define se pueden eliminar usando la
 * directiva #undef.
 */

/* Definiendo dos constantes con #define */
#define SCREEN_HEIGHT 1080
#define SCREEN_WIDTH 1920

/* Previo a la compilacion se reemplazan los identificadores por sus valores */
int screen_pixel_array[SCREEN_HEIGHT][SCREEN_WIDTH];

/* Las directivas #ifdef y #ifndef son condicionales y se utilizan
 * respectivamente para verificar si una macro o constante ya ha sido
 * definida o no lo ha sido. Para completar la estructura condicional
 * esta disponible la directiva #else y se debe cerrar el bloque de
 * condicon con la directiva #endif
 */

/*Uso de la directiva #ifndef (Solo ilustrativo)*/
#ifndef PLATFORM
#define PLATFORM "OPENCORE"
#endif

/*Uso de las directivas #ifdef y #undef (Solo ilustrativo)*/
#ifdef FPGA_SUPPORT
#undef FPGA_SUPPORT //La aplicacion no soporta cores de FPGA
#endif

#ifndef sum
#define sum(a,b) (a+b)
#endif

int main()
{

/* El bloque condicional conformado con las directivas #if, #elif, #else
 * se puede usar para solo compilar ciertas partes del codigo, esto ayuda
 * a que el codigo sea portable entre distintas plataformas
 */

 /* Las directivas #error y #warning se utilizan para forzar al compilador
  * a arrojar un error o un warning en caso de llegar a estas sentencias
  */

/* A manera ilustrativa se pueden manipular los "switchs" de compilacion
 * del header comp_switchs.h e instanciar ya sea un objeto de la clase FooClass
 * o de la clase CustomClass, sino corresponde a ninguno de los "switchs"
 * definidos entonces se debe arrojar sea un error o un warning de compilacion
 */

#if defined(X86) || defined(ARM32) || defined(MIPS)
 FooClass *obj = new FooClass;
#elif defined(X64) || defined(ARM64) || defined(PWPC) || defined(RISCV)
 CustomClass *obj = new CustomClass;
#else
//#error "Procesador no soportado por la aplicacion"
#warning "Procesador no soportado por la aplicacion"
#define UNKW_PROC 1
#endif

/*Cuando se usa el warning hay que verificar que no llame metodos del objeto */

#ifndef UNKW_PROC
    obj->display();
    delete obj;
#endif

/* La directiva #pragma es dependiente del compilador y sirve para dat ciertas
 * instrucciones al compilador, por ejemplo, silenciar un warning o en el caso
 * de sistemas embebidos ubicar de manera forzosa una variable en cierta region
 * de memoria o para antender interrupciones por hardware. Lamentablemente no
 * tengo un ejemplo funcional en C++ del uso de esta directiva con el compilador
 * GCC en MinGW32 5.11.1
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

    int c;

#pragma GCC diagnostic pop

    return 0;
}
