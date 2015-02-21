/**
 * BitInputStream.hpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/18
 * The class is for FINAL SUBMISSION, input bit by bit
 */
 
#ifndef BITISTREAM_HPP
#define BITISTREAM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

typedef unsigned char byte;

using namespace std;

class BitInputStream{
    private :
        istream &in;
        bitset<8> buffer;
        int count;
        
    public :
        BitInputStream(istream &input, unsigned int total): in(input){
            buffer.reset();
            count = 0;
        }
        
        void fill();
        
        bool getBit();
        
        //bool isEmpty();
};


#endif
