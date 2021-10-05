#include "buffer.h"
#include <stdlib.h> /* required for rand() */
#include <pthread.h>
#include <semaphore.h>
#include <iostream>

using namespace std;


buffer_item buffer[BUFFER_SIZE];
int head = 0;
int tail = 0;
int count = 0;



bool isEmpty()
{
  return (count == 0);
  
}

bool isFull()
{
  return (count == BUFFER_SIZE);
  
}


void display()
{
  int start = head;
  int end = tail;
  
  int i = 0;
  int x = 0;
  
  
  for( int i = start; x < count; i = (i + 1) % BUFFER_SIZE)
  {
    cout << buffer[i] << " ";
    x++;
    
    if(i == (end - 1))
    {
      break;
    }
    
  }
  
  if(count == 0)
  {
    cout << " EMPTY ";
  }
  
  
}



int insert_item(buffer_item item){
  
  /* insert item into buffer
     return 0 if successful, otherwise return -1 indictating error condition */
  
  if(!isFull())
  {
    cout << "Item " << item << " was produced by a producer." << endl;
    buffer[tail] = item;
    tail = (tail + 1) % BUFFER_SIZE;
    count++;
    
    return 0;
  }
  return -1;
  
  
  
  
}



int remove_item(buffer_item *item){
  
  /* remove an object from bufffer
   placeing it in item
   return 0 if successful, otherwise
   return -1 indicating an error condition */
  
  
  if(!isEmpty())
  {
    cout << "An item was consumed by a consumer." << endl;
    *item = buffer[head];
    head = (head % 1) % BUFFER_SIZE;
    count--;
    
    return 0;
  }
  
  return -1;
  
    
}


