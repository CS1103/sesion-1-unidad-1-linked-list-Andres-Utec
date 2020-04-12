//
// Created by Andres Riveros on 4/11/20.
//
#include <cctype>
#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H
#include <iostream>
using namespace std;
namespace utec
{
    template<typename T>
    struct node_t {
        T value_ = 0;
        node_t* next_ = nullptr;
    };
    inline namespace first{
        template<typename T>
        class linked_list_t{
        private:
            node_t<T>* head_ = nullptr;
            node_t<T>* tail_ = nullptr;
            size_t size_ = 0;
        public:
            // constructors
            linked_list_t() = default;
            linked_list_t(const linked_list_t& other);
            linked_list_t&operator=(const linked_list_t& other);
            linked_list_t(linked_list_t&& other) noexcept ;
            linked_list_t&operator=(linked_list_t&& other) noexcept;

            //  destroyers
            ~linked_list_t();

            // add operations
            void push_front(T value);
            void push_back(T value);
            void insert(size_t index, T value);

            // remove operations;
            void pop_front();
            void pop_back();
            void erase(size_t index);

            // traversal operations
            T& item(size_t index);
            const T& item(size_t index) const;

            // get size of list
            size_t size() const;

        };
    }
    template<typename T>
    utec::first::linked_list_t<T>::linked_list_t(const utec::linked_list_t<T> &other) {
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
    template<typename T>
    utec::linked_list_t<T> &utec::first::linked_list_t<T>::operator=(const utec::linked_list_t<T> &other) {
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
    template<typename T>
    utec::first::linked_list_t<T>::linked_list_t(utec::linked_list_t<T> &&other) noexcept{
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
    template<typename T>
    utec::linked_list_t<T> &utec::first::linked_list_t<T>::operator=(utec::linked_list_t<T> &&other) noexcept {
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
    template<typename T>
    utec::first::linked_list_t<T>::~linked_list_t() {
        int size_linkedlist = size_;
        for(int i = 0; i < size_linkedlist; i++){
            pop_front();
        }
    }
    template<typename T>
    void utec::first::linked_list_t<T>::push_front(T value) {
        //head_ = value, head_ anterior
        head_ = new node_t<T>{value, head_};
        /*  Equivalente a lo de arriba
        auto node = new node_t{value, head_};
        head_ = node;*/
        if(tail_ == nullptr) tail_ = head_;
        size_++;
    }
    template<typename T>
    void utec::first::linked_list_t<T>::push_back(T value) {
        if(size_==0){
            push_front(value);
        }
        else{
            auto node = new node_t<T>{value, nullptr};
            tail_->next_ = node;
            tail_ = node;
            size_++;
        }
    }
    template<typename T>
    void utec::first::linked_list_t<T>::insert(size_t index, T value) {
        if(index == 0){push_front(value);}
        else{
            auto beforeNode = head_;
            for(int i = 0; i < index - 1; i++){
                beforeNode = beforeNode->next_;
            }
            auto newNode = new node_t<T>{value,beforeNode->next_};
            beforeNode ->next_ = newNode;
            size_++;
        }

    }
    template<typename T>
    void utec::first::linked_list_t<T>::pop_front() {
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
    template<typename T>
    void utec::first::linked_list_t<T>::pop_back() {
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
    template<typename T>
    void utec::first::linked_list_t<T>::erase(size_t index) {
        if(head_==tail_ || index== 0) {
            pop_front();
        }
        else if(size_- 1 == index){
            pop_back();
        }
        else{
            auto beforeNodo = head_;
            auto eraseNodo = head_;
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
    template<typename T>
    T &utec::first::linked_list_t<T>::item(size_t index) {
        auto actual = head_;
        while(index--)
            actual = actual -> next_;
        return actual->value_;
    }
    template<typename T>
    const T &utec::first::linked_list_t<T>::item(size_t index) const {
        auto actual = head_;
        while(index--)
            actual = actual -> next_;
        return actual->value_;
    }
    template<typename T>
    size_t utec::first::linked_list_t<T>::size() const {
        return size_;
    }
}



#endif //LINKED_LIST_LINKED_LIST_H
