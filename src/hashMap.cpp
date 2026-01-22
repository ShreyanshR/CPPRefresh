#include <iostream>
#include <vector>

class Node{
    public:
        int key;
        int value;
        Node* next;

        Node(int key, int value)
            : key(key), value(value), next(nullptr) {}
};

class HashTable{
    private:
        int capacity;
        int size;
        std::vector<Node*> table;

        int hasFunction(int key){
            return key % capacity;
        }

    public:
        HashTable(int capacity)
            : capacity(capacity), size(0){
                table.resize(capacity, nullptr);
            }

        void insert(int key, int value){
            int index = hashFunction(key);
            Node* node = table[index];

            if (!node){
                table[index] = new Node(key, value);
            }
        }   
}

