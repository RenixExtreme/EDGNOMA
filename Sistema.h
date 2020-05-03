#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "Secuencia.h"

class Sistema {
	protected:
		std::list<Secuencia> secuencias;
	public:
		Sistema();
		void menu_aiuda(std::string comando);
		void menu_ppal(std::string comando);
		void guardar(std::list<char> &lista, std::string nombre);
		void guardar(std::string nombre);
		void cargarArchivo(std::string comando);
		void conteo();
		short int cantbases(std::list<char> lista);
		void listar_secuencias();
		void histograma(std::string nameSecuencia);
		void subsecuencia(std:: string subsecuencia);
		void enmascarar(std:: string comando);
		std::string mascara(int tam);
};

#include "Sistema.hpp"
#endif
