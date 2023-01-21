#pragma once

template <class TKey, class TElement>
class IMap {
    private:


    public:
        virtual ~IMap(){}

        virtual int GetSize() const = 0;
        virtual TElement& Get(const TKey&) const = 0;
        virtual void Add(const TKey&, const TElement&) = 0;
        virtual void Remove(const TKey&) = 0;
        virtual Sequence<TKey>* GetKeys() const = 0;
        virtual Sequence<TElement>* GetElements() const = 0;
};