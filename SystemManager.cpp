#include "SystemManager.h"

void SystemManager::setMemoryInfo(unsigned int ramMemory, int pageSize, int numOfFrames) {
   ramMemory_ = ramMemory;
   pageSize_ = pageSize;

   CPU_.setMemoryInfo(ramMemory, pageSize, ramMemory / pageSize);
}

void SystemManager::decideAction(int PID, int priorityLevel) {
   if (currPriorityLevel_ < priorityLevel) {
      // Put current executing process in ReadyQueue then execute new process
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
   if (currPID_ >= 1) {
      cout << "Terminating Process: \n\tPID: " << currPID_
           << " \n\tPriorityLevel " << currPriorityLevel_
           << endl;

      CPU_.terminateTheCurrentProcess(currPID_, currPriorityLevel_);
   } else {
      cout << "No process is currently using the CPU \n";
   }
}

void SystemManager::putInReadyQueue(int PID, int priorityLevel) {
   CPU_.putInReadyQueue(PID, priorityLevel);
}

void SystemManager::showProcessInCPU() {
   if (currPID_ == -1 || currPriorityLevel_ == -1 || currPID_ == 0 || currPriorityLevel_ == 0)
      cout << "There's no process executing in the CPU right now. \n";

   else
      cout << "USING CPU: \n\tPID: " << currPID_ << " \n\tPriorityLevel: " << currPriorityLevel_ << endl;

   CPU_.showProcessInReadyQueue();
}

void SystemManager::requestDiskAccess(int diskNumber, string fileName) {
   if (currPID_ >= 1) {
      Devices_.requestDiskAccess(currPID_, currPriorityLevel_, diskNumber, fileName);
      CPU_.executeNextProcess(currPID_, currPriorityLevel_);
   } else {
      cout << "Please add a process first \n";
   }
}

void SystemManager::releaseDisk(int diskNumber) {
   int PID, priorityLevel;
   Devices_.releaseDisk(diskNumber, PID, priorityLevel);
   decideAction(PID, priorityLevel);
}
