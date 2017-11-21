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

void CPU::putInReadyQueue(int PID, int priorityLevel) {
   
}

void CPU::terminateTheCurrentProcess() {
   // The process that currently uses the CPU terminates. It leaves the system immediately
   nextProcessToExecute();

   // Release the memory used by the current executing process
   Memory_.releaseMemory(PCB_.getPID());
}

void CPU::nextProcessToExecute() {
   // Find next process with highest priorityLevel

}

void CPU::showProcessInCPU() {
   //
}
void CPU::showProcessInReadyQueue() {
   // Iterate through ReadyQueue show the process
}

#endif
