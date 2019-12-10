// Timer.hxx
// GL, 14.5.2011
//------------------
#ifndef TIMER_HXX_
#define TIMER_HXX_

class Timer{
	double T0, T1;
	double T;
	double running;
	double doubleTimeSec();
public:
	Timer();
	~Timer();
	void start();
	void stop();
	double getTime();
	void reset();
};

#endif /* TIMER_HXX_ */
