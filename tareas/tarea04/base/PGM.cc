#include <PGM.hh>

///////////////////////
//Métodos a implementar

// Versiones secuenciales
void PGM::invert()
{

}

void PGM::pixelate(uint32_t sizeWindow)
{
	uint32_t step;
	step = 1 << sizeWindow;
	
}

void PGM::hEdges()
{
	PGM mAux = *this;
	

}


// Versiones paralelas
void PGM::invertMP()
{

}

void PGM::pixelateMP(uint32_t sizeWindow)
{
	uint32_t step;
	step = 1 << sizeWindow;
	
}

void PGM::hEdgesMP()
{
	PGM mAux = *this;
	

}



