#pragma once
#include "./Sequence/ArrSeq.hpp"

template <class T>
class Node {
    public:
        T data;
        int height;
        Node<T>* left;
        Node<T>* right;
        
        Node(){
            left = right = nullptr;
            height = 0;
        }

        Node(const T& data){
            this->data = data;
            height = 1;
            left = right = nullptr;
        }
};

template <class T>
class AVLTree{
    private:
        Node<T>* root;
        int size;
        int height;
        int (*cmp) (const T&, const T&);

        int GetHeight(Node<T>* node) const {
            return node?node->height:0; 
        }

        int GetBfactor(Node<T>* node) const {
            return GetHeight(node->right) - GetHeight(node->left);
        }

        void FixHeight(Node<T>* node){
            int hl = GetHeight(node->left);
            int hr = GetHeight(node->right);
            if (hl>hr) node->height = hl+1;
            else node->height =  hr+1;
        }

        Node<T>* RotateRight(Node<T>* node){
            Node<T>* root = node->left;
            node->left = root->right;
            root->right = node;
            FixHeight(node);
            FixHeight(root);
            return root;
        }

        Node<T>* RotateLeft(Node<T>* node){
            Node<T>* root = node->right;
            node->right = root->left;
            root->left = node;
            FixHeight(node);
            FixHeight(root);
            return root;
        }

        Node<T>* Balance(Node<T>* node){
            FixHeight(node);
            if (GetBfactor(node) == 2){
                if (GetBfactor(node->right) < 0)
                    node->right = RotateRight(node->right);
                return RotateLeft(node);
            }

            if (GetBfactor(node) == -2){
                if (GetBfactor(node->left) > 0)
                    node->left = RotateLeft(node->left);
                return RotateRight(node);
            }

            return node;
        }

        Node<T>* Insert(Node<T>* node, const T& data){
            if (!node) return new Node<T>(data);

            if (cmp(data, node->data) < 0)
                node->left = Insert(node->left, data);
            else
                node->right = Insert(node->right, data);
            return Balance(node);
        }

        Node<T>* GetMin(Node<T>* node) const {
            return node->left?GetMin(node->left):node;
        }

        Node<T>* RemoveMin(Node<T>* node){
            if (!node->left) return node->right;
            node->left = RemoveMin(node->left);
            return Balance(node);
        }//vspomogatelnaya rvet svyazi

        Node<T>* privateRemove(Node<T>* node, const T& data){
            if (!node) return nullptr;
            if (cmp(data, node->data)<0) 
                node->left = privateRemove(node->left, data);
            else if (cmp(data, node->data) > 0)
                node->right = privateRemove(node->right, data);
            else {
                Node<T>* ptr_left = node->left;
                Node<T>* ptr_right = node->right;
                delete node;
                if (!ptr_right) return ptr_left;
                Node<T>* ptr_min = GetMin(ptr_right);
                ptr_min->right = RemoveMin(ptr_right);
                ptr_min->left = ptr_left;
                return Balance(ptr_min);
            }

            return Balance(node);
        }

        void GetSequence(Node<T>* node, Sequence<T>* seq) const {
            if (!node) return;
            GetSequence(node->left, seq);
            seq->Append(node->data);
            GetSequence(node->right, seq);   
        }
        
        T& privateGet(Node<T>* node, const T& key) const {
            if (cmp(node->data, key) == 0) return node->data;
            if (cmp(node->data, key) > 0) return privateGet(node->left, key);
            else return privateGet(node->right, key);
        }

    public:
        AVLTree(int (*cmp)(const T&, const T&)){
            root = nullptr;
            size = 0;
            this->cmp = cmp;
        }

        ~AVLTree(){
            while (root) root = privateRemove(root, root->data);
        }

        Sequence<T>* ToSequence() const {
            Sequence<T>* seq = new ArraySequence<T>();
            GetSequence(root, seq);
            return seq;
        }

        int GetSize() const {
            return size;
        }

        void Add(const T& key){
            root = Insert(root, key);
            size++;
        }

        void Remove(const T& key){
            root = privateRemove(root, key);
            size --;
        }

        T& Get(const T& key) const {
            return privateGet(root, key);
        }
};