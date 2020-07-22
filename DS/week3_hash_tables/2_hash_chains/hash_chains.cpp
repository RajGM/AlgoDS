#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}
    std::unordered_map<std::string,std::string> myTable;
    vector<std::string> a;
    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        /*
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (hash_func(elems[i]) == query.ind)
                    std::cout << elems[i] << " ";
            std::cout << "\n";
        } else {
            vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems.end());
            else if (query.type == "add") {
                if (it == elems.end())
                    elems.push_back(query.s);
            } else if (query.type == "del") {
                if (it != elems.end())
                    elems.erase(it);
            }
        }
        */
        
       if(query.type == "add"){
          std::unordered_map<std::string,std::string>::const_iterator got = myTable.find (query.s);
           if ( got == myTable.end() )
            myTable.insert({query.s,""});
           else
            ;
       }
       else if(query.type == "del"){
           std::unordered_map<std::string,std::string>::const_iterator got = myTable.find (query.s);
           if ( got == myTable.end() )
            ;
           else
            myTable.erase(got);
       }
       else if(query.type == "find"){
           std::unordered_map<std::string,std::string>::const_iterator got = myTable.find (query.s);
           if ( got == myTable.end() ){
            a.push_back("no");
            //std::cout<<"no \n";
           }
           else{
             a.push_back("yes");
            //std::cout<<"yes \n";
           }
       }
       else if(query.type == "check"){
           /*
           std::unordered_map<std::string,std::string>::const_iterator got = myTable.find (query.s);
           if ( got == myTable.end() )
            std::cout<<"\n";
           else
            std::cout<<got->first<<"\n";
            */
             std::string gb;
            for(auto& x : myTable){
                gb = gb+x.first+" ";
                //gc = gc +" "+gb;
            }
            /*
            int i=0;
            for(i=0;i<=gb.size();i++)
                gb[i]=gb[i+1];
            //gc[i+1]="";    
            */
            a.push_back(gb);
       }

    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
    
    void writeQ(){
        for(int i=0;i<a.size();i++){
           std::cout<<a[i]<<"\n";
       }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    proc.writeQ();
    return 0;
}

