#include <PGM.hh>


void PGM::invert()
{
	for (uint32_t i = 0; i < this->rows(); i++) {
		for (uint32_t j = 0; j <this->cols(); j++) {
			uint32_t grayLevel = this->value(i,j);
			
			uint32_t grayLevelInv = _maxGreyValue - grayLevel;
			this->value(i,j, grayLevelInv);

		}
	}
}

void PGM::pixelate(uint32_t sizeWindow)
{
	uint32_t step;
	step = 1 << sizeWindow;
	
	for (uint32_t i = 0; i < this->rows(); i += step) {
		for (uint32_t j = 0; j <this->cols(); j += step) {
			uint32_t mean;
			
			mean = 0;
			for(uint32_t ii = i; (ii < i+step) && (ii < _nrow); ii++){
				for(uint32_t jj = j; (jj < j+step) && (jj < _ncol); jj++){
					mean += this->value(ii,jj);
				}
			}
			mean = std::round((float)mean / (step*step));
			
			for(uint32_t ii = i;(ii < i+step) && (ii < _nrow); ii++){
				for(uint32_t jj = j; (jj < j+step) && (jj < _ncol); jj++){
					this->value(ii,jj, mean);
				}
			}

		}
	}
	
}

void PGM::hEdges()
{
	PGM mAux = *this;
	
	for (uint32_t i = 1; i < mAux.rows() - 1 ; i++) {
		for (uint32_t j = 1; j < mAux.cols() - 1; j++) {
			
			int32_t footValue, headValue, sobelValue ;
			footValue  =     mAux.value(i+1,j-1);
			footValue += 2 * mAux.value(i+1,j);
			footValue +=     mAux.value(i+1,j+1);
			headValue  =     mAux.value(i-1,j-1);
			headValue += 2 * mAux.value(i-1,j);
			headValue +=     mAux.value(i-1,j+1);
			
			sobelValue = footValue - headValue;
			
			if(sobelValue < 0) {
				sobelValue = 0;
			}
			if(sobelValue > 255){
				sobelValue = 255;
			}
			this->value(i-1,j-1,sobelValue);
			this->value(i-1,j  ,sobelValue);
			this->value(i-1,j+1,sobelValue);
			this->value(i  ,j-1,sobelValue);
			this->value(i  ,j  ,sobelValue);
			this->value(i  ,j+1,sobelValue);
			this->value(i+1,j-1,sobelValue);
			this->value(i+1,j  ,sobelValue);
			this->value(i+1,j+1,sobelValue);
		}
	}
}







