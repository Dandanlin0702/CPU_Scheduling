#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;

struct PCB {
	// Process indentifier
	int pid;

};

class Memory {
public:
	Memory() {}
   Memory(long int ramMemory_, int pageSize_, int numberOfHardDisks_)
   : ramMemory(ramMemory_), pageSize(pageSize_), numberOfHardDisks(numberOfHardDisks_) {}
   ~Memory() {}

	void createPCB();

   void setUpSystem(long int ramMemory_, int pageSize_, int numberOfHardDisks_);
	// Create new Process
	void createNewProcess(int priorityLevel_);
	// Load page into memory
	void loadPageIntoSystem();

	// Show State of Memory
	void showMemoryState();

	// Release Memory
	void releaseMemory(int PID_);
private:
	long int ramMemory = 0;
	int pageSize = 0, numberOfHardDisks = 0;
};

#endif
