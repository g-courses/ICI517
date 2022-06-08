#include <global.hh>
#include <Timer.hpp>
#include <omp.h>

int main(int argc , char *argv []) {
	std::random_device dev;  
	
	//Por omisión, se paraleliza con la capacidad del HW
	int32_t nt    = omp_get_max_threads();
	int32_t aSize = 20;
	
	///////////////////////////////////////
	//  Read command-line parameters
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-nt") {
			nt = atoi(argv[i+1]);
		}
		if (mystr == "-asize") {
			aSize = atoi(argv[i+1]);
		}
	}
	
	auto datos = new uint32_t[aSize];

	//LLenar vector con algo...
	Timer<std::chrono::milliseconds> t1;
	
	t1.start();
	#pragma omp parallel for num_threads(nt) 
	for(size_t i = 0; i < aSize; ++i){	
		std::mt19937 gen(dev()); 
		std::uniform_int_distribution<> unif(0, 10000);
		datos[i] = unif(gen);
		
		/*
		int32_t thID = omp_get_thread_num();
		#pragma omp critical
		{
			std::cout << "thID:" << thID << ", dato[" << i << "]="<< datos[i] << std::endl;
		}
		*/
		
	}
	t1.stop();
	
	std::cout << "elapsed:" <<  t1.elapsed() << "ms\n";
	
	
	
	return(EXIT_SUCCESS);
}
