#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <class T>
struct nodo
{
public :
    nodo* izquierdo;
    nodo* derecho;
    T dato ;
    nodo (T d )
    {
        dato = d ;
        izquierdo=nullptr;
        derecho=nullptr;
    }
};

#endif // NODO_H_INCLUDED
