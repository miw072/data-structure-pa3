/**
 * HCNode.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingyu Wang(TO DO) 2015/2/11
 * This cpp file is used to define HCNode, overload the '<' operator
 * Note that '<' is used for priority compare.
 */

#include "HCNode.hpp"

//overload the operator ' <'
//if the count is equal, then compare them by the ASCII code of the symbol
//else compare the count
bool HCNode::operator < (const HCNode& other){
  if (this->count == other.count){
    return this->symbol < other.symbol;
  }
  return this->count > other.count;
}