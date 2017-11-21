#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;



class Memory {
public:
	Memory() {}
   Memory(long int ramMemory, int pageSize, int numberOfHardDisks)
   : ramMemory_(ramMemory), pageSize_(pageSize), numberOfHardDisks_(numberOfHardDisks) {}
   ~Memory() {}

	// Allocate memory for process
	void allocateMemoryForProcess(int PID, int priorityLevel);
	// Function for m command
	void requestMemoryOperation(int memoryAddress);
	// Release Memory for current process
	void releaseMemory(int PID);
	// Show State of Memory
	void snapshotSystem();







	// Load page into memory
	void loadPageIntoSystem();



private:
	int timeStamp_ = 1;
	int pageNumber_ = 0;
	long int ramMemory_ = 0;
	int pageSize_ = 0, numberOfHardDisks_ = 0;
};

#endif
