#include<iostream>
#include<unordered_map>
#include<fstream>
#include<stdlib.h>
#include<vector>
#include<string>
#include"fileHandling.h"

using namespace std;

int main(){
	unordered_map<string,int> unigram;

	fileToMap("unigram.txt",unigram);

	for(stringMap::const_iterator it = unigram.begin(); it != unigram.end(); ++it){
    	cout << it->first << "-" << it->second<< "\n";
	}
	string c = "asdjasd";
	string colorBegin = "\033[0;36m", colorEnd = "\033[0m";

	cout << colorBegin<<c<<colorEnd<<"aaaaa";

}