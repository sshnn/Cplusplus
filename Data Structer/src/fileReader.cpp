#include "fileReader.hpp"
#include <fstream>
#include <fstream>

using namespace std;

  File::File() : x{}, y{}, head{nullptr} {}

  DoublyLinkedList File::getList()const
  {
    return x;
  }

  Data File::getData()const
  {
    return y;
  }

  Node *File::getNode()const
  {
    return head;
  }


void File::FileRead(DoublyLinkedList x, Data y, Node** head )
{   
  string value = "";
  string del = "";  
  string str=""; 
  ifstream file("Veri.txt");

  while (getline(file, str))
  {   
    int i;

    if(str[0]=='E')
    {
      for(i=2; str[i]!='#'; ++i)
        value += str[i];


      for(int k = i + 1; str[k]!=')'; ++k) 
        y.name+=str[k];

      //cout <<"-"<< y.name<<"-"<<endl;

      y.addIndex = stoi(value);

      if(y.addIndex > x.get_size()+1) 
        x.insertPos(head ,x.get_size() + 1, y.name);      
       else 
         x.insertPos(head, y.addIndex, y.name);

      y.name="";
      str="";
      value="";
    }
    else if(str[0]=='S') {
      for(int k=2; str[k]!=')'; ++k) 
        del += str[k];
      
      y.deleteIndex = stoi(del);
      //cout<<"\n"<<y.deleteIndex<<" indexli "<<x.size<<" size\n";
      if(y.deleteIndex >= x.get_size())
        x.delete_back(head);
      else
        x.delete_at(head,y.deleteIndex);
      str="";
      del="";
      y.deleteIndex=0;

   }
   
  }
}
