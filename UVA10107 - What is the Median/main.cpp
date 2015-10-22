//
//  main.cpp
//  UVA Problem 10107
//  Created by Mathieu Spegagne on 22/10/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.

# include <iostream>
# include <algorithm>
# include <math.h> 
# include <queue>

using namespace std;

int main(int argc, const char * argv[]) {

    int value;
    int size = 0;    
    int res = 0;
    priority_queue<int, std::vector<int>, std::greater<int> > right;   
    priority_queue<int, std::vector<int>, std::less<int> > left;

    while (cin >> value) {
        size++;

        if (value >= exp2(31))
           break;
        if (size >= 10000)
           break;

        bool notFirst = true;

        if(right.size() == 0){
            notFirst = false;
            right.push(value);
            res = value;
        }
        else if(left.size() == 0){
            if(value >= right.top() && notFirst) {   
                left.push(right.top());
                right.pop();                
                right.push(value);
            }
            else{                
                left.push(value);
            }
            notFirst = false;
            res = left.top() + (right.top() - left.top())/2;
        }

        if(value >= res && notFirst)
        {
            if(left.size() < right.size()){        
                left.push(right.top());
                right.pop();                
                right.push(value);
                res = left.top() + (right.top() - left.top())/2;
            }
            else if(left.size() > right.size()){  
                right.push(value);
                res = left.top() + (right.top() - left.top())/2;
            }
            else {          
                right.push(value);
                res = right.top();
            }
        }
        else if(value < res && notFirst)
        {
            if(left.size() > right.size()){       
                right.push(left.top());
                left.pop();                
                left.push(value);            
                res = left.top() + (right.top() - left.top())/2;
            }
            else if(left.size() < right.size()){    
                left.push(value);
                res = left.top() + (right.top() - left.top())/2;
            }
            else {
                left.push(value);
                res = left.top();
            }
        }
       
        cout << res << endl;

    }
    return 0;
}

