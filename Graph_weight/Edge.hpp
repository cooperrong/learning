#pragma once
#include<iostream>
#include<cassert>
using namespace std;

template<class Weight>
class Edge{
private:
    int a,b;
    Weight weight;
public:
    Edge(int v, int w,Weight weight){

         this->a = v;
         this->b = w;
         this->weight = weight;

    }
    Edge(){}

    int V(){

        return a;

    }
    int W(){

        return b;
    }

    Weight Wt(){

        return weight;

    }
    int other(int x){
        assert(x == this->a|| x==this->b);
       
        return x == a?b:a;
    }


    friend ostream& operator<<(ostream &os, const Edge &e){


        os<<e.a<<" - "<<e.b<< " weiht:"<<e.weight<<"  ";
        return os;
    }

    bool operator<(const Edge & e){

        return this->weight < e.weight;
    }
    bool operator<=(const Edge & e){

        return this->weight <= e.weight;
    }
    bool operator>=(const Edge & e){

        return this->weight >= e.weight;
    }
    bool operator>(const Edge & e){

        return this->weight > e.weight;
    }





};