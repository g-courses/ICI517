#pragma once

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
//  Nombre Completo:
/////////////////////////////////////////////////////////////////////////////////

#include <global.hh>
#include <Matrix.hpp>

class MultMatrix
{
private:
	//Todas las variables privadas deben comenzar con _


public:
	MultMatrix(){}
	~MultMatrix(){}
	
	void DOijk(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C);
	void DOkij(const Matrix<float>& A,const Matrix<float>& B, Matrix<float>& C);

};



