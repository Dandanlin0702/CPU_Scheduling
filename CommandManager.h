#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
using namespace std;

#include "Devices.h"

class CommandManager {
public:
   // System Set up
   void setMemoryInfo(unsigned int ramMemory, int pageSize, int numOfFrames) { CPU_.setMemoryInfo(ramMemory, pageSize, numOfFrames); }

   // CPU related functions
   int assignPID() { return CPU_.assignPID(); }
   int getCurrPID() { return CPU_.getCurrPID(); }

   void decideAction(int PID, int priorityLevel) { CPU_.decideAction(PID, priorityLevel); }
   void terminateTheCurrentProcess() { CPU_.terminateTheCurrentProcess(); }
   void showProcessInCPU() { CPU_.showProcessInCPU(); }
   void showProcessInReadyQueue() { CPU_.showProcessInReadyQueue(); }

   void setMemoryAddress(int memoryAddress) { CPU_.setMemoryAddress(memoryAddress); }
   void snapshotSystem() { CPU_.snapshotSystem(); }
   void requestMemoryOperation(int PID) { CPU_.requestMemoryOperation(PID); }
   void allocateMemoryForProcess(int PID, int priorityLevel) { CPU_.allocateMemoryForProcess(PID, priorityLevel); }

   void setHardDiskInfo(int numberOfHardDisks) { Devices_.setHardDiskInfo(numberOfHardDisks); }
   void releaseDisk(int diskNumber) { Devices_.releaseDisk(diskNumber); }
   void requestDiskAccess(int diskNumber, string fileName) { Devices_.requestDiskAccess(diskNumber, fileName); }
   void showProcessInHardDisk() { Devices_.showProcessInHardDisk(); }


private:
   CPU CPU_;
   Devices Devices_;
};

#endif
