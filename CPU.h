#ifndef CPU_H
#define CPU_H

#include <map>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

#include "PCB.h"
#include "Memory.h"

const int max = INT_MAX;


class CPU {
public:
   CPU() {}
   ~CPU() {}

   int assignPID() { return PCB_.assignPID(); }

   void removeFromCPU(int& currPID, int& currPriorityLevel, string instructionType);
   void terminateTheCurrentProcess(int& currPID, int& currPriorityLevel);

   // Put process with PID into ReadyQueue
   void putInReadyQueue(int PID, int priorityLevel);
   // void showProcessInCPU(int currPID, int currPriorityLevel);
   void showProcessInReadyQueue();
   // Function to find next process to execute
   void executeNextProcess(int& currPID, int& currPriorityLevel);


   void setMemoryInfo(const long int ramMemory, int pageSize, int numOfFrames) {
      Memory_.setMemoryInfo(ramMemory, pageSize, numOfFrames);
   }

   // Functions related to Memory
   void snapshotSystem() { Memory_.snapshotSystem(); }
   void requestMemoryOperation(int PID, int memoryAddress_) { Memory_.requestMemoryOperation(PID, memoryAddress_); }
   void allocateMemoryForProcess(int PID, int priorityLevel) { Memory_.allocateMemoryForProcess(PID, priorityLevel); }

private:
   PCB PCB_;
   Memory Memory_;

   map<int, queue<int>, std::greater<int>> readyQueue_;
   map<int, queue<int>>::iterator it;
};

#endif
