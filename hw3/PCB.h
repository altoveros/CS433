#pragma once
#include <iostream>

using namespace std;

static int const MAX = 30;

// Remember to add comments to your code
// ...

// enum class of process state
// A process (PCB) in ready queue should be in READY state
enum class ProcState {NEW, READY, RUNNING, WAITING, TERMINATED};

/* 
Process control block(PCB) is a data structure representing a process in the system.
A process should have at least an ID and a state(i.e.NEW, READY, RUNNING, WAITING or TERMINATED).
It may also have other attributes, such as scheduling information (e.g. priority)
*/
class PCB {
public:
    // The unique process ID
	string id;
    // The priority of a process valued between 1-50. Larger number represents higher priority
	unsigned int priority;
	// The current state of the process.
  unsigned int burst;
  
  unsigned int waiting;
	// A process in the ReadyQueue should be in READY state
	ProcState state;
  
  int quantum;

	// TODO: Add constructor and other necessary functions for the PCB class
  PCB(); //Default Constructor 
  PCB(string, int, int); //Overloaded Constructor which takes the task #, priority, and burst length)
  ~PCB(); //Deconstructor~
  
  
};

/*
An array(list) of all PCB elements in the system.
*/
class PCBTable {
	// TODO: Add your implementation of the PCBTable
  
  
  //Default constructor for PCBTable
  public:
    PCBTable();
    ~PCBTable();
  
  
  
  //FUNCTIONS 
  void add(PCB *pcb); 
  PCB table[MAX];
  
  
  //Private Values
  private:
  int Num;

  


  

};