#include <global.hh>
#include <Timer.hpp>

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
	Timer timer1;
	int sizeBytes, numberElements;
	
	int N = 15;
	
	///////////////////////////////////////
	//  Read command-line parameters
	if(argc != 3){
		std::cerr << "Uso: " << argv[0] << " -N <size>" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string mystr;
	for (size_t i=0; i < argc; i++) {
		mystr=argv[i];
		if (mystr == "-N") {
			N =  atoi(argv[i+1]);
		}

	}
	
	sizeBytes = 1 << N;
	//sizeBytes = N*1024;
	numberElements = sizeBytes/sizeof(float);
	
	float* matrixExample = new float[ numberElements ];

	//std::cout << "Size: " << (float)sizeBytes / (1024)<< " KBytes\n";
	
	timer1.start();
	for(size_t i = 0; i < numberElements; i++ ){
		matrixExample[i] += 1.0;
	}
	timer1.stop();
	//std::cout << "Elapsed time in first for: " << timer1.elapsed<std::chrono::milliseconds>() << "ms\n";
	
	timer1.start();
	int steps = 1024 * 1024 * 1024; // Arbitrary number of steps

	int lengthMod = numberElements - 1;

	for (size_t i = 0; i < steps; i++) {
		matrixExample[(i * 5) & lengthMod]++; // (x & lengthMod) is equal to (x % A.Length)
		
	}
	
	
	timer1.stop();
	//std::cout << "Elapsed time in second for: " << timer1.elapsed<std::chrono::milliseconds>() << "ms\n";
	
	std::cout << N << ":" << (float)sizeBytes / (1024) << "KB:" <<  timer1.elapsed<std::chrono::milliseconds>() << "\n";
	
	delete[] matrixExample;
	
	return(EXIT_SUCCESS);
}


