/**
 * CSC 225, Assignment 7
 */

#include <stdio.h>

/**
 * Prints out positive integers, counting backwards from n to 1.
 * n - A positive integer at which to start
 */
void countBackwardsFrom(int n) {
    /* TODO: Complete this function. */
    if(n==1){
        printf("%d",n);
    }
    else if(n>1){
        printf("%d, ",n);
        countBackwardsFrom(n-1);
    }

}

/**
 * Prints out positive integers, counting forwards from 1 to n.
 * n - A positive integer at which to stop
 */
void countForwardsTo(int n) {
    /* TODO: Complete this function. */
    if(1==n){
        printf("%d", n);
    }
    
    else if(n>1){
        countForwardsTo(n-1);
        
        printf(", %d",n);
        
    }
    

}

