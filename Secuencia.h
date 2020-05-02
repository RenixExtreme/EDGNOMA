#ifndef SECUENCIA_H_
#define SECUENCIA_H_

#include <string>
#include <list>

class Secuencia{
	private:
		std::string nombre;
		std::list<char> secuencia;
	public:
		Secuencia();
		std::string getNombre();
		void setNombre(std:: string newNombre);
		void setSecuencia(std::list<char> &codigos);
		std::list<char>& getSecuencia();
		void vaciarSecuencia();
};

#include "Secuencia.hpp"
#endif
