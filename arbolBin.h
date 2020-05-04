#ifndef ARBOLBIN_H_INCLUDED
#define ARBOLBIN_H_INCLUDED
#include <iostream>
#include "nodo.h"

using namespace std;


template<typename A>
struct arbolBin
{
public:
    arbolBin( )
    {
        raiz=nullptr;
        nodos = 0 ;
    }

    nodo<A>* getRaiz( )
    {
        return raiz;
    }

    int estaVacio( )
    {
        return (raiz==nullptr) ;
    }
    void insertar (A const &);
    nodo<A>* buscar ( const A &);
    void recorrerPre( ) ;
    void preorden( nodo<A> *);
    void recorrerIn( ) ;
    void inorden( nodo<A> *);
    size_t tamano ( ) const ;
private:
    nodo<A> * raiz;
    size_t nodos;
} ;

#endif // ARBOLBIN_H_INCLUDED
