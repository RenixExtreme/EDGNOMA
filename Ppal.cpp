#include <iostream>
#include "string.h"
#include "Sistema.h"

int main(int argc, char **argv){
	Sistema *FASTA = new Sistema();
	char comando[256];
	std::cout<<"Sistema FASTA"<<std::endl;
	std::cout<<"Si desea salir del sistema, escriba 'salir'"<<std::endl;
	std::cout<<"$ ";
	std::cin.getline(comando, 256);
	while(strcmp(comando, "salir")!=0 && strcmp(comando, "Salir")!=0 && strcmp(comando, "SALIR")!=0){
		FASTA->menu_ppal(comando);
		std::cout<<"$ ";
		std::cin.getline(comando, 256);
	}
	return 0;
}
