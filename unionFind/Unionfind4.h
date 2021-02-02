#pragma once
#include<iostream>
#include<cassert>

using namespace std;

namespace UF4{

class Unionfind4{

private:
    int* parent;
    int* rank;
    int count;
public:
    Unionfind4(int n){

        this->count = n;
        parent = new int[this->count];
        rank = new int[this->count];
        for(int i = 0; i< n; i++){

            parent[i] = i;
            rank[i] = 1;
        }

    }
    ~Unionfind4(){


        delete [] parent;
        delete [] rank;

    }
    int find(int p){
        assert(p >= 0 && p< this->count);

        // while(p != parent[p]){
        //     parent[p] = parent[parent[p]];
        //     p = parent[p];

        // }
        // return p;

        if( p != parent[p]){
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    bool isConnected(int p,int q){

       return find(q) == find(p);

    }

    void unionelements(int p, int q){
        assert(p >= 0 && p< this->count);
        assert(q >= 0 && q< this->count);
        int  rootq = find(q);
        int rootp = find(p);
        if(rootp == rootq) return;
        if(rank[rootq] > rank[rootp]){

         parent[rootp] = rootq;
         
        }
        else if(rank[rootq] < rank[rootp]){
            parent[rootq] = rootp;
            
        }
        else{


            parent[rootq] = rootp;
            rank[p]++;
        }


    }









};







}