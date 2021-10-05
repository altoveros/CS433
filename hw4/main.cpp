#include "buffer.h"
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// MUTEX // SEMPHORES 
pthread_mutex_t mutex;
sem_t empty;
sem_t full;


int insert_item(buffer_item item);
int remove_item(buffer_item *item);
void display();

void *producer(void *param){
  buffer_item item;
  
  while(true)
  {
    // sleep for a random period of time
    sleep(rand() % BUFFER_SIZE);
    // generate a random number
    item = rand() % RAND_MAX;
    
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    
    if(insert_item(item) == 0){
      cout << "Current contents of the buffer: ";
      display();
      cout << endl;
    }
    else{
      printf("ERROR! Unable to produce.");
    }
    
    
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    
  }
  
  
}



void *consumer(void *param){
  buffer_item item;
  
  while(true){
    // sleep for a random period of time
    sleep(rand() & BUFFER_SIZE);
    
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    
    
    
    if(remove_item(&item) == 0)
    {
      cout << "Current contents of the buffer: ";
      display();
      cout << endl;
    }
    else{
      printf("ERROR! Unable to Consume. ");
    }
  }
  
  pthread_mutex_unlock(&mutex);
  sem_post(&empty);
  
}





int main(int argc, char *argv[]){
  
  
    cout << "CS 433 Programming assignment 3" << std::endl;
    cout << "Author: Ian Altoveros" << std::endl;
    cout << "Date: 11/30/2020" << std::endl;
    cout << "Course: CS433 (Operating Systems)" << std::endl;
    cout << "Description : The Producer - Consumer Model " << std::endl;
    cout << "=================================" << std::endl;
  
  
  /* 1. Get command line arguments argv[1], argv[2], argv[3] */
  /* 2. Initialize buffer */
  /* 3. Create producer thread(s) */
  /* 4. Create consumer thread(s) */
  /* 5. Sleep */
  /* 6. Exit */
  
  
  if(argc != 4)
  {
    printf("You have entered the incorrect parameters to run the program. Enter a 3 command-line argument\n");
    exit(1);
    
  }
  
  
  // STEP 1.
  int sleepTime = atoi(argv[1]);
  int nProducer = atoi(argv[2]);
  int nConsumer = atoi(argv[3]);
  
  
 
  // STEP 2.
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
  
  pthread_t producer_threads[nProducer];
  pthread_t consumer_threads[nConsumer];
  
  
  
  // STEP 3.
  
  for(int i  = 0; i < nProducer; i++)
  {
    pthread_create(&producer_threads[i], NULL, producer, NULL);
  }
  
  // STEP 4.
  for(int i = 0; i < nConsumer; i++)
  {
    pthread_create(&consumer_threads[i], NULL, consumer, NULL);
  }
  
  // STEP 5.
  sleep(sleepTime);
  
  
  // STEP 6.
  cout << "EXITING" << endl;
  
  
  exit(0);
  
  
   
  
  
  
  
}