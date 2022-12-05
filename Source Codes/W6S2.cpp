#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int match(char a, char b){
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

int check(char* s){
    stack<pair<char, int>> stack;
    for(int i = 0; i < strlen(s); i++){           
        
        // mo ngoac thi day vao stack
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack.push(make_pair (s[i] ,i));
        }else{  //dong ngoac
            if(stack.empty()) return i; 
            pair<char, int> x = stack.top();
            stack.pop();
            if(!match(x.first,s[i])) return x.second;
        }
    }
    if(stack.empty()) return 0;
    pair<char, int> x = stack.top();
    return x.second;// thieu dau ngoac dong
}

int main() {
    char str[]="(([))))))";
    int result = check(str);
    if(result==0) cout<<"Bieu thuc OK"<<endl;
    else cout<<"Co loi tai vi tri "<<result<<endl;
    return 0;
}