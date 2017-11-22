#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <iostream>
using namespace std;

struct FrameTable {
	int timeStamp_ = 1;
	int pageNumber_ = 0;
	int PID_ = 0;
};

class Memory {
public:
	Memory() {}
   Memory(long int ramMemory, int pageSize, int numberOfHardDisks)
   : ramMemory_(ramMemory), pageSize_(pageSize), numberOfHardDisks_(numberOfHardDisks) {}
   ~Memory() {}

	// Allocate memory for process
	void allocateMemoryForProcess(int PID, int priorityLevel);
	// Function for m command
	void requestMemoryOperation(int PID, int memoryAddress);
	// Release Memory for current process
	void releaseMemory(int PID);
	// Show State of Memory
	void snapshotSystem();







	// Load page into memory
	void loadPageIntoSystem();



private:
	long int ramMemory_ = 0;
	int pageSize_ = 0, numberOfHardDisks_ = 0;

	int timeStamp_ = 1;
	int numOfFrames_ = ramMemory_/pageSize_;
	vector<FrameTable*> frameTable_;

	void updateFrameTable(int PID, int pageNumber);
	void replaceWithLRU(int PID, int pageNumber);
};

#endif
