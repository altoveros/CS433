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

void schedule(PCBTable);

int main(int argc, char *argv[])
{
  std::cout << endl;
  std::cout << "=========================================================" << std::endl;
  std::cout << "CS 433 Programming assignment 3" << std::endl;
  std::cout << "Author: Fernando Alvarado" << std::endl;
  std::cout << "Date: 11/04/2020" << std::endl;
  std::cout << "Course: CS433 (Operating Systems)" << std::endl;
  std::cout << "Description : A First Come First Serve (FCFS) scheduler" << std::endl;
  std::cout << "=========================================================" << std::endl;
  std::cout << endl;

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

  // open the input file
  std::ifstream infile(argv[1]);
  string line;
  PCBTable ReadyQueue;
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
    PCB temp(name, priority, burst);
    ReadyQueue.addPCB(temp);
  }
  // TODO: Add your code to run the scheduler and print out statistics
  schedule(ReadyQueue);

  return 0;
}

void schedule(PCBTable queue)
{
  
}