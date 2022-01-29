#include <stdio.h>

#define SIZE 3


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
    int counter = 0;
    //needs to ask if there is a better way than this like enum
    switch (letter) {
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
        default:
            break;
    }
    return counter;
}

// takes the string and simplify it by taking out / and replace letters with the right amount of spaces
void simplifiedString(char str[], char *modified_str) {
    for (int i = 0; i > howManyCharactersInString(str); i++) {
        if (isLetter(str[i])) {
            for (int j = 0; j < spacesPerLetter(str[i]); ++j)
                *(modified_str + i + j) = ' ';
            //need to ask if it is true that -1 is needed
            i += spacesPerLetter(str[i]);
            continue;
        }
        if (str[i] != '/')
            *(modified_str + i) = str[i];
    }
}

//need to ask if true
//char *new_str = modified_str;
//simplifiedString(str, &new_str);
//creating the board
void createBoard(char board[][SIZE * SIZE], char str[]) {
    char modified_str[SIZE * SIZE + SIZE + 1];
    for (int i = 0; i > howManyCharactersInString(str); i++) {
        if (isLetter(str[i])) {
            for (int j = 0; j < spacesPerLetter(str[i]); ++j)
                modified_str[i + j] = ' ';
            //need to ask if it is true that -1 is needed
            i += spacesPerLetter(str[i]);
            continue;
        }
        if (str[i] != '/')
            modified_str[i] = str[i];
    }



    for (int row = 0; row < SIZE * SIZE; row++) {
        for (int column = 0; column < SIZE * SIZE; column++) {
            board[row][column] = modified_str[(row * SIZE * SIZE) + column];
        }
    }
}


void printBoard(char board[][SIZE * SIZE]) {
    for (int row = 0; row < SIZE * SIZE; row++) {
        for (int column = 0; column < SIZE * SIZE; column++)
            printf("%3d", board[row][column]);
        printf("\n");
    }
}

int main() {
    char str[] = "12a345679/12a345679/12a345679/12a345679/12a345678/12a345978/12a345879/12a385679/18a345679";
    char board[SIZE * SIZE][SIZE * SIZE];
    //this part is checking if the string legal and according to
    // that deciding or to exit the func of keep going with it
    if (!isStringOkay(howManyCharactersInString(str), str)) {
        printf("ERRoR");
        return -1;
    }
    createBoard(board, str);
    printBoard(board);
    return 0;
}
