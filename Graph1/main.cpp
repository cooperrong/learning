#include<iostream>
#include<ctime>
#include<vector>
#include"DensGraph.h"
#include"SparseGraph.h"
#include"ReadGraph.h"
#include"Component.h"
#include"Path.h"
#include"ShortPath.h"
using namespace std;

void test(){
vector<int> ius;


string filename1 = "testG1.txt";
SparseGraph sgraph(13,false);

ReadGraph<SparseGraph> file1(sgraph,filename1);
Component<SparseGraph> component1(sgraph);
cout<<"compon1 = "<< component1.count()<<endl;
sgraph.grahpshow();
Path<SparseGraph> p(0,sgraph);
p.showpath(6,ius);

string filename2 = "testG2.txt";
DensGraph dgraph(7,false);
ReadGraph<DensGraph> file2(dgraph,filename2);
Component<DensGraph> component2(dgraph);
cout<<"component = "<< component2.count()<<endl;
Path<DensGraph> p1(0,dgraph);
p1.showpath(6,ius);
ShortPath<DensGraph> s1(0,dgraph);
s1.showpath(6);


dgraph.graphshow();

}

int main(){


    test();
    system("pause");
    return 0;
}