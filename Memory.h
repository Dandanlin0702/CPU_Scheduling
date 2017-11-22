#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <iostream>

using namespace std;

struct FrameTable {
	int timeStamp_;
	int pageNumber_ = 0;
	int PID_ = 0;
};

class Memory {
public:
	Memory() {}
   Memory(long int ramMemory, int pageSize)
   : ramMemory_(ramMemory), pageSize_(pageSize), numOfFrames_(ramMemory/pageSize) {}
   ~Memory() {}

	// Load page into memory
	void loadPageIntoSystem();

	// Allocate memory for process
	void allocateMemoryForProcess(int PID, int priorityLevel);
	// Function for m command
	void requestMemoryOperation(int PID, int memoryAddress);
	// Release Memory for current process
	void releaseMemory(int PID);
	// Show State of Memory
	void snapshotSystem();

private:
	long int ramMemory_ = 0;
	int pageSize_ = 0;

	int timeStamp_ = 1;
	int numOfFrames_ = 0;;
	vector<FrameTable*> frameTable_;

	void updateFrameTable(int PID, int pageNumber);
	void replaceWithLRU(int PID, int pageNumber);
};

#endif
