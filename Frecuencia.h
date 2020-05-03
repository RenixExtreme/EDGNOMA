#ifndef FRECUENCIA_H_
#define FRECUENCIA_H_

class Frecuencia{
	private:
		char ci;
		long fi;
	public:
		Frecuencia();
		void setCi(char parametro);
		void setFi(long parametro);
		char getCi();
		long getFi();
};

#include "Frecuencia.hpp"
#endif
