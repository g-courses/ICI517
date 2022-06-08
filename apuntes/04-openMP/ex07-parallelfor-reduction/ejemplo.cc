#include <global.hh>
#include <Timer.hpp>
#include <omp.h>


int main(int argc , char *argv []) {
	std::random_device dev;  
	
	//Por omisión, se paraleliza con la capacidad del HW
	uint32_t nt    = omp_get_max_threads();
	uint32_t aSize = 20;
	
	///////////////////////////////////////
	//  Read command-line parameters
	std::string mystr;
	for (size_t i=0; i < (size_t)argc; i++) {
		mystr=argv[i];
		if (mystr == "-nt") {
			nt = atoi(argv[i+1]);
		}
		if (mystr == "-asize") {
			aSize = atoi(argv[i+1]);
		}
	}
	

	//
	
	uint32_t total = 0;
	#pragma omp parallel for num_threads(nt) reduction(+:total)
	for(size_t i = 0; i < aSize; ++i){	
		total += i;
	}
	
	
	std::cout << "Total:" <<  total << "\n";
	
	
	
	return(EXIT_SUCCESS);
}
