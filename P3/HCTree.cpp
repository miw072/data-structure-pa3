/**
 * HCNode.cpp for PA3
 * Author: Mingxuan Wang(A53077257) & Jingyu Wang(TO DO) 2015/2/11
 * This cpp file is used to implement HCTree opeartions defined in HCTree.hpp
 */
 
#include "HCTree.hpp"
#include<algorithm>

using namespace std;

/* deleteAll(HCNode * node)
 * This helper method is to delete all nodes in a HCTree
 * Input: Root of a HCTree
 */
void deleteAll(HCNode *node){
	if (node){
		deleteAll(node->c0);
		deleteAll(node->c1);
		delete node;
	}
}

HCTree::~HCTree(){
	deleteAll(this->root);
}

/* HCTree::build(const vector<int>& freqs)
 * This method is to build a HCTree which is used to encode and decode 
 * Input: freqs is a int vector contains frequency of occurance of each byte of infile
 */
void HCTree::build(const vector<int>& freqs){

	typedef priority_queue<HCNode*,vector<HCNode*>,HCNodePtrComp> PQ;
  PQ huffPQ;
  
  //get frequency of each byte, use it to create a HCNode and push it into the priority queue
	for (int i = 0; i < freqs.size(); i++){
		if (freqs[i] != 0){
		leaves[i] = new HCNode(freqs[i], (unsigned char)i);
		huffPQ.push(leaves[i]);
    count++;
		}
	}
  
	//loop until all inner nodes are in the tree except the root
	while (huffPQ.size() > 1){
    
		//get the first two highest priority nodes
		HCNode* node1 = huffPQ.top();
		huffPQ.pop();
		HCNode* node2 = huffPQ.top();
		huffPQ.pop();
    
		//merge these two nodes to a new node, put it in the tree
		int newCount = node1->count + node2->count;
		HCNode* newNode = new HCNode(newCount, (unsigned char)0);
		node1->p = newNode;
		node2->p = newNode;
		newNode->c0 = node1;
		newNode->c1 = node2;
    
		//push the newNode into the priority queue
		huffPQ.push(newNode);  
	}
  
	//deal with the root
	if (huffPQ.size() == 1){
		root = huffPQ.top();
		huffPQ.pop();
	}else{
		root = NULL;
	}
 
}

/* HCTree::encode(byte symbol, BitOutputStream& out) const;
 * This method is to encode a given byte using the HCTree built above
 * Input: symbol is the byte to be encoded, out is the output file stream used to write code to a file
 * Note this method is for FINAL SUBMISSION
 */
/*
void HCTree::encode(byte symbol, BitOutputStream& out) const{
	HCNode* current = leaves[symbol];
  
	//create a int vector contains the sequence of code
	vector<int> code;
  
	//traverse the tree from leaves to root, use a vector to keep record of the path
	if (!current->p){
		code.insert(0, 0);
	}else{
		while (current->p){
		if (current->p->c0 == current){
			code.insert(0, 0);
		}else{
			code.insert(0, 1);
		}
		current = current->p;
		}
	}
	//output the each element of the vector to out
	//TO DO: NOT IMPLEMENT BITOUT
	for (int i = 0; i < code.size(); i++){
		out.WriteBit(code[i]);
	}
} 
*/

/* HCTree::decode(BitInputStream& in) const;
 * This method is to decode a given input stream using the HCTree built above
 * Input: in is the input stream need to be decoded
 * Output: symbol coded in the next sequence of bits from the stream.
 * Note this method is for FINAL SUBMISSION
 */
 /*
int HCTree::decode(BitInputStream& in) const{
	HCNode* current = root;
	int currentBit;
  
	//TO DO: IN.NEXT UNFINISHED
	//traverse the tree from root to leaves, find the symbol along the path
	while(current->c0 || current->c1){
		currentBit = in.nextBit();
		if (bit == 1){
			current = currren->c1;
		}else if (bit == 0){
			current = current->c0;
		}else{
			return -1;
		}
	}
	return current->(int)symbol;
}
*/

/* HCTree::encode(byte symbol, ofstream& out) const;
 * This method is to encode a given byte using the HCTree built above
 * Input: symbol is the byte to be encoded, out is the output file stream used to write code to a file
 * Note this method is for CHECKPOINT
 */
void HCTree::encode(byte symbol, ofstream& out) const{
  HCNode* current = leaves[symbol];
  
  //create a string contains the sequence of code
  string code;
  
  //traverse the tree from leaves to root, use a vector to keep record of the path
  if (!current->p){
    code = "0" + code;
  }else{
    while (current->p){
      if (current->p->c0 == current){
        code = "0" + code;
      }else{
        code = "1" + code;
      }
      current = current->p;
    }
  }
  //output the each element of the vector to out
  for (int i = 0; i < code.size(); i++){
	out.put(code[i]);
  }
  
} 


/* HCTree::decode(ifstream& in) const;
 * This method is to decode a given input stream using the HCTree built above
 * Input: in is the input stream need to be decoded
 * Output: symbol coded in the next sequence of bits from the stream.
 * Note this method is for CHECKPOINT
 */
int HCTree::decode(ifstream& in) const{
  HCNode* current = root;
  int currentBit;
  
  //traverse the tree from root to leaves, find the symbol along the path
  while(current->c0 || current->c1){
    currentBit = in.get() - '0';
    if (currentBit == 1){
      current = current->c1;
    }else if (currentBit == 0){
      current = current->c0;
    }else{
      return -1;
    }
  }
  return (int)current->symbol;
}

int HCTree::getCount(){
  return count;
}

 
 
