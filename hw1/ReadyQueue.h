#ifndef READYQUEUE_H
#define READYQUEUE_H

#include "PCB.h"
#include <vector>

using namespace std;


// ReadyQueue header file, contains all the known processes for the readyQueue class.

class ReadyQueue
{

  private: 
 vector <PCB> readyQueue;
  int current_size;
  int max_size;
  int removedID;
  
  
  
  
  public:
  ReadyQueue();
  ~ReadyQueue();
  
  int parent(int i); //parent node
  int left(int i); //left node
  int right(int i); //right node

  void swap(PCB* z, PCB* y);
  bool isLeaf(int i);
  void heapify_Up(int i);
  void heapify_Down(int i);
  int getMax();
  bool find(PCB pcb);
  void sortQ();
  bool isEmpty();
  
  
  
  
  void add(PCB process);
  PCB removeHighest();
  void display();
  int getSize();

};

#endif