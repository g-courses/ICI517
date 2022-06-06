#pragma once

/////////////////////////////////////////////////////////////////////////////////
//
//   Uso:
//   		Matrix varName(fileName);
//
//   Description:
//                Carga los datos de una matriz 2d
//                desde el archivo 'fileName'
//                a memoria principal (variable 'varName')
//
//   Atributos privados:
//	             _nfil, _ncol   : filas, columnas de datos de la matriz
//               _matrixInMemory: matriz en memoria.
//
//   Atributos públicos:
//               Matrix(nfil,  ncol)        : crea una matriz vacía de nfil x ncol
//               Matrix(fileName, separador): crea una matriz con los datos del archivo 'fileName'. Los datos
//                                            de la matriz están separados por el caracter 'separador'
//               operador ()    : sobrecargado para acceder a los datos de la matriz (i,j)
//               rows()         : devuelva la cantidad de filas de la matriz.
//               cols()         : devuelva la cantidad de columnas de la matriz.
//               value(i,j)     : devuelve el elmente i,j
//               value(i,j, val): asigna el valor val al elemento i,j
//
//  Última revisión: 2022-03-23
//
/////////////////////////////////////////////////////////////////////////////////

#include <sstream>
#include <iostream>
#include <fstream>
#include <exception>

struct matrixException : public std::exception {
	std::string msg;
	const char * what () const throw () {
		return(msg.c_str()) ;
	}
};


template <typename T>
class Matrix{

private:
	std::ifstream _matrixFile;
	
	std::string _separador;
	std::string _fileName;
	
	T *_matrixInMemory;
	uint32_t _nfil, _ncol;
	
	
public:
	Matrix(uint32_t nfil, uint32_t ncol);
	Matrix(std::string fileName, std::string separador);
	~Matrix();
	
	void load();
	 T operator()(uint32_t id_i, uint32_t id_j) const;
	 T value(uint32_t id_i, uint32_t id_j) const;
	void value(uint32_t id_i, uint32_t id_j, T val);
	
	uint32_t rows() const {return _nfil;}
	uint32_t cols() const {return _ncol;}
	
	
private:
	void openFile();
	void loadInMemory();

};

template <typename T>
Matrix<T>::Matrix(uint32_t nfil, uint32_t ncol): _nfil(nfil), _ncol(ncol)
{
	_matrixInMemory = new T[ _nfil * _ncol ];
}

template <typename T>
Matrix<T>::Matrix(std::string fileName, std::string separador): _fileName(fileName), _separador(separador)
{

}

template <typename T>
Matrix<T>::~Matrix()
{
	delete[] _matrixInMemory;
}

template <typename T>
void Matrix<T>::load()
{
	this->openFile();
	
	this->loadInMemory();
	
}


template <typename T>
void Matrix<T>::openFile()
{
	_matrixFile.open(_fileName);
	if(!_matrixFile.good()){
		matrixException mException;
		mException.msg= "Error en acceso a archivo: " + _fileName;
		throw mException;
	}
}

template <typename T>
void Matrix<T>::loadInMemory()
{
	std::string line;
	size_t index = 0;
	
	std::getline(_matrixFile, line);

	index = line.find(_separador);
	
	_nfil    = std::stoi( line.substr(0, index) );
	_ncol = std::stoi( line.substr(index + _separador.length(), line.length()) );
	
	_matrixInMemory = new T[ _nfil * _ncol ];
	

	for(size_t i = 0; i < _nfil; i++){
		std::getline(_matrixFile, line);
			
		for(size_t j = 0; j < _ncol; j++){
			index = line.find(_separador);
			std::stringstream ssLine( line.substr(0, index)  );
			T value;
			ssLine >> value;

			_matrixInMemory[i*_ncol + j] = value;
			
			line.erase(0, index + _separador.length());	
		}
	}
	_matrixFile.close();
}

template <typename T>
T Matrix<T>::operator()(uint32_t id_i, uint32_t id_j) const
{
	return(_matrixInMemory[id_i*_ncol + id_j]);
}

template <typename T>
T Matrix<T>::value(uint32_t id_i, uint32_t id_j) const
{
	return(_matrixInMemory[id_i*_ncol + id_j]);
}

template <typename T>
void Matrix<T>::value(uint32_t id_i, uint32_t id_j, T val)
{
	uint32_t idx = id_i*_ncol + id_j;
	_matrixInMemory[idx] = val;
}









