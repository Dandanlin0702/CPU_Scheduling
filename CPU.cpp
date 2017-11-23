#ifndef CPU_CPP
#define CPU_CPP

#include "CPU.h"

void CPU::decideAction(int PID, int priorityLevel) {
   if (currPriorityLevel_ < priorityLevel) {
      // Put current executing process in ReadyQueue then execute new process
      putInReadyQueue(currPID_, currPriorityLevel_);
      currPID_ = PID;
      currPriorityLevel_ = priorityLevel;
   } else {
      putInReadyQueue(PID, priorityLevel);
   }
}

void CPU::removeFromCPU() {
   putInReadyQueue(currPID_, currPriorityLevel_);
   executeNextProcess();
}

void CPU::putInReadyQueue(int PID, int priorityLevel) {
   it = readyQueue_.find(priorityLevel-1);

   if (it == readyQueue_.end()) {
      queue<int> listOfProcess;
      listOfProcess.push(PID);

      readyQueue_.insert(pair<int, queue<int>>(priorityLevel-1, listOfProcess));
   } else {
      it->second.push(PID);
   }
}

void CPU::terminateTheCurrentProcess() {
   // The process that currently uses the CPU terminates. It leaves the system immediately
   // Release the memory used by the current executing process
   Memory_.releaseMemory(currPID_);
   Memory_.removeFromFrameTable(currPID_);
   executeNextProcess();
}

void CPU::executeNextProcess() {
   // Find next process with highest priorityLevel
   it = readyQueue_.begin();
   if (readyQueue_.empty()) {
      currPID_ = 0;
      currPriorityLevel_ = 0;

      return;
   } else if (!it->second.empty()){
      currPID_ = it->second.front();
      currPriorityLevel_ = it->first + 1;

      it->second.pop();

      if (it->second.empty()) {
         readyQueue_.erase(it);
      }
   }
}


void CPU::showProcessInCPU() {
   if (currPID_ == 0)
      cout << "There's no process in the CPU right now. \n";

   else
      cout << "CPU: \n Process: " << currPID_ << ". Priority Level: " << currPriorityLevel_ << endl;
}
void CPU::showProcessInReadyQueue() {
   // Iterate through ReadyQueue show the process
   if (readyQueue_.empty()) {
      cout << "Ready Queue is empty \n";
   } else {
      it = readyQueue_.begin();

      if (it->second.empty()) {
         cout << "Ready Queue is Empty. \n";
      } else {
         cout << "Ready Queue: \n";
         queue<int> tempQueue = it->second;

         while (it != readyQueue_.end()) {
            while (!tempQueue.empty()) {
               cout << " Process: " << tempQueue.front() << " Priority Level: " << it->first+1 << endl;

               tempQueue.pop();
            }
         }
      }
   }

   return;
}

#endif
