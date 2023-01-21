#pragma once

template <class TKey, class TElement>
class Pair{
    private:
        TKey key;
        TElement element;
    public:
        Pair(){}

        Pair(const TKey& key){
            this->key = key;
        }

        Pair(const TKey& key, const TElement& element){
            this->key = key;
            this->element = element;
        }

        ~Pair(){}

        TKey& GetKey() const {
            return (TKey&)key;
        }

        TElement& GetElement() const {
            return (TElement&)element;
        }
        
        bool operator ==(const Pair<TKey, TElement>& pair){
            if (key==pair.key) return true;
            else return false;
        }

};
