#include "huff.h"
#include <iostream>
#include<fstream>
#include <cstring>

int main(int argc, char* argv[]) {
    /*if(argc == 2){
        if((argv[1][0] == '-') && (argv[1][1] == 'd'))

            decompress();
    }
    else
        compress();*/
    int func;//func为1就压缩，为2就解压
    string infilename, outfilename;
    cin >> func >> infilename >> outfilename;
    Huffman Test(func, infilename, outfilename);

    return 0;
}
