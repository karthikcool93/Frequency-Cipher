#include<unordered_map>
#include<fstream>


using std::string;
using std::unordered_map;
using std::ifstream;

typedef unordered_map<string,int> stringMap;

void calculateFreq(string filename, stringMap& unigram, stringMap& bigram, stringMap& trigram){
	ifstream is(filename);     // open file

	char left='-', middle='-', right='-';

	char c;
	while (is.get(c)){
		left = middle;
		middle = right;
		right = c;
		if((right>=65&&right<=90)||(right>=97&&right<=122)){
			if(right>=65&&right<=90)
				right+=32;

			string t = "";
			t+=right;
			unigram[t]++;

			if (middle >= 97 && middle <= 122) {
                    t = "";
                    t = middle + t;
                    t = t + right;
                    bigram[t]++;


                    if (left >= 97 && left <= 122) {
                        t = "";
                        t += left;
                        t += middle;
                        t += right;
                        trigram[t]++;
                    }
                }
		}
	}

	is.close();
}
