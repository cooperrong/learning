#pragma once
#include<iostream>
#include<ctime>
#include<iostream>
#include<ctime>
#include"Unionfind.h"
#include"Unionfind2.h"
#include"Unionfind3.h"
#include"Unionfind4.h"
using namespace std;

namespace UnionfindTestHelper{

void testUF1(int n){


    srand(time(NULL));
    UF1::Unionfind uf =UF1::Unionfind(n);
    time_t startTime = clock();
    for(int i = 0; i < n ; i++){
        int a = rand()%n;
        int b = rand()%n;
        uf.unionElements(a,b);
    }

    for(int i =0 ;i<n;i++){
        int a = rand()%n;
        int b = rand()%n;
        uf.isConnected(a,b);
    }

    time_t endTime = clock();

    cout<<"UF1, "<<2*n<<" ops  "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
}



void testUF2(int n){

srand(time(NULL));

UF2::Unionfind2 uf = UF2::Unionfind2(n);
time_t startTime = clock();

for(int i = 0;i < n;i++){

    int a= rand()%n;
    int b = rand()%n;

    uf.unionelements(a,b);
}
for(int i = 0;i < n;i++){

    int a= rand()%n;
    int b = rand()%n;

    uf.isConnect(a,b);
}

time_t endTime = clock();
cout<<"UF2, "<<2*n<<" ops "<<double(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl;
}


void testUF3( int n){

    srand(time(NULL));

    UF3::Unionfind3 uf = UF3::Unionfind3(n);
    time_t startTime = clock();

    for(int i = 0;i < n ; i++){

        int a = rand()%n;
        int b = rand()%n;

        uf.unionelements(a,b);

    }
    for(int i = 0;i < n ; i++){

        int a = rand()%n;
        int b = rand()%n;

        uf.isConnected(a,b);
        
    }

    time_t endTime = clock();

    cout<<"UF3, "<<2*n<<" ops "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

}

void testUF4( int n){

    srand(time(NULL));

    UF4::Unionfind4 uf = UF4::Unionfind4(n);
    time_t startTime = clock();

    for(int i = 0;i < n ; i++){

        int a = rand()%n;
        int b = rand()%n;

        uf.unionelements(a,b);

    }
    for(int i = 0;i < n ; i++){

        int a = rand()%n;
        int b = rand()%n;

        uf.isConnected(a,b);
        
    }

    time_t endTime = clock();

    cout<<"UF4, "<<2*n<<" ops "<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;

}



}
