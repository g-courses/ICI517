#include <global.hh>

// Intrinsics to use
#include <emmintrin.h> 
#include <immintrin.h> 
#include <xmmintrin.h>


void showRegister(std::string name, __m128 reg){
	float* tmpOut = new float[4];
	
	_mm_store_ps(tmpOut, reg);
	
	std::cout << name << " = ";
	for(size_t ii=0; ii < 4; ii++){
		std::cout << tmpOut[ii];
		std::cout << " ";
	}
	std::cout << std::endl;
	
	delete[] tmpOut;
}

int main(int argc, char** argv)
{
	__m128 matrix_a; //registro de float de 128 bits	
	__m128 step01;
	matrix_a = _mm_setzero_ps();

	float* dataMemoryIn  = new float[4];
	float* dataMemoryOut = new float[4];
	
	dataMemoryIn[0] = 0.5;
	dataMemoryIn[1] = 1.5;
	dataMemoryIn[2] = 2.5;
	dataMemoryIn[3] = 3.5;
	
	// __m128 _mm_load_ps(float const* mem_addr)
	// dst[127:0] := MEM[mem_addr+127:mem_addr]
	matrix_a = _mm_load_ps(dataMemoryIn);
	
	showRegister("matrix_a", matrix_a);
	
	//step01 = matrixA;
	step01 = _mm_shuffle_ps(matrix_a, matrix_a, _MM_SHUFFLE(3,3,0,0) );
	
	showRegister("step01", step01);



	return(EXIT_SUCCESS);
}