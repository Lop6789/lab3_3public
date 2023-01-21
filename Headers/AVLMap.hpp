#pragma once
#include "IMap.hpp"
#include "AVLTree.hpp"
#include "Pair.hpp"

template <class TKey, class TElement>

class AVLMap : public IMap<TKey, TElement>{

    private:    
        AVLTree<Pair<TKey, TElement>> data;

    public:
        AVLMap(int(*cmp)(const Pair<TKey, TElement>&, const Pair<TKey, TElement>&)) : data(cmp) {}
        
        ~AVLMap(){}

        int GetSize() const override {
            return data.GetSize();
        }

        TElement& Get(const TKey& key) const override {
            // if (ContainsKey(key)){
            Pair<TKey, TElement> pair(key);
            return (data.Get(pair)).GetElement();
            // }
        }

        void Add(const TKey& key, const TElement& element) override {
            Pair<TKey, TElement> pair(key, element);
            data.Add(pair);
        }

        void Remove(const TKey& key) override {
            Pair<TKey, TElement> pair(key);
            data.Remove(pair);
        }

        Sequence<TKey>* GetKeys() const override {
            Sequence<Pair<TKey, TElement>>* pairs = data.ToSequence();
            Sequence<TKey>* keys = new ArraySequence<TKey>();
            for (int i = 0; i < pairs->GetLength(); i++){
                keys->Append(pairs->Get(i).GetKey());
            }
            delete pairs;
            return keys;
        }

        Sequence<TElement>* GetElements() const override {
            Sequence<Pair<TKey, TElement>>* pairs = data.ToSequence();
            Sequence<TElement>* elements = new ArraySequence<TElement>();
            for (int i = 0; i < pairs->GetLength(); i++){
                elements->Append(pairs->Get(i).GetElement());
            }
            delete pairs;
            return elements;
        } 


        // bool ContainsKey(const TKey& tkey) const override {
        //     Sequence<TKey>* keys = GetKeys();
        //     for (int i = 0; i < keys->GetLength(); i++){
        //         if (tkey == keys->Get(i)) return true;
        //     }
        //     return true;
        // }





};


