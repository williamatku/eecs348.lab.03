#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// give programmer control of program compute boundaries
#define MAX_PLAYS 100
#define MAX_TOUCHDOWNS MAX_PLAYS
#define MAX_FIELDGOALS MAX_PLAYS
#define MAX_SAFETIES MAX_PLAYS

/*
    Dev:            William A. Morris
    Created:        2023-02-09
    Last Modified:  2023-02-09

    KUID:           3057236
    Email:          morris.william@ku.edu
    Class:          EECS 348 
    Lab Section:    Thursdays @9am

    Description:    
        A simple (and probably unsafe) C Program to calculate possible play breakdowns of NFL Football scores.
*/
int main(int argc, char** argv) {
    // DEFINE point values for every play
    const int TD_POINTS = 6; 
    const int FG_POINTS = 3;
    const int SAFETY_POINTS = 2;
    const int TD2P_POINTS = 8;
    const int TDFG_POINTS = 7;
    // DEFINE max plays per game to check for
    const int TD_MAX = MAX_TOUCHDOWNS;
    const int FG_MAX = MAX_FIELDGOALS;
    const int SAFETY_MAX = MAX_SAFETIES;
    const int TD2P_MAX = MAX_TOUCHDOWNS;
    const int TDFG_MAX = MAX_TOUCHDOWNS;

    int dest_score;
    if (argc == 2) { 
        dest_score = atoi(argv[1]); // get score to calculate possibilities
    } else {
        printf("Enter a score: "); // ENSURE user is passing in a point value to calculate all possibilities within
        scanf("%d",&dest_score);
    }

    char buffer[10] = "not zero";
    printf("Listing all possibilities found w/ score: %d...\nPress ENTER to get more results, type 0 or 1 and then ENTER to exit.\n", dest_score);

    for (int td = 0; td < TD_MAX; td++) {
    for (int fg = 0; fg < FG_MAX; fg++) {
    for (int safety = 0; safety < SAFETY_MAX; safety++) {
    for (int td2p = 0; td2p < TD2P_MAX; td2p++) {
    for (int tdfg = 0; tdfg < TDFG_MAX; tdfg++) {
        // for every score possibility within programming-specified range...
        int score 
            = TD_POINTS*td 
            + FG_POINTS*fg 
            + SAFETY_POINTS*safety 
            + TD2P_POINTS*td2p 
            + TDFG_POINTS*tdfg;
        // match the score with USER provided score
        if (score == dest_score) {
            // print all results, as well as prompt the user to continue or term. the program
            fflush(stdin); // flush input and wait for any user-input
            printf("\tTDs:%d, FGs:%d, SAFETYs:%d, TD+2p:%d, TD+FG:%d\n",
                td, fg, safety, td2p, tdfg);
            fgets(buffer,100,stdin); // keep running the program until the user exits
            if (buffer[0] == '0' || buffer[0] == '1') return 0;
        }   
    }}}}}
    printf("Goodbye :)\n");
}