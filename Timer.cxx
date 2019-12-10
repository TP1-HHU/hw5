// Timer.cxx
// GL, 14.5.2011

#include "Timer.hxx"
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
//-----------------------------------
using namespace std;
//-------------------------------------------
// Public parts
//-------------------------------------------
Timer::Timer(): T0(0), T1(0), T(0), running(false){}
//---------------------------------------
Timer::~Timer(){}
//---------------------------------------
void Timer::start(){
    if (running){
    	cout << "Timer is already running!" << endl;
    	exit(1);
    }
	running = true;
	T0 = doubleTimeSec();
}
//---------------------------------------
void Timer::stop(){
	if (!running){
		cout << "Tried to stop non-running timer!" << endl;
		exit(1);
	}
	running = false;
	T1 = doubleTimeSec();
}
//---------------------------------------
double Timer::getTime(){
  if (running == false)
     T = T1-T0;
  else
     T = doubleTimeSec() - T0;
	return (T);
}
//---------------------------------------
void Timer::reset(){
	running = false;
	T0 = 0; T1 = 0; T = 0;
}

//-------------------------------------------
// Private parts
//-------------------------------------------
//-------------------------------------------

double Timer::doubleTimeSec()
{
	struct timeval tstruct;
	while(gettimeofday(&tstruct,0) == -1);
	return double( double(tstruct.tv_sec) + double(tstruct.tv_usec)*1.e-6 );
}
