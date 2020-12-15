#include "huff.h"
#include <iostream>
using namespace std;

void Node:: fillCodebook(string * codebook, string &code) {
    if(!leftC && !rightC){
        codebook[data] = code;
        return;
    }
    if(leftC){
        code += '0';
        leftC->fillCodebook(codebook, code);
        code.erase(code.end()-1);
    }
    if(rightC){
        code += '1';
        rightC->fillCodebook(codebook, code);
        code.erase(code.end()-1);
    }
}

Node:: Node(Node * rc, Node * lc){
    frequency = rc->frequency + lc->frequency;
    rightC = rc;
    leftC = lc;
    min = (rc->min < lc->min) ? rc->min : lc->min;
}

void Heap:: push(Node *newNode) {
    int currentHeapNode = ++heapSize;
    while (currentHeapNode != 1 && *minHeap[currentHeapNode / 2] > *newNode) {
        minHeap[currentHeapNode] = minHeap[currentHeapNode / 2];
        currentHeapNode = currentHeapNode / 2;
    }
    minHeap[currentHeapNode] = newNode;
}

void Heap:: pop(){
    Node *lastNode = minHeap[heapSize];
    minHeap [heapSize--] = minHeap[1];
    int currentHeapNode = 1;
    int child = 2;
    
    while (child <= heapSize) {
        if (child < heapSize && *minHeap[child] > *minHeap[child + 1])
            child++;

        if (*minHeap[child] > *lastNode)
            break;

        minHeap[currentHeapNode] = minHeap[child];
        currentHeapNode = child;
        child *= 2;
    } // while not at end of heap
    
    minHeap[currentHeapNode] = lastNode;
}

bool Node::operator> (const Node &rhs){
    if(frequency > rhs.frequency)
        return true; 
    if(frequency < rhs.frequency)
        return false;
    if(frequency == rhs.frequency)
        if(min > rhs.min)
            return true;
    return false;
}

Huffman::Huffman(int func, string infilename, string outfilename)
{
    fin.open(infilename, ios::binary);
    if (!fin) {
        cerr << "open fin error." << endl;
        return;
    }
    fout.open(outfilename, ios::binary);
    if (!fout) {
        cerr << "open fout error." << endl;
        return;
    }
    if (func == 1)compress();
    else if (func == 2)decompress();
}
Huffman::~Huffman()
{
    fin.close();
    fout.close();
}
void Huffman::compress()
{
    unsigned char nextChar;
    // first, calculate the frequencies of each character
    fin >> noskipws;
    while (fin >> nextChar)
        frequencies[nextChar]++;


    Node* root = constructHeap();
    string code;
    root->fillCodebook(codebook, code);

    putOut();
}

void Huffman::putOut()
{
    fout << "HUFFMAN" << '\0';

    unsigned int i;
    for (i = 0; i < 256; i++) {
        fout << (char)(0x000000ff & frequencies[i]);
        fout << (char)((0x0000ff00 & frequencies[i]) >> 8);
        fout << (char)((0x00ff0000 & frequencies[i]) >> 16);
        fout << (char)((0xff000000 & frequencies[i]) >> 24);
    }

    unsigned char nextChar;
    char nextByte = 0;
    int bitCounter = 0;

    fin.clear();
    fin.seekg(0);
    fin >> noskipws;
    while (fin >> nextChar) {
        for (i = 0; i < codebook[nextChar].size(); i++, bitCounter++) {
            if (bitCounter == 8) {
                fout << nextByte;
                nextByte = 0;
                bitCounter = 0;
            }
            if (codebook[nextChar][i] == '1')
                nextByte = nextByte | (0x01 << bitCounter);
        }
    }
    if (bitCounter)
        fout << nextByte;
}

void Huffman::decompress()
{
    fin >> noskipws;
    char magic[8];
    fin.read(magic, 8);
    char nextByte;
    for (int i = 0; i < 256; i++) {
        fin.read((char*)&frequencies[i], 4);
    }

    Node* root = constructHeap();
    string code;
    root->fillCodebook(codebook, code);

    while (fin >> nextByte) {
        for (int i = 0; i < 8; i++) {
            if ((nextByte >> i) & 0x01)
                code += '1';
            else
                code += '0';
            for (int i = 0; i < 256; i++) {
                if (codebook[i] == code) {
                    if (frequencies[i]) {
                        fout << (unsigned char)i;
                        code.clear();
                        frequencies[i]--;
                        break;
                    }
                    else
                        return;
                }
            } // for
        }
    }
}

Node* Huffman::constructHeap()
{
    Heap minHeap;
    Node* nextNode;
    for (int i = 0; i < 256; i++) {
        if (frequencies[i]) {
            nextNode = new Node(i, frequencies[i]);
            minHeap.push(nextNode);
        }
    }

    Node* node1;
    Node* node2;
    Node* merged;
    while (minHeap.size() > 1) {
        node1 = minHeap.top();
        minHeap.pop();
        node2 = minHeap.top();
        minHeap.pop();
        merged = new Node(node1, node2);
        minHeap.push(merged);
    }

    return minHeap.top();
}
