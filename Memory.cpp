#include "Memory.h"

void Memory::allocateMemoryForProcess(int PID, int priorityLevel) {
   // Check if the process is the first process created, if yes, load page 0 into memory
   cout << "Testing: ram: " << ramMemory_ << " nnn " << pageSize_ << endl;
   cout << " total num of frames " << numOfFrames_ << endl;

   if (PID == 1) {
      FrameTable* tempTable = new FrameTable;

      // If current process id == 1, mean it is the very first process we created
      // So, load page #0 to frameTable #0
      tempTable->timeStamp_ = timeStamp_;
      tempTable->pageNumber_ = 0;
      tempTable->PID_ = PID;

      frameTable_.push_back(tempTable);
   }
}

void Memory::requestMemoryOperation(int PID, int memoryAddress, int pageNumber) {
   timeStamp_ += 1;

   if (memoryAddress > ramMemory_) {
      cout << "The memory address you entered is not valid \n"
           << "Please enter a memory address within range: (1~) " << ramMemory_ << endl;
   } else {
      // Check if the pageNumber is already been used but process PID
      for (int i = 0; i < frameTable_.size(); ++i) {
         if (frameTable_[i]->PID_ == PID && frameTable_[i]->pageNumber_ == pageNumber) {
            frameTable_[i]->timeStamp_ = timeStamp_;

            return;
         }
      }

      updateFrameTable(PID, pageNumber);
   }
}

/********************************Helper Function*****************/
void Memory::updateFrameTable(int PID, int pageNumber) {
   // Check if memory if full or not, if yes, remove LRU process
   cout << " Testing: curr frametable size is: " << frameTable_.size()
        << "\nTesting: curr numOfFrames_ is: " <<numOfFrames_ << endl;

   if (isTableFull) {
      // When frame table is full
      int rowPos = -1;
      // First, find empty table slots
      if (emptyTableSlot(rowPos)) {
         // Place current process in the empty row
         placeInRowPos(rowPos, PID, pageNumber);
      } else {
         cout << "Replacing LRU process in FrameTable with current process \n";
         // Otherwise, replace with the LRU process
         replaceWithLRU(PID, pageNumber);
      }
   } else {
      FrameTable* tempFrame = new FrameTable;

      tempFrame->pageNumber_ = pageNumber;
      tempFrame->PID_ = PID;
      tempFrame->timeStamp_ = timeStamp_;

      frameTable_.push_back(tempFrame);

      if (frameTable_.size() == numOfFrames_) {
         isTableFull = true;
      }
   }
}

void Memory::replaceWithLRU(int PID, int pageNumber) {
   int rowPos = 0, leastTime_ = frameTable_[0]->timeStamp_;
   // Iterate through the frametable find the LRU process
   for (int i = 1; i < frameTable_.size(); ++i) {
      if (frameTable_[i]->timeStamp_ < leastTime_) {
         rowPos = i;
      }
   }

   placeInRowPos(rowPos, PID, pageNumber);
}

// Show State of Memory
// For each used frame display the process number that occupies it and the page number stored in it
void Memory::snapshotSystem() {
   cout << "--------------------------------------------------------\n"
        << "|    FrameNumber" << "    PageNumber" << "    PID" << "    TimeStamp     |\n"
        << "--------------------------------------------------------\n";
   for (int i = 0; i < frameTable_.size(); ++i) {
      cout << "|       " << i << "               "
           << frameTable_[i]->pageNumber_ << "          "
           << frameTable_[i]->PID_ << "          "
           << frameTable_[i]->timeStamp_ << "        |"
           << endl;
      cout << "--------------------------------------------------------\n";
   }
}

void Memory::releaseMemory(int PID) {}

void Memory::removeFromFrameTable(int PID) {
   if (frameTable_.size() != 0) {
      for (int i = 0; i < frameTable_.size(); ++i) {
         if (frameTable_[i]->PID_ == PID) {
            // frameTable_[i] = nullptr;
            frameTable_[i]->PID_ = -1;
            frameTable_[i]->pageNumber_ = -1;
            frameTable_[i]->timeStamp_ = -1;

            break;
         }
      }
   }
}

bool Memory::emptyTableSlot(int& rowPos) {
   cout << "Looking for empty slots in frame table \n";
   for (int i = 0; i < frameTable_.size(); ++i) {
      if (frameTable_[i]->PID_ == -1) {
         return true;
      }
   }

   return false;
}

void Memory::placeInRowPos(int rowPos, int PID, int pageNumber) {
   frameTable_[rowPos]->PID_ = PID;
   frameTable_[rowPos]->timeStamp_ = timeStamp_;
   frameTable_[rowPos]->pageNumber_ = pageNumber;
}
