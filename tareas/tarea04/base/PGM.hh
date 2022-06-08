#pragma once

/////////////////////////////////////////////////////////////////////////////////
//
//   Uso:
//   		PGM varName(fileName, sep);
//
//   Description:
//                Carga los datos de una matriz 2d con tipo de dato T
//                desde el archivo 'fileName' a memoria principal (variable 'varName').
//                
//
//
//   Atributos públicos:
//               Hereda todos los métodos publicos de Matrix<uint32_t>
//               toFile(std::string fileName)
//               invert()
//               pixelate(uint32_t sizeWindow)
//               hEdges()
//
//  Última revisión: 2022-06-07
//
/////////////////////////////////////////////////////////////////////////////////

#include <sstream>
#include <iostream>
#include <fstream>
#include <exception>
#include <cmath>

#include <Matrix.hpp>

class PGM : public Matrix<uint32_t>{

private:
	std::ofstream _pgmFile;
	
	uint32_t _maxGreyValue;
	
	
public:
	PGM(uint32_t nfil, uint32_t ncol) : Matrix<uint32_t>(nfil, ncol) {}
	PGM(std::string fileName, std::string separador) : Matrix<uint32_t>(fileName, separador) {}
	PGM(const PGM& p) : Matrix<uint32_t>(p) { _maxGreyValue = p._maxGreyValue; }
	
	~PGM() {}
	
	void load(){
			openFile();
			loadInMemory();
	}
	
	uint32_t maxGreyValue() const {return _maxGreyValue;}
	void     maxGreyValue(uint32_t maxGreyValue )  { _maxGreyValue = maxGreyValue;}
	
	void toFile(std::string fileName){
		_pgmFile.open(fileName);
		if(!_pgmFile.good()){
			matrixException mException;
			mException.msg= "Error en acceso a archivo: " + fileName;
			throw mException;
		}
	
	
		_pgmFile << "P2\n";
		_pgmFile << this->cols() << " " << this->rows() << "\n";
		_pgmFile << _maxGreyValue << "\n";
	
		for (uint32_t i = 0; i < this->rows(); i++) {
			for (uint32_t j = 0; j <this->cols(); j++) {
				uint32_t grayLevel = this->value(i,j);
				_pgmFile << grayLevel<< " ";
			}
			_pgmFile << "\n";
		}
		_pgmFile.close();
	}
	
private:
	void loadInMemory(){
		std::string line;
		size_t index = 0;

		std::getline(_matrixFile, line);
		if(line != "P2"){
			matrixException mException;
			mException.msg= "El archivo: " + _fileName + " no es PGM P2";
			throw mException;
		}
	
		std::getline(_matrixFile, line);
		index = line.find(_separador);
		_ncol = std::stoi( line.substr(0, index) );
		_nrow = std::stoi( line.substr(index + _separador.length(), line.length()) );
	
		std::getline(_matrixFile, line);
		_maxGreyValue = std::stoi(line);

		_matrixInMemory = new uint32_t[ _nrow * _ncol ];
	
		line.clear();
		for(size_t i = 0; i < _nrow; i++){	
			std::getline(_matrixFile, line);
		
			for(size_t j = 0; j < _ncol; j++){
				if( line.length() == 0 ){
					//El formato P2 no permite que las lineas de la matriz
					//tengan mas de 70 caracteres. Esto implica que una
					//linea de la imagen esté en más de una línea de la
					//matriz.
					std::getline(_matrixFile, line);
				}
			
				index = line.find(_separador);
				std::stringstream ssLine( line.substr(0, index)  );
				uint32_t value;
				ssLine >> value;

				_matrixInMemory[i*_ncol + j] = value;
		
				line.erase(0, index + _separador.length());	
			}
		}

		_matrixFile.close();
	}
	
public:
	///////////////////////
	//Métodos a implementar
	
	// Versiones secuenciales
	void invert();
	void pixelate(uint32_t sizeWindow);
	void hEdges();
	
	// Versiones paralelas
	void invertMP();
	void pixelateMP(uint32_t sizeWindow);
	void hEdgesMP();
};

