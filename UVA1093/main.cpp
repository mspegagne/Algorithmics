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

	while(length--){

	    int nb = 0;
	    cin >> nb >> ws;

		for(int i = 0; i < nb; i++) {		
			cin >> petrols[i];
		}

		int sum = 0;
		int need = 0;
		for(int i = 0; i < nb; i++) {		
			cin >> distances[i];
			need = petrols[i] - distances[i];
			sum += need;

		}

		if(sum < 0){
			cout << "Not possible" << endl;
		}
		else {
			sum = 0;
			res = 1;
		}


	}
    
	return 0;
}

