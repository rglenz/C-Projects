/**
 *  * CSC 225, Assignment 8
 *   */

/* TODO: Included any required libraries. */
#include "wordList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *  * Adds a new occurrence to the end of a list.
 *   * tail - A pointer to the current tail of a list, NULL if it's empty.
 *    * line - The line in which the word occurs
 *     * lineNum - The number of that line within the file
 *      * wordNum - The position of that word within that line
 *       *
 *        * Returns a pointer to the new tail of the list.
 *         */
Node *addToTail(Node *tail, char *line, int lineNum, int wordNum) {
    /* TODO: Implement this function. */
    Node *ptr;
    ptr=(Node *)malloc(sizeof(Node));
     
    strcpy(ptr->line,line);
    ptr->lineNum=lineNum;
    ptr->wordNum=wordNum;
    
    tail->next=ptr;
    return(ptr);
}

/**
 *  * Removes an occurrence from the beginning of a list.
 *   * head - A pointer to the current head of a list, NULL if it's empty
 *    * line - A pointer at which to store the removed line
 *     * lineNum - A pointer at which to store the removed line number
 *      * wordNum - A pointer at which to store the removed word number
 *       *
 *        * Returns a pointer to the new head of the list, NULL if it's (now) empty.
 *         */
Node *rmFromHead(Node *head, char *line, int *lineNum, int *wordNum) {
    /* TODO: Implement this function. */
    Node *ptr;
     
    if(head==NULL){
        return(NULL);
    }
    ptr=head->next; 
    strcpy(line,head->line);
    *lineNum=(head->lineNum);
    *wordNum=(head->wordNum);
    free(head); 
    return(ptr);
    
    
}

/**
 *  * Prints out every node in a list.
 *   * head - A pointer to the head of a list, NULL if it's empty
 *    */
void printList(Node *head) {
    /* TODO: Implement this function. */
    char *hdln;
    int hdLineNum=0,hdWordNum=0;
    hdln=head->line;
    head=head->next; 
    while(head!=NULL){
        head=rmFromHead(head,hdln,&hdLineNum,&hdWordNum);  
        printf("Line %d, word %d: %s",hdLineNum,hdWordNum,hdln);  
      
    }
}
