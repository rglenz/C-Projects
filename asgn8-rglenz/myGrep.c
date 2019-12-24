/*Raymond Lenz Assignment 8*/

#include <stdio.h>
#include "wordList.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int index=0,lineCount=0,wordCount=0,tempLength=0;
    int maxLnCnt=0,len=0,nodeCnt=0;
    char maxLn[MAXLINE],line[MAXLINE],tmpLn[MAXLINE];
    FILE *file;
    char *token;
    Node *tail,*head;
    Node dummy;
    /*initialize the dummy node to head and tail*/
    head=&dummy;
    tail=&dummy;
    /*checks for proper amount of args*/
    if(argc!=3){
        printf("myGrep: Improper number of arguments\n");
        printf("Usage: ./a.out <word> <filename>\n");
        return 0;
    }
    /*open the file */ 
    file=fopen(argv[2],"r");
    /*check to see if file exists*/
    if(!file){
        printf("myGrep: Unable to open file: %s\n",argv[2]);
        return 0;
    }
    /*print the command line args*/
    for(index=0;index<argc;index++){
        printf("%s ",argv[index]);
    }
    printf("\n");
   
    /*iterate through the file and find the max line and line count */
    while(fgets(tmpLn,MAXLINE,file)){
        tempLength=strlen(tmpLn);
        if(tempLength>maxLnCnt){
            maxLnCnt=tempLength;
            strcpy(maxLn,tmpLn);
        }
        strcpy(line,tmpLn);
        wordCount=0;
        token=strtok(tmpLn," ");  
        while(token!=NULL){ 
            len=strlen(token);
            if(token[len-1]=='\n'){
                token[len-1]='\0';
            }
            if(!strcmp(token,argv[1])){
                nodeCnt++;
                tail=addToTail(tail,line,lineCount,wordCount);                      
            }
            wordCount++;
            token=strtok(NULL," ");
        }                
        lineCount++;
    }
    
    /*format the output*/ 
    printf("Longest line (%d characters): %s",maxLnCnt,maxLn);
    printf("Number of lines: %d\n",lineCount);
    printf("Total occurrences of \"%s\": %d\n",argv[1],nodeCnt);
    /*handle if the word isn't found*/
    if(nodeCnt==0){
        return 0;
    } 
    printList(head);
    fclose(file);
    return(0);
}
