#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        //std::cout<<"Next:"<<next<<" Position:"<<position<<"\n";
        Bracket b(next,position);
        //std::cout<<"B.Next:"<<b.type<<" B.Position:"<<b.position<<"\n";
        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(b);
        }
        //std::cout<<"Running upto this"<<"\n";
        if(opening_brackets_stack.size()==0 && (next == ')' || next == ']' || next == '}')){
            //std::cout<<"Next:"<<next<<"\n";
            std::cout<<position+1;
            return 0;
        }
        
        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            Bracket bt = opening_brackets_stack.top();
            //std::cout<<"bt:"<<bt.type<<" bt Position:"<<bt.position<<"\n";
            if(next == ')' && bt.type == '(')
                opening_brackets_stack.pop();
            else if(next == ']' && bt.type == '[')
                opening_brackets_stack.pop();
            else if(next == '}' && bt.type == '{')
                opening_brackets_stack.pop();
            else{
                //std::cout<<"Wrong case"<<"\n";
                std::cout<<position+1;
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if(opening_brackets_stack.size()==0){
        std::cout<<"Success";
    }else{
        std::cout<<opening_brackets_stack.top().position+1;
    }
    return 0;
}