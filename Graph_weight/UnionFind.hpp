#pragma once
#include<iostream>
#include<cassert>

using namespace std;


namespace UF1{


class UnionFind{
private:
    int * id;
    int capacity;
public:
    UnionFind(int capacity){

        id = new int[capacity];
        this->capacity = capacity;
    }

    int find(int v){
         assert(v >= 0 && v < capacity);
        return id[v];
    }

    bool isConnected(int v, int w){
        assert(v >= 0 && v < capacity);
        assert(w >= 0 && w < capacity);
        return id[v] = id[w];
    }

    void Union(int v, int w){
         assert(v >= 0 && v < capacity);
         assert(w >= 0 && w < capacity);
         int idv = id[v];

         for (int i = 0 ; i < capacity ; i++ ){

             if(idv == id[i]){

                 id[i] = id[w];
             }
         }



    }





};






}


namespace UF2{

class UnionFind{

private:
    int* parent;
    int capacity;
public:
    UnionFind(int capacity){

        parent = new int[capacity];
        this->capacity = capacity;
        for(int i = 0 ; i < capacity; i++){

            parent[i] = i;
        }
    }

    int find(int v){
         assert(v >= 0 && v < capacity);
        // assert(w >= 0 && w < capacity);

        while(v != parent[v]){
            v = parent[v];
            

        }


        return v;
    }


    bool isConnect(int v , int w){
            assert(v >= 0 && v < capacity);
            assert(w >= 0 && w < capacity);

            return  find(v) == find(w);

    }

    void Union(int v, int w){

         assert(v >= 0 && v < capacity);
         assert(w >= 0 && w < capacity);
        int rootv = find(v);
        int rootw = find(w);

        parent[rootv] = rootw;
       
        


    }


};








}