#include <iostream>
#include "sequential-list.h"

/*
SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType[cap];
    capacity_ = cap;
    size_ = 0;

}

SequentialList::~SequentialList()
{
    delete data_;
    data_ = nullptr;
}

unsigned int SequentialList::size() const
{
    // Returns the number of elements in the list.
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    // Returns true if the list is empty, false otherwise
    return size() == 0;
}

bool SequentialList::full() const
{
    //Returns true if the list is at capacity, false otherwise
    return size() == capacity();
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    // Returns the value at the given index in the list.  If index is invalid, return the value of the last element
    if(empty()){
        std::cout << "The list is empty" << std::endl;
        empty();
    }
    else if(index >= size() || index < 0){
        return data_[size()-1];
    }
    else {
     return data_[index];
    }
}

unsigned int SequentialList::search(DataType val) const
{
    //Searches  for  the  given  value,  and  returns the index of this value if found.  Returns the size of the list otherwise
    if(empty()){
        return size();
    }
    int i = -1;
do{
    i++;
}
while(val != data_[i] && i < size());

if (i >= size()){
    return size();
}
else {
    return i;
}
}

void SequentialList::print() const
{
    // Prints all elements in the list to the standard output.
    if(size() == 0){
        std::cout << "There are no elements in this list";
    }
    else{
        for(int i = 0; i < size(); i++){
            std::cout << data_[i] << " ";
        }
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    // Inserts a value into the list at a given index.  Returns true if successful and false otherwise
    if(full() || index > size()){
        return false;
    }
    else if (index < size()){
        for (unsigned int i = (size() - 1); i > index; i--) {
            data_[i+1] = data_[i];
        }
        data_[index+1]=data_[index];
    }
    data_[index] = val;
    size_++;
    return true;
    }

bool SequentialList::insert_front(DataType val)
{
   insert(val, 0);
}

bool SequentialList::insert_back(DataType val)
{
    insert(val, size());
}

bool SequentialList::remove(unsigned int index)
{
    if(index >= size() || empty()){
        return false;
    }
    else if (index < size()){
        for (unsigned int i = index; i < size(); i++) {
            data_[i] = data_[i+1];
        }
        size_--;
        return true;
    }
}

bool SequentialList::remove_front()
{
    if (empty()){
        return false;
    }
    else{
        remove(0);
    }
}

bool SequentialList::remove_back()
{
    if (empty()){
        return false;
    }
    else{
        remove(size()-1);
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index < capacity()){
        data_[index] = val;
        return true;
    }
    else{
        return false;
    }
}

*/