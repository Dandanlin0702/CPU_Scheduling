#include "UserCommand.h"

void UserCommand::createNewProcess(string userCommand_) {
   // Obtain the priority level of new process
   int priorityLevel = stoi(userCommand_.substr(2, userCommand_.size()-1));

   if (priorityLevel < 1) {
      cout << "ERROR \n Please enter a valid priority level. \n";
   }

   cout << "// Testing: this process has priority level of \n" << priorityLevel << endl;
}

void UserCommand::releaseDisk(string userCommand_) {
   size_t diskNumber = userCommand_.at(2);

   
}

void UserCommand::requestDiskAccess(string userCommand_) {

}

void UserCommand::terminateTheCurrentProcess() {

}

void UserCommand::requestMemoryAccess(string userCommand_) {
   size_t memoryAddress = userCommand_.at(2);


}

void UserCommand::showDetails(string userCommand_) {
   // Check is the command is S r
   if (userCommand_.at(2) == 'r') {
      // When command is S r call commandSR() function
      commandSR();
   } else if (userCommand_.at(2) == 'i') {
      // When command is S i
      commandSI();
   } else if (userCommand_.at(2) == 'm') {
      // When command is S m
      commandSM();
   } else {
      cout << "Sorry you entered an unknown command \n";
   }

   return;
}

// Function to show
   // 1. what process is currently using the cpu
   // 2. What processed are waiting in the ready-queue
void UserCommand::commandSR () {
   CPU_.showCurrentProcess();
   CPU_.showProcessInReadyQueue();
}

// Function to show
   // 1. What processes are currently using the hard disks
   // 2. What processes are waiting to use the hard disk
   // For each busy hard disk show the process that uses it and show its I/O-queue. Make sure to display the filenames for each process.
void UserCommand::commandSI () {

}

// Function to show
   // Shows the state of memory.
   // For each used frame display the process number that occupies it and the page number stored in it
void UserCommand::commandSM () {
   Memory_.showCurrentMemoryState();
}
