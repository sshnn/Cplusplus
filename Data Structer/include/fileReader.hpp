#ifndef FILEREADER_HPP
#define FILEREADER_HPP
#include "data.hpp"

class File {
public:
    File();
    void FileRead(DoublyLinkedList x, Data y, Node** head);
    DoublyLinkedList getList()const;
    Data getData()const;
    Node *getNode()const;
private:
    DoublyLinkedList x;
    Data y;
    Node *head;
};

#endif