#include "Memory.h"

void Memory::allocateMemoryForProcess(int PID, int priorityLevel) {
   // Check if the process is the first process created, if yes, load page 0 into memory
   if (PID == 1) {
      FrameTable* tempTable = new FrameTable;

      // If current process id == 1, mean it is the very first process we created
      // So, load page #0 to frameTable #0
      tempTable->timeStamp_ = 1;
      tempTable->pageNumber_ = 0;
      tempTable->PID_ = PID;

      frameTable_.push_back(tempTable);
   }
}

void Memory::requestMemoryOperation(int PID) {
   // Caculate which page the current executing process is in
   //pageNumber_ =memoryAddress_ / pageSize_;
   updateFrameTable(PID, pageNumber_);
}

void Memory::releaseMemory(int PID) {}

// Show State of Memory
// For each used frame display the process number that occupies it and the page number stored in it
void Memory::snapshotSystem() {
   cout << "--------------------------------------------------------\n"
        << "|   FrameNumber" << "  |  PageNumber" << "  |  PID" << "  |  TimeStamp   |\n"
        << "--------------------------------------------------------\n";
   for (int i = 0; i < frameTable_.size(); ++i) {
      cout << "|       " << i << "        |      "
           << frameTable_[i]->pageNumber_ << "       |   "
           << frameTable_[i]->PID_ << "   |      "
           << frameTable_[i]->timeStamp_ << "       |"
           << endl;
      cout << "--------------------------------------------------------\n";
   }
}

/********************************Helper Function*****************/
void Memory::updateFrameTable(int PID, int pageNumber) {
   // Check if memory if full or not, if yes, remove LRU process
   int currFrameTableNum_ = frameTable_.size();
   if (currFrameTableNum_ == numOfFrames_) {
      replaceWithLRU(PID, pageNumber);
   } else {
      FrameTable* tempFrame = new FrameTable;

      timeStamp_= timeStamp_ += 1;
      tempFrame->pageNumber_ = pageNumber;
      tempFrame->PID_ = PID;
      tempFrame->timeStamp_ = timeStamp_;

      frameTable_.push_back(tempFrame);
   }
}

void Memory::replaceWithLRU(int PID, int pageNumber) {
   int frameNumWithLRU_ = -1, leastTime_ = frameTable_[0]->timeStamp_ ;
   // Iterate through the frametable find the LRU process
   for (int i = 1; i < frameTable_.size(); ++i) {
      if (frameTable_[i]->timeStamp_ < leastTime_) {
         frameNumWithLRU_ = i;
      }
   }

   // Replace the process with LRU with current process
   frameTable_[frameNumWithLRU_]->pageNumber_ = pageNumber;
   frameTable_[frameNumWithLRU_]->PID_ = PID;
   frameTable_[frameNumWithLRU_]->timeStamp_ = timeStamp_+1;
}
