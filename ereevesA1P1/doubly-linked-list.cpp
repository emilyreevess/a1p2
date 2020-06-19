#include "doubly-linked-list.h"
#include <iostream>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    value = data; //This sets the value of the node to the data that is entered
    prev = nullptr;
    next = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
// Initializes an empty doubly linked list
    size_ = 0; // setting size equal to zero
    head_ = nullptr;
    tail_ = nullptr; //setting these pointers to be null
}

DoublyLinkedList::~DoublyLinkedList()
{
    //  Destructor, which frees all dynamically allocated memory, if any
    head_ = nullptr;
    tail_ = nullptr;
}

unsigned int DoublyLinkedList::size() const
{
    //  Returns the number of elements of nodes in the list
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    // Returns the maximum number of elements the list can hold.
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    // Returns true if the list is empty, false otherwise
    return size_ == 0;
}

bool DoublyLinkedList::full() const
{
    // Returns true if the list is at capacity, false otherwise
    return size_ == CAPACITY;
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    //Returns the value at the given index in the list. If index is invalid, return the value of the last element
    //validity check
    if (index > size() || size() == 0 || index < 0) {
        return tail_->value;
    }
    //if index == 0
    if (index == 0 && size() > 0) {
        return head_->value;
    }
    if (index == size() - 1) {
        return tail_->value;
    }
    if (size() > 0 && index > 0 && index < size()) {
        Node *temp = head_;
        for (unsigned int i = 0; i <= (index - 1); i++) {
            temp = temp->next;
        } //iterate through until previous is pointing to the node in the index selected
        return temp->value;
    }
}

unsigned int DoublyLinkedList::search(DataType value) const
{
    Node *temp = head_;
    if(temp == nullptr){
        return 0;
    }
    else{
    int index = 0;
    for (unsigned int i = 0; i <= size() - 1; i++) {
        if (value == temp->value) {
            return index;
        } else if (value != temp->value) {
            temp = temp->next;
            index++;
        } else {
            return size();
        }
    }
    }

}


void DoublyLinkedList::print() const
{
    if (head_ == nullptr) {
        return;
    }
    //print all nodes
    Node *temp = head_;
    while (temp != nullptr) {
        cout<< temp->value << "->";
        temp = temp->next;
    }
    cout<< endl;
}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    if(size() == 0){
        cout<< "There are no nodes or pointers this list is empty" << endl;
    }

    if(size() == 0 && index == 0){
        return head_;
    }

    if(size() > 0){
        Node *temp = head_;
        for(unsigned int i=0; i >= index-1; i++){
            temp = temp->next;
        }
        return temp;
    }
}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    // Inserts a value into the list at a given index.  Returns true if successful and false otherwise
    //step 1. check position validity, compare with 0 and size,
    //if not valid, quit, report error, or force into a valid value
    //omitted in this demo, assuming it is valid
    if(index > size()){
        return false;
    }/* validity check. If index is greater than size, there is no element of that index. It also must be greater
    greater than zero as that would be invalid*/


    //step 2. create new node
    Node *newNode = new Node(value);

    //step 3. if special case, when position = 0
    //insert as the new head
    //3.1 when head == nullptr, or size == 0
    // the newNode will become the new head and the new tail
    if(head_ == nullptr || size() == 0){
        head_ = newNode;
        tail_ = newNode;
        size_++;
        return true;
    } //This is done because newNode will be the only node in the list

    //3.2 when size > 0, (position = 0)
    // insert at the head position
    if(size() > 0 && index == 0){
        newNode->next = head_;
        head_->prev = newNode;
        head_ = newNode;
        size_++;
        return true;
    }

    //step 4. when size > 0, position = size
    //insert at the end of the list, the node will become the new tail
    if(size() > 0 && index == size()){
        newNode->prev = tail_;
        tail_->next = newNode;
        tail_ = newNode;
        size_++;
        return true;
    }

    //step 5. when size > 0, position > 0,  position < size
    if(size() > 0 && index > 0 && index < size()){
        Node *previous = head_;
        Node *current = head_->next;
        for(unsigned int i = 0; i <= (index-1); i++){
            previous = current;
            current = current->next;
        } //iterate through until previous is pointing to the node in the index selected
        newNode->next = previous; //linking the back of newNode to the node at the selected index to essentially push it back
        newNode->prev = previous->prev; //this links the new node to the back of the node in the index before the selected node
        previous->prev->next = newNode; //links the node before the selected index to the new node
        previous->prev = newNode;// links the front of the node that was is in selected index to the new node
        size_++;
        return true;
    }

}

bool DoublyLinkedList::insert_front(DataType value)
{
    insert(value,0);
}

bool DoublyLinkedList::insert_back(DataType value)
{
    insert(value, size());
}

bool DoublyLinkedList::remove(unsigned int index)
{
    //step 1. check position validity, compare with 0 and size,
    if(index > size()){
        return false;
    }// for index > size there is no node here to remove
    // for index < zero there is no node that can be removed

    //step 2.1 special case, if position == 0, remove head
    if(index == 0){
        if(size() == 1){
            tail_ = nullptr;
        }
        Node *temp = head_;
        head_ = head_->next;
        delete temp;
        head_->prev = nullptr;
        size_--;
        return true;
    }


    //step 2.2, special case, if position == size - 1, remove tail
    if(index == (size() -1)){
        //use a temp pointer
        //properly set the pointers, don't forget setting tail pointer
        Node *temp = tail_;
        tail_ = temp->prev;
        //deallocate node memory
        delete temp;
        size_--;
        return true;
    }

    //step 3. to prepare for removing a node in the middle of the list, find the pointer to the location
    if(size() > 0 && index > 0 && index < size()){
        Node *previous = head_;
        Node *current = head_->next;
        for(unsigned int i = 0; i <= (index-1); i++){
            previous = current;
            current = current->next;
        } //iterate through until previous is pointing to the node in the index selected
        current->prev = previous->prev;
        previous->prev->next = current;
        delete previous;
        size_--;
        return true;
    }


}

bool DoublyLinkedList::remove_front()
{
    remove(0);
}

bool DoublyLinkedList::remove_back()
{
    remove(size()-1);
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if(size() == 0){
        return false;
    }

    if(size() == 0 && index == 0){
        head_->value = value;
        return true;
    }

    if(size() > 0){
        Node *temp = head_;
        for(unsigned int i=0; i >= index-1; i++){
            temp = temp->next;
        }
        temp->value = value;
        return true;
    }
}

