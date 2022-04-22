#include <global.hh>

// Intrinsics to use
#include <emmintrin.h> 
#include <immintrin.h> 
#include <xmmintrin.h>


int main(int argc, char** argv)
{
	__m128 dataRegister; //registro de float de 128 bits	
	dataRegister = _mm_setzero_ps();

	float* dataMemoryIn  = new float[4];
	float* dataMemoryOut = new float[4];
	
	dataMemoryIn[0] = 0.5;
	dataMemoryIn[1] = 1.5;
	dataMemoryIn[2] = 2.5;
	dataMemoryIn[3] = 3.5;
	
	// __m128 _mm_load_ps(float const* mem_addr)
	// dst[127:0] := MEM[mem_addr+127:mem_addr]
	dataRegister = _mm_load_ps(dataMemoryIn);

	//__m128 _mm_mul_ps(__m128 a, __m128 b)
	//	FOR j := 0 to 3
	//		i := j*32
	//		dst[i+31:i] := a[i+31:i] * b[i+31:i]
	//	ENDFOR
	dataRegister = _mm_mul_ps(dataRegister, dataRegister);

	//__m128 _mm_rcp_ps (__m128 a)
	//	FOR j := 0 to 3
	//		i := j*32
	//		dst[i+31:i] := SQRT(a[i+31:i])
	//	ENDFOR		
	dataRegister = _mm_rcp_ps(dataRegister);

	// void _mm_store_ps (float* mem_addr, __m128 a)
	// MEM[mem_addr+127:mem_addr] := a[127:0]
	_mm_store_ps(dataMemoryOut, dataRegister);
	
	
	//Visualizar el contenido del array de salida
	for(size_t ii=0; ii < 4; ii++){
		std::cout << "dataMemoryOut["<< ii <<"] = ";
		std::cout << dataMemoryOut[ii];
		std::cout << std::endl;
	}
	

	return(EXIT_SUCCESS);
}
