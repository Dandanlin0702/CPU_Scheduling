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

   // Function to check whether the new process can preempt the current process or not
   void decideAction(int PID, int priorityLevel);
   // Put process with PID into ReadyQueue
   void putInReadyQueue(int PID, int priorityLevel);
   // Terminate the current executing process
   void terminateTheCurrentProcess();
   // Function to find next process to execute
   void executeNextProcess();

   // Functions for command 'S r', first, show the process in CPU. Then, show process in ReadyQueue
   void showProcessInCPU();
   void showProcessInReadyQueue();

private:
   int currPID_ = 0;
   int currPriorityLevel_ = 0;

   map<int, queue<int>, std::greater<int>> readyQueue_;
   map<int, queue<int>>::iterator it;

   PCB PCB_;
   Memory Memory_;
};

#endif
