#ifndef MEMORY_CPP
#define MEMORY_CPP

#include "Memory.h"

void Memory::allocateMemoryForProcess(int PID, int priorityLevel) {
   // Check if the process is the first process first, if yes, load page 0 into memory
}

void Memory::requestMemoryOperation(int memoryAddress) {
   // Caculate which page the current executing process is in
   pageNumber_ = ramMemory_ / memoryAddress;
}

void Memory::releaseMemory(int PID) {}

// Show State of Memory
// For each used frame display the process number that occupies it and the page number stored in it
void Memory::snapshotSystem() {}

#endif
