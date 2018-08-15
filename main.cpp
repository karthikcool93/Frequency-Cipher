#include<iostream>
#include<unordered_map>
#include<fstream>
#include<vector>
#include"fileHandling.h"
#include"generateCipherText.h"
#include"utility.h"
#include"freqCount.h"

using namespace std;

int main(){

	string cipherText,cipherTextCopy;

	string plaintTextFile = "plainText.txt", cipherTextFile="cipherText.txt";

	generateCipher(plaintTextFile, cipherText);

	// cout<<cipherText<<endl;

	stringToFile(cipherTextFile,cipherText);

	cipherTextCopy = cipherText;

	vector<pair<string, int> > unigramNovel;
	vector<pair<string, int> > bigramNovel;
	vector<pair<string, int> > trigramNovel;

	fileToVector("unigram.txt",unigramNovel);
	fileToVector("bigram.txt",bigramNovel);
	fileToVector("trigram.txt",trigramNovel);

	unordered_map<string,int> unigram;
	unordered_map<string,int> bigram;
	unordered_map<string,int> trigram;

	string filename = "cipherText.txt";

	calculateFreq(filename,unigram,bigram,trigram);

	vector<pair<string, int> > unigramCipher = mapToSortedVector(unigram);
	vector<pair<string, int> > bigramCipher = mapToSortedVector(bigram);
	vector<pair<string, int> > trigramCipher = mapToSortedVector(trigram);

	int mapping[26], reverseMapping[26];
	for (int i = 0; i < 26; ++i){
		mapping[i] = -1;
		reverseMapping[i] = -1;
	}
	int visited[26] = {0};

	createMapping(mapping,unigramNovel,unigramCipher,visited, reverseMapping);
	createMapping(mapping,bigramNovel,bigramCipher,visited, reverseMapping);
	createMapping(mapping,trigramNovel,trigramCipher,visited, reverseMapping);

	char ch;
	string colorBegin = "\033[0;33m", colorEnd = "\033[0m";
	do{
		cout<<colorBegin<<"\nCipher Text : "<<colorEnd<<endl;
		cout<<cipherText<<endl;
		cout<<colorBegin<<"\nDecrypted Text : \n"<<colorEnd;
		decodeCipher(cipherText,mapping);
		cout<<endl;
		cout<<colorBegin<<"\nMappings : \n"<<colorEnd;
		for (int i = 0; i < 26; ++i){
			if (mapping[i]!=-1){
				char key = 'a'+i;
				char value = mapping[i]+'a';
				cout<<key<<"-"<<value<<endl;
			}	
		}
		char key,value;
		do{
			cout<<endl;
			cout<<"Enter key value pair to add/modify:"<<endl;
			cout<<"Press 2 to decrypt"<<endl;
			cout<<"Press 1 to exit"<<endl;
			cin>>key;
			if(key>=97&&key<=122){
				cin>>value;
				if(reverseMapping[value-'a']!=-1){
					mapping[reverseMapping[value-'a']] = -1;
				}
				if(mapping[key-'a']!=-1){
					reverseMapping[mapping[key-'a']] = -1;
				}
				mapping[key-'a'] = value-'a';
				reverseMapping[value-'a'] = key-'a';
			}	
			ch=key;
		}while(ch!='2'&&ch!='1');
	}while(ch!='1');


	return 0;

}