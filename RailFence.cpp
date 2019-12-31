//Railfence Cipher
//code by Bipin Timalsina
#include<iostream>
#include<string>
using namespace std;
class RailFence{
	public:
	int nrow,ncol;
	int getKey(){
			int key;
			cout<<"Enter the Key (number of rails) \n";
			cin>>key;
			return key;	
		}
		string getMessage(){
			string msg;
			cout<<"Enter the message  \n";
			cin.ignore();
			getline(cin,msg);
			return msg;	
		}
	void encrypt(string msg, int key){
		// creating a matrix to encrypt msg with key 
	    // key = rows , length of msg=no. of characters = columns 
	    nrow= key;
	    ncol= msg.length();
	    char rail_matrix[nrow][ncol]; 
	  
	    // filling the rail matrix with ^ symbol 
	    for (int i=0; i < nrow; i++) {
	        for (int j = 0; j < ncol; j++){
	            rail_matrix[i][j] ='^'; 
			}
		}
		// to find the direction 
	    bool downward = false; 
	    int r = 0, c = 0; 
	    string ciphertext; 
	  
	    for (int i=0; i < msg.length(); i++) {
	        // checking  the direction of flow 
	        // reverse the direction if the top or bottom rail is just filled 
	        if (r == 0 || r == key-1) 
	            downward = !downward; 
	  
	        // filling  with  characters in the plaintext 
	        rail_matrix[r][c++] = msg[i]; 
	  
	        // find the next row using direction 
	        downward ?r++ : r--; 
	    } 
	  	//to print the rail matrix
		for (int i=0; i < nrow; i++) {
	        for (int j = 0; j < ncol; j++){
	           cout<< rail_matrix[i][j]<<"  "; 
			}
			cout<<"\n";
		}
	    // generating  the ciphertext using the rail_matrix 
	    
	    for (int i=0; i < key; i++) {
	        for (int j=0; j < msg.length(); j++) {
	            if (rail_matrix[i][j]!='^') 
	                ciphertext.push_back(rail_matrix[i][j]); //appending a character
			}
		}
		
		cout<<"\n The Ciphertext is:::> "<<ciphertext<<"\n";
	}
		
	void decrypt(string msg, int key){
			
		// creating a matrix to encrypt msg with key 
	    // key = rows , length of msg=no. of characters = columns 
	    nrow= key;
	    ncol= msg.length();
	    char rail_matrix[nrow][ncol]; 
	    string plaintext;
	  
	    // filling the rail matrix with ^ symbol 
	    for (int i=0; i < nrow; i++) {
	        for (int j = 0; j < ncol; j++){
	            rail_matrix[i][j] ='^'; 
			}
		}
		// to find the direction 
	    bool downward; 
	    int r = 0, c= 0; 
	  
	    // marking  the places with '~' 
	    for (int i=0; i < msg.length(); i++) {
	        // check the direction of flow 
	        if (r == 0) 
	            downward = true; 
	        if (r == key-1) 
	            downward = false; 
	        // place the marker 
	        rail_matrix[r][c++] = '~'; 
	  
	        // find the next row using direction flag 
	        downward?r++ : r--; 
	    } 
	  
	    // filling  the rail matrix 
	    int indx = 0; 
	    for (int i=0; i<key; i++) {
	        for (int j=0; j<msg.length(); j++) {
	            if (rail_matrix[i][j] == '~' && indx<msg.length()) 
	     			rail_matrix[i][j] = msg[indx++]; 
	    	}
		}           
	  
	  
	    //  reading  the matrix in zig-zag order to get the plaintext  
	    r = 0, c = 0; 
	    for (int i=0; i< msg.length(); i++) 
	    { 
	        // check the direction of flow 
	        if (r == 0) 
	            downward = true; 
	        if (r == key-1) 
	            downward = false; 
	  
	        // checking  the marker 
	        if (rail_matrix[r][c] != '~') 
	            plaintext.push_back(rail_matrix[r][c++]); //appending 
	        // finding  the next row using direction flag 
	        downward?r++: r--; 
	    } 
	cout<<"The Plaintext is:::>"<<plaintext<<"\n";
	}
		
		
};
int main(){
	cout<<"				=====Rail Fence Cipher===== ";
	int choice;
	char more;
	RailFence rf;
	int k;
	string m;
	do{
		cout<<"\n 	Enter 1 for ENCRYPTION, 2 for DECRYPTION and 3 for EXIT \n";
		cin>>choice;
		switch(choice){
			case 1:
				k= rf.getKey();
				m= rf.getMessage();
				rf.encrypt(m,k);
				break;
				
			case 2:
				k= rf.getKey();
				m= rf.getMessage();
				rf.decrypt(m,k);
				break;
			case 3:
				exit(1);
			default:
				cout<<"\n INVALID CHOICE! \n";
		}
	cout<<"\n Do you want to perfrom more ENCRYPTION/DECRYPTION ? (y/n)\n ";
	cin>>more;
	} while(more=='y'|| more=='Y');
	cout<<"\n\n 	Thank You! \n\n";	
}