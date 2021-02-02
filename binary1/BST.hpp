#include<iostream>
#include<queue>
using namespace std;

template<class Key,class Value>
class BST {

private:
    struct Node{

        Key key;
        Value value;
        Node* left;
        Node* right;
        Node(Key key,Value value){
            this->key = key;
            this->value = value;
            this->left = NULL;
            this->right = NULL;
        }
    };

    Node* root;
    int count;
public:
    BST(){
        this->count = 0;
        this->root = NULL;
    }

    ~BST(){

        destroy(this->root);
        cout<<"size = "<<this->size()<<endl;
    }

    int size(){
        return this->count;
    }

    bool isEmpty(){
        return this->count == 0;
    }

    void insert(Key key,Value value){

        this->root = insert(this->root,key,value);
    }
    // depth-first traversal

    //previd traveral

    void predepthprint(){

        predepthprint(this->root);
    }


    //inorder traversal
    void indepthprint(){

        indepthprint(this->root);
    }

    //postorder traversal

    void postdepthprint(){
        postdepthprint(this->root);
    }

    //breath-first traveral

    void breathPrint(){
        breathPrint(this->root);
    }
    Key minimum(){
        if(this.root == NULL){
            return -1;
        }

        Node* minNode = minimum(this->root);
        return minNode->key;
    }

    void deletMin(){

        this->root = deletMin(this->root);
    }

private:

    Node* insert(Node* node,Key key,Value value){
            if(node == NULL){

                this->count++;
                return new Node(key,value);
            }
            else if(node->key == key){

                node->value = value;
                return node;
            }
            else if(node->key > key){

                node->left = insert(node->left,key,value);
            }
            else{

                 node->right = insert(node->right,key,value);
            }



    }

    void predepthprint(Node* node){

        if(node){

            cout<<node->key<<" ";
            predepthprint(node->left);
            predepthprint(node->right);
        }
    }

    void indepthprint(Node* node){

        
        if(node){

            
            indepthprint(node->left);
            cout<<node->key<<" ";
            indepthprint(node->right);
        }

    }

    void  postdepthprint(Node* node){

        if(node){

            
            postdepthprint(node->left);
            postdepthprint(node->right);
            cout<<node->key<<" ";
        }
    }

//destroy()

void destroy(Node* node){

    if(node){

        destroy(node->left);
        destroy(node->right);
        delete node;
        this->count--;
    }
}

//breath-first traversal

void breathPrint(Node* root){
    if(root == NULL)return;

    queue<Node*> q;
    Node* node;
    q.push(root);
    while(!q.empty()){

        node = q.front();
        cout<<node->key<<" ";
        q.pop();
        if(node->left){
            q.push(node->left);
            cout<<" left ";
            }
        if(node->right){
            q.push(node->right);
            cout<<" right ";
        }

        cout<<endl;
    }



}

Node* minimum(Node* node){

    if(node->left  == NULL){
        return node;
    }
    return minimum(node->left);
}


//delete Min

Node* deletMin(Node* node){

    if(node->left == NULL){
        Node* newNode = node->right;
        delete node;
        return newNode;
    }

    node->left = deletMin(node->left);
    return node;
}

};