#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"



#define ANSI_COLOR_BLUE  "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void error(char* err){
    printf(" Error %s \n",err);
}


void makeMove(char board[][SIZE*SIZE], char move[]){
    char *token;

    char *func_name;
    func_name = strtok(move , ',');
    char* arg[4] = {NULL,NULL,NULL,NULL};
    int counter = 0;
    while( token != NULL && counter < 4 ) {
        token = strtok(NULL, ',');
        arg[counter] = token;
        counter++;
    }
    if (arg[4] != NULL){
        error("too many args");
     return;
    }
}

bool isnumber(char *arg1);

void pickMove(char board[][SIZE * SIZE], char* func , char* arg1, char* arg2, char* arg3){
    if (arg2 == NULL || arg1 == NULL){
        error("give me more arg");
        return;
    }
    //calling to replaceall
    if(!strcmp(func,"replaceAll")){
        if(arg3 == NULL)
            replaceAll(board,*arg1,*arg2);
        else
            error("too many args");
        return;
    }
    //calling to change
    if(!strcmp(func,"change")){
        int locationRow,locationCol;
        char c;
        if (!isnumber(arg1) || !isnumber(arg2)) {
            error("not a number ");
            return;
        }
        locationRow = atoi(arg1);
        locationCol = atoi(arg2);
        if (arg3 == NULL){
            error("missing arg");
            return;
        }
        c = *arg3;
        change(board,locationRow,locationCol,c);
        return;
    }
    //calling to add
    if(!strcmp(func,"add")){
        int locationRow,locationCol;
        char c;
        if (!isnumber(arg1) || !isnumber(arg2)) {
            error("not a number ");
            return;
        }
        locationRow = atoi(arg1);
        locationCol = atoi(arg2);
        if (arg3 == NULL){
            error("missing arg");
            return;
        }
        c = *arg3;
        add(board,locationRow,locationCol,c);
        return;
    }
    //calling to delete
    if(!strcmp(func,"delete")){
        int locationRow,locationCol;
        if (!isnumber(arg1) || !isnumber(arg2)) {
            error("not a number ");
            return;
        }
        locationRow = atoi(arg1);
        locationCol = atoi(arg2);
        if (arg3 != NULL){
            error("too many args");
            return;
        }
        delete(board,locationRow,locationCol);
        return;
    }

}

bool isnumber(char *arg1) {
    for (int i = 0; arg1[i] != '\0'; ++i) {
        if(!isDigit(arg1[i]))
            return 0;
    }
    return 1;
}

void replaceAll(char board[][SIZE*SIZE], char char1, char char2);
void change(char board[][SIZE*SIZE], int locationRow, int locationCol, char char1);
void add(char board[][SIZE*SIZE], int locationRow, int locationCol, char char1);
void delete(char board[][SIZE*SIZE], int locationRow, int locationCol);

/*
    int main () {
    char str[80] = "This is - www.tutorialspoint.com - website";

    char *token;


    token = strtok(str, ',');


    while( token != NULL ) {


        token = strtok(NULL, ',');
    }

    return(0);
}

 */


//TODO: TEST

//a func that check if a character is a digit
int isDigit(char c) {
    if (c >= '1' && c <= '9')
        return 1;
    return 0;
}

//a func that check if a character is a letter
int isLetter(char c) {
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

//this function check for the number of characters in the string
int howManyCharactersInString(char const str[]) {
    int counter = 0, index = 0;
    while (str[index] != '\0') {
        counter++;
        index++;
    }
    //needs to ask if it is right
    return ++counter;
}


//this func checks all the characters are legal or / or digit or letter
int isStrGoodCharacters(int size, char str[]) {
    for (int i = 0; i < size - 1; ++i) {
        if (!(str[i] == '/' || isDigit(str[i]) || isLetter(str[i])))
            return 0;
    }
    return 1;
}

//this func counts for the legal amount of character ,already checks letters as spaces
int placeCounter(int size, char str[]) {
    int counter = 0;
    for (int index = 0; index < size; index++) {
        if (isDigit(str[index]) || str[index] == '/')
            counter++;
        if (isLetter(str[index]))
            switch (str[index]) {
                case 'a':
                    counter += 1;
                    break;
                case 'b':
                    counter += 2;
                    break;
                case 'c':
                    counter += 3;
                    break;
                case 'd':
                    counter += 4;
                    break;
                case 'e':
                    counter += 5;
                    break;
                case 'f':
                    counter += 6;
                    break;
                case 'g':
                    counter += 7;
                    break;
                case 'h':
                    counter += 8;
                    break;
                case 'i':
                    counter += 9;
                    break;
            }
    }

    if (counter != (SIZE * SIZE) * (SIZE * SIZE) + (SIZE * SIZE) - 1)
        return 0;
    return 1;
}

//this func checks all the possible ways that the string can be forbidden
int isStringOkay(int size, char str[]) {
    if (!isStrGoodCharacters(size, str) || !placeCounter(size, str))
        return 0;
    return 1;
}


// this func returns how many spaces are needed to fill the board for specific letter
int spacesPerLetter(char letter) {
    //needs to ask if there is a better way than this like enum
    switch (letter) {
        case 'a':
          return 1;
        case 'b':
          return 2;
        case 'c':
          return 3;
        case 'd':
          return 4;
        case 'e':
          return 5;
        case 'f':
          return 6;
        case 'g':
          return 7;
        case 'h':
          return 8;
        case 'i':
          return 9;
        default:
          return 0;
    }
}

// takes the string and simplify it by taking out / and replace letters with the right amount of spaces
void simplifiedString(char str[], char *modified_str) {
    for (int i = 0; i > howManyCharactersInString(str); i++) {
        if (isLetter(str[i])) {
            for (int j = 0; j < spacesPerLetter(str[i]); ++j)
                *(modified_str + i + j) = ' ';
            i += spacesPerLetter(str[i]);
            continue;
        }
        if (str[i] != '/')
            *(modified_str + i) = str[i];
    }
}


//creating the board
void createBoard(char board[][SIZE * SIZE], char str[]) {
    char modified_str[SIZE * SIZE * SIZE * SIZE + SIZE + 1];
    int blanksAdded = 0;
    for (int i = 0; i < howManyCharactersInString(str); i++) {
        if (isLetter(str[i])) {
            for (int j = 0; j < spacesPerLetter(str[i]); ++j)
                modified_str[i + j + blanksAdded] = ' ';
            blanksAdded += (spacesPerLetter(str[i]) - 1);
        }
        else if (str[i] != '/')
            modified_str[i + blanksAdded] = str[i];
        else {
          blanksAdded--;
        }
    }

    for (int row = 0; row < SIZE * SIZE; row++) {
        for (int column = 0; column < SIZE * SIZE; column++) {
            board[row][column] = modified_str[(row * SIZE * SIZE) + column];
        }
    }
}
// prints the board
void printBoard(char board[][SIZE * SIZE]) {
    for (int row = 0; row < SIZE * SIZE; row++) {
        for (int column = 0; column < SIZE * SIZE; column++) {
          printf(ANSI_COLOR_BLUE "%3c" ANSI_COLOR_RESET, board[row][column]);
        }
        printf("\n");
    }
}




int main() {

    error("no");

    char str[] = "12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12ab5679/18a345679";
    char board[SIZE * SIZE][SIZE * SIZE];
    if (!isStringOkay(howManyCharactersInString(str), str)) {
        printf("ERRoR");
        return -1;
    }
    createBoard(board, str);
    printBoard(board);
    scanf("%c");
    return 0;
}
