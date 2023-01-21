#pragma once
#include "Sequence.hpp"
#include "DynamicArr.hpp"
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class ArraySequence : public Sequence <T>{
    private:
        DynamicArray<T> arr;
    
    public:

        ArraySequence(){}

        ArraySequence(int size) : arr(size) {}

        ArraySequence(T* items, int size) : arr(items, size){}

        ArraySequence(const ArraySequence<T>& arrseq) : arr(arrseq.arr){}

        //copy

        ~ArraySequence(){}


        // T operator[](int const index){
        //     //assert
        //     return arr->Get(index);
        // }

        T& GetFirst() const override {
            //assert (length <=0);
            return arr.GetFirst();
        }

        T& GetLast() const override {
            //assert
            return arr.GetLast();
        }

        T& Get(int index) const override {
            return arr.Get(index);
        }  
        
        void Set(int index, const T& value) override {
            arr.Set(index, value);
        }

        int GetLength() const override {
            return arr.GetLength();
        }
        
        void Swap(int i, int j) override {
            arr.Swap(i, j);
        }
        

        void Resize(int newsize) {
            arr.Resize(newsize);    
        }

        void Append(const T& item) override {
            arr.Append(item);
        }

        void Prepend(const T& item) override {
            arr.Prepend(item);
        }

        void InsertAt (int index, const T& item) {
            arr.InsertAt(index, item);
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override{
            ArraySequence<T>* buff = new ArraySequence<T>();
            int diff = endIndex - startIndex;
            buff->Resize(diff);
            for (int i = 0; i < diff; i++) {
                buff->Set(i, Get(startIndex+i));
            }
            return (Sequence<T>*)buff;
        }

        Sequence<T>* Copy() const override{
            return (Sequence<T>*)(new ArraySequence<T>(*this));
        }

        int IndexOf(const T& item) const override{
            return arr.IndexOf(item);
        }
        //Sequence<T>* Concat(Sequence<T>* list) = 0;//
        
};