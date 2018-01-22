//
//  main.cpp
//  Dz_Algoritm
//
//
//  Copyright © 2017 Ivan Slavyanskiy. All rights reserved.
//
#include "speed_test.h"
#include <iostream>
#include "BinHeap.h"
#include "binomstuct1.h"
#include "work_with_file.h"
using namespace std;

int main(int argc, char* argv[])
{
    cout<< argc<<endl;
    cout<< argv[1]<<endl;
    cout<< argv[2]<<endl;
    cout<< argv[3]<<endl;
    if (argc !=4) return 0;
    string in_f = argv[1];
    string out_f = argv[2];
    string mode_work = argv[3];
    if ((mode_work != "file_test") && (mode_work != "speed_test")) return 0;
    
    if (mode_work == "file_test")
    {
       // cout<<inp_from_file(in_f, out_f);
    };
    if (mode_work == "speed_test")
    {
        test_1(out_f);
        //test_2(out_f);
        //test_34(out_f);
        
        
    };
   
    
    //test2->print_heap();
    
    
    return 0 ;
    
};
