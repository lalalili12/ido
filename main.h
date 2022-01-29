//
// Created by User on 1/29/2022.
//

#ifndef UNTITLED2_MAIN_H
#define UNTITLED2_MAIN_H
#define SIZE 3
int isDigit(char c);
void replaceAll(char board[][SIZE*SIZE], char char1, char char2);
void change(char board[][SIZE*SIZE], int locationRow, int locationCol, char char1);
void add(char board[][SIZE*SIZE], int locationRow, int locationCol, char char1);
void delete(char board[][SIZE*SIZE], int locationRow, int locationCol);

#endif //UNTITLED2_MAIN_H
