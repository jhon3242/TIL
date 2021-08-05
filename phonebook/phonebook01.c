#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 20
#define CAPACITY 100

char *name[CAPACITY];
char *number[CAPACITY];
char buffer[BUFFER_SIZE];
int n = 0;

void add();
void find();
void removes();
void status();
	
int main(){

	while(1){
		printf("$ ");
		scanf("%s",buffer);
		if (strcmp(buffer, "add") == 0){
			/* add */
			add();
		} else if (strcmp(buffer, "find") == 0){
			/* find */
			find();
		}  else if (strcmp(buffer, "remove") == 0){
			/* remove */
			removes();
		}  else if (strcmp(buffer, "status") == 0){
			/* status */
			status();
		} else if (strcmp(buffer, "exit") == 0){
			/* exit */
			break;
		}
		
	}
		
	return 0;	
}
void add(){
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];
	scanf("%s %s",buf1,buf2);
	
	name[n] = strdup(buf1);
	number[n] = strdup(buf2);
	n++;

	printf("%s was added successfully \n",buf1);
}

void find(){
	int i =0;
	char buf[BUFFER_SIZE];
	
	scanf("%s",buf);
	while (i<n){
		if(strcmp(name[i],buf) == 0){
			printf("%s \n",number[i]);
			return;
		}
		i++;
	} 
	printf("No person named '%s' exists.\n",buf);
}

void removes(){
	char buf[BUFFER_SIZE];
	scanf("%s",buf);
	int i=0;
	while (i<n){
		if(strcmp(name[i], buf)==0){
			name[i] = name[n-1];
			number[i] = number[n-1];
			n--;
			printf("'%s' was deleted successfully. \n ",buf);
			return;
		}
		i++;
	}
	printf("No person named '%s' exists.\n",buf);
}

void status(){
	int i=0;
	while (i<n){
		printf("%s %s\n",name[i],number[i]);
		i++;
	}
	printf("Total %d persons.\n",n);
}
