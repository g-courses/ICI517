#include <global.hh>
#include <Timer.hpp>

void makeCells(const int32_t& i)
{	
	std::this_thread::sleep_for(std::chrono::milliseconds(i*10));
}

int32_t makeCells()
{
	std::random_device dev;  
	std::mt19937 gen(dev()); 
	std::uniform_int_distribution<> unif(10, 200);
	
	int32_t cells = unif(gen);
	
	std::this_thread::sleep_for(std::chrono::milliseconds(cells));
	return(cells);
}

int main(int argc , char *argv []) { 
	double start
	
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
	

	Timer<std::chrono::milliseconds> t1;
	t1.start();
	

	/*
	#pragma omp parallel for num_threads(nt) schedule(static,1)
	for(size_t i = 0; i < aSize; ++i){		
		int32_t thID = omp_get_thread_num();	
		makeCells(i);
		printf("thID=%d\titer=%ld\tcellsMade=%ld\n",thID, i, i+1);
	}
	*/
	
	/*
	#pragma omp parallel for num_threads(nt) schedule(guided)
	for(size_t i = 0; i < aSize; ++i){		
		int32_t thID = omp_get_thread_num();	
		int32_t cellsMade = makeCells();
		printf("thID=%d\titer=%ld\tcellsMade=%d\n",thID, i, cellsMade);
		
	}
	*/
	
	start = omp_get_wtime();
	#pragma omp parallel num_threads(nt)
	{
		#pragma omp for  schedule(dynamic,5)
		for(size_t i = 0; i < aSize; ++i){		
			int32_t thID = omp_get_thread_num();	
			int32_t cellsMade = makeCells();
			printf("%f\tthID=%d\titer=%ld\tcellsMade=%d\n",omp_get_wtime() - start, thID, i, cellsMade);
			
		}
	}
	
	
	
	t1.stop();
	
	std::cout << "elapsed:" <<  t1.elapsed() << "ms\n";
	
	return(EXIT_SUCCESS);
}
