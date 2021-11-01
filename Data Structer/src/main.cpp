#include <iostream>
#include <fstream>
#include "Node.hpp"
#include "data.hpp"
#include "fileReader.hpp"


using namespace std;

File r;
Node *head =r.getNode();


int main()
{
  r.FileRead(r.getList() ,r.getData() ,&head);  
  r.getList().printList(head);
  
 
  
}

