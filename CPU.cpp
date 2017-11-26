#ifndef CPU_CPP
#define CPU_CPP

#include "CPU.h"

void CPU::removeFromCPU(int& currPID, int& currPriorityLevel, string instructionType) {
   if (instructionType != "preemptive") {
      putInReadyQueue(currPID, currPriorityLevel);
      executeNextProcess(currPID, currPriorityLevel);
   } else {
      putInReadyQueue(currPID, currPriorityLevel);
      executeNextProcess(currPID, currPriorityLevel);
   }
}

void CPU::terminateTheCurrentProcess(int& currPID, int& currPriorityLevel) {
   // The process that currently uses the CPU terminates. It leaves the system immediately
   // Release the memory used by the current executing process
   Memory_.releaseMemory(currPID);
   Memory_.removeFromFrameTable(currPID);

   removeFromCPU(currPID, currPriorityLevel, "terminate");
}

void CPU::putInReadyQueue(int PID, int priorityLevel) {
   if (priorityLevel == 1) {
      ;
   } else {
      it = readyQueue_.find(priorityLevel);

      if (it == readyQueue_.end()) {
         queue<int> listOfProcess;
         listOfProcess.push(PID);

         cout << "Testing in CPU.cpp. Process " << PID << " is being put into Ready queue, with priorityLevel of " << priorityLevel << endl;

         readyQueue_.insert(pair<int, queue<int>>(priorityLevel-1, listOfProcess));
      } else {
         it = readyQueue_.find(priorityLevel-1);

         it->second.push(PID);
      }
   }
}

void CPU::showProcessInReadyQueue() {
   it = readyQueue_.begin();
   if (it == readyQueue_.end()) {
      cout << "Ready Queue is empty \n";
   } else {
      if (it->second.empty() || it->first == -1) {
         cout << "Ready Queue is Empty. \n";
      } else {
         it = readyQueue_.begin();

         cout << "Ready Queue: \n";
         queue<int> tempQueue = it->second;

         while (it != readyQueue_.end()) {
            while (!tempQueue.empty()) {
               cout << " Process: " << tempQueue.front() << " Priority Level: " << it->first+1 << endl;

               tempQueue.pop();
            }

            ++it;
         }
      }
   }
}

void CPU::executeNextProcess(int& currPID, int& currPriorityLevel) {
   // Find next process with highest priorityLevel
   it = readyQueue_.begin();
   if (it == readyQueue_.end()) {
      currPID = -1;
      currPriorityLevel = -1;

      cout << "No process in ready queue right now \n";
   } else if (!it->second.empty()){
      currPID = it->second.front();
      currPriorityLevel = it->first + 1;

      it->second.pop();

      if (it->second.empty()) {
         readyQueue_.erase(it);
      }
   }
}

#endif
