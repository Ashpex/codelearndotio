#include <iostream>
#include <stack>
using namespace std;

void reverse(stack<char> randomStack, string randomString){
    for(int i = 0; i < randomString.length(); i++){
        randomStack.push(randomString[i]);
    }
    while(!randomStack.empty()){
        cout << randomStack.top();
        randomStack.pop();
    }
}

string DecToBin(stack<int> randomStack, int r_value){
    while(r_value > 0){
        int remainder = r_value % 2;
        randomStack.push(remainder);
        r_value /= 2;
    }
    string binary;
    while(!randomStack.empty()){
        int digit = randomStack.top();
        randomStack.pop();
        binary += to_string(digit);
    }
    return binary;
}
string encodeString(stack<char> u_stack, string r_randomString){
    string result;
    for(int i = 0; i <= r_randomString.length(); i++){
        if( u_stack.empty()|| r_randomString[i] == u_stack.top()){
           u_stack.push(r_randomString[i]);
        }
        else if(r_randomString[i] != u_stack.top()){
            int count = 0;
            result += u_stack.top();
            while(!u_stack.empty()){
                u_stack.pop();
                count ++;
            }
            result += to_string(count);
            u_stack.push(r_randomString[i]);
        }
    }
    return result;
}
int main(){
    int n = 0;
    stack<char> randomStack;
    string randomString;
    getline(cin,randomString);
    cin.clear();
    cout << encodeString(randomStack,randomString) << endl;
    return 0;
}