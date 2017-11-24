#include "SystemManager.h"

void SystemManager::setMemoryInfo(unsigned int ramMemory, int pageSize, int numOfFrames) {
   CPU_.setMemoryInfo(ramMemory, pageSize, numOfFrames);
   ramMemory_ = ramMemory;
   pageSize_ = pageSize;
   numOfFrames_ = ramMemory / pageSize;
}

void SystemManager::setMemoryAddress(int memoryAddress) {
   memoryAddress_ = memoryAddress;
   pageNumber_ = memoryAddress_/pageSize_;
}

void SystemManager::decideAction(int PID, int priorityLevel) {
   if (currPriorityLevel_ < priorityLevel) {
      // Put current executing process in ReadyQueue then execute new process
      CPU_.putInReadyQueue(currPID_, currPriorityLevel_);
      currPID_ = PID;
      currPriorityLevel_ = priorityLevel;
   } else {
      CPU_.putInReadyQueue(PID, priorityLevel);
   }
}

void SystemManager::terminateTheCurrentProcess(int& currPID_, int& currPriorityLevel_) {
   CPU_.terminateTheCurrentProcess(currPID_, currPriorityLevel_);
}

void SystemManager::putInReadyQueue(int PID, int priorityLevel) {
   CPU_.putInReadyQueue(PID, priorityLevel);
}

void SystemManager::showProcessInCPU() {
   if (currPriorityLevel_ == 0 || currPriorityLevel_ == -1)
      cout << "There's no process in the CPU right now. \n";

   else
      cout << "CPU: \n Process: " << currPID_ << " Priority Level: " << currPriorityLevel_ << endl;
}

void SystemManager::showProcessInReadyQueue() {
   CPU_.showProcessInReadyQueue();
}


void SystemManager::requestDiskAccess(int diskNumber, string fileName) {
   Devices_.requestDiskAccess(currPID_, diskNumber, fileName);
   CPU_.removeFromCPU(currPID_, currPriorityLevel_, "disk");
}
