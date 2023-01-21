#pragma once
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class DynamicArray{
    private:
        T* data;
        int length;
    
    public:

        DynamicArray(){
            data = nullptr;
            length = 0;
        };

        DynamicArray(int size){
            data = new T[size];
            length = size;
        }

        DynamicArray(T* items, int size){
            data = new T[size];
            for (int i = 0; i < size; i++){
                data[i] = items[i];
            }
            length = size;
        }
        //copy
        //const
        DynamicArray(const DynamicArray<T>& arr){
            length = arr.length;
            data = new T[length];
            for (int i=0; i<length; i++){
                data[i] = arr.data[i];
            }
        }

        ~DynamicArray(){
            delete[] data;
            length = 0;
            data = nullptr;
        }


        // T operator[](int const index){
        //     //assert
        //     return data[index];
        // }

        T& GetFirst() const {
            //assert (length <=0);
            return data[0];
        }

        T& GetLast() const {
            //assert
            return data[length-1];
        }

        T& Get(int index) const {
            return data[index];
        }  
        
        void Set(int index, const T& value)  {
            data[index] = value;
        }

        int GetLength() const {
            return length;
        }
        
        void Swap(int i, int j)  {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
        

        void Resize(int newsize) {
            T* newData = new T[newsize];
            int tmpsize = 0;
            tmpsize = (newsize > length)? length:newsize;

            for (int i = 0; i<tmpsize; i++){
                newData[i] = data[i];
            }

		    if (data) delete[] data;
            data = newData;
            length = newsize;
        }

        void Append(const T& item)  {
            Resize(length+1);
            Set(length-1, item);
        }

        void Prepend(T item)  {
            
        }

        void InsertAt (int index, const T& item) {
            int newLength = length+1;
            Resize(newLength);
            T buff;
            int mvqty = newLength - index - 1;

            for (int i = 0; i < mvqty; i++) {
                buff = data[newLength - i - 2];
                Set(newLength - i - 1, buff);
            }
            Set(index, item);
        }

        int IndexOf(const T& item) const {
            for (int i = 0 ; i<length; i++){
                if (data[i] == item) return i;
            }
            return -1;
            // return true;
        }
        //Sequence<T>* Concat(Sequence<T>* list) = 0;//
        
};