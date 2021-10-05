/**
 * Driver program 
 * 
 * Add other data structures and .cpp and .h files as needed.
 * 
 * The input file is in the format:
 *
 *  [name], [priority], [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "PCB.h"

using namespace std;



//Helper Function to find Max Priority in PCBTable

void findMax(PCB table[], int n)
{
  PCB temp; //TEMP Value to hold PCB to swap
  
  
  for(int i = 0 ;i < n;i++)
    {
      for(int j = 0; j < n-i-1;j++)
        {
          if(table[i].priority < table[j].priority)
            {
              temp = table[i];
              table[i] = table[j];
              table[j] = temp;
            }
        }
    }
}


int main(int argc, char *argv[])
{
    std::cout << "CS 433 Programming assignment 3" << std::endl;
    std::cout << "Author: Ian Altoveros" << std::endl;
    std::cout << "Date: 11/6/2020" << std::endl;
    std::cout << "Course: CS433 (Operating Systems)" << std::endl;
    std::cout << "Description : Priority scheduler" << std::endl;
    std::cout << "=================================" << std::endl;
    
    int QUANTUM = 10;
    // Check that input file is provided at command line
    if(argc < 2 ) {
        cerr << "Usage: " << argv[0] << " <input_file> [<time_quantum>]" << endl;
        exit(1);
    }

    // Read the time quantum if provided.
    if(argc >= 3) {
        QUANTUM = atoi(argv[2]);
    }

    // Read task name, priority and burst length from the input file 
    string name;
    int priority;
    int burst;
//       int count=0;
//   int tat=0;
//   int tatTemp=0;
//   int wt=0;
//   int atat=0;
//   int awt=0;
  
  
   int TurnAroundTime = 0;
   int WaitingTime = 0;
   int AverageTime = 0;
   int AverageWT = 0;
   int num = 0;
   int TurnAroundTimeTemp = 0;
  PCBTable pcbQueue;

    // open the input file
    std::ifstream infile(argv[1]);
    string line;
    while(getline(infile, line) ) {
        std::istringstream ss (line);
        // Get the task name
        getline(ss, name, ',');
        
        // Get the task priority 
        string token;
        getline(ss, token, ',');
        priority = std::stoi(token);

        // Get the task burst length 
        getline(ss, token, ',');
        burst = std::stoi(token);
        
        cout << name << " " << priority << " " << burst << endl;
        // TODO: add the task to the scheduler's ready queue
        // You will need a data structure, i.e. PCB, to represent a task 
    PCB pcb(name,priority,burst);
    pcbQueue.add(&pcb);
    num++;
      
    }
  
  
  findMax(pcbQueue.table,num);
  
  for(int i = 0; i < num; i++)
    {
      TurnAroundTime = pcbQueue.table[i].burst;
      WaitingTime = TurnAroundTime - pcbQueue.table[i].burst;
      TurnAroundTimeTemp = TurnAroundTime;
      cout << "TURN AROUND TIME = " << TurnAroundTime << ", WAITING TIME = " << WaitingTime << endl;
      AverageTime =+ TurnAroundTime;
      AverageWT = WaitingTime;
    } 


   cout << "AVERAGE TURNING TIME = "<< AverageTime/num <<", AVERAGE WAITING TIME = "<< AverageWT/num << endl;
    // TODO: Add your code to run the scheduler and print out statistics

    return 0;


}
