#include<iostream>
#include<string>
#include"Solution.hpp"
#include"BinaryTree.hpp"

using namespace std;

void test(){

BinaryTree<int,int> bt;
bt.insertrecu(29,100);
bt.insertrecu(90,100);

bt.deleteMin();
bt.deleteMax();
cout<<"size = "<<bt.size()<<endl;

}

int main(){

test();

system("pause");
return 0;

}