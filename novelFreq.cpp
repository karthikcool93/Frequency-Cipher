#include<iostream>
#include<unordered_map>
#include<fstream>
#include<vector>
#include"fileHandling.h"
#include"freqCount.h"

using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

int main(){

	unordered_map<string,int> unigram;
	unordered_map<string,int> bigram;
	unordered_map<string,int> trigram;

	string filename = "novel.txt";

	calculateFreq(filename,unigram,bigram,trigram);

	vector<pair<string, int> > unigramCopy(unigram.begin(), unigram.end());
	vector<pair<string, int> > bigramCopy(bigram.begin(), bigram.end());
	vector<pair<string, int> > trigramCopy(trigram.begin(), trigram.end());

	sort(unigramCopy.begin(), unigramCopy.end(), less_second<string, int>());
	sort(bigramCopy.begin(), bigramCopy.end(), less_second<string, int>());
	sort(trigramCopy.begin(), trigramCopy.end(), less_second<string, int>());

	mapToFile("unigram.txt",unigramCopy);
	mapToFile("bigram.txt",bigramCopy);
	mapToFile("trigram.txt",trigramCopy);

	for(vector<pair<string, int> >::const_iterator it = unigramCopy.begin(); it != unigramCopy.end(); ++it){
    	cout << it->first << "-" << it->second<< "\n";
	}
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~\n";
	for(vector<pair<string, int> >::const_iterator it = bigramCopy.begin(); it != bigramCopy.end(); ++it){
    	cout << it->first << "-" << it->second<< "\n";
	}
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~\n";
	for(vector<pair<string, int> >::const_iterator it = trigramCopy.begin(); it != trigramCopy.end(); ++it){
    	cout << it->first << "-" << it->second<< "\n";
	}
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~\n";
	
	return 0;

}