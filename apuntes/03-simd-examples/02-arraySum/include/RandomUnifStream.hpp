#ifndef __RandomUnifStream__
#define __RandomUnifStream__

#include <random>

template <typename T>
class RandomUniformStream{
        private:
                std::random_device _dev;
                double _max;
        public:
                RandomUniformStream(double m) : _max(m) {}
                T nextNumber();
                T operator() ();
};

template <typename T>
T RandomUniformStream<T>::nextNumber()
{
        std::uniform_real_distribution<> unif(-_max, _max);

        T number = unif(_dev);

        return(number);
}

template <typename T>
T RandomUniformStream<T>::operator() ()
{
        return(nextNumber());
}

#endif