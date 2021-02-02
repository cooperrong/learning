#include<iostream>
#include<string>
#include<ctime>
#include"SparseGraph.hpp"
#include"DensGraph.hpp"
#include"ReadGraph.hpp"
#include"MinHeap.hpp"
#include"Edge.hpp"
#include"LazyPrimMST.hpp"
#include"IndexMinHeap.hpp"
#include"Prim.hpp"
#include"UnionFind.hpp"
#include"Dijkstra.hpp"
#include"BellmanFord.hpp"
#include"Krusk.hpp"

using namespace std;


void test(){
   

   string filename = "Graph5.txt";

   SparseGraph<double> sgraph(4,true);
   ReadGraph<SparseGraph<double>,double> file(filename,sgraph);
   Dijkstra<SparseGraph<double>,double>  dist(0,sgraph);
   dist.showPath(0);
   dist.showPath(1);
   dist.showPath(2);
   dist.showPath(3);
   

    
}

int main(){

    test();


    system("pause");
    return 0;
}