#include <global.hh>

#include <Timer.hpp>
#include <Matrix.hpp>

#include <MultMatrix.hh>

/////////////////////////////////////////////////////////////////////////////////
//  Identificación del alumno
//
// Nombre Completo:
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./matrixMult --matrix matrix_file
//
//   Description:
//           -->Completar la descripción
//
/////////////////////////////////////////////////////////////////////////////////

void uso(std::string pname)
{
	std::cerr << "Uso: " << pname << " --matrix MATRIX_FILE" << std::endl;
}

int main(int argc, char** argv)
{

	Timer<std::chrono::nanoseconds> timer1;
	std::string fileMatrixA;
	
	///////////////////////////////////////
	//  Read command-line parameters
	if(argc != 3){
		uso(argv[0]);
		exit(EXIT_FAILURE);
	}
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "--matrix") {
			fileMatrixA = argv[i+1];
		}
	}
	
	if(fileMatrixA == ""){
		uso(argv[0]);
		exit(EXIT_FAILURE);
	}
	
	Matrix<float> m1(fileMatrixA, " ");
	
	timer1.start();
	try{
		m1.load();
	} catch(std::exception& e){
		std::cerr << e.what() <<std::endl;
		exit(EXIT_FAILURE);
	}
	timer1.stop();
	
	std::cout << "Time to load matrix in memory: " << timer1.elapsed() << " ns\n";
	
	for(size_t i=0; i< m1.rows(); i++){
		for(size_t j=0; j< m1.cols(); j++){
			std::cout << m1(i,j) << "\t";
		}
		std::cout << std::endl;
	}
	
	
	// Ejemplo de creación de matrix vacía
	MultMatrix mm;
	Matrix<float> C(m1.rows(), m1.cols());
	
	//Ejemplo de llamada al método del algoritmo ijk
	mm.DOijk(m1, m1, C);
	
	
	return(EXIT_SUCCESS);
}


