#pragma once
#include<algorithm>
#include<iostream>
#include<cassert>

using namespace std;

template<class Item>
class MinHeap{
private:
    Item* data;
    int  count;
    int capacity;

    void shiftUp(int k){


        while(k > 1 && data[k] < data[k/2]){
            swap(data[k],data[k/2]);
            k/=2;

        }
    }


    void shiftDown( int k){

        while( k*2 <= count ){  //这里有两个问题需要解决，1.k的边界问题，即k不大于count但是k可以等于count，2.data[k]要跟k的左右子树进行比较，而不是只比较一个

            int j = 2*k;
            if(j+1 <= count && data[j] > data[j+1])j++;
            if(data[k] <= data[j]){
                break;
            }
            else{
                swap(data[k],data[j]);
                k = j;
            }

        }

    }

public:
    MinHeap(int capacity){

        this->capacity = capacity;
        data = new Item[capacity+1];
        count = 0;
    }

    MinHeap(Item arr[],int n){
        data = new Item[n+1];
        capacity = n;
        count = n;

        for(int i =0; i < n; i++){

            data[i+1] = arr[i];
        }

        for(int i = count/2;i > 0;i--){

            shiftDown(i);
        }


    }
    ~MinHeap(){

        delete [] data;
    }

    void insrtelement(Item x){
        assert(count+1 <= capacity);
        data[count+1] = x;
        shiftUp(count+1);
        count++;
    }
    int size(){

        return count;

    }

    bool isEmpty(){


        return this->count == 0;
    }

    Item extractMin(){
        assert(count>0);
        Item temp;
        temp = data[1];
        swap(data[1],data[count]);
        count--;                             //先count--后shiftdown(1);这样保证count这个元素被剔除
        shiftDown(1);
        return temp;
    }

    Item getMin(){

        assert(count >0);
        return data[1];
    }


};