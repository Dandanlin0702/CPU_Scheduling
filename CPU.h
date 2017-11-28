#ifndef CPU_H
#define CPU_H

#include <map>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

#include "PCB.h"
#include "Memory.h"

class CPU {
public:
   CPU() {}
   ~CPU() {}

   int assignPID() { return PCB_.assignPID(); }

   // Function to terminate current executing process
   void terminateTheCurrentProcess(int& currPID, int& currPriorityLevel);

   // Functiosn for:
   //    1. Put process with PID into ReadyQueue
   //    2. Show process in ready queue
   void putInReadyQueue(int PID, int priorityLevel);
   void showProcessInReadyQueue();

   // Function to find next process to execute
   void executeNextProcess(int& currPID, int& currPriorityLevel);

   // Function for setting up memory system
   void setMemoryInfo(const long int ramMemory, int pageSize, int numOfFrames) {
      Memory_.setMemoryInfo(ramMemory, pageSize, numOfFrames);
   }

   // Functions related to Memory
   void snapshotSystem() { Memory_.snapshotSystem(); }
   void requestMemoryOperation(int PID, int memoryAddress, int pageNumber) {
      Memory_.requestMemoryOperation(PID, memoryAddress, pageNumber);
   }
   void allocateMemoryForProcess(int PID, int priorityLevel) { Memory_.allocateMemoryForProcess(PID, priorityLevel); }

private:
   PCB PCB_;
   Memory Memory_;

   map<int, queue<int>, std::greater<int>> readyQueue_;
   map<int, queue<int>>::iterator it;
};

#endif
