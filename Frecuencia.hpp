#ifndef FRECUENCIA_HPP_
#define FRECUENCIA_HPP_

Frecuencia:: Frecuencia(){}

//Getters & setters


void Frecuencia:: setCi(char parametro){
	this->ci=parametro;
}

void Frecuencia:: setFi(long parametro){
	this->fi=parametro;
}

char Frecuencia:: getCi(){
	return this->ci;
}

long Frecuencia:: getFi(){
	return this->fi;
}

#endif