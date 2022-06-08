#include <global.hh>
#include <omp.h>

int main(int argc , char *argv []) {
	
	int32_t nt = omp_get_max_threads();
	std::cout << "Max threads: " << nt << std::endl;

	#pragma omp parallel
	{
		int32_t thID = omp_get_thread_num();
		
		std::cout << "Thread ID:" << thID <<std::endl;			
	}
	
	return(EXIT_SUCCESS);
}

