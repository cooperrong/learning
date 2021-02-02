#pragma once
#include<iostream>
#include<cassert>
using namespace std;

namespace UF2{

class Unionfind2{
private:
    int* parent;
    int count;
public:
    Unionfind2(int n){

        this->count = n;
        parent = new int[this->count];
        for(int i =0;i < this->count;i++){

            parent[i] = i;
        }
    }
    ~Unionfind2(){
        delete [] parent;
    }

    int find(int p){
        assert(p >= 0 && p < this->count );
        while(p != parent[p]){

            p = parent[p];
        }
        return p;

    }

    bool isConnect(int p,int q){
        return find(p) == find(q);
    }

    void unionelements(int p,int q){

            int rootp = find(p);
            int rootq = find(q);
        if(rootp == rootq){
            return;
        }

        parent[rootp] = rootq;
    }



};





}
