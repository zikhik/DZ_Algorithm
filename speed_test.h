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
#include <ctime>
#include <iostream>
#include<fstream>
#include <vector>
#include "funcbinom.h"
using namespace std;


void test_1(string file_out)
{
    ofstream fileout (file_out, ios::out | ios::app);
   
    MinHeap binh;;
    node* binomh = nullptr;
    int buff=0;
    clock_t start_clock = clock();
    fileout<< "*********** Start first test ********"<<endl;
    for (int i=0; i<20160; i++)
    {
        srand(i);
        buff = rand() %1500000000 -750000000;
        binh.insertKey(buff);
    }


    clock_t end_clock = clock();
    clock_t result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl;
    start_clock = clock();
    for (int i=0; i<20160; i++)
    {
        srand(i);
        buff = rand() %1500000000 -750000000;
        binomh = Insert(buff,binomh);
        
    }
    end_clock = clock();
    result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinomHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl<<endl<<endl;
       
    

    
    fileout.close();
}
void test_2(string file_out)
{
    ofstream fileout (file_out, ios::out | ios::app);
    vector<MinHeap> vec1;
    vector<node*> vec2;
    int buff=0;
    
    fileout<< "*********** Start second test ********"<<endl;
    
    clock_t start_clock = clock();
    
    for (int i=0; i<2000; i++)
    {
        MinHeap binh;
        srand(i);
        for(int j=0; j<10000; j++)
        {
            buff = rand() %1500000000 -750000000;
            binh.insertKey(buff);
        }
        vec1.push_back(binh);
        
    }
    MinHeap bheap;
    vector<MinHeap>::iterator it1;
    for(it1 = vec1.begin(); it1!= vec1.end();it1++)
    {
        
        bheap= bheap.merge_bin_heaps(bheap, *it1);
        
    }

    clock_t end_clock = clock();
    clock_t result_clock = end_clock - start_clock;
    fileout<<"************* Result: ****************"<<endl;
    fileout<<"***** BinHeap - "<< (float)result_clock/CLOCKS_PER_SEC<< " second *************"<<endl;
    start_clock = clock();
    
    for (int i=0; i<2000; i++)
    {
        srand(i);
        node* binomh = nullptr;
        
        for(int j=0; j<10000; j++)
        {
            
            buff = rand() %1500000000 -750000000;
            binomh = Insert(buff, binomh);
        }
        
        vec2.push_back(binomh);
    }

    node* binomheap = nullptr;
    binomheap=vec2.at(0);
    start_clock = 0;
    end_clock=0;
    start_clock = clock();
    for(int i=0; i<vec2.size()-1; i++)
    {
        binomheap = Union(binomheap, vec2.at(i+1));
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
    node* binomh = nullptr;
    int buff=0;
    clock_t start_clock = clock();
    
    for (int i=0; i<1209600; i++)
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
    for (int i=0; i<1209600; i++)
    {
        buff = rand() %1500000000 -750000000;
        binomh = Insert(buff,binomh);
        
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
        binomh =ExtractMin(binomh, 1);
        
    }
    end_clock = clock();
    result_clock = end_clock - start_clock;
    fileout<<"***** BinomHeap - " << (float)result_clock/CLOCKS_PER_SEC << " second *************"<<endl;
    fileout<<"*********** END fourth test ********"<<endl<<endl<<endl;
    fileout.close();
    
}

#endif /* speed_test_h */
