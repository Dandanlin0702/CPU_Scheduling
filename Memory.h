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
   ~Memory() {}


	void getMemoryInfo();

/*****************************Setter*******************************/
	void setMemoryInfo(unsigned int ramMemory, int pageSize) { ramMemory_ = ramMemory; pageSize_ = pageSize; }
	void setMemoryAddress(int memoryAddress) { memoryAddress_ = memoryAddress; }
/*****************************Getter********************************/
	unsigned int getRamMemory() { return ramMemory_; }
	int getPageSize() { return pageSize_; }


	// Load page into memory
	void loadPageIntoSystem();
	// Allocate memory for process
	void allocateMemoryForProcess(int PID, int priorityLevel);
	// Function for m command
	void requestMemoryOperation(int PID);
	// Release Memory for current process
	void releaseMemory(int PID);
	// Show State of Memory
	void snapshotSystem();

private:
	unsigned int ramMemory_;
	int pageSize_;

	int timeStamp_ = 1, numOfFrames_ = 0;
	int memoryAddress_ = 0, pageNumber_ = 0;

	vector<FrameTable*> frameTable_;

	void updateFrameTable(int PID, int pageNumber);
	void replaceWithLRU(int PID, int pageNumber);
};

#endif
