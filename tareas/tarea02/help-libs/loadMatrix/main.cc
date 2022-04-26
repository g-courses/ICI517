#include <global.hh>

#include <Timer.hpp>
#include <Matrix.hpp>

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./matrix --A matrix_file  
//
//   Description:
//           Programa driver que muestra el uso de la librería para cargar matrices (Matrix.hpp)
//           y de medición de tiempo (Timer.hpp)
//
/////////////////////////////////////////////////////////////////////////////////


int main(int argc, char** argv)
{

	Timer<std::chrono::nanoseconds> timer1;
	std::string fileMatrixA;
	
	///////////////////////////////////////
	//  Read command-line parameters
	if(argc != 3){
		std::cerr << "Uso: " << argv[0] << " --A MATRIX_FILE" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "--A") {
			fileMatrixA = argv[i+1];
		}
	}
	
	Matrix<double> m1(fileMatrixA, " ");
	
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
	
	
	
	return(EXIT_SUCCESS);
}


