#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct movie{
    int sno;
    char name[50];
    int imdb;
    char type[50];
    char actor[50];
    char actress[50];
    char sup_actor[50];
    char sup_actress[50];
    char friends[100];
    int expenditure;
    int duration;
}movie;
void create(){
    movie *s;
    FILE *fp;
    
    int n,i;
    printf("Enter how many movies you want to store:");
    scanf("%d",&n);
    
    s=(movie*)calloc(n,sizeof(movie));
    fp=fopen("mymovies.txt","w");
    
    for(i=0;i<n;i++){
        printf("Enter sno");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter name");
        scanf("%[^\n]s",s[i].name);
        printf("Enter rating");
        scanf("%d",&s[i].imdb);
        fflush(stdin);
        printf("Enter type of movie");
        scanf("%[^\n]s",s[i].type);
         fflush(stdin);
        printf("Enter actor name");
        scanf("%[^\n]s",s[i].actor);
         fflush(stdin);
        printf("Enter actress name");
        scanf("%[^\n]s",s[i].actress); 
        fflush(stdin);
        printf("Enter supportive actor name");
        scanf("%[^\n]s",s[i].actor); 
        fflush(stdin);
        printf("Enter supportive actress name");
        scanf("%[^\n]s",s[i].sup_actress); 
        fflush(stdin);
        printf("Enter name of friends");
        scanf("%[^\n]s",s[i].friends); 
        printf("Enter expenditure");
        scanf("%d",&s[i].expenditure);
        fwrite(&s[i],sizeof(movie),1,fp);
    }
    fclose(fp);
}
void display(){
movie s1;
FILE *fp;
fp = fopen("mymovies.txt","r");
while(fread(&s1,sizeof(movie),1,fp)){
	printf("\n%-5d%-20s",s1.sno,s1.name);
	printf("%-20d",s1.imdb);
	printf("%-20s",s1.type);
	printf("%-20s",s1.actor);
	printf("%-20s",s1.actress);
	printf("%-20s",s1.actress);
	printf("%-20s",s1.sup_actor);
	printf("%-20s",s1.sup_actress);
	printf("%-20s",s1.friends);
	printf("%d",s1.expenditure);
}
fclose(fp);
}
void append(){
 movie *s;
    FILE *fp;
    
    int n,i;
    printf("Enter how movies you want:");
    scanf("%d",&n);
    
    s=(movie*)calloc(n,sizeof(movie));
    fp=fopen("mymovies.txt","a");
    
    for(i=0;i<n;i++){
        printf("Enter sno");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter name");
        scanf("%[^\n]s",s[i].name);
        printf("Enter rating");
        scanf("%d",&s[i].imdb);
        fflush(stdin);
        printf("Enter type of movie");
        scanf("%[^\n]s",s[i].type);
        fflush(stdin);
        printf("Enter actor name");
        scanf("%[^\n]s",s[i].actor);
        fflush(stdin);
        printf("Enter actress name");
        scanf("%[^\n]s",s[i].actress); 
        fflush(stdin);
        printf("Enter supportive actor name");
        scanf("%[^\n]s",s[i].actor); 
        fflush(stdin);
        printf("Enter supportive actress name");
        scanf("%[^\n]s",s[i].sup_actress); 
        fflush(stdin);
        printf("Enter name of friends");
        scanf("%[^\n]s",s[i].friends); 
        printf("Enter expenditure");
        scanf("%d",&s[i].expenditure);
    }
    fclose(fp);
	}
void noofrec(){
		movie s1;
		FILE *fp;
		fp = fopen("mymovies.txt","r");
		fseek(fp,0,SEEK_END);
		int n = ftell(fp)/sizeof(movie);
		printf("\n\nNO OF RECORDS=%d",n);
		fclose(fp);
	}
void search(){
    printf("\n1.Search by actor name");
    printf("\n2.Search by actress name");
    printf("\n3.Search by friend name");
    int ch;
    printf("\nEnter Your Choice: ");
    scanf("%d",&ch);
        switch(ch){
            case 1:
            	actor();
            	break;
            case 2:
			      actress();
				  break;
			case 3:
			      friend_name();
				  break;	  	
          }

}
void update(){
		movie s1;
FILE *fp, *fp1;
fp = fopen("mymovies.txt","r");
fp1= fopen("temp.txt","w");
int sno,found=0;
printf("enter sno to update:");
scanf("%d",&sno);
while(fread(&s1,sizeof(movie),1,fp)){
	if(s1.sno==sno){
		found=1;
	fflush(stdin);
        printf("Enter new name");
        scanf("%[^\n]s",s1.name);
        printf("Enter rating");
        scanf("%d",&s1.imdb);
        fflush(stdin);
        printf("Enter type of movie");
        scanf("%[^\n]s",s1.type);
        fflush(stdin);
        printf("Enter actor name");
        scanf("%[^\n]s",s1.actor);
        fflush(stdin);
        printf("Enter actress name");
        scanf("%[^\n]s",s1.actress); 
        fflush(stdin);
        printf("Enter supportive actor name");
        scanf("%[^\n]s",s1.actor); 
        fflush(stdin);
        printf("Enter supportive actress name");
        scanf("%[^\n]s",s1.sup_actress); 
        fflush(stdin);
        printf("Enter name of friends");
        scanf("%[^\n]s",s1.friends); 
        printf("Enter expenditure");
        scanf("%d",&s1.expenditure);
}
fwrite(&s1,sizeof(movie),1,fp1);
}
fclose(fp);
fclose(fp1);
if(found){
	fp1=fopen("temp.txt","r");
	fp=fopen("mymovies.txt","w");
	
	while(fread(&s1,sizeof(movie),1,fp1)){
         fread(&s1,sizeof(movie),1,fp)	;
     }
	fclose(fp);
    fclose(fp1);
}
else
   printf("\nRecord Not Found\n");
}

void delete_rec(){
			movie s1;
FILE *fp, *fp1;
fp = fopen("mymovies.txt","r");
fp1= fopen("temp.txt","w");
int sno,found=0;
printf("enter sno to delete:");
scanf("%d",&sno);
while(fread(&s1,sizeof(movie),1,fp)){
	if(s1.sno==sno){
		found=1;
}
else
   fwrite(&s1,sizeof(movie),1,fp1);
}
fclose(fp);
fclose(fp1);
if(found){
	fp1=fopen("temp.txt","r");
	fp=fopen("mymovies.txt","w");
	
	while(fread(&s1,sizeof(movie),1,fp1)){
         fread(&s1,sizeof(movie),1,fp)	;
     }
	fclose(fp);
    fclose(fp1);
}
else
   printf("\nRecord Not Found\n");

}
 void actress(){
	   movie s1;
       FILE *fp;
        fp = fopen("mymovies.txt","r");
        int found=0;
        char actress[50];
        printf("enter actress name to search:");
        scanf("%s",actress);
        while(fread(&s1,sizeof(movie),1,fp)){
        	if(strcmp(s1.actress,actress)==0){
	     	found=1;
	       printf("\n%-5d%-20s",s1.sno,s1.name);
	        printf("%-20d",s1.imdb);
          	printf("%-20s",s1.type);
           	printf("%-20s",s1.actor);
	        printf("%-20s",s1.actress);
         	printf("%-20s",s1.sup_actor);
	        printf("%-20s",s1.sup_actress);
	        printf("%-20s",s1.friends);
         	printf("%d",s1.expenditure);
}
}
if(!found)
    printf("\nRecord Not Found\n");
fclose(fp);
	}

void actor(){
	  movie s1;
FILE *fp;
fp = fopen("mymovies.txt","r");
int found=0;
char actor[50];
printf("enter actor name to search:");
scanf("%s",actor);
while(fread(&s1,sizeof(movie),1,fp)){
	if(strcmp(s1.actor,actor)==0){
		found=1;
	printf("\n%-5d%-20s",s1.sno,s1.name);
	printf("%-20d",s1.imdb);
	printf("%-20s",s1.type);
	printf("%-20s",s1.actor);
	printf("%-20s",s1.actress);
	printf("%-20s",s1.sup_actor);
	printf("%-20s",s1.sup_actress);
	printf("%-20s",s1.friends);
	printf("%d",s1.expenditure);
}
}
if(!found){
    printf("\nRecord Not Found\n");
}
fclose(fp);
	}

void friend_name(){
	  movie s1;
FILE *fp;
fp = fopen("mymovies.txt","r");
int found=0;
char friend_name[50];
printf("enter friend name to search:");
scanf("%s",friend_name);
while(fread(&s1,sizeof(movie),1,fp)){
	if(strcmp(s1.friends,friend_name)==0){
		found=1;
	printf("\n%-5d%-20s",s1.sno,s1.name);
	printf("%-20d",s1.imdb);
	printf("%-20s",s1.type);
	printf("%-20s",s1.actor);
	printf("%-20s",s1.actress);
	printf("%-20s",s1.sup_actor);
	printf("%-20s",s1.sup_actress);
	printf("%-20s",s1.friends);
	printf("%d",s1.expenditure);
}
}
if(!found)
    printf("\nRecord Not Found\n");
fclose(fp);
	}	
		
	

int main() {
    int ch;
    do{
        printf("\n1.CREATE");
         printf("\n2.DISPLAY");
          printf("\n3.APPEND");
          printf("\n4.NO OF RECORDS");
          printf("\n5.SEARCH");
          printf("\n6.UPDATE");
          printf("\n7.DELETE");
           printf("\n0.EXIT");
           
        printf("\nEnter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
               create();
            break;
            case 2:
                display();
            break;
            case 3:
                append();
            break;
            case 4:
                noofrec();
            break;
            case 5:
                search();
            break;
            case 6:
            	update();
            break;	
            case 7:
            		delete_rec();
            break;	
        }
    }
    while(ch!=0);

    return 0;
}
