#include<iostream>
#include<ctime>
#include"SparseGraph.hpp"
using namespace std;


void test(){


srand(time(NULL));

int N = 20;
int M =100;

SparseGraph g(N,false);

for(int i = 0;i < M;i++){


    int a = rand()%N;
    int b = rand()%N;

    g.addEdge(a,b);
}

int w;
for(int j=0; j < N; j++){

SparseGraph::adjSparseGraph adj(j,g);
cout<<j<<":";

for(w = adj.begin();!adj.end();w = adj.next()){

    
    cout<<w<<" ";




}
cout<<endl;


}
}


int main(){

    test();

    system("pause");
    return 0;
}