#include <iostream>
#include <stack>
using namespace std;

bool isParenthesesMatch(string s){
    stack<char> st;

    for(char ch:s){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            // if(st.empty()){
            //     return false;
            // }
            if(st.top() == '(' && ch==')' || st.top() == '{' && ch=='}' || st.top() == '[' && ch==']'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    string s = "(({{[[([{]])}])]]}}))";

    cout<<isParenthesesMatch(s)<<endl;

    return 0;
}