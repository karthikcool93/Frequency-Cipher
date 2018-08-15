#include <string>
#include <unordered_map>
#include <fstream>
#include <vector>
#include "splitString.h"
 
using std::string;
using std::unordered_map;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::pair;

typedef unordered_map<string,int> stringMap;
typedef vector<pair<string, int> > stringVector;

bool fileToVector(string filename, stringVector& fileVector){
	ifstream ifile;
    ifile.open(filename.c_str());
    if(!ifile)
        return false;   //could not read the file.    
    string line;
    string key;
    vector<string> v_str;
    while(ifile>>line)
    {
        splitString(v_str,line,'|');
        for(vector<string>::iterator iter = v_str.begin();;++iter)        //First vector element is the key.
        {
            if(iter == v_str.begin())
            {
                // fileMap[*iter] = 0;
                key= *iter;
                continue;
            }
            fileVector.push_back(make_pair(key,stoi(*iter)));
            // fileMap[key]= stoi(*iter);
            v_str.clear();
            break;
        }
    }
    ifile.close();
    return true;
}

bool fileToMap(const std::string &filename, stringMap &fileMap)  //Read Map
{
    ifstream ifile;
    ifile.open(filename.c_str());
    if(!ifile)
        return false;   //could not read the file.    
    string line;
    string key;
    vector<string> v_str;
    while(ifile>>line)
    {
        splitString(v_str,line,'|');
        for(vector<string>::iterator iter = v_str.begin();;++iter)        //First vector element is the key.
        {
            if(iter == v_str.begin())
            {
                fileMap[*iter] = 0;
                key= *iter;
                continue;
            }
            fileMap[key]= stoi(*iter);
            v_str.clear();
            break;
        }
    }
    ifile.close();
    return true;
}

bool mapToFile(const string &filename,const stringVector &fileMap)     //Write Map
{
    ofstream ofile;
    ofile.open(filename.c_str(),ofstream::out);
    if(!ofile)
    {
        return false;           //file does not exist and cannot be created.
    }
	for (int i = 0; i < 5; ++i)
	{
		ofile<<fileMap[i].first<<"|"<<fileMap[i].second;
        ofile<<"\n";
	}
	ofile.close();	
    return true;
}

void stringToFile(string filename,string input){
	ofstream ofile;
	ofile.open(filename.c_str(),ofstream::out);
	ofile<<input;
	ofile.close();
}



