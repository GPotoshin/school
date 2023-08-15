#include <limits.h>
#include <stdio.h>

#define CESAR 'c'
#define XOR 'x'
#define FREQ 'f'
#define BUF_SIZE 32
  

// ~pr~ ~mode~ ~inputf~ ~outputf~ ~password(or shift)~
int main(int argc, char* argv[]){
	int mode;
	int shift;
	int buf[32];

	char *path;
	char password[32];
	char inputString[20];

	FILE *inputf;
	FILE *outputf;


	/* input check */

	if(argc == 1){
		printf("mode: ");
		scanf("%s", inputString);
		mode = (int)inputString[0];
	}
	else{
		mode = (int)*argv[1];
	}

	if(mode != CESAR && mode != XOR && mode != FREQ){
		printf("Incorrect mode\n");
		return 0;
	}
		
	if(argc <= 2){
		printf("input file: ");
		scanf("%s", inputString);
		path = inputString;
	}
	else{
		path = argv[2];
	}
	inputf = fopen(path, "r");

	if(inputf == NULL){
		printf("File does not exist\n");
		return 0;
	}
	
	/* here we go to FREQ mode as programm does not want to work properly if I put that piece of code in the end */

	if(mode == FREQ){
		int symbol[256];
		for(int i = 0; i < 256; i++)
			symbol[i] = 0;

		for(;;){
			for(int i = 0; i < BUF_SIZE; i++){
				buf[i] = fgetc(inputf);
				if(buf[i] == EOF)
					break;
			}
			for(int i = 0; i < BUF_SIZE; i++){
				if(buf[i] == EOF){
					fclose(inputf);
					int s;
					int c;
					for(int i = 256; i > 0; i--){
						s = INT_MAX;
						for(int j = 0; j < 256; j++){
							if(symbol[j] < s){
								s = symbol[j];
								c = j;
							}
						}
						symbol[c] = INT_MAX;
						printf("%d:\t%d\t%d\n", i, c, s);
					}
					return 0;
				}
				symbol[buf[i]]++;
			}
		}
	}	

	/* End of FREQ mode */

	if(mode == CESAR || mode == XOR){
		if(argc <= 3){
			printf("output file: ");
			scanf("%s", inputString);
			path = inputString;
		}
		else{
			path = argv[3];
		}

		if(argc <= 4){
			if(mode == CESAR){
				printf("shift: ");
				scanf("%d", &shift);
			}
			else{
				printf("password(max:32): ");
				scanf("%s", password);
			}
		}
	}
	outputf = fopen(path, "w");


	/* end of input check */
	/*     CESAR mode     */
	
	if(mode == CESAR){
		for(;;){
			for(int i = 0; i < BUF_SIZE; i++){
				buf[i] = fgetc(inputf);
				if(buf[i] == EOF)
					break;
			}
			for(int i = 0; i < BUF_SIZE; i++){
				if(buf[i] == EOF){
					fclose(inputf);
					fclose(outputf);
					return 0;
				}
				fputc(buf[i] + shift, outputf);
			}
		}
	}

	/* end of CESAR mode */
	/*      XOR mode     */

	if(mode == XOR){
		int passwordLen;
		for(passwordLen = 0; passwordLen < 32; passwordLen++){
			if(password[passwordLen] == 0)
				break;
		}
		
		char pchar = 0;
		for(;;){
			for(int i = 0; i < BUF_SIZE; i++){
				buf[i] = fgetc(inputf);
				if(buf[i] == EOF)
					break;
			}
			for(int i = 0; i < BUF_SIZE; i++){
				if(buf[i] == EOF){
					fclose(inputf);
					fclose(outputf);
					return 0;
				} 
				fputc(buf[i]^password[(i + pchar)%passwordLen], outputf);
			}
			pchar = (pchar + BUF_SIZE)%passwordLen;
		}
		fclose(inputf);
		fclose(outputf);
	}
	/* end of XOR mode */
}
