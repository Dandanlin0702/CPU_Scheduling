#include "CPU.h"

void CPU::terminateTheCurrentProcess(int& currPID, int& currPriorityLevel) {
   Memory_.releaseMemory(currPID);
   Memory_.removeFromFrameTable(currPID);

   executeNextProcess(currPID, currPriorityLevel);
}

void CPU::putInReadyQueue(int PID, int priorityLevel) {
   it = readyQueue_.find(priorityLevel);

   if (it == readyQueue_.end()) {
      queue<int> listOfProcess;
      listOfProcess.push(PID);

      readyQueue_.insert(pair<int, queue<int>>(priorityLevel, listOfProcess));
   } else {
      it = readyQueue_.find(priorityLevel);

      it->second.push(PID);
   }
}

void CPU::showProcessInReadyQueue() {

   it = readyQueue_.begin();
   if (it == readyQueue_.end()) {
      cout << "Ready Queue is empty \n";
   } else {
      if (it->second.empty() || it->first == -1 || it->first == 0) {
         cout << "Ready Queue is Empty. \n";
      } else {
         it = readyQueue_.begin();

         cout << "Ready Queue: \n";

         while (it != readyQueue_.end()) {
            queue<int> tempQueue = it->second;
            while (!tempQueue.empty()) {
               if (it->first != 0 && tempQueue.front() != 0) {
                  cout << " Process: " << tempQueue.front() << " Priority Level: " << it->first << endl;
               }
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

      cout << "No process in ready queue right now \n" << "currPID is " << currPID << " currPriorityLevel is " << currPriorityLevel << endl;
   } else if (!it->second.empty()){
      currPID = it->second.front();
      currPriorityLevel = it->first;

      it->second.pop();

      if (it->second.empty()) {
         readyQueue_.erase(it);
      }
   }
}
