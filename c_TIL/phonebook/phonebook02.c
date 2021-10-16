#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 20
#define CAPACITY 100

char *name[CAPACITY];
char *number[CAPACITY];
char buffer[BUFFER_SIZE];
int n = 0;

void add();
int seach();
void find();
void removes();
void status();
void load();
void save();
	
int main(){

	while(1){
		printf("$ ");
		scanf("%s",buffer);
		 if (strcmp(buffer, "read") == 0){
			/* load */
			load();
		} 
		else if (strcmp(buffer, "add") == 0){
			/* add */
			add();
		} else if (strcmp(buffer, "find") == 0){
			/* find */
			find();
		} else if (strcmp(buffer, "remove") == 0){
			/* remove */
			removes();
		} else if (strcmp(buffer, "status") == 0){
			/* status */
			status();
		}  else if (strcmp(buffer, "save") == 0){
			/* save */
			save();
		} else if (strcmp(buffer, "exit") == 0){
			/* exit */
			break;
		}
		
	}
		
	return 0;	
}
void add(){
	int i = n-1;
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];
	scanf("%s %s",buf1,buf2);
	
	while (i>=0 && strcmp(name[i], buf1) > 0){
		name[i+1] = name[i];
		number[i+1] = number[i];
		i--;
	}
	name[i+1] = strdup(buf1);
	number[i+1] = strdup(buf2);
	n++;

	printf("%s was added successfully \n",buf1);
}
int search(char *buf){
	int i=0;
	while (i<n){
		if(strcmp(name[i], buf)==0){
			return i;
		}
		i++;
	}
	return -1;
}
void find(){
	
	char buf[BUFFER_SIZE];
	scanf("%s",buf);
	int index = search(buf);
	if (index == -1){
		printf("No person named '%s' exists.\n",buf);
	} else {
		printf("%s\n",number[index]);
	}
}

void removes(){
	char buf[BUFFER_SIZE];
	scanf("%s",buf);
	
	int index = search(buf);
	if (index == -1){
		printf("No person named '%s' exists.\n",buf);
		return;
	}
	int j = index;
	while (j<n-1){
		name[j] = name[j+1];
		number[j] = number[j+1];
		j++;
	}
	n--;
	printf("'%s' was deleted successfully.\n",name[index]);
}

void status(){
	int i=0;
	while (i<n){
		printf("%s %s\n",name[i],number[i]);
		i++;
	}
	printf("Total %d persons.\n",n);
}
void load(){
	
	char file_name[BUFFER_SIZE];
	char buf1[BUFFER_SIZE];
	char buf2[BUFFER_SIZE];
	
	scanf("%s", file_name);
	FILE *fp = fopen(file_name, "r");
	if(fp == NULL){
		printf("open ERROR\n");
		return;
	}
	while(fscanf(fp, "%s",buf1) != EOF){
		fscanf(fp, "%s",buf2);
		name[n] = strdup(buf1); 
		number[n] = strdup(buf2);	
		n++;
	}
	fclose(fp);	
}

void save(){
	int i=0;
	char file_name[BUFFER_SIZE];
	char tmp[BUFFER_SIZE];

	scanf("%s",tmp); // which is for "as", discarded
	scanf("%s",file_name);
	FILE *fp = fopen(file_name,"w");
	if(fp == NULL){
		printf("open ERROR\n");
		return;
	}
	while(i<n){
		fprintf(fp,"%s %s\n",name[i],number[i]);
		i++;
	}
	fclose(fp);
}
