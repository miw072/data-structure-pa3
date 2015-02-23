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
        
        /* BitOutputStream::put(char i)
         * This method is to put a bit to the buffer 
         * Input: the bit to be put in present as char
         */
        void put(char bit);
        
        /* BitOutputStream::flush()
         * This method is to flush the buffer out as a byte 
         */
        void flush();
        
        /* BitOutputStream::writeByte(byte ch)
         * This method is to write a byte to buffer, for header-writing use
         * Input: the byte to be wrttien
         */        
        void writeByte(byte ch);
};


#endif
