#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class ListNode {
    public:
        T data;
        ListNode<T>* next;

    ListNode(T data){
        this->data = data; 
        next = nullptr;
        }

    ListNode(){
        next = nullptr;
    }
};



template <class T>
class LinkedList {
    private:
        ListNode<T>* head;
        ListNode<T>* tail;
        int length;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        LinkedList(T* items, int size){
            length = size;
            head = new ListNode<T>(items[0]);
            ListNode<T>* ptr = head;
            for (int i = 1; i < size; i++){
                ptr->next = new ListNode<T>(items[i]);
                ptr = ptr->next;    
            }
            tail = ptr;
        }

        LinkedList(const LinkedList<T>& list){
            length = list.length;
            head = new ListNode<T>(list.head->data);

            ListNode<T>* ptr_this = head;
            ListNode<T>* ptr_other = list.head;

            for (int i = 1; i < length; i++){
                ptr_this->next = new ListNode<T>(ptr_other->next->data);
                ptr_this = ptr_this->next;
                ptr_other = ptr_other->next;
            }
            tail = ptr_this;
        }
        

        ~LinkedList(){

            ListNode<T>* ptr = head;
            ListNode<T>* ptr_prev;

            while (ptr) {
                ptr_prev = ptr;
                ptr = ptr->next;
                delete ptr_prev;
            }
        }

        T& GetFirst() const {
            return head->data;
        }

        T& GetLast() const {
            return tail->data;
        }

        T& Get (int index) const {
            ListNode<T>* ptr = head;
            for (int i = 0; i < index; i++){
                ptr = ptr->next;
            }
            return ptr->data;
        }

        int GetLength() const {
            return length;
        }

        LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
            LinkedList<T>* res = new LinkedList<T>();
            ListNode<T>* ptr_this = head;

            for (int i = 0; i < startIndex; i++) {
                ptr_this = ptr_this->next;
            }
    
            for (int i = startIndex; i < endIndex; i++){
                res->Append(ptr_this->data);
                ptr_this = ptr_this->next;
            }
            return res;
        }


        void Append(const T& item){
            if (length == 0){
                head = new ListNode<T>(item);
                tail = head;
                length++;
            }
            else{
                tail->next = new ListNode<T>(item);
                tail = tail->next;
                length++;
            }
        }

        void Prepend(const T& item){
            if (length == 0){
                head = new ListNode<T>(item);
                tail = head;
                length++;
            }
            else{
                ListNode<T>* ptr_new = head;
                head = new ListNode<T>(item);
                head->next = ptr_new;
                length++;
            }
        }

        void InsertAt(const T& item, int index){
            if (index == 0){
                Prepend(item);
                return;
            }
            if (index == length-1){
                Append(item);
                return;
            }
            ListNode<T>* ptr = head;
            ListNode<T>* ptr_prev = nullptr;

            for (int i = 0; i < index; i++){
                ptr_prev = ptr;
                ptr = ptr->next;
            }

            ListNode<T>* ptr_new = new ListNode<T>(item);
            ptr_prev->next = ptr_new;
            ptr_new->next = ptr;
        }

        void Set (int index, const T& item){
            ListNode<T>* ptr = head;
            for (int i = 0; i < index; i++){
                ptr = ptr->next;
            }
            ptr->data = item;
        }

        int IndexOf(const T& item) const {
            ListNode<T>* ptr = head;
            for (int i = 0; i < length; i++){
                if (ptr->data == item) return i;
                ptr = ptr->next;
            }

            return -1;
        }
        

        void print() {
            cout << "Length: " << length << endl;
            cout << "[ ";
            ListNode<T>* ptr = head;
            for (int i = 0; i < length; i++) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }

        cout << "]" << endl;
    }
};
        