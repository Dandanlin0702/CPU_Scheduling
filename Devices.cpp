#include "Devices.h"

void Devices::requestDiskAccess(int PID, int priorityLevel, int diskNumber, string fileName) {
   HardDisk* tempHardDisk = new HardDisk;

   tempHardDisk->PID_ = PID;
   tempHardDisk->priorityLevel_ = priorityLevel;
   tempHardDisk->fileName_ = fileName;
   tempHardDisk->isOccupied_ = true;

   it = hardDiskQueue_.find(diskNumber);
   if (it != hardDiskQueue_.end()) {
      it->second.push(tempHardDisk);
   } else {
      queue<HardDisk*> tempDiskQueue;
      tempDiskQueue.push(tempHardDisk);

      hardDiskQueue_.insert(pair<int, queue<HardDisk*> >(diskNumber, tempDiskQueue));
   }
}

void Devices::releaseDisk(int diskNumber, int& PID, int& priorityLevel) {
   it = hardDiskQueue_.find(diskNumber);
   
   if (it == hardDiskQueue_.end()) {
      cout << "Oops, there's no processes are using the hard disk " << diskNumber << ". \n";
   } else {
      if (it->second.empty()) {
         cout << "There's no process usig hard disk #" << diskNumber << endl;
      } else {
         cout << "Releasing Hard Disk #" << diskNumber << endl;

         PID = it->second.front()->PID_;
         priorityLevel = it->second.front()->priorityLevel_;

         it->second.pop();
      }
   }
}

/***************************** Command S *****************************/
void Devices::showProcessInHardDisk() {
   unordered_map<int, queue<HardDisk*> >hardDiskQueueCopy;
   hardDiskQueueCopy = hardDiskQueue_;

   if (hardDiskQueueCopy.size() == 0) {
      cout << "No process is using the Hard Disk ATM. \n";
   } else {
//      cout << "--------------------------------------------------------\n"
//           << "|                      In Hard Disk                    |\n"
//           << "--------------------------------------------------------\n";
       cout << "Hard Disk #";
      for (it = hardDiskQueueCopy.begin(); it != hardDiskQueueCopy.end(); ++it) {
         if (it->second.empty()) {
            cout << "No process in using Hard Disk #" << it->first << endl;
         } else {
             cout << it->first << ": \n\tPID: " << it->second.front()->PID_ << " \n\tFileName: " << it->second.front()->fileName_ << endl;
             
//            cout << "--------------------------------------------------------\n"
//                 << "|        DiskNumber" << "        PID" << "        File         |\n"
//                 << "--------------------------------------------------------\n";
//            cout << "|            " << it->first << "                "
//                 << it->second.front()->PID_ << "           "
//                 << it->second.front()->fileName_ << "         |\n"
//                 << "--------------------------------------------------------\n";

            it->second.pop();

            if (it->second.empty()) {
               cout << "No process is waiting for the Hard Disk # " << it->first << ". \n";
            } else {
//               cout << "--------------------------------------------------------\n"
//                    << "|                      Hard Disk Queue                 |\n"
//                    << "--------------------------------------------------------\n";
                cout << "Hard Disk Queue #";
               while (!it->second.empty()) {
                  if (it->second.front()->isOccupied_ == true) {
                      cout << it->first << ": \n\tPID: " << it->second.front()->PID_ << " \n\tFileName: " << it->second.front()->fileName_ << endl;
//                  cout << "--------------------------------------------------------\n"
//                       << "|        DiskNumber" << "        PID" << "        File      " << "   |\n"
//                       << "--------------------------------------------------------\n";
//                  cout << "|            " << it->first << "                "
//                       << it->second.front()->PID_ << "           "
//                       << it->second.front()->fileName_ << "        |\n"
//                       << "--------------------------------------------------------\n";
                  }
                  it->second.pop();
               }
            }
         }

         showProcessInWaitingQueue(it);
      }
   }
}

void Devices::showProcessInWaitingQueue(unordered_map<int, queue<HardDisk*> >::iterator it) {
   queue<HardDisk*> tempDiskQueue;

   tempDiskQueue = it->second;
   while (!tempDiskQueue.empty()) {
      cout << "\tWaiting Queue "
      << it->first << ": \n"
      << "\t\tProcess: " << tempDiskQueue.front()->PID_
      << "\n \t\tFile Name: " << tempDiskQueue.front()->fileName_
      << endl;

      tempDiskQueue.pop();
   }
}
