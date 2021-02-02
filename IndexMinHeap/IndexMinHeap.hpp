#pragma once
#include<iostream>
#include<cassert>
using namespace std;


template<class Item>
class IndexMinHeap{
private:
    Item *data;
    int * indexes;
    int* reverse;
    int count;
    int capacity;

    void shiftUp(int k){

        while(k > 0){

            if(data[indexes[k]] < data[indexes[(k-1)/2]]){

                swap(indexes[k],indexes[(k-1)/2]);
                reverse[indexes[k]] = k;
                reverse[indexes[(k-1)/2]] = (k-1)/2;

            }
            else{

                break;
            }

            k = (k-1)/2;


        }



    }


    void shiftDown(int k){

            int j = 0;
        while( 2*k+1 < count){
            j = 2*k+1;
            if(j+1 < count && data[indexes[j]] > data[indexes[j+1]])j++;

            if(data[indexes[k]] > data[indexes[j]]){

                swap(indexes[k],indexes[j]);
                reverse[indexes[k]] = k;
                reverse[indexes[j]] = j;
            }
            else{

                break;
            }

            k = j;


        }



    }
public:
    IndexMinHeap(int capacity){
        data = new Item[capacity];
        indexes = new int[capacity];
        reverse = new int[capacity];
        this->count = 0;
        this->capacity = capacity;
        for(int i = 0; i < capacity; i++){

            reverse[i] = -1;
        }

    }

    ~IndexMinHeap(){

        delete [] data;
        delete [] indexes;
        delete [] reverse;
    }

    void insert(int index, Item item){
        assert(index >= 0 && index < capacity);
        if(reverse[index] == -1){

            data[index] = item;
            indexes[count] = index;
            reverse[index] = count;

            
            shiftUp(count);
            count++;


        }
        


    }

    Item extra(){

        if(count){

            Item ret = data[indexes[0]];
            swap(indexes[0],indexes[count-1]);
            reverse[indexes[0]] = 0;
            reverse[indexes[count-1]] = -1;
                 count--;
                shiftDown(0);
            

                return ret;

        }
        else{


            return NULL;
        }



    }

    bool contain(int index){

        return reverse[index] == -1;
    }

    void change(int index, Item item){

        if(reverse[index] != -1){

            data[index] = item;

            int j = reverse[index];
            shiftUp(j);
            shiftDown(j);
            




        }



    }


};