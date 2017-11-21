#ifndef PCB_H
#define PCB_H

class PCB {
public:
   PCB();
   PCB(int priorityLevel) : priorityLevel_(priorityLevel) {}
   ~PCB();

   // Create PCB for process starts from 1
   int assignPID() { return PID_+1; }
   // Function to obtain the Process indentifier
   int getPID() { return PID_; }
   // Function to get priorityLevel
   int getPriorityLevel() { return priorityLevel_; }

private:
   int PID_ = 0;
   int priorityLevel_;
};

#endif
