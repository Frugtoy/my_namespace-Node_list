#pragma once
#include "exception"

namespace my_namespace {
template<typename T>
class Node_list
{
public:
Node_list(){ this->_size = 0; this->_head = nullptr;}
void push_back(T value) {
    
    if(this->_head == nullptr) {
        this->_head = new Node<T>(value);
        this->_size++;
    }
    else {
        Node<T>* buf = this->_head;
        while(buf->next!= nullptr)
        {
            buf = buf->next;
        } 
        buf->next = new Node<T>(value);
        this->_size++;
    }
}
size_t get_size(){return this->_size;}
T& operator[](const size_t index) {
    
    if( index >= this->_size)
        throw std::out_of_range("the element with that index hadn't been created");
    size_t counter = 0;
    Node<T>* buf  = this->_head;
    while(buf != nullptr)
    {
        if(counter == index)
        {
            return buf->data;
        }
        buf = buf->next;
        counter++;
    }
}
void pop_front() {
    Node<T> * buf = this->_head;
    this->_head = this->_head->next;
    delete buf;
    this->_size-- ;
}
void clear () {
    while(this->_size) {
        this->pop_front();
    }
}
void push_front(T data) {
    this->_head = new Node<T>(data , this->_head);
    this->_size ++;

}
void pop_back(){
    this->removeAt(this->_size-1);
}
void removeAt(size_t index){
    if (index >= this->_size)
        throw std::out_of_range("index>=size");
    if(index == 0)
        this->pop_front();
    else {
        Node<T>* previous = this->_head;
        for(int i = 0; i<this->_size ; i++) {
            if(i < index) 
                previous = previous->next;   
        }
        Node<T>* todel = previous->next;
        previous->next = todel->next;
        delete todel;
        this->_size --;
    }

}
void insert(T data , size_t index) {
    if (index >= this->size)
        throw std::out_of_range("size <= index");
    if(index == 0)
        this->push_front(data);
    else {
    Node<T>* previous = this->_head;
        for(int i =0; i<index;++i) {
            previous = previous->next;
        }
        previous->next = new Node<T>(data);
        this->_size++;
    }
}
~Node_list(){
    this->clear();
}
private:
template<typename M>
 class Node 
    {
    public:
    Node(M data = T(), Node<M>* next = nullptr) {
        this->data = data;
        this->next = next;
    }
        Node<M>* next;
        M data;
    };
size_t _size;
Node<T>* _head;
};
}