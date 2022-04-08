#ifndef __TIMER_CLASS__
#define __TIMER_CLASS__ 

#include <chrono>
#include <ratio>

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime, endTime;

public:
	Timer(){}

	void start();
	void stop();
	
	template <class TIME> 
	double elapsed();

};

void Timer::start()
{
	startTime = std::chrono::high_resolution_clock::now();
}
void Timer::stop()
{
	endTime = std::chrono::high_resolution_clock::now();
}


template <class TIME>
double Timer::elapsed()
{
	//auto e = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
	auto e = std::chrono::duration_cast<TIME>(endTime - startTime);
	//auto e = std::chrono::duration<double, TIME>(endTime - startTime);
	return(e.count());
}


#endif