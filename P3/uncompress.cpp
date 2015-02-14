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
	
  
}