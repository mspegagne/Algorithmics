//
//  main.cpp
//  UVA Problem 608 - Counterfeit Dollar
//
//  Created by Mathieu Spegagne on 19/10/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.

# include <iostream>
# include <algorithm> 

using namespace std;



int main(int argc, const char * argv[]) {

    int length;
    int pos = 0;
    int j = 0;
    cin >> length >> ws;

	while(length--){
	    int coins[12] = {0};
	    int occ[12] = {0};
		for(int i = 0; i < 3; i++) {
			
			string left;
			cin >> left;

			string right;
			cin >> right;

			string weight;
			cin >> weight;
			
			if(weight == "even") {
				for(j = 0; j < left.length(); j++) {
					pos = left[j] - 'A';
					occ[pos]++;	
					coins[pos] = 1;

					pos = right[j] - 'A'; 
					occ[pos]++;	
					coins[pos] = 1;
				}
			} else if(weight == "up"){
				for(j = 0; j < left.length(); j++) {
					pos = right[j] - 'A';
					occ[pos]++;			
					if(coins[pos] == 0)
						coins[pos] = 2;
					if(coins[pos] == 3) 
						coins[pos] = 1;	

					pos = left[j] - 'A';
					occ[pos]++;	
					if(coins[pos] == 0) 
						coins[pos] = 3;
					if(coins[pos] == 2) 
						coins[pos] = 1;
					
				}
			} else if(weight == "down"){
				for(j = 0; j < left.length(); j++) {
					pos = right[j] - 'A';
					occ[pos]++;	
					if(coins[pos] == 0) 
						coins[pos] = 3;
					if(coins[pos] == 2)
						coins[pos] = 1;

					pos = left[j] - 'A';
					occ[pos]++;	
					if(coins[pos] == 0) 
						coins[pos] = 2;
					if(coins[pos] == 3)
						coins[pos] = 1;
				}
			}	
		}

		char res;
		int occMax = 0;
		int val = 0;

		for(j = 0; j < 12; j++) {
			// cout << coins[j] << "--" << occ[j] << endl;
			char letter = 'A' + j;
			if(coins[j] == 3 || coins[j] == 2) {
				if(occ[j] > occMax) {
					occMax = occ[j];
					res = letter;	
					val = coins[j];	
				}
			}
		}

		if(val == 2) {
			cout << res << " is the counterfeit coin and it is light." << endl; 
		} else if(val == 3) {
			cout << res << " is the counterfeit coin and it is heavy." << endl; 
		} 
	}	
    
	return 0;
}

