/**
 * BitOutputStream.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/20
 * The class is for FINAL SUBMISSION, output bit by bit
 */

#include "BitOutputStream.hpp"

using namespace std;

void BitOutputStream::put(char i){
    if(count < 0){
        flush();
    }

    if (i == '0'){
        buffer.set(count, 0);
        count--;
    }else if (i == '1'){
        buffer.set(count, 1);
        count--;
    }
}

void BitOutputStream::flush(){
    unsigned int num = buffer.to_ulong();
    unsigned char ch = (unsigned char) num;
    out.put(ch);
    count = 7;
}
