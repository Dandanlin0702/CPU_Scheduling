#include "Start_App.h"
#include "User_Command.h"

void StartApp::runApp() {
   // Variable to store user commands
   string userCommand;
   UserCommand userCommand_;

   unsigned int ramMemory = 0, pageSize = 0, numberOfHardDisks = 0;
   cout << "How much RAM memory(in bytes) is there on the simulated computer? (Range from 1-4000000000)";
   cin >> ramMemory;

   while (ramMemory > 4,000,000,000 || ramMemory < 1) {
      cout << "Please enter a valid RAM memory (Range from 1-4000000000)";
      cin >> ramMemory;
   }

   cout << "What is the size of a page/frame?";
   cin >> pageSize;

   cout << "How many hard disks the simulated computer has?";
   cin >> numberOfHardDisks;

   setUpSystem (pageSize, numberOfHardDisks);

   cout << "Input 'H' or 'h' for help \n"
        << "Enter 'Q' or 'q' to end the program \n"
        << "Else, please enter command: ";

   // While loop keeps reading user's input
   do {
      cout << "> ";

      getline (cin, userCommand);

      switch (userCommand.at(0)) {
         case 'Q':
            cout << "Program terminatting";
            exit(1);
         case 'q':
            cout << "Program terminatting";
            exit(1);
         case 'H':
            helpMenu();
         case 'h':
            helpMenu();
         case 'A':
            userCommand_.createNewProcess(userCommand);
         case 'D':
            userCommand_.releaseDisk(userCommand);
         case 'd':
            userCommand_.requestDiskAccess(userCommand);
         case 't':
            userCommand_.terminateTheCurrentProcess();
         case 'm':
            userCommand_.requestMemoryAccess(userCommand);
         case 'S':
            userCommand_.showDetails(userCommand);
         default:
            cout << "Unknown command. Please type 'H' or 'h' for help. \n";
      }

      cout << "\n";
   } while (true);
}

void StartApp::setUpSystem(int pageSize_, int numberOfHardDisks_) {

}

string StartApp::helpMenu () {
   stringstream ss;
   ss << "Following are the commands you can use: "
      // Interrupts:
      << "Create a new process: \n  \"A \"\n"
      << "\"S \" \n"
      << "Release a disk: \"D \" \n"

      // System Calls: Lower Case
      << "Request a disk: \"d \" \n"
      << "Terminate a process: \"t \" \n"
      << "Show the PIDs of the processes in the Ready Queue: \"r \" \n"
      << "Show the PIDs and printer specic information of the processes in the PRINTER queues: \"p \" \n"
      << "Show the PIDs and printer specic information of the processes in the DISK queues: \"d \" \n"
      << "Show the CD/RW queues: \"c \" \n";

   return ss.str();
}
