#include "Devices.h"

void Devices::requestDiskAccess(int diskNumber, string fileName) {
   CPU_.removeFromCPU();

   if (diskNumber >= hardDisk_.size()) {
      cout << "Sorry you entered an invalid diskNumber, please try again \n>>";

      return;
   } else {
      hardDisk_[diskNumber-1]->PID_ = CPU_.getCurrPID();
      hardDisk_[diskNumber-1]->fileName_ = fileName;
      hardDisk_[diskNumber-1]->isOccupied_ = true;
   }
}

void Devices::releaseDisk(int diskNumber) {

}

/****************Command S****************************************/
void Devices::showProcessInHardDisk() {
   if (hardDisk_.size() == 0) {
      cout << "No process is using the Hard Disk ATM. \n";
   } else {
      for (int i = 0; i < hardDisk_.size(); ++i) {
         if (hardDisk_[i]->isOccupied_ == true) {
            cout << "Hard Disk " << i << ": process " << hardDisk_[i]->PID_ << endl;

            showProcessInWaitingQueue(i);
         }
      }
   }
}

void Devices::showProcessInWaitingQueue(int hardDiskNumber) {

}

//For each busy hard disk show the process that uses it and show its I/O-queue. Make sure to display the filenames for each process.
void Devices::showIOQueue(int hardDiskNumber) {

}
// Get filename for process with PID number PID_
void Devices::getFileName(int PID) {

}
