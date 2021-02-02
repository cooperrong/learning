#include<iostream>
#include<ctime>
#include"IndexMinHeap.hpp"

using namespace std;

void test(){
    srand(time(NULL));
    int V = 10;
IndexMinHeap<int> heap(V);

for(int i = 0 ; i < V; i=i+2){
    int temp = rand()%100;

    heap.insert(i,temp);
    cout<<temp<<" ";
}

cout<<endl;

for(int i = 0 ; i < V ; i++){

    cout<<heap.extra()<<" ";
}

cout<<endl;


}

int main(){

    test();

    system("pause");
    return 0;
}