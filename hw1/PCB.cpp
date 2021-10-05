#ifndef PCB_CPP
#define PCB_CPP


#include "PCB.h"


//PCB Class, all functions from the header file are defined here.

//Default Constructor -- Set Default Values
PCB::PCB()
{
  pcbNum = 0;
  pcbPrioNum = 0;
  currentState = "NEW";
  
  
}

PCB::PCB(int id, int prio, string state)
{
  pcbNum = id;
  pcbPrioNum = prio;
  currentState = state;

}


PCB::~PCB()
{}


int PCB::getID()
{
  return pcbNum; // returns ID
}

void PCB::setID(int id)
{
  pcbNum = id; // Set ID
}


int PCB::getPrio()
{
  return pcbPrioNum; // return Priority num
}


 void PCB::setPrio(int prio)
 {
   pcbPrioNum = prio; // set Prio value
 }


  string PCB::getState()
  {
	  return currentState;
  }


void PCB::setState(string state)
{
  currentState = state; //set PCB state
}

#endif //END 
