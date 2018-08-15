#include<fstream>

using std::string;
using std::ifstream;
using std::cout;


void generateCipher(string filename, string& cipherText){
	ifstream is(filename);     // open file

	char c;
	while (is.get(c)){
		if((c>=65&&c<=90)||(c>=97&&c<=122)){
			if(c<97)
				c+=32;
			c-=97;
			c=(c+1)%26;
			c+=97;
			cipherText+=c;
		}else
			cipherText+=c;
	}
	is.close();
}

void decodeCipher(string cipherText, int mapping[]){
	string modifiedCipherText="";
	string colorBegin = "\033[0;36m", colorEnd = "\033[0m";
	for (int i = 0; i < cipherText.length(); ++i){
		if(cipherText[i]>=97&&cipherText[i]<=122){
			if(mapping[cipherText[i]-'a']!=-1){
				cipherText[i] = mapping[cipherText[i]-'a']+'a';
				cout<<colorBegin<<cipherText[i]<<colorEnd;
			}else{
				cout<<cipherText[i];
			}
		}else{
			cout<<cipherText[i];
		}
		modifiedCipherText+=cipherText[i];
	}
}