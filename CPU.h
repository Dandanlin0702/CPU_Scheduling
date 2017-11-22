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

   void setMemoryInfo(unsigned int ramMemory, int pageSize) { Memory_.setMemoryInfo(ramMemory, pageSize); }
   void setMemoryAddress(int memoryAddress) { Memory_.setMemoryAddress(memoryAddress); }

   int getCurrPID() { return currPID_; }

   // Function to check whether the new process can preempt the current process or not
   void decideAction(int PID, int priorityLevel);
   // Removecurrently executing process out CPU
   void removeFromCPU();
   // Put process with PID into ReadyQueue
   void putInReadyQueue(int PID, int priorityLevel);
   // Terminate the current executing process
   void terminateTheCurrentProcess();
   // Function to find next process to execute
   void executeNextProcess();

   // Function relate to PCB
   int assignPID() { return PCB_.assignPID(); };

   // Functions related to Memory
   void snapshotSystem() { Memory_.snapshotSystem(); }
   void requestMemoryOperation(int PID) { Memory_.requestMemoryOperation(PID); }
   void allocateMemoryForProcess(int PID, int priorityLevel) { Memory_.allocateMemoryForProcess(PID, priorityLevel); }


   // Functions for command 'S r', first, show the process in CPU. Then, show process in ReadyQueue
   void showProcessInCPU();
   void showProcessInReadyQueue();


private:
   PCB PCB_;
   Memory Memory_;

   int currPID_ = 0;
   int currPriorityLevel_ = 0;

   map<int, queue<int>, std::greater<int>> readyQueue_;
   map<int, queue<int>>::iterator it;
};

#endif
