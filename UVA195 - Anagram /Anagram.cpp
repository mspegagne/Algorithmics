# include <iostream>
# include <algorithm> 

using namespace std;


bool compUpper(char A, char B){
	if(tolower(A) == tolower(B))
		return (A < B);

	return (tolower(A) < tolower(B));
}


int main(int argc, const char * argv[]) {

    int length;

    cin >> length;

    while(length--){

        string input;
        cin >> input;

    	sort(input.begin(),input.end(), compUpper);
        do {
    		cout << input << '\n';
    	} while (next_permutation(input.begin(),input.end(), compUpper));
    }
}

