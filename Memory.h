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

/***************************** Setter *****************************/
	void setMemoryInfo(long int ramMemory, int pageSize, int numOfFrames) { ramMemory_ = ramMemory; pageSize_ = pageSize; numOfFrames_ = numOfFrames; }

/***************************** Getter *****************************/
	long int getRamMemory() { return ramMemory_; }
	int getPageSize() { return pageSize_; }

/***************************** Regular *****************************/
	// Load page into memory
	void loadPageIntoSystem();
	// Allocate memory for process
	void allocateMemoryForProcess(int PID, int priorityLevel);
	// Function for m command
	void requestMemoryOperation(int PID, int memoryAddress, int pageNumber);
	// // Release Memory for current process
	// void releaseMemory(int PID);
	// Remove the information stored in Frame Table when a process terminates
	void removeFromFrameTable(int PID);

	// Show State of Memory
	void snapshotSystem();

private:
	long int ramMemory_;
	int pageSize_, timeStamp_ = 0, numOfFrames_ = 0;

	vector<FrameTable*> frameTable_;

	bool isTableFull = false;

	// Helper functions:
	//		1. Find empty slots in Frame table
	//		2. Place process in a certain position in frameTable
	// 	3. Update frame table
	// 	4. Replace current process with LRU process in frame table
	bool emptyTableSlot(int& rowPos);
	void placeInRowPos(int rowPos, int PID, int pageNumber);

	void updateFrameTable(int PID, int pageNumber);
	void replaceWithLRU(int PID, int pageNumber);
};

#endif
