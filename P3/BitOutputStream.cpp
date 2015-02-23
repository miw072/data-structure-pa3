/**
 * BitOutputStream.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingjue Wang(A97007709) 2015/2/20
 * The class is for FINAL SUBMISSION, output bit by bit
 */

#include "BitOutputStream.hpp"

using namespace std;


/* BitOutputStream::put(char i)
 * This method is to put a bit to the buffer 
 * Input: the bit to be put in present as char
 */
void BitOutputStream::put(char i){
    //buffer is full, need to flush out as a byte
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

/* BitOutputStream::flush()
 * This method is to flush the buffer out as a byte 
 */
void BitOutputStream::flush(){
    unsigned long int num = buffer.to_ulong();
    unsigned char ch = static_cast<unsigned char>(num);
    out.put(ch);
    count = 7;
}

/* BitOutputStream::writeByte(byte ch)
 * This method is to write a byte to buffer, for header-writing use
 * Input: the byte to be wrttien
 */
void BitOutputStream::writeByte(byte ch){
    for (int i = 0; i < 8; i++){
        put(((ch >> (7 - i)) & 1) + '0');
    }
}
