#include "Devices.h"

void Devices::requestDiskAccess(int diskNumber, string fileName) {
   cout << "Total disk num is :" << numberOfHardDisks_ << endl;

   if (diskNumber > numberOfHardDisks_) {
      cout << "Sorry you entered an invalid diskNumber, please try again \n";

      return;
   } else {
      HardDisk* tempHardDisk = new HardDisk;
      queue<HardDisk*> tempDiskQueue;

      tempHardDisk->PID_ = CPU_.getCurrPID();
      tempHardDisk->fileName_ = fileName;
      tempHardDisk->isOccupied_ = true;

      tempDiskQueue.push(tempHardDisk);
      hardDisk_.push_back(tempDiskQueue);
   }

   CPU_.removeFromCPU();
}

void Devices::releaseDisk(int diskNumber) {

}

/***************************** Command S *****************************/
void Devices::showProcessInHardDisk() {
   if (hardDisk_.size() == 0) {
      cout << "No process is using the Hard Disk ATM. \n";
   } else {
      for (int i = 0; i < hardDisk_.size(); ++i) {
         if (hardDisk_[i].front()->isOccupied_ == true) {
            cout << "Hard Disk " << i+1 << ": process " << hardDisk_[i].front()->PID_ << endl;
         }

         showProcessInWaitingQueue(i);
      }
   }
}

void Devices::showProcessInWaitingQueue(int hardDiskNumber) {
   queue<HardDisk*> tempDiskQueue;

   tempDiskQueue = hardDisk_[hardDiskNumber];
   while (!tempDiskQueue.empty()) {
      cout << "Following processes are waiting to access to hard disk number "
           << hardDiskNumber+1 << ": \n"
           << " Process: " << tempDiskQueue.front()->PID_
           << endl;

      tempDiskQueue.pop();
   }
}

//For each busy hard disk show the process that uses it and show its I/O-queue. Make sure to display the filenames for each process.
void Devices::showIOQueue(int hardDiskNumber) {

}
// Get filename for process with PID number PID_
void Devices::getFileName(int PID) {

}
