#include "SystemManager.h"

void SystemManager::setMemoryInfo(unsigned int ramMemory, int pageSize, int numOfFrames) {
   ramMemory_ = ramMemory;
   pageSize_ = pageSize;
   numOfFrames_ = ramMemory / pageSize;

   CPU_.setMemoryInfo(ramMemory, pageSize, numOfFrames_);
}

void SystemManager::requestMemoryOperation(int memoryAddress) {
   pageNumber_ = memoryAddress/pageSize_;
   CPU_.requestMemoryOperation(currPID_, memoryAddress, pageNumber_);
}

void SystemManager::decideAction(int PID, int priorityLevel) {
   if (currPriorityLevel_ < priorityLevel) {
      // Put current executing process in ReadyQueue then execute new process
      cout << "new process coming in current process info:  " << currPID_ << " priorityLevel " << currPriorityLevel_ << endl;
      CPU_.putInReadyQueue(currPID_, currPriorityLevel_);
      // Update current executing process' info
      currPID_ = PID;
      currPriorityLevel_ = priorityLevel;
   } else {
      // put the new process in ready queue b/c it has lower priority than the current process
      CPU_.putInReadyQueue(PID, priorityLevel);
   }
}

void SystemManager::terminateTheCurrentProcess() {
   cout << "Terminating curr process in CPU with " << currPID_ << " priorityLevel " << currPriorityLevel_ << endl;

   CPU_.terminateTheCurrentProcess(currPID_, currPriorityLevel_);
}

void SystemManager::putInReadyQueue(int PID, int priorityLevel) {
   CPU_.putInReadyQueue(PID, priorityLevel);
}

void SystemManager::showProcessInCPU() {
   if (currPID_ == -1 || currPriorityLevel_ == -1 || currPID_ == 0 || currPriorityLevel_ == 0)
      cout << "There's no process executing in the CPU right now. \n";

   else
      cout << "CPU: \n Process: " << currPID_ << " Priority Level: " << currPriorityLevel_ << endl;

   CPU_.showProcessInReadyQueue();
}

void SystemManager::requestDiskAccess(int diskNumber, string fileName) {
   Devices_.requestDiskAccess(currPID_, diskNumber, fileName);

   //CPU_.putInReadyQueue(currPID_, currPriorityLevel_);
   CPU_.executeNextProcess(currPID_, currPriorityLevel_);
}
