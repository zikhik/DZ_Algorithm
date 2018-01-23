//
//  work_with_file.h
//  Dz_Algoritm
//
//  Created by Admin on 16.01.18.
//  Copyright © 2018 Ivan Slavyanskiy. All rights reserved.
//

#ifndef work_with_file_h
#define work_with_file_h
#include "BinHeap.h"
#include <iostream>
#include<fstream>
#include "funcbinom.h"
using namespace std;

int inp_from_file(string file_in, string file_out)
{
    std::ifstream fin(file_in, ios::in );
    std::ofstream fout(file_out, ios::out | ios::app);
    if (!fin) return 1;
    std::string command;
    
    
    node* binomh = nullptr;
    MinHeap binh;
    
    while (!fin.eof()) {
        fin >> command;
        if (command == "Insert")
        {
            int key;
            fin >> key;
            binh.insertKey((int)key);
            binomh = Insert((int)key, binomh);
            
        }
        if (command == "GetMin")
        {
            fout<<binh.getMin();
            fout<<GetMin(binomh);
            
        }
        if (command == "Print")
        {
            binh.printfile(file_out);
            printfilebinom(binomh, file_out);
        }
        
    
        
        if (command == "ExtractMin")
        {
            binh.extractMin();
            binomh = ExtractMin(binomh, 1);
        }
        if (command == "GetMax")
        {
            fout<<binh.getmax();
            fout<<GetMax(binomh);
            
        }

    }
    
        return 0;


}

#endif /* work_with_file_h */
