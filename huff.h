#include <cstdlib>
#include <string>
#include<fstream>

using namespace std;
class Huffman;
class Node{
    friend Huffman;
    unsigned char data;
    unsigned int frequency;
    unsigned char min;
    Node * leftC;
    Node * rightC;
public:
    Node(){}
    Node(const Node &n){data = n.data; frequency = n.frequency; leftC = n.leftC; rightC = n.rightC;}
    Node(unsigned char d, unsigned int f): data(d), frequency(f), min(d){}
    Node(Node *, Node *);
    void fillCodebook(string *, string &);
    bool operator> (const Node &);
};

class Heap{
    Node **minHeap;
    int heapSize;
public:
    Heap(){heapSize = 0; minHeap = new Node*[257];} 
    void push(Node *);
    int size(){return heapSize;}
    void pop();
    Node * top(){return minHeap[1];}
};

class Huffman {
    unsigned int frequencies[256] = { 0 };
    string codebook[256];
    ifstream fin;
    ofstream fout;
public:
    Huffman(int func, string infilename, string outfilename);
    ~Huffman();
    void compress();
    void putOut();
    void decompress();
    Node* constructHeap();
};
