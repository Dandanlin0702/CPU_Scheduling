#ifndef CPU_CPP
#define CPU_CPP

#include "CPU.h"

void CPU::terminateTheCurrentProcess() {
   // The process that currently uses the CPU terminates. It leaves the system immediately


   // Release the memory used by the process
   Memory_.releaseMemory(getProcessIdentifier());
}

void CPU::showProcessInCPU() {

}
void CPU::showProcessInReadyQueue() {

}


int CPU::getProcessIdentifier() {

}

#endif
