#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include "Secuencia.h"
#include "Frecuencia.h"
#include "arbolBin.h"
#include "TablaHuffman.h"


class Sistema {
	protected:
		std::list<Secuencia> secuencias;
		std::list<Frecuencia> frecuencias;
	public:
		Sistema();
		void menu_aiuda(std::string comando);
		void menu_ppal(std::string comando);
		void guardar(std::list<char> &lista, std::string nombre);
		void guardar(std::string nombre);
		void cargarArchivo(std::string comando);
		void conteo();
		short cantbases(std::list<char> lista);
		void listar_secuencias();
		void histograma(std::string nameSecuencia);
		void subsecuencia(std:: string subsecuencia);
		std::string mascara(int tam);
		void enmascarar(std:: string comando);
		void codificar(std:: string nombre);
		void almacenarFrecuencias();
		void algoritmoHuffman();
};

#include "Sistema.hpp"
#endif
