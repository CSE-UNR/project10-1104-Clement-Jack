// Jack Clement

#include <stdio.h>
#define Length 6

void Round(char Word[Length], int Count, char Guess[][Length]);
void Winner(int Count, int Win, char Guess[][Length]);
void Check(int index, char Word[Length], char Guess[][Length]);

int main(){
	int Count = 0;
	int Win = 1;
	char Guess[6][Length];
	char Word[Length];
	FILE* Wfile;
	Wfile = fopen("mystery.txt", "r");
	if(Wfile == NULL){
		printf("Cannot access text file\n");
		return 0;
	}
	fscanf(Wfile, " %s", Word);
	do{
		Win = 1;
		Round(Word, Count, Guess);
		for(int index = 0; index < Length - 1; index++){
			if(!(Guess[Count][index] <= 'Z' && Guess[Count][index] >= 'A')){
				Win = 0;
		}
	}
		if(Win != 1){
			for(int index = 0; index <= Count; index++){
			printf("\n%s\n", Guess[index]);
			Check(index, Word, Guess);
			printf("\n");
		}	
		Count++;
		}
	}while(Win != 1 && Count != 6);
	Winner(Count, Win, Guess);
	fclose(Wfile);
	return 0;
}

void Round(char Word[Length], int Count, char Guess[][Length]){	
	printf("GUESS %d! Enter your guess: ", Count + 1);
	scanf(" %s", Guess[Count]);
	printf("\n================================");
	for(int Index = 0; Index < Length - 1; Index++){
		if(Word[Index] == Guess[Count][Index]){
			Guess[Count][Index] -= 'a' - 'A';
		}
	}
	return;
}

void Winner(int Count, int Win, char Guess[][Length]){
	if(Win == 0 && Count == 6){
		printf("\nYou lost, better luck next time!\n");
	}
	else if(Win == 1){
		if(Count == 0){
			printf("\n		%s\n	You won in 1 guess!\n 		GOATED!\n", Guess[Count]);
		}
		else if(Count == 1 || Count == 2){
			printf("\n		%s\n	You won in %d guesses!	\n         	Amazing!\n", Guess[Count], Count + 1);
	}
		else if(Count == 3 || Count == 4){
			printf("\n		%s\n	You won in %d guesses!\n 	        Nice!\n", Guess[Count], Count + 1);
		}
		else if(Count == 5){
			printf("\n		%s\n	You won in 6 guesses!\n", Guess[Count]);
		}
	}
	return;
}
	
void Check(int index, char Word[Length], char Guess[][Length]){
	int H = 0;
	for(int C = 0; C < Length - 1; C++){
	H = 0;
		for(int Index = 0; Index < Length - 1; Index++){
			if(Guess[index][C] == Word[Index] && Guess[index][C] <= 'z' && Guess[index][C] >= 'a' ){
			printf("^");
			H = 1;
		}
		}
		if(H != 1){
		printf(" ");
		}
	}
	return;
}
	

