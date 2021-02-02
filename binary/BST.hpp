#include<iostream>
using namespace std;

template<class Key,class Value>
class BST{

private:
    struct Node{

        Key key;
        Value value;
        Node* left;
        Node* right;
        Node(Key key,Value value){
            this->key = key;
            this->left = left;
            this->right = this->left =NULL;

        }
    };

    Node* root;
    int count;
public:
    BST(){
        this->root = NULL;
        this->count = 0;
    }
    ~BST();

    bool isEmpty(){
        return this->count == 0;
    }

    int size(){
        return this->count;
    }

    void insert(Key key,Value value){
        this->root = insert(root,key,value);
    }

    bool contain(Key key){
        return contain(root,key);

    }
private:
    Node* insert(Node* node,Key key,Value value){

        if(node == NULL){

           // node = ;
            this->count++;
            return new Node(key,value);
        }
        else if(node->key == key){
            node->value = value;
        }
        else if(node->key > key){
            node->left = insert(node->left,key,value);
        }
        else if(node->key < key){

            node->right = insert(node->right,key,value);
        }
    }
    bool contain(Node* node,Key key){
        if(node == NULL){
            return false;
        }
        else if(node->key == key){
            return true;
        }
        else if(node->key > key){
            return contain(node->left,key);
        }
        else{
            return contain(node->right,key);
        }
    }


};

