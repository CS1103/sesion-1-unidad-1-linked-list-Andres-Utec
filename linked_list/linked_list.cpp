//
// Created by Andres Riveros on 4/11/20.
//

#include "linked_list.h"

utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    // Clean the linked list
    int size_linkedlist = size_;
    for(int i = 0; i < size_linkedlist; i++){
        pop_front();
    }
    for(int i = 0; i < other.size_;i++){
        push_back(other.item(i));
    }
    size_ = other.size_;

}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) {
    // Clean the linked list
    if(this == &other){return *this;}
    int size_linkedlist = size_;
    for(int i = 0; i < size_linkedlist; i++){
        pop_front();
    }
    for(int i = 0; i < other.size_;i++){
        push_back(other.item(i));
    }
    size_ = other.size_;
    return *this;
}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept{
    int size_linkedlist = size_;
    for(int i = 0; i < size_linkedlist; i++){
        pop_front();
    }
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {
    // TO DO
    int size_linkedlist = size_;
    for(int i = 0; i < size_linkedlist; i++){
        pop_front();
    }
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
    return *this;
}

utec::first::linked_list_t::~linked_list_t() {
    int size_linkedlist = size_;
    for(int i = 0; i < size_linkedlist; i++){
        pop_front();
    }
}

void utec::first::linked_list_t::push_front(int value) {
    //head_ = value, head_ anterior
    head_ = new node_t{value, head_};
    /*  Equivalente a lo de arriba
    auto node = new node_t{value, head_};
    head_ = node;*/
    if(tail_ == nullptr) tail_ = head_;
    size_++;
}

void utec::first::linked_list_t::push_back(int value) {
    if(size_==0){
        push_front(value);
    }
    else{
        auto actual = head_;
        while(actual-> next_){
            actual = actual->next_;
        }
        auto node = new node_t{value, tail_->next_};
        actual -> next_ = node;
        tail_ = node;
        size_++;
    }
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if(index == 0){
        push_front(value);
    }
    else if(size_ == index){
        push_back(value);
    }
    else{
        auto beforeNode = head_;
        for(int i = 0; i < index - 1; i++){
            beforeNode = beforeNode->next_;
        }
        auto newNode = new node_t{value,beforeNode->next_};
        beforeNode ->next_ = newNode;
        size_++;
    }

}

void utec::first::linked_list_t::pop_front() {
    // Si ambos son iguales
    if(head_ == tail_){
        delete[] head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else{
        auto next = head_-> next_;
        delete head_;
        head_ = next;
        size_--;
    }
}

void utec::first::linked_list_t::pop_back() {
    if(head_== tail_){
        pop_front();
    }
    else{
        auto find_second_last = head_;
        while(find_second_last ->next_->next_){
            find_second_last = find_second_last->next_;
        }
        delete tail_;
        find_second_last->next_ = nullptr;
        tail_ = find_second_last;
        size_--;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    if((head_==tail_) || (index==0)){
        pop_front();
    }
    else if(size_- 1 == index){
        pop_back();
    }
    else{
        auto beforeNodo = head_;
        auto eraseNodo = head_;
        int x = index;
        for(int i = 0; i < index; i++){
            eraseNodo = eraseNodo->next_;
            if(i < index - 1)
                beforeNodo = beforeNodo->next_;
        }
        beforeNodo->next_ = beforeNodo->next_->next_;
        delete eraseNodo;
        size_--;
    }
}

int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head_;
    while(index--)
        actual = actual -> next_;
    return actual->value_;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head_;
    while(index--)
        actual = actual -> next_;
    return actual->value_;
}

size_t utec::first::linked_list_t::size() const {
    return size_;
}

