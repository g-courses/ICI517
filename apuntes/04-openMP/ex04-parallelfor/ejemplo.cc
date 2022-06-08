#include <global.hh>
#include <omp.h>

int main(int argc , char *argv []) {
	
	//Por omisión, se paraleliza con la capacidad del HW
	int32_t nt = omp_get_max_threads();
	
	///////////////////////////////////////
	//  Read command-line parameters
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-nt") {
			nt = atoi(argv[i+1]);
		}
	}
	
	uint32_t totalData = 20;
	
	#pragma omp parallel for  num_threads(nt)
	for(size_t i = 0; i < totalData; ++i){	
		int32_t thID = omp_get_thread_num();
		#pragma omp critical
		{
			std::cout << "thID:" << thID << ",i=" << i << std::endl;
		}
	}
	
	return(EXIT_SUCCESS);
}
