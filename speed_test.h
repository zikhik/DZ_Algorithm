//
//  speed_test.h
//  Dz_Algoritm
//
//  Created by Admin on 15.01.18.
//  Copyright © 2018 Ivan Slavyanskiy. All rights reserved.
//

#ifndef speed_test_h
#define speed_test_h
#include "BinHeap.h"
//#include "BinomHeap.h"
#include <ctime>
#include <iostream>
#include<fstream>
#include <vector>
//#include "Boinomstruct.h"
#include "binomstuct1.h"
#include <list>
using namespace std;


void test_1(string file_out)
{
    ofstream fileout (file_out, ios::out | ios::app);
   
    
    
   
    vector<MinHeap> vec1;
    vector<bmheap*> vec2;
    
    int buff=0;
    
    for (int i=0; i<2; i++)
    {
        MinHeap binh;
        srand(i);
        for(int j=0; j<1000000; j++)
        {
            buff = rand() %1500000000 -750000000;
            binh.insertKey(buff);
        }
        vec1.push_back(binh);
       
    }
    
    /*for (int i=0; i<100000; i++)
    {
        BinomHeap binomh;
        srand(5);
        for(int j=0; j<9; j++)
        {
            buff = rand() %1500000000 -750000000;
            binomh.insert(buff);
        }
        
        vec2.push_back(binomh);
        
    }*/
    for (int i=0; i<2; i++)
    {
    srand(i);
    bmheap* binomh = new bmheap();
        
        for(int j=0; j<1000000; j++)
        {
            
            buff = rand() %1500000000 -750000000;
            binomh = binomh->bmheap_insert(binomh, buff, std::to_string (buff) );
        }
        
        vec2.push_back(binomh);
    }
    
    fileout<< "*********** Start first test ********"<<endl;
    MinHeap bheap;
    vector<MinHeap>::iterator it1;
    clock_t start_clock = clock();
    for(it1 = vec1.begin(); it1!= vec1.end();it1++)
    {
       
        bheap= bheap.merge_bin_heaps(bheap, *it1);
    
    }

    clock_t end_clock = clock();
    clock_t result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl;
    
    bmheap* binomheap = new bmheap();
    vector<bmheap*>::iterator it2;
    start_clock = 0;
    end_clock=0;
    start_clock = clock();
    for(it2 = vec2.begin(); it2!= vec2.end();it2++)
    {
        binomheap = binomheap->bmheap_union(binomheap, *it2);
        
    }
        
    end_clock = clock();
    result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinomHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl;
       
    

    
    
}
/*void test_2(string file_out)
{
    ofstream fileout (file_out, ios::out | ios::app);
    
    srand(3);
    fileout<< "*********** Start second test ********"<<endl;
    MinHeap binh1;
    MinHeap binh2;
    MinHeap binh3;
    MinHeap binh4;
    MinHeap binh5;
    MinHeap binh6;
    MinHeap binh7;
    MinHeap binh8;
    MinHeap binh9;
    MinHeap binh10;
    BinomHeap binomh1;
    BinomHeap binomh2;
    BinomHeap binomh3;
    BinomHeap binomh4;
    BinomHeap binomh5;
    BinomHeap binomh6;
    BinomHeap binomh7;
    BinomHeap binomh8;
    BinomHeap binomh9;
    BinomHeap binomh10;
    int buff=0;
    clock_t start_clock = clock();
    
    for (int i=0; i<1000001; i++)
    {
        buff = rand() %1500000000 -750000000;
        binh1.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh2.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh3.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh4.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh5.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh6.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh7.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh8.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh9.insertKey(buff);
        buff = rand() %1500000000 -750000000;
        binh10.insertKey(buff);
    }
    clock_t end_clock = clock();
    clock_t result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl;
    srand(5);
    start_clock = clock();
    for (int i=0; i<1000001; i++)
    {
        buff = rand() %1500000000 -750000000;
        binomh1.insert(buff);
        buff = rand() %1500000000 -750000000;
        binomh2.insert( buff);
        buff = rand() %1500000000 -750000000;
        binomh3.insert( buff);
        buff = rand() %1500000000 -750000000;
        binomh4.insert(buff);
        buff = rand() %1500000000 -750000000;
        binomh5.insert( buff);
        buff = rand() %1500000000 -750000000;
        binomh6.insert( buff);
        buff = rand() %1500000000 -750000000;
        binomh7.insert( buff);
        buff = rand() %1500000000 -750000000;
        binomh8.insert( buff);
        buff = rand() %1500000000 -750000000;
        binomh9.insert( buff);
        buff = rand() %1500000000 -750000000;
        binomh10.insert( buff);
        
        
    }
    end_clock = clock();
    result_clock = end_clock - start_clock;
    fileout<<"***** BinomHeap - " << (float)result_clock/CLOCKS_PER_SEC << " second *************"<<endl;
    fileout<<"*********** END second test ********"<<endl<<endl<<endl;
    fileout.close();
}
void test_34(string file_out)
{
    ofstream fileout (file_out, ios::out | ios::app);
    
    srand(3);
    fileout<< "*********** Start third test ********"<<endl;
    MinHeap binh;
    BinomHeap binomh;
    int buff=0;
    clock_t start_clock = clock();
    
    for (int i=0; i<3000001; i++)
    {
        buff = rand() %1500000000 -750000000;
        binh.insertKey(buff);
    }
    clock_t end_clock = clock();
    clock_t result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl;
    srand(5);
    start_clock = clock();
    for (int i=0; i<3000001; i++)
    {
        buff = rand() %1500000000 -750000000;
        binomh.insert(buff);
        
    }
    end_clock = clock();
    result_clock = end_clock - start_clock;
    fileout<<"***** BinomHeap - " << (float)result_clock/CLOCKS_PER_SEC << " second *************"<<endl;
    fileout<<"*********** END third test ********"<<endl<<endl<<endl;
    fileout<< "*********** Start fourth test ********"<<endl;
    
    start_clock = clock();
    
    for (int i=0; i<11111; i++)
    {
        binh.extractMin();
    }
    end_clock = clock();
    result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl;
    start_clock = clock();
    for (int i=0; i<11111; i++)
    {
        binomh.extractMin();
        
    }
    end_clock = clock();
    result_clock = end_clock - start_clock;
    fileout<<"***** BinomHeap - " << (float)result_clock/CLOCKS_PER_SEC << " second *************"<<endl;
    fileout<<"*********** END third test ********"<<endl<<endl<<endl;
    fileout.close();
    
}*/

#endif /* speed_test_h */
