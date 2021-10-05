#include "PCB_Table.h"
#include <iostream>

#include <vector>

using namespace std;


PCB_Table::PCB_Table()
{

}


void PCB_Table::createTable(int num) //Creates a table of PCB processes and sets state to "READY"
{
  for ( int i = 0 ; i < num;  i++)
  {
    PCB newPCB = PCB(i, i, "READY");
    vectList.push_back(newPCB);
  }
}
  
 PCB PCB_Table::getElem(int id) // Returns element at index ID
 {
   return vectList.at(id);
 }

