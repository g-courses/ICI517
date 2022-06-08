#include <global.hh>

#include <Timer.hpp>
#include <PGM.hh>

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./matrix -m matrix_file  -p n
//
//   Description:
//           Programa driver que muestra el uso de la librería para cargar matrices (PGM.hh)
//           y de medición de tiempo (Timer.hpp)
//
/////////////////////////////////////////////////////////////////////////////////


int main(int argc, char** argv)
{

	Timer<std::chrono::milliseconds> timer1;
	std::string fileMatrixA;
	uint32_t sizeWinPix;
	
	///////////////////////////////////////
	//  Read command-line parameters
	if(argc != 5){
		std::cerr << "Uso: " << argv[0] << " -m MATRIX_FILE -p n" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-m") {
			fileMatrixA = argv[i+1];
		}
		if (mystr == "-p") {
			sizeWinPix = std::stoi(argv[i+1]);
		}
	}
	
	PGM m1(fileMatrixA, " ");
	
	timer1.start();
	try{
		m1.load();
	} catch(std::exception& e){
		std::cerr << e.what() <<std::endl;
		exit(EXIT_FAILURE);
	}
	timer1.stop();
	std::cout << "Time to load matrix in memory: " << timer1.elapsed() << " ms\n";

	//Se crean dos matrices PGM adicionales e iguales a m1.
	PGM m2 = m1;
	PGM m3 = m1;
	
	//m1.maxGreyValue(200);
	m1.toFile("test-orig.pgm" );
	
	
	timer1.start();
	m1.invert();
	timer1.stop();
	std::cout << "Time to invert: " << timer1.elapsed() << " ms\n";
	m1.toFile("test-inv.pgm" );
	
	
	timer1.start();
	m2.pixelate(sizeWinPix);
	timer1.stop();
	std::cout << "Time to pixelate: " << timer1.elapsed() << " ms\n";
	m2.toFile("test-pix.pgm" );
	
	
	timer1.start();
	m3.hEdges();
	timer1.stop();
	std::cout << "Time to Horizontal edges: " << timer1.elapsed() << " ms\n";
	m3.toFile("test-hEdges.pgm" );
	
	
	
	
	return(EXIT_SUCCESS);
}


