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

   // Functions to
   //    1. Decides where to put new process: CPU or ReadyQueue
   //    2. Terminates current process
   //    3. Put process in ReadyQueue
   //    4. Show process that is currently using CPU
   void decideAction(int PID, int priorityLevel);
   void terminateTheCurrentProcess();
   void putInReadyQueue(int PID, int priorityLevel);
   void showProcessInCPU();

   // Functions:
   //    1. Snap shot the memory system
   //    2. For command 'm', request memory operation
   //    3. Allocate memory for new processes
   void snapshotSystem() { CPU_.snapshotSystem(); }
   void requestMemoryOperation(int memoryAddress) { CPU_.requestMemoryOperation(currPID_, memoryAddress, memoryAddress/pageSize_); }
   void allocateMemoryForProcess(int PID, int priorityLevel) { CPU_.allocateMemoryForProcess(PID, priorityLevel); }


   // Functions:
   //    1. Set numberOfHardDisks
   //    2. Release a disk
   //    3. For command 'd', request disk access
   //    4. Shwo Processes in Hard Disk
   void setHardDiskInfo(int numberOfHardDisks) { Devices_.setHardDiskInfo(numberOfHardDisks); }
   void releaseDisk(int diskNumber) { Devices_.releaseDisk(diskNumber); }
   void requestDiskAccess(int diskNumber, string fileName);
   void showProcessInHardDisk() { Devices_.showProcessInHardDisk(); }

private:
   CPU CPU_;
   Devices Devices_;

   // Two integer variables to track the PID and PriorityLevel of current executing process
   int currPID_ = 0, currPriorityLevel_ = 0;

   unsigned int ramMemory_;
   int pageSize_;
};

#endif
