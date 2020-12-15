#include "huff.h"
#include <iostream>
#include<fstream>
#include <cstring>



int main(int argc, char* argv[]) {
    
    int func;
    string infilename, outfilename;
    cin >> func >> infilename >> outfilename;
    Huffman Test(func, infilename, outfilename);

    return 0;
}

