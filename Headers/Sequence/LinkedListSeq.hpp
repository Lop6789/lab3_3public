#pragma once
#include "Sequence.hpp"
#include "LinkedList.hpp"
//Don't forget to add : public Seq<T>

template <class T>
class LinkedListSequence : public Sequence<T> {
    private:
        LinkedList<T> list;

    public:
        LinkedListSequence(){}

        LinkedListSequence(T* items, int size) : list(items, size){}

        LinkedListSequence(const LinkedListSequence<T>& listseq) : list(listseq.list){}

        LinkedListSequence(const LinkedList<T>& list) : list(list){}

        ~LinkedListSequence(){}

        T& Get (int index) const override{
            return list.Get(index);
        }

        T& GetFirst() const override{
            return list.GetFirst();
        }

        T& GetLast() const override{
            return list.GetLast();
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override{
            // return (Sequence<T>*) (new LinkedListSequence<T>(*(list->GetSubList(startIndex, endIndex))));
            return (Sequence<T>*) (list.GetSubList(startIndex, endIndex));
        }

        int GetLength() const override{
            return list.GetLength();
        }

        int IndexOf(const T& item) const override{
            return list.IndexOf(item);
        }

        void Append(const T& item) override {
            list.Append(item);
        }

        void Prepend (const T& item) override {
            list.Prepend(item);
        }

        void InsertAt(int index, const T& item) override{
            list.InsertAt(index, item);
        }

        void Set(int index, const T& item) override{
            list.Set(index, item);
        }

        void Swap(int i, int j) override{
            T tmp = list.Get(i);
            list.Set(i, Get(j));
            list.Set(j, tmp);
        }

        void print(){
            list.print();
        }

        void Delete(int index){
            list.Delete(index);
        }

        Sequence<T>* Copy() const override{
            return (Sequence<T>*) (new LinkedListSequence<T>(*this));
        }

        bool operator ==(const LinkedListSequence& lseq){
            return true;
        }

        LinkedListSequence& operator =(const LinkedListSequence& lseq){
            list = lseq.list;
            return *this;
        }

        bool Contains(const T& item) const override {
            for (int i = 0; i < list.GetLength(); i++){
                if (list.Get(i) == item) return true;
            }

            return false;
        }
};