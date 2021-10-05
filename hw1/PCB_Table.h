#ifndef PCB_TABLE_H
#define PCB_TABLE_H

#include "PCB.h"
#include "vector"



// CREATES PCB TABLE WITH NUM
using namespace std;

class PCB_Table
{
  private:
      vector<PCB> vectList;

  public:
   PCB_Table();
  void createTable(int num);
  PCB getElem(int id);


};
#endif