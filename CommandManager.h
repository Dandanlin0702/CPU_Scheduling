
/*
#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
using namespace std;

#include "Devices.h"

class CommandManager {
public:

   // CPU related functions
   int assignPID() { return CPU_.assignPID(); }
   int getCurrPID() { return CPU_.getCurrPID(); }

   void decideAction(int PID, int priorityLevel)
   void terminateTheCurrentProcess();
   void showProcessInCPU();
   void showProcessInReadyQueue();

   void snapshotSystem();
   void requestMemoryOperation(int PID, int memoryAddress);
   void allocateMemoryForProcess(int PID, int priorityLevel);

   void releaseDisk(int diskNumber);
   void requestDiskAccess(int diskNumber, string fileName);
   void showProcessInHardDisk();


private:
   CPU CPU_;
   Devices Devices_;
};

#endif
*/
