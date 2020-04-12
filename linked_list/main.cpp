#include <iostream>
#include <cassert>
#include <string>
#include "linked_list.h"
using namespace std;

int main() {

    utec::linked_list_t<int> ll;

    // Probar el metodo push_front;
    for(int i = 0; i < 10; ++i){
        ll.push_front(i);
    }

    // Verifico el tamaño
    assert(ll.size() == 10);

    string result;
    for(int i = 0; i < 10; ++i){
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");

    // pop_front test

    for(int i = 0; i < 5; ++i){
        ll.pop_front();
    }
    // Verifico el tamaño
    assert(ll.size() == 5);


    // pop_front test

    for(int i = 0; i < 5; ++i){
        ll.pop_front();
    }
    // Verifico el tamaño
    assert(ll.size() == 0);


    // push_back test

    for(int i = 0; i < 10; ++i){
        ll.push_back(i);
    }
    assert(ll.size() == 10);

    string result1;
    for(int i = 0; i < 10; ++i){
        result1 += to_string(ll.item(i)) + " ";
    }
    assert(result1 == "0 1 2 3 4 5 6 7 8 9 ");


    // pop_back() test

    for(int i = 0; i < 5;++i){
        ll.pop_back();
    }
    // Verifico el tamaño
    assert(ll.size() == 5);


    for(int i = 0; i < 5 ; ++i){
        ll.pop_back();
    }
    assert(ll.size() == 0);


    // erase test

    for(int i = 0; i < 10; ++i){
        ll.push_back(i);
    }
    ll.erase(2);
    ll.erase(4);
    ll.erase(0);
    string test_erase;
    for(int i = 0; i < 7; ++i){
        test_erase += to_string(ll.item(i)) + " ";
    }
    assert(ll.size()== 7);
    assert(test_erase == "1 3 4 6 7 8 9 ");

    // insert test

    utec::linked_list_t<int> ll1;

    for(int i = 0; i < 10; ++i){
        ll1.push_back(i);
    }
    ll1.insert(1, 10);
    ll1.insert(1, 200);
    ll1.insert(1,900);
    ll1.insert(5, 1000);
    ll1.insert(13, 2000);
    string test_insert;
    for(int i = 0; i < 15; ++i){
        test_insert += to_string(ll1.item(i)) + " ";
    }
    assert(ll1.size()== 15);
    assert(test_insert == "0 900 200 10 1 1000 2 3 4 5 6 7 8 2000 9 ");

    // Constructor test - lvalue
    utec::linked_list_t<int> test1{ll1};
    string test_constructor;
    for(int i = 0; i < test1.size(); i++){
        test_constructor += to_string(test1.item(i)) + " ";
    }
    assert(test1.size()== 15);
    assert(test_constructor == "0 900 200 10 1 1000 2 3 4 5 6 7 8 2000 9 ");


    // Equality operator test

    utec::linked_list_t<int> test2 = ll1;
    string equality_test;
    for(int i = 0; i < test2.size(); i++){
        equality_test += to_string(ll1.item(i)) + " ";
    }
    assert(test2.size()== 15);
    assert(equality_test == "0 900 200 10 1 1000 2 3 4 5 6 7 8 2000 9 ");

    cout <<"This work fine!!" << endl;

    
    return 0;
}
