#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
using namespace std;

#include "CPU.h"
#include "Devices.h"

class SystemManager {
public:

   // Setter
   void setMemoryInfo(unsigned int ramMemory, int pageSize, int numOfFrames);
   int assignPID() { return CPU_.assignPID(); }
   void setCurrPID(int PID, int priorityLevel) { currPID_ = PID; currPriorityLevel_ = priorityLevel; }

   // Getter
   int getCurrPID() { return currPID_; }
	unsigned int getRamMemory() { return ramMemory_; }
	int getPageSize() { return pageSize_; }


   void decideAction(int PID, int priorityLevel);
   void terminateTheCurrentProcess();
   void putInReadyQueue(int PID, int priorityLevel);
   void showProcessInCPU();
   // void showProcessInReadyQueue();

   void snapshotSystem() { CPU_.snapshotSystem(); }
   void requestMemoryOperation(int memoryAddress);
   void allocateMemoryForProcess(int PID, int priorityLevel) { CPU_.allocateMemoryForProcess(PID, priorityLevel); }

   // void getDeviceInfo() { Devices_.getDeviceInfo(); }
   void setHardDiskInfo(int numberOfHardDisks) { Devices_.setHardDiskInfo(numberOfHardDisks); }

   void releaseDisk(int diskNumber) { Devices_.releaseDisk(diskNumber); }
   void requestDiskAccess(int diskNumber, string fileName);
   void showProcessInHardDisk() { Devices_.showProcessInHardDisk(); }

private:
   CPU CPU_;
   Devices Devices_;

   int currPID_ = 0;
   int currPriorityLevel_ = 0;

   unsigned int ramMemory_;

	int pageSize_;
	int pageNumber_ = 0, numOfFrames_ = 0;

   // int memoryAddress_ = 0;
};

#endif
