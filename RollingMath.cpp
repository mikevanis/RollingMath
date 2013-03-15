#include "RollingMath.h"
#include <Arduino.h>

int rollingAverage(int *store, int size, int entry) {
	long total = 0;
	int result;
	for(int i=0; i<size-1; i++) {
		store[i] = store[i+1];
		total += store[i];
	}
	store[size-1] = entry;
	total += entry;
	result = total / size;
	return result;
}

int rollingMode(int *store, int size, int entry) {
	int result;
	int pos;
	int inner;
	int most;
	int mostsize;
	int current;
	int currentsize;
	
	// Roll array
	for(int i=0; i<size-1; i++) store[i] = store[i+1];
	store[size-1] = entry;
	
	most = 0;
	mostsize = 0;
	for(pos=0; pos<size; pos++) {
		current = store[pos];
		currentsize = 0;
		for(inner=pos+1; inner<size; inner++) {
			if(store[inner]==current) currentsize++;
		}
		if(currentsize > mostsize) {
			most = current;
			mostsize = currentsize;
		}
		if(size-pos < mostsize) break;
	}
	return most;
}

int rollingMinimum(int *store, int size, int entry) {
	int minval;
	
	// Roll array
	for(int i=0; i<size-1; i++) store[i] = store[i+1];
	store[size-1] = entry;
	
	minval = 32767;
	for(int i=0; i<size; i++) {
		if(store[i]<minval) minval = store[i];
	}
	return minval;
}

int rollingMaximum(int *store, int size, int entry) {
	int maxval;
	
	// Roll array
	for(int i=0; i<size-1; i++) store[i] = store[i+1];
	store[size-1] = entry;
	
	maxval = 0;
	for(int i=0; i<size; i++) {
		if(store[i]>maxval) maxval = store[i];
	}
	return maxval;
}