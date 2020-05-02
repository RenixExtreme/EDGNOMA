#ifndef SECUENCIA_HPP_
#define SECUENCIA_HPP_

//Constructor
Secuencia:: Secuencia(){}

//Getters & setters
std::string Secuencia:: getNombre(){
	return this->nombre;
}

void Secuencia:: setNombre(std::string newNombre){
	this->nombre=newNombre;
}

void Secuencia:: setSecuencia(std::list<char> &codigos){
	this->secuencia=codigos;
}

std::list<char>& Secuencia::getSecuencia(){
	return this->secuencia;
}

void Secuencia:: vaciarSecuencia(){
	this->secuencia.clear();
}

#endif
