


#include "ReadyQueue.h"
#include "PCB.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>


using namespace std;

//ReadyQueue class, all functions are defined here.

ReadyQueue::ReadyQueue() //Default constructor
{
  
 vector<PCB>  readyQueue; //CREATE a PCB vector
 current_size = 0;
 max_size = 30;
 removedID = 0;
}


ReadyQueue::~ReadyQueue() //Deconstructor
{
  
}


 int ReadyQueue::parent(int i) //Helper function to find the parent node
 {
   //return i / 2;
  return (i-1)/2;
 }

int ReadyQueue::left(int i) // Helper function to find the left node
{
  return i * 2;
  //return (2*i+1);
}
  
int ReadyQueue::right(int i) //Helper function to find the right node
{

  return (2*i+2);
}

void ReadyQueue::swap(PCB* z, PCB* y) // Helper function to swap values in the PCB vector.
{
  PCB var = *z;
  *z = *y;
  *y = var;
}

bool ReadyQueue::isLeaf(int i)
{
	return (i < current_size/2) ? false : true;
}

void ReadyQueue::heapify_Up(int i) //A recursive function to find the parent node.
{
  if(i > current_size) return;
  if( i == 1) return;
  
  
    if(readyQueue[i].getPrio() > readyQueue[parent(i)].getPrio()) //IF the child is bigger than the bigger node, swap and call heapify once more.
  {
    swap(&readyQueue[parent(i)], &readyQueue[i]);
    heapify_Up(parent(i));

  }
   
 
}



void ReadyQueue::heapify_Down(int i)
{
  if (i > current_size) return;
  int swapID = i;
  
  if(left(i) <= current_size && readyQueue[i].getPrio() < readyQueue[left(i)].getPrio()) //If left child is bigger, swap.
  {
   // cout << "LEFT CHILD IS BIGGER" << endl;
    swapID = left(i);
  }
  
  if(right(i) <= current_size && readyQueue[swapID].getPrio() < readyQueue[right(i)].getPrio()) //If right child is bigger, swap.
  {
    //cout << "RIGHT CHILD IS BIGGER" << endl;
    swapID = right(i);
}
  
  if(swapID != i) //Swap whether dependent on the left or right child.
  {
    //cout << "SWAPPING" << endl;
    swap(&readyQueue[i], &readyQueue[swapID]);
    heapify_Down(swapID);
  }
  

}
  
int ReadyQueue::getMax() //RETURNS 1ST SLOT OF VECTOR AKA MAX.
{
  return readyQueue[0].getPrio(); 
}

bool ReadyQueue::find(PCB pcb) //SEARCH if the PCB exists in the vector
{
  bool found = false;
  for(int i = 0; i < current_size; i++)
  {
    if(readyQueue[i].getID() == pcb.getID())
    {
      found = true;
      return found;
    }
  }
  return found;
}

void ReadyQueue::add(PCB process) // Adds a PCB entry to the vector
{
  
  if(current_size >= max_size)
  {
    return; //Prevents adding entries past the max size
  }
  else //ELSE add the entry, increase size and heapify.
  {
  readyQueue.push_back(process);
  current_size++;
  heapify_Up(current_size-1);
  
  
}
}
  
PCB ReadyQueue::removeHighest()
{
  PCB result; 
  
   if(current_size <= 0)
   {
     return result; //If current size is <= 0 RETURN
   }
  if(current_size == 1)
  {
    result.setState("TERMINATED");
    return result; //If current size is == 1 RETURN;
  }
  else
  {
    PCB highest = readyQueue.front(); //Highest number is the front of the vector
    
    highest.setState("RUNNING"); //Set state to running
    
    readyQueue.erase(readyQueue.begin()); //ERASE Front of the vector
    
    current_size = readyQueue.size(); // get Size of vector
    
    heapify_Down(0);
    
    return highest;
}
}



void ReadyQueue::display()
{
cout << "\n";
  cout << "============================================================="<< endl;
  cout << "=============== CURRENT PROCESSES IN QUEUE  =================" << endl;
  cout << "=============================================================" << endl;
  cout << setw(20) << "ID: ";
  cout << setw(20) << "Priority: ";
  cout << setw(20) <<"State: ";
  cout << "\n";
  cout << "============================================================";
  cout << "\n";
  
  for(int i = 0; i < current_size; i++)
    {
      int ID = readyQueue[i].getID();
      int priority = readyQueue[i].getPrio();
      string state = readyQueue[i].getState();
      
      cout << setw(20) << ID;
      cout << setw(20) << priority;
      cout << setw(20) << state;
      cout << "\n";
    }
  
  cout << "=============================================================";
  cout << "\n" << "\n";
  
  
  
  
  
}
int ReadyQueue::getSize()
{
  return current_size; // Returns SIZE of vector
}

bool ReadyQueue::isEmpty()
{
  if(current_size == 0)
  {
    cout << "QUEUE IS EMPTY" << endl;
    return true;
  }
  return false;
}