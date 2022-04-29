#include <global.hh>

#include <emmintrin.h> //SSE2 instrisics
#include <immintrin.h> //AVX intrinsics

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./program_name  .......
//
//   Description:
//                ...................
//
/////////////////////////////////////////////////////////////////////////////////




int main(int argc, char** argv)
{
	uint64_t nx = 2000000;
	uint64_t nt = 1000;

	RandomUniformStream<float> unifStream(100);


	///////////////////////////////////////
	//  Read command-line parameters
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-nt") {
			nt = atoi(argv[i+1]);
		}
		if (mystr == "-nx") {
			nx = atoi(argv[i+1]);
		}
	}

	nx = 1 << nx;
	std::cout << "Problem size: nx=" << nx << std::endl;
	std::cout << "Iterations  : nt=" << nt << std::endl;

	Timer<std::chrono::milliseconds> timer;

	// Array que contiene los numeros a sumar
	float *vectorA, *vectorB ;

	//////////////////////////////////////////////////////////////////////
	// Inicializa el array, alineado a 16 Bytes para __m128 y 32 Bytes para __m256
	vectorA = (float*)aligned_alloc (16, sizeof(float)*nx);
	vectorB = (float*)aligned_alloc (32, sizeof(float)*nx);

	for(size_t i = 0; i < nx; i++) {
		vectorA[i] = unifStream();
		vectorB[i] = vectorA[i];
	}

	//////////////////////////////////////////////////////////////////////
	// Suma secuencial
	//
	double total;
	timer.start();
	for(size_t j = 0; j<nt; j++) {
		total = 0.0;
		for(size_t i=0; i<nx; i++) {
			total +=vectorA[i];
		}
	}
	timer.stop();
	std::cout << "Suma Secuencial: " << total << " - Time:"<< timer.elapsed() << " ms"  << std::endl;

	//////////////////////////////////////////////////////////////////////
	// Suma vectorial con registros de 128 bits
	//
	__m128 regDataIn128, regTotal128;

	timer.start();
	for(size_t j = 0; j<nt; j++) {

		// El registro acumulador se carga con ceros
		regTotal128 = _mm_setzero_ps();
		
		// Se van sumando de a 4 float
		for(size_t i = 0; i < nx; i += 4) {

			// Se cargan 128 bits (4 float) en el registro SIMD
			regDataIn128 = _mm_load_ps(&vectorA[i]);

			// Se realiza la suma vectorial
			regTotal128 = _mm_add_ps(regDataIn128, regTotal128);
		}
		
		// El array de salida debe tener 128 bits,
		// para almacenar 4 float. 
		float *vectorOut = new float[4]; 

		// Se almacena el contenido del registro regTotal (unidad simd)
		// en el array de salida (memoria principal)
		_mm_storeu_ps(vectorOut, regTotal128);

		// Se procede a la reducción
		total = 0.0;
		total = vectorOut[0] + vectorOut[1] + vectorOut[2] + vectorOut[3];
		
		delete [] vectorOut;
	}
	timer.stop();
	
	std::cout << "Suma vectorial (__m128): " << total << " - Time:"<< timer.elapsed() << " ms" <<std::endl;

	
	//////////////////////////////////////////////////////////////////////
	// Suma vectorial con registros de 256 bits
	//
	__m256 regDataIn256, regTotal256;

	timer.start();
	for(size_t j = 0; j<nt; j++) {
		// El registro acumulador se carga con ceros
		regTotal256 = _mm256_setzero_ps();
		
		// Se van sumando de a 8 float
		for(int i = 0; i < nx; i += 8) {
			// Se cargan 256 bits (8 float) en el registro SIMD
			regDataIn256 = _mm256_load_ps(vectorB + i);
			

			// Se realiza la suma vectorial
			regTotal256 = _mm256_add_ps(regDataIn256, regTotal256);
		}
		
		// El array de salida debe tener 256 bits, 
		// para poder almacenar 8 float. 
		float* vectorOut = new float[8]; 

		// Se almacena el contenido del registro regTotal (unidad simd)
		// en el array de salida (memoria principal)
		_mm256_storeu_ps(vectorOut, regTotal256);
	
		// Se procede a la reducción
		total = 0.0;
		total = vectorOut[0] + vectorOut[1] + vectorOut[2] + vectorOut[3] + vectorOut[4] + vectorOut[5] + vectorOut[6] + vectorOut[7];
		
		delete [] vectorOut;
	}
	timer.stop();
	
	std::cout << "Suma vectorial (__m256d): " << total << " - Time:"<< timer.elapsed() << " ms" << std::endl;


	return(EXIT_SUCCESS);
}