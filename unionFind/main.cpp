#include<iostream>
#include"Unionfind.h"
#include"UnionfindTestHelper.h"
using namespace std;

int find( int i,int arr[]){
    
    if (i != arr[i]){

        arr[i] = find(arr[i],arr);
    }
    return arr[i];
}

void test(){
int arr[]= {1,2,3,4,5,6,7,8,9,9};

find(0,arr);
for(int i= 0;i<10;i++){

    cout<<arr[i]<<endl;
}


}

int main(){

    test();

    system("pause");
    return 0;
}