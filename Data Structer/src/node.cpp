#include <iostream>
#include "Node.hpp"

using namespace std;

int DoublyLinkedList::size = 0;

int DoublyLinkedList::get_size()const
{
  return size;
}


Node* DoublyLinkedList::getNode(string data)
{   
    Node* newNode = new Node();
 
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

bool DoublyLinkedList::insertPos(Node** current, int index, string data)
{ 
    // checks index 
    if (index < 1 || index > size + 1) {
        cout<<" invalid value\n";
        return 0;
    }
    else {        
        while (index--) {
 
            if (index == 0) { 
                Node* temp = getNode(data);
                temp->next = *current; 
                *current = temp;
              }
            else
              current = &(*current)->next;
        }
        size++;
    }
    return 1;
}

void DoublyLinkedList::delete_at(struct Node** head, int index) 
{     
      if(index < 1) {
        cout<<"\n index should be >= 1\n";
      }
       else if(index == 1 && *head != nullptr) { 
        Node* nodeToDelete = *head;
        *head = (*head)->next;
        delete(nodeToDelete);

        if(head != nullptr)
          (*head)->prev = nullptr;
      } 
      else {
        Node* temp = *head;
        for(int i = 1; i < index-1; i++) {
          if(temp != nullptr) {
            temp = temp->next;
          }
        }

        if(temp != nullptr && temp->next != nullptr) {
          Node* nodeToDelete = temp->next;
          temp->next = temp->next->next;
          if(temp->next->next != nullptr)
            temp->next->next->prev = temp->next;  
          delete(nodeToDelete); 
        } 
        else {
          cout<<"\n The node is already null\n";
        }       
      }
} 

void DoublyLinkedList::delete_back(struct Node** head)
{
  if(*head != nullptr) {
    
    if((*head)->next == nullptr) {
      *head = nullptr;
    } else {

      Node* temp = *head;
      while(temp->next->next != nullptr)
        temp = temp->next;
      
      Node* lastNode = temp->next;
      temp->next = nullptr;
      delete(lastNode); 
    }
  }
}

void DoublyLinkedList::printList(Node* node)
{
    Node* last;
    cout<<" Liste: \n";
    while (node != nullptr)
    {
        cout<<" "<<node->data<<" <-->";
        last = node;
        node = node->next;
    }    
}
