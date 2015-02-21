/**
 * BitOutputStream.hpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/18
 * The class is for FINAL SUBMISSION, output bit by bit
 */
 
#ifndef BITOSTREAM_HPP
#define BITOSTREAM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>


typedef unsigned char byte;

using namespace std;

class BitOutputStream{
    private :
        ostream &out;
        bitset<8> buffer;
        int count;
        
    public :
        BitOutputStream(ostream &output):out(output){
            buffer.reset();
            count = 7;
        }
        
        void put(char bit);
        
        void flush();
        
        //void writeToFile(); 
};


#endif
