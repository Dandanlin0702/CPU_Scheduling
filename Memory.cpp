#include "Memory.h"

void Memory::allocateMemoryForProcess(int PID, int priorityLevel) {
   updateFrameTable(PID, 0);
}

void Memory::requestMemoryOperation(int PID, int memoryAddress, int pageNumber) {
   if (memoryAddress > ramMemory_) {
      cout << "The memory address you entered is not valid \n"
           << "Please enter a memory address within range: (1~) "
           << ramMemory_ << endl;
   } else {
      // Check if the pageNumber is already been used but process PID
      for (unsigned int i = 0; i < frameTable_.size(); ++i) {
         if (frameTable_[i]->PID_ == PID && frameTable_[i]->pageNumber_ == pageNumber) {
            timeStamp_ += 1;
            frameTable_[i]->timeStamp_ = timeStamp_;

            return;
         }
      }

      updateFrameTable(PID, pageNumber);
   }
}

/******************************** Helper Functions ****************************/
void Memory::updateFrameTable(int PID, int pageNumber) {
   timeStamp_ += 1;
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
      for (unsigned int i = 1; i < frameTable_.size(); ++i) {
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
        << "|                      Frame Table                     |\n"
        << "--------------------------------------------------------\n"
        << "--------------------------------------------------------\n"
        << "|    FrameNumber" << "    PageNumber" << "    PID" << "    TimeStamp     |\n"
        << "--------------------------------------------------------\n";
   for (unsigned int i = 0; i < frameTable_.size(); ++i) {
       cout << "|       " << i << "               "
            << frameTable_[i]->pageNumber_ << "          "
            << frameTable_[i]->PID_ << "          "
            << frameTable_[i]->timeStamp_ << "        |"
            << endl;
       cout << "--------------------------------------------------------\n";
   }
}

// void Memory::releaseMemory(int PID) {
// }

void Memory::removeFromFrameTable(int PID) {
   if (frameTable_.size() != 0) {
      for (unsigned int i = 0; i < frameTable_.size(); ++i) {
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
   for (unsigned int i = 0; i < frameTable_.size(); ++i) {
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
