#include <iostream>
#include <fstream>
#include <string>
#include <set>

std::fstream dataFile1("/Users/amy/Documents/zadania_4/zadania_4/dane_1.txt", std::ios::in);
std::fstream resultFile1("/Users/amy/Documents/zadania_4/zadania_4/wyniki_1.txt", std::ios::out);

std::fstream dataFile2("/Users/amy/Documents/zadania_4/zadania_4/dane_2.txt", std::ios::in);
std::fstream resultFile2("/Users/amy/Documents/zadania_4/zadania_4/wyniki_2.txt", std::ios::out);

std::fstream dataFile3("/Users/amy/Documents/zadania_4/zadania_4/dane_3.txt", std::ios::in);
std::fstream resultFile3("/Users/amy/Documents/zadania_4/zadania_4/wyniki_3.txt", std::ios::out);

//A w ASCII
const int BEGIN = 65;
//Z w ASCII
const int END = 90;
//dlugosc alfabetu angielskiego
const int ABC_LEN = 26;

int main(int argc, char* argv[])
{
//------zadanie 0------
{
    std::string line;
    const int k = 107;
    while (std::getline(dataFile1, line)) 
    {
        std::string newLine;
        for(unsigned i=0; i<line.length(); i++) 
        {
            char letter;
            if(line[i] > END - k % ABC_LEN)
                letter = line[i] + (k % ABC_LEN) - ABC_LEN;
            else 
                letter = line[i] + (k % ABC_LEN);
            newLine.push_back(letter);
        }
        resultFile1 << newLine << std::endl;
    }
    dataFile1.close();
    resultFile1.close();
}
//------------------------
    
//------zadanie 1------
{
    std::string word;
    int k;
    while (dataFile2 >> word >> k) 
    {
        std::string newLine;
        for(unsigned i=0; i<word.length(); i++) 
        {
            char letter;
            if(word[i] < BEGIN + k % ABC_LEN)
                letter = word[i] - (k % ABC_LEN) + ABC_LEN;
            else 
                letter = word[i] - (k % ABC_LEN);
            newLine.push_back(letter);
        }
        resultFile2 << newLine << std::endl;
    }
    dataFile2.close();
    resultFile2.close();    
}   
//------------------------
    
//------zadanie 2------
{
    std::string word, encryption;
    while(dataFile3 >> word >> encryption)
    {
        std::set<int> keys;
        for (unsigned i=0; i<word.length(); i++) 
        {
            int k;
            if(encryption[i] - word[i] < 0)
                k = encryption[i] - word[i] + ABC_LEN;
            else
                k = encryption[i] - word[i];
            keys.insert(k);
        }
        if(keys.size() > 1)
            resultFile3 << word << std::endl;
    }
    dataFile3.close();
    resultFile3.close();
}
//------------------------
    return 0;
}
