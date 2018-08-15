#include<unordered_map>
#include <string>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;
using std::pair;

typedef vector<pair<string, int> > stringVector;
typedef unordered_map<string,int> stringMap;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

stringVector mapToSortedVector(stringMap m){
	stringVector vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), less_second<string, int>());
	vec.resize(5);
	return vec;
}

void createMapping(int mapping[], stringVector novel, stringVector cipher,int visted[], int reverseMapping[]){
	for (int i = 0; i < cipher.size()&&i<5; ++i){
		for (int j = 0; j < cipher[i].first.size(); ++j){
			if(mapping[cipher[i].first[j]-'a'] == -1 && visted[novel[i].first[j]-'a'] == 0){
				mapping[cipher[i].first[j]-'a'] = novel[i].first[j]-'a';
				reverseMapping[novel[i].first[j]-'a'] = cipher[i].first[j]-'a';
				visted[novel[i].first[j]-'a'] = 1;
			}
		}
	}
}

