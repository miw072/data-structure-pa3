/**
 * BitInputStream.hpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/18
 * The class is for FINAL SUBMISSION, input bit by bit
 */
 
#ifndef BITISTREAM_HPP
#define BITISTREAM_HPP

#include <iostream>
#include <fstream>


typedef unsigned char byte;

using namespace std;

class BitInputStream{
    private :
        istream &in;
        unsigned char buffer;
        int nbits;
        
    public :
        BitInputStream(istream &input): in(input){
            buffer = 0;
            nbits = 8;
        }
        
        void fill();
        
        char getBit();
        
        //bool isEmpty();
};


#endif
