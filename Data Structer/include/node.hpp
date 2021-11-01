#ifndef NODE_HPP
#define NODE_HPP
#include <string>

struct Node {
   std::string data;
   struct Node *prev;
   struct Node *next;
};
 
class DoublyLinkedList {
public:
   int get_size()const;
   Node *getNode(std::string data);
   bool insertPos(Node** current, int pos, std::string data);
   void delete_at(struct Node** head_ref, int position);
   void delete_back(struct Node** head);
   void printList(Node* node);
private:
   static int size;
};

#endif