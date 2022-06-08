#include <global.hh>

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
	
	uint32_t limSup = 5000;
	
	#pragma omp parallel num_threads(nt) private(limSup)
	{
		int32_t thID = omp_get_thread_num();
		#pragma omp critical
		{
		std::cout << "Thread ID:" << thID << "->" << limSup << std::endl;	
		}
		
		limSup *= 200;
	}
	
	std::cout << "Main Thread:" << "->" << limSup << std::endl;	
	
	#pragma omp parallel num_threads(nt) firstprivate(limSup)
	{
		int32_t thID = omp_get_thread_num();
		#pragma omp critical
		{
		std::cout << "Thread ID:" << thID << "->" << limSup << std::endl;	
		}
	
		limSup *= 200;
	}

	std::cout << "Main Thread:" << "->" << limSup << std::endl;	
	
	return(EXIT_SUCCESS);
}
