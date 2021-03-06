#pragma once
#include<iostream>
#include<cassert>


using namespace std;


namespace UF1{


class Unionfind{

private:
    int* id;
    int count;
public:
    Unionfind(int n){

    count = n;
    id = new int[count];
    for(int i = 0; i< count; i++){

        id[i] = i;
    }
}
~Unionfind(){

    delete [] id;
}

int find(int p){
    assert(p >= 0 && p < this->count);
    return id[p];
}
bool isConnected(int p,int q){

    return find(p) == find(q);
}

void unionElements(int p,int q){


    int pID = find(p);
    int qID = find(q);
    if(pID == qID){

        return;
    }

    for(int i=0;i< this->count;i++){

        if(id[i]== pID){
            id[i]= qID;
        }
    }
}

};

}