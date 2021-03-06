#pragma once

/////////////////////////////////////////////////////////////////////////////////
//
//   Uso:
//   		Matrix<T> varName(fileName, sep);
//
//   Description:
//                Carga los datos de una matriz 2d con tipo de dato T
//                desde el archivo 'fileName' a memoria principal (variable 'varName').
//				  La matriz se almacena en memoria en forma contigua.
//
//   Atributos privados:
//	             _nrow, _ncol   : filas, columnas de datos de la matriz
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
//  Última revisión: 2022-06-07
//
/////////////////////////////////////////////////////////////////////////////////

/************************************

//(1) Ejemplo de carga en memoria desde un archivo file1
	Matrix<double> m1(file1, " ");
	
	try{
		m1.load();
	} catch(std::exception& e){
		std::cerr << e.what() <<std::endl;
		exit(EXIT_FAILURE);
	}

//(2) Copia de una matriz ya cargada en memoria en otra matriz
	Matrix<double> m2 = m1;

//(3) Devolver el elemento (i,j) de la matriz m2
	m2(i, j)
	m2.value(i, j)

//(4) Asignar el valor val al elemento (i,j) de la matriz m2
	m2.value(i, j, val)
************************************/


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

protected:
	std::ifstream _matrixFile;
	
	std::string _separador;
	std::string _fileName;
	
	T *_matrixInMemory;
	uint32_t _nrow, _ncol;
	
	
public:
	Matrix(uint32_t nfil, uint32_t ncol);
	Matrix(std::string fileName, std::string separador);
	Matrix(const Matrix& m);
	~Matrix();
	
	void load();
	 T operator()(uint32_t id_i, uint32_t id_j) const;
	 
	 T value(uint32_t id_i, uint32_t id_j) const;
	void value(uint32_t id_i, uint32_t id_j, T val);
	
	uint32_t rows() const {return _nrow;}
	uint32_t cols() const {return _ncol;}
	
	
protected:
	void openFile();
	void loadInMemory();

};

template <typename T>
Matrix<T>::Matrix(uint32_t nfil, uint32_t ncol): _nrow(nfil), _ncol(ncol)
{
	_matrixInMemory = new T[ _nrow * _ncol ];
}

template <typename T>
Matrix<T>::Matrix(std::string fileName, std::string separador): _fileName(fileName), _separador(separador)
{

}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& m)
{	
	_nrow = m._nrow;
	_ncol = m._ncol;
	
	_matrixInMemory = new T[ _nrow * _ncol ];

	for(size_t i = 0; i < _nrow; i++){	
		for(size_t j = 0; j < _ncol; j++){
			_matrixInMemory[i*_ncol + j] = m._matrixInMemory[i*_ncol + j];
			
		}
	}
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
	
	_nrow    = std::stoi( line.substr(0, index) );
	_ncol = std::stoi( line.substr(index + _separador.length(), line.length()) );
	
	_matrixInMemory = new T[ _nrow * _ncol ];
	

	for(size_t i = 0; i < _nrow; i++){
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









