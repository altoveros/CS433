#include "PCB.h"
#include <iostream>

// TODO: Add your implementation here

using namespace std;

PCB::PCB() //Setting default constructors
{
  id = "";
  priority = 0;
  burst = 0;
  waiting = 0;
  state = ProcState::NEW; 
}


PCB::~PCB(){} //Deconstructor


PCB::PCB(string task, int newPrio, int newBurst)
{
  id = task;
  priority = newPrio;
  burst = newBurst;
  
  
}


PCBTable::PCBTable()
{

}

PCBTable::~PCBTable()
{

}





void PCBTable::add(PCB* p)
{
  table[Num] = *p;
  Num++;
  
}






