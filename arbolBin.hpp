#ifndef ARBOLBIN_HPP_INCLUDED
#define ARBOLBIN_HPP_INCLUDED
#include <iostream>
#include "nodo.h"
#include "arbolBin.h"

template <class A>
void arbolBin<A>::insertar (A const& item )
{
    nodo<A> *nodoNuevo = new nodo<A>(item);
    nodo<A> * padre = nullptr;

    if (estaVacio( )) // Es un arbol nuevo
    {
        raiz = nodoNuevo; // deja de estar vacio, crea una raiz , increment a nodos y sale
        ++nodos;
        return;
    }

    nodo<A>* enUso=raiz; // asign a la raiz actual como enUso

    while ( enUso ) // busca e l nodo padre
    {
        padre = enUso;
        // si nuevo valor > que el del padre asigna nuevo nodo a la derecha , de lo contrario a izquierda
        enUso = nodoNuevo->dato > enUso->dato ? enUso->derecho : enUso->izquierdo;
    }

    if ( nodoNuevo->dato < padre->dato )
        padre->izquierdo = nodoNuevo;
    else
        padre->derecho = nodoNuevo;
    ++nodos;
}

template <typename A>
nodo<A>* arbolBin<A>::buscar (A const& valor)
{
    nodo<A> *enUso = raiz;
    while ( enUso )
    {
        if ( enUso->dato == valor)
        {
            return enUso;
        }
        else if ( valor < enUso->dato )
        {
            enUso = enUso->izquierdo;
        }
        else
            enUso = enUso->derecho;
    }
    return nullptr;
}

template<typename A>
size_t arbolBin<A>::tamano ( ) const
{
    return nodos ;
}

template<typename A>
void arbolBin<A>::preorden( nodo<A>* nodo )
{

    if (nodo != nullptr)
    {
        cout <<" "<< nodo->dato <<" ";
        if ( nodo->izquierdo)
            preorden (nodo->izquierdo);
        if (nodo->derecho)
            preorden (nodo->derecho);
    }
}

template<typename A>
void arbolBin<A>::recorrerPre( )
{
    preorden (raiz);
}

template<typename A>
void arbolBin<A>::inorden( nodo<A>* nodo )
{
    if (nodo != nullptr)
    {
        if ( nodo->izquierdo)
            inorden ( nodo->izquierdo);
        cout << " " << nodo->dato << " " ;
        if ( nodo->derecho)
            inorden(nodo->derecho) ;
    }
}

template<typename A>
void arbolBin<A>::recorrerIn( )
{
    inorden (raiz);
}



#endif // ARBOLBIN_HPP_INCLUDED
