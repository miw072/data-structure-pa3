#include "HCTree.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

unsigned int readInt(ifstream &in){
  unsigned int num = (in.get()<<24) | (in.get()<<16) | (in.get()<<8) | (in.get());
  return num;
}

void readHeader(ifstream &in, vector<int> &freqs, int count){
  for (int i = 0; i < count; i++){
    unsigned char ch = in.get();
    unsigned int num = readInt(in);
    freqs[ch] = num;
  }
}

int main(int argc, char* argv[]){
  if (argc != 3){
		printf("Invalid command line input. Please follow the instructions and restart!\n");
		return -1;
	}
 
  string infile = argv[1];
	string outfile = argv[2];
	   
	//declare iuput file stream and open the infile
	std::ifstream ifs;
	ifs.open (infile, std::ifstream::in | std::ifstream::binary);
	
	//create a int vector of frequency of each symbol
	vector<int> freqs(256, 0);
	
  unsigned int count = (ifs.get()<<24) | (ifs.get()<<16) | (ifs.get()<<8) | (ifs.get());
  readHeader(ifs, freqs, count);
  
  HCTree hcTree;
	hcTree.build(freqs);
  
  //declare output file stream and open the outfile
	std::ofstream ofs;
	ofs.open(outfile, std::ofstream::out | std::ofstream::app);
 
  int total = 0;
  for (int i = 0; i < freqs.size(); i++){
    total += freqs[i];
  }
  
  if (ifs.is_open()){
		
    for (int i = 0; i < total; i++){
      ofs.put((unsigned char)hcTree.decode(ifs));
    }
		
	}else{
		printf("error: cannot open file\n");
	}
  
  ifs.close();
  ofs.close();
}