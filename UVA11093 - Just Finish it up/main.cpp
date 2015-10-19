//
//  main.cpp
//  UVA Problem 11093
//
//  Created by Mathieu Spegagne on 19/10/2015.
//  Copyright (c) 2015 Mathieu Spegagne. All rights reserved.

# include <iostream>
# include <algorithm> 

using namespace std;

const int MAX_N = 100010;

int petrols[MAX_N];
int distances[MAX_N];

int main(int argc, const char * argv[]) {

    int length;
    cin >> length >> ws;

	for(int i = 1; i != (length+1); i++) {

	    int nb = 0;
	    cin >> nb >> ws;

		for(int i = 0; i < nb; i++) {		
			cin >> petrols[i];
		}

		int sum = 0;
		int need = 0;
		for(int j = 0; j < nb; j++) {		
			cin >> distances[j];
			need = petrols[j] - distances[j];
			sum += need;
		}

		if(sum < 0){
			cout << "Case " << i << ": Not possible" << endl;
		}
		else {			
			int dep = 0;
			int value = -1;
			for(int j = 0; j < nb; j++) {
				int res = 0;
				for(int k = 0; k < nb; k++) {
					int station = (dep+k)%nb;
					res += petrols[station] - distances[station];
					if(res < 0){
						dep++;
						break;
					}
					if(k == (nb-1)){
						value = dep + 1;
						break;
					}						
				}
				if(value != -1){
					cout << "Case " << i << ": Possible from station " << value << endl;
					break;
				}
			}
		}
	}
	return 0;
}

