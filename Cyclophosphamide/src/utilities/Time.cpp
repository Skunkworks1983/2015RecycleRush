/*
 * Time.cpp
 *
 *  Created on: Mar 21, 2015
 *      Author: s-4020395
 */

#include <utilities/Time.h>
#include <chrono>

Time::Time() {
	// TODO Auto-generated constructor stub

}

Time::~Time() {
	// TODO Auto-generated destructor stub
}

unsigned long Time::getTime() {
	using namespace std::chrono;
	unsigned long ms = duration_cast<milliseconds>(
			high_resolution_clock::now().time_since_epoch()).count();
	return ms;
}

