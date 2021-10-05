#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <ctime>

#include "PCB.h"
#include "PCB_Table.h"
#include "ReadyQueue.h"



// done by: Ian Altoveros
// CS:433 OPERATING SYSTEMS



using namespace std;

int main()
{
  cout << "--------------------------------------------" << endl;
  cout << " DONE BY : IAN ALTOVEROS" << endl;
  cout << " DESCRIPTION: SIMULATION OF A PRIORITY QUEUE" << endl;
  cout << "---------------------------------------------" << endl;
  

    cout << "======================START OF TEST 1======================\n" <<endl;
  
  
  PCB_Table table; // Create a PCT_Table
  table.createTable(30); // Creates a PCT_Table of 30 Entries

  
  
  ReadyQueue q1;
  
  //Inserting processes into Q1
  
  cout << "[INSERTING PROCESSES: '15', '6', '23', '29', '8' into q1...]" << endl;
   
  q1.add(table.getElem(15));
  q1.add(table.getElem(6));
  q1.add(table.getElem(23));
  q1.add(table.getElem(29));
  q1.add(table.getElem(8));
  q1.display();
  
  
  // Removing highest priority of Q1
  
  cout << "REMOVING HIGHEST PRIORITY: " << q1.getMax() << endl;
  q1.removeHighest();
  q1.display();
  
  
  // Removing highest priority of Q1
  
  cout << "REMOVING HIGHEST PRIORITY: " << q1.getMax() << endl;
  q1.removeHighest();
  q1.display();
  
  
  //Inserting processes once again into Q1.
  
 cout << "[INSERTING PROCESSES: '3', '17', '22', '12', '19' into q1...]" << endl;
  
 q1.add(table.getElem(3));
 q1.add(table.getElem(17));
 q1.add(table.getElem(22));
 q1.add(table.getElem(12));
 q1.add(table.getElem(19));
 q1.display();
  

 q1.removeHighest();
 q1.display();

 q1.removeHighest();
 q1.display();
 q1.removeHighest();
 q1.display();
 q1.removeHighest();
 q1.display();
  
 q1.removeHighest();
 q1.display();
 q1.removeHighest();
 q1.display();
 q1.removeHighest();
 q1.display();
 q1.removeHighest();
 q1.display();
  
  
  // END OF TEST 1
  
  cout << "======================END OF TEST 1======================\n" <<endl;
  
 cout << "======================TEST 2 START=========================\n" <<endl;
  
  
  
    for(int i = 0; i <= 15; i++) //Make a ready queue with 15 random value
    {
      int randNum = rand() % 30;
     PCB randProc; 
     randProc = table.getElem(randNum);
     randProc.setPrio(rand() % 50 + 1);
     q1.add(randProc);
    }
  
  q1.display();
  
  
  srand(time(NULL)); //USED FOR TIME
  struct timeval tim; //Time structs to keep time
  gettimeofday(&tim, NULL);
  
  double initialTime=tim.tv_sec+(tim.tv_usec/1000000.0); 

  for(int i =0; i < 1000000; i++) //loop for a million times
  {
    
    int choice = rand() % 2;
    if(choice == 0)
    {
      if(!q1.isEmpty())
      {
        q1.removeHighest();
      }
    }

    
  }
        

  
      
  gettimeofday(&tim, NULL);
  q1.display();
  cout << "======================END OF TEST 2======================\n" <<endl;
  double finalTime = tim.tv_sec+(tim.tv_usec/1000000.0);
  double elapsedTime = finalTime - initialTime; // Calculate elapsed time
   cout << "PROGRAM TIME: " << elapsedTime << " seconds." << endl;
  cout << "\n";
  return 0;
  
  
  
  
  

}
