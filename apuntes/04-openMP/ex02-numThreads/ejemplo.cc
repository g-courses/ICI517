#include <global.hh>
#include <omp.h>

int main(int argc , char *argv []) {
	
	//Por omisión, se paraleliza con la capacidad del HW
	//int32_t nt = std::thread::hardware_concurrency();
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
	
	uint32_t limSup = 5000;
	
	
	std::random_device dev;  
	
	#pragma omp parallel num_threads(nt)
	{
		std::mt19937 gen(dev()); 
		std::uniform_int_distribution<> unif(0, limSup);
		
		int32_t thID = omp_get_thread_num();
		int32_t timeToSleep = unif(gen);
		
		std::cout << "Thread ID:" << thID << "->" << timeToSleep << std::endl;	
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToSleep));
		std::cout << "Thread ID:" << thID << " awake" << std::endl;	
		
	}
	
	
	return(EXIT_SUCCESS);
}
