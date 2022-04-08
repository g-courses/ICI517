#include <global.hh>
#include <Timer.hpp>

/////////////////////////////////////////////////////////////////////////////////
//   Usage:
//           ./program_name  -N <size>
//            
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
	numberElements = sizeBytes/sizeof(float);
	
	float* matrixExample = new float[ numberElements ];

	for(size_t i = 0; i < numberElements; i++ ){
		matrixExample[i] += 1.0;
	}

	int steps = 1024 * 1024 * 1024; // number of steps
	int lengthMod = numberElements - 1;

	timer1.start();
	for (size_t i = 0; i < steps; i++) {
		matrixExample[(i * 5) & lengthMod]++; // (x & lengthMod) is equal to (x % A.Length)
		
	}
	timer1.stop();
	
	std::cout << N << ":" << (float)sizeBytes / (1024) << "KB:" <<  timer1.elapsed<std::chrono::milliseconds>() << "\n";
	
	delete[] matrixExample;
	
	return(EXIT_SUCCESS);
}


