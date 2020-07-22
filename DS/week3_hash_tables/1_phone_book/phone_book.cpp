#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, name;
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}

vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    vector<Query> contacts;
    
    std::unordered_map<int,string> myTable;
    myTable.rehash(myTable.size());
    for(int i=0;i<queries.size();i++){
        std::unordered_map<int,std::string>::const_iterator got = myTable.find(queries[i].number);
        if(queries[i].type == "add"){
            //std::unordered_map<int,std::string>::const_iterator got = myTable.find(queries[i].number);
            if(got == myTable.end()){
                myTable.insert({queries[i].number,queries[i].name});
                //erase after finding then add new    
            }else{
                myTable.erase(got);
                myTable.insert({queries[i].number,queries[i].name});
            }
        }
        else if(queries[i].type == "del"){
            myTable.erase(queries[i].number);
        }
        else if(queries[i].type == "find"){
            if(got == myTable.end()){
                result.push_back("not found");
                //std::cout<<"not found \n";
            }else{
                result.push_back(got->second);
                //std::cout<<got->second<<"\n";
            }
        }
    }
    
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}