#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
using std::map;

int const Letters =    4;
int const NA      =   -1;

typedef map<char, int> edges;
typedef vector<edges> trie;

struct Node
{
	int next [Letters];

	Node ()
	{
		fill (next, next + Letters, NA);
	}

	bool isLeaf () const
	{
	    return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter)
{
	switch (letter)
	{
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

trie build_trie(vector<string> &patterns) {
 
 if (patterns.empty()) {
        return trie{};
    }
 trie t{edges{}}; 
 int root{0},cnt{0};
 
 for(auto& i:patterns){
     int currentN = root;
     for(auto j:i){
         if(t[currentN].find(j)!=t[currentN].end()){
             currentN = t[currentN][j];
         }else{
            t.emplace_back(edges{});
            t[currentN][j] = ++cnt;
            currentN = cnt;
         }
     }
 }
 
 return t;
}

vector <int> solve (const string& text, int n,vector <string>& patterns)
{
	vector <int> result;
	trie t = build_trie(patterns);
	map<std::string,int> pattMap;
	for(int i=0;i<patterns.size();i++){
		pattMap.insert(std::pair<std::string,int>(patterns[i],pattMap.size()));
	}
	vector<int> pattSize;
	for(int i=0;i<patterns.size();i++){
	    pattSize.push_back(patterns[i].size());
	}
	/*
	std::cout<<"Mapping"<<"\n";
	for (auto& x: pattMap) {
    std::cout << x.first << ": " << x.second << '\n';
  } 
	*/
	
	// write your code here
	for(int i=0;i<text.size();++i){
		int currV =0;
		int currSId = i;
		char currS = text[currSId];
		int tC =0;
		while(true){
		tC=currV+1;
		string strT =  text.substr(i,tC); 
		if(pattMap.find(strT)!=pattMap.end()){
		     //   std::cout<<"Match without end:"<<strT<<" i:"<<i<<"\n";
		        result.push_back(i);
		}
		
		
		
		if(t[currV].empty()){
			result.push_back(i);
			break;
		}else if(t[currV].find(currS)!=t[currV].end()){
			currV = t[currV][currS];
			currS = text[++currSId];
		}else{
		    break;
		}
	}

	}

     //auto res = unique(result.begin(), result.end());
    vector<int> finalR;
    if(result.size()>=1){
        finalR.push_back(result[0]);
        for(int i=1;i<result.size();i++){
        if(finalR[finalR.size()-1]!=result[i]){
        finalR.push_back(result[i]);
    }    
    }    
    }
    
    


	return finalR;
}

int main (void)
{
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (text, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}

