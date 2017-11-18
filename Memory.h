#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
using namespace std;

class Memory {
public:
	Memory() {}
   Memory(long int ramMemory_, int pageSize_, int numberOfHardDisks_)
   : ramMemory(ramMemory_), pageSize(pageSize_), numberOfHardDisks(numberOfHardDisks_) {}
   ~Memory() {}

   void setUpSystem(long int ramMemory_, int pageSize_, int numberOfHardDisks_);
   // Fucntion for command 'S'
   void showCurrentMemoryState();
private:
	long int ramMemory = 0;
	int pageSize = 0, numberOfHardDisks = 0;
};

#endif
