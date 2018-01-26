//
//  correct.h
//  Dz_Algoritm
//
//  Created by Admin on 23.01.18.
//  Copyright © 2018 Ivan Slavyanskiy. All rights reserved.
//

#ifndef correct_h
#define correct_h
#include "BinHeap.h"
#include "funcbinom.h"
#include <cstring>
using namespace std;

void correct_tests(string file_out)
{
    ofstream fout (file_out, ios::out | ios::app);
    fout<< "***** Start Correct Tests *****"<<endl<<endl;
    node* binomh = nullptr;
    MinHeap binheap;
    int test = 34;
    fout<<"***** Insert one key *****"<<endl;
    binheap.insertKey(test);
    binomh = Insert(test, binomh);
    if (binheap.harr[0] == test) fout<< "BinHeap - OK!";
        else fout<< "BinHeap - ERROR!";
    if (binomh->data == test) fout<< "BinomHeap - OK!";
        else fout<< "BinomHeap - ERROR!";
    
    fout<<"***** Get Min key *****"<<endl;
    test =  binheap.getMin();
    if (test==34 ) fout<< "BinHeap - OK!"<<endl;
    else fout<< "BinHeap - ERROR!"<<endl;
    test = GetMin(binomh);
    if (test==34 ) fout<< "BinomHeap - OK!"<<endl;
    else fout<< "BinomHeap - ERROR!"<<endl;
    
    fout<<"***** Get Max key *****"<<endl;
    test =  binheap.getmax();
    if (test==34 ) fout<< "BinHeap - OK!"<<endl;
    else fout<< "BinHeap - ERROR!"<<endl;
    test = GetMax(binomh);
    if (test==34 ) fout<< "BinomHeap - OK!"<<endl;
    else fout<< "BinomHeap - ERROR!"<<endl;
    
    fout<<"***** Exctract Min key *****"<<endl;
    test =  binheap.extractMin();
    binomh = ExtractMin(binomh, 1);
    if ((test ==34) &&(binomh->data == 34)) fout<< "BinHeap - OK!"<<endl<< "BinomHeap - OK!"<<endl;
    else fout<< "BinHeap - ERROR!"<<endl<<"BinomHeap - ERROR!"<<endl;
    
    

    
}

#endif /* correct_h */
