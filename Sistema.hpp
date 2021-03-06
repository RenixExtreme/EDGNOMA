#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_

#include<iostream>

Sistema:: Sistema(){}

//Procedimiento que administra las opciones del sistema
void Sistema:: menu_ppal(std::string comando){

	if(comando.substr(0,4).compare("help")==0){
		menu_aiuda(comando);
	}
	else if(comando.substr(0,6).compare("cargar")==0){
		cargarArchivo(comando);
	}
	else if(comando.substr(0,6).compare("conteo")==0){
		conteo();
	}
	else if(comando.substr(0,17).compare("listar_secuencias")==0){
		listar_secuencias();
	}
	else if(comando.substr(0,10).compare("histograma")==0){
		histograma(comando.substr(11));
	}
	else if(comando.substr(0,15).compare("es_subsecuencia")==0){
		subsecuencia(comando.substr(16));
	}
	else if(comando.substr(0,10).compare("enmascarar")==0){
		enmascarar(comando);
	}
	else if(comando.substr(0,7).compare("guardar")==0){
		guardar(comando.substr(8));
	}
}

//Procedimiento auxiliar para guardar la información en la estructura del sistema
void Sistema::guardar(std::list<char> &lista, std::string nombre){
    Secuencia preliminar;
    preliminar.setNombre(nombre);
    preliminar.setSecuencia(lista);
    secuencias.push_back(preliminar);
}

//Procedimiento encargado de cargar el archivo al sistema
void Sistema::cargarArchivo(std:: string comando){
    int sca=secuencias.size();
    std:: string nombreFile=comando.substr(7);
    std::string nombre;
    std::fstream archivo;
    archivo.open(nombreFile, std:: fstream::in);
    archivo.seekg(0,archivo.end);
    if(!archivo.fail() && archivo.tellg() !=0){
    	archivo.seekg(0,archivo.beg);
        std::list<char>subSec;
        char codigo;
        while(!archivo.eof()){
            archivo.get(codigo);
            if(codigo == '>'){
                if(subSec.size() != 0){
                    guardar(subSec,nombre);
                    subSec.clear();
                }
                getline(archivo,nombre,'\n');
                archivo.get(codigo);
            }
            else if(codigo == '\n'){
            	continue;
            }
            subSec.push_back(codigo);
        }
        guardar(subSec,nombre);
        int n=secuencias.size()-sca;
        if(n == 1){
            std::cout<<n<<" secuencia cargada correctamente desde \""<<nombreFile<<"\"\n";
        }
        else{
            std::cout<<n<<" secuencias cargadas correctamente desde \""<<nombreFile<<"\"\n";
        }
    }
    else if (archivo.tellg() == 0){
      std::cout<<nombreFile<<" no contiene ninguna secuencia";
    }
    else
    {
        std::cout<<"Error al cargar archivo\n";
    }
    archivo.close();
}

//Procedimiento para contar el número de secuencias cargadas en el sistema
void Sistema::conteo(){
    int nsecuencias=secuencias.size();
    if(nsecuencias == 0){
        std::cout<<"No hay secuencias cargadas en memoria\n";
    }
    else if(nsecuencias == 1){
        std::cout<<"1 secuencia en memoria\n";
    }
    else{
        std::cout<<"Hay "<<nsecuencias<<" secuencia en memoria\n";
    }
}

//Procedimiento que cuenta las bases y ayuda a la funcion
short int Sistema:: cantbases(std::list<char> lista)
{
	  std::list<char> bases;
		bases.push_front('A');
		bases.push_front('U');
		bases.push_front('T');
		bases.push_front('G');
		bases.push_front('C');
    char c;
    int n=lista.size();
    for (int i=0; i < n; i++)
    {
        c=lista.front();
        bases.remove(c);
        lista.pop_front();
    }
    return 5-(bases.size());
}

//Procedimiento para listar las secuencias
void Sistema:: listar_secuencias()
{
    std::list<Secuencia> aux=secuencias;
    int ns=aux.size();
    if(ns != 0)
    {
        Secuencia saux;
        for(int i=0; i<ns; i++)
        {
            saux=aux.front();
            if(saux.getNombre() == "Full_SEQUENCE")
            {
                std::cout<<"Secuencia \""<<saux.getNombre()<<"\" contiene "<<cantbases(saux.getSecuencia())<<" bases\n";
            }
            else
            {
                std::cout<<"Secuencia \""<<saux.getNombre()<<"\" contiene al menos "<<cantbases(saux.getSecuencia())<<" bases\n";
            }
            aux.pop_front();
        }
    }
    else
    {
        std::cout<<"No hay secuencias en memoria\n";
    }
}


//Procedimiento para generar el histograma de una secuencia en particular
void Sistema:: histograma(std::string nameSecuencia){
	std::list<Secuencia>:: iterator itS;
	Secuencia chosen;
	for(itS=secuencias.begin();itS!=secuencias.end();itS++){
		if(itS->getNombre()==nameSecuencia){
			chosen=*itS;
			break;
		}
	}
	std::list<char>::iterator itC, itSubC;
	std::list<char>codigos_aux=chosen.getSecuencia();
	codigos_aux.sort();
	codigos_aux.unique();
	for(itC=codigos_aux.begin();itC!=codigos_aux.end();itC++){
		int cont=0;
		for(itSubC=chosen.getSecuencia().begin();itSubC!=chosen.getSecuencia().end();itSubC++){
			if(*itC==*itSubC){
				cont++;
			}
		}
		std::cout<<*itC<<" frecuencia_"<<*itC<<": "<<cont<<'\n';
	}
}

//Procedimiento para hallar la cantidad de ocurrencias de una subSecuencia en las que se encuentran cargadas en el sistema
void Sistema:: subsecuencia(std:: string subsecuencia){
	std::list<std::string>str_secue;
	std::string str_prelim;
	std::list<Secuencia>::iterator itS;
	std::list<char>::iterator itC;
	int cont=0;
	for(itS=secuencias.begin();itS!=secuencias.end();itS++){
		for(itC=itS->getSecuencia().begin();itC!=itS->getSecuencia().end();itC++){
			str_prelim.push_back(*itC);
		}
		str_secue.push_back(str_prelim);
	}
	std::list<std::string>::iterator itSt;
	for(itSt=str_secue.begin();itSt!=str_secue.end();itSt++){
		}
	for(itSt=str_secue.begin();itSt!=str_secue.end();itSt++){
		if(itSt->find(subsecuencia) != std::string::npos){
			cont++;
		}
	}
	if(secuencias.size()==0){
		std::cout<<"No hay secuencias cargadas en memoria\n";
	}
	else if(cont==0){
		std::cout<<" La secuencia dada no existe\n";
	}
	else{
		std::cout<<"La secuencia dada se repite "<<cont<<" veces\n";
	}
}

void Sistema::enmascarar(std:: string comando){
	/*//No hay secuencias cargadas en memoria.
	if(secuencias.begin()==secuencias.end()){
		std::cout<<"No hay secuencias cargadas"<<'\n';
		}
	//Buscar el nombre de la secuencia.
	std:: list<Secuencia>::iterator it = secuencias.begin();
	int pausa=0;
	while(it != secuencias.end()){
		if(comando.substr(11)==it->getNombre()){
			Secuencia temporal;
			std:: string nombretemp;
			std:: list<char>secu;
			for (int i = 0; i < it->getSecuencia().size(); ++i)
			{
				secu.push_back('X');
			}
				//secu.push_back('\n');
			temporal.setNombre(it->getNombre());
			temporal.setSecuencia(secu);
			secuencias.insert(it, temporal);
			secuencias.erase(it++);
			pausa++;
		}
		it++;
	}
	if (pausa==0)
	{
		//La secuencia dada no existe, por tanto no se enmascara nada.
		std::cout<<"No se enmascararon subsecuencias."<<'\n';
	}else
	{
		if (pausa==1)
		{
			//1 secuencia ha sido enmascarada.
			std::cout<<"Una subsecuencia enmascarada."<<'\n';
		}else
		{
			//s secuencias han sido enmascaradas.
			std::cout<<"Varias subsecuencias esmascaradas."<<'\n';
		}
	}*/
}

//Procedimiento encargado de guardar las estructuras en archivos al sistema
void Sistema::guardar(std::string nombre){
	std::list<Secuencia>::iterator itS;
	std::list<char>::iterator itC;
	std::ofstream archivo;  // objeto de la clase ofstream

    archivo.open(nombre + ".fasta");

    for(itS=secuencias.begin();itS!=secuencias.end();itS++){
    	archivo <<">"<< itS->getNombre() <<std::endl;
		for(itC=itS->getSecuencia().begin();itC!=itS->getSecuencia().end();itC++){
			archivo << *itC;
		}
		archivo <<std::endl;
	}
	std::cout<<"Secuencias guardadas"<<std::endl;
	archivo.close();
}

//Procedimiento que provee las ayudas al usuario sobre como utilizar lso comandos del sistema
void Sistema:: menu_aiuda(std::string comando){
	int opc=0;
	if(comando.compare("help cargar")==0){
		opc=1;
	}
	else if(comando.compare("help conteo")==0){
		opc=2;
	}
	else if(comando.compare("help listar_secuencias")==0){
		opc=3;
	}
	else if(comando.compare("help histograma")==0){
		opc=4;
	}
	else if(comando.compare("help es_subsecuencia")==0){
		opc=5;
	}
	else if(comando.compare("help enmascarar")==0){
		opc=6;
	}
	else if(comando.compare("help guardar")==0){
		opc=7;
	}
	else if(comando.compare("help")==0){
		opc=8;
	}

	switch (opc){
	case 1:
		std::cout<<"cargar + [nombre_archivo]. Ejemplo: cargar fasta.fa ."<<'\n';
		std::cout<<"Carga en memoria los datos contenidos en el archivo identificado por nombre_arcivo."<<'\n';
		break;
	case 2:
		std::cout<<"conteo."<<'\n';
		std::cout<<"Imprime por pantalla la cantidad de secuencias cargadas en memoria."<<'\n';
		break;
	case 3:
		std::cout<<"listar_secuencias."<<'\n';
		std::cout<<"Imprime en n líneas (una para secuencia) la información básica (cantidad de bases) de cada secuencia."<<'\n';
		break;
	case 4:
		std::cout<<"histograma + [descripcion secuencia]. Ejemplo: histograma descripcion_secuencia"<<'\n';
		std::cout<<"Imprime el histograma de una secuencia, en caso de que exista."<<'\n';
		break;
	case 5:
		std::cout<<"es_subsecuencia + [secuencia]. Ejemplo: es_subsecuencia subsecuencia."<<'\n';
		std::cout<<"Genera un reporte, de todos los vuelos que han sido vendidos, cambiados o cancelados por la agencia de viajes."<<'\n';
		break;
	case 6:
		std::cout<<"enmascarar + [secuencia]. enmascarar secuencia."<<'\n';
		std::cout<<"Enmascara una secuencia dada por el usuario, si existe"<<'\n';
		break;
	case 7:
		std::cout<<"guardar + [nombre_archivo]. Ejemplo: guardar + archivo_salida."<<'\n';
		std::cout<<"Guarda en el archivo nombre_archivo las secuencias cargadas en memoria."<<'\n';
		break;
	case 8:
		std::cout<<"Los comandos disponibles son:\n";
		std::cout<<"cargar + [nombre_archivo]. Ejemplo: cargar fasta.fa ."<<'\n';
		std::cout<<"conteo."<<'\n';
		std::cout<<"listar_secuencias."<<'\n';
		std::cout<<"histograma + [descripcion secuencia]. Ejemplo: histograma descripcion_secuencia"<<'\n';
		std::cout<<"es_subsecuencia + [secuencia]. Ejemplo: es_subsecuencia subsecuencia."<<'\n';
		std::cout<<"enmascarar + [secuencia]. enmascarar secuencia."<<'\n';
		std::cout<<"guardar + [nombre_archivo]. Ejemplo: guardar + archivo_salida."<<'\n';
		break;
	default:
		std::cout<<"El comando ingresado no existe."<<'\n';
		return;
		break;
	}
}

#endif
