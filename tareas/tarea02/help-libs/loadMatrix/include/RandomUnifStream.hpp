#ifndef __RandomUnifStream__
#define __RandomUnifStream__

#include <random>

class RandomUniformStream{
        private:
                std::random_device _dev;
                double _max;
        public:
                RandomUniformStream(double m) : _max(m) {}
                double nextNumber();
                double operator() ();
};

double RandomUniformStream::nextNumber()
{
        std::uniform_real_distribution<> unif(-_max, _max);

        double number = unif(_dev);

        return(number);
}

double RandomUniformStream::operator() ()
{
        return(nextNumber());
}

#endif