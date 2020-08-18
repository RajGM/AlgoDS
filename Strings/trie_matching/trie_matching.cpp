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
	// write your code here
	char firT = text[0];
	int rootT = 0;
	for(int i=0;i<text.size();++i){
		int currV =0;
		int currSId = i;
		char currS = text[currSId];
		while(true){
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
	return result;
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