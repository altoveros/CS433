#ifndef PCB_H
#define PCB_H

#include <iostream>
#include <fstream>


using namespace std;

// DESCRIPTION: PCB Header, has all the functions known to the PCB class

class PCB
{
  private:
    int pcbNum;
    int pcbPrioNum;
    string currentState;

public:
  PCB(); //Def Constructor
  PCB(int id, int prio,string state);
  ~PCB(); //Desconstructor
  
  
  // -PROCESSES TO BE DEFINED IN PCB.CPP- //
  
  int getID(); // get Process ID
  void setID(int id); // set Process ID
  
  int getPrio(); //return Priority ID
  void setPrio(int prio); // set Priority ID
  
  string getState(); // get State
  void setState(string state); // Set State

};

#endif