//
// Created by 86199 on 2022/11/17.
//

#ifndef LAB4_FUN_H
#define LAB4_FUN_H
void fun(int choice);
void functionOne();
int **functionTwo(char *filename);
struct Track * functionThree(char *filename);
int** functionFour(char *filename);
struct track*functionFive(char *filename);
int **functionSix(char *filename,int number);
struct Track*functionSeven(char*filename,int number);
int **functionEight(char *filename,int number);
struct track*functionNine(char *filename,int number);
void functionTen(char *filename,int number);
void functionEleven(char *filename,int number);
void functionTwelve(char*filename,int number);
void functionThirteen(char*filename,int number);
void functionFourteen();
void meau();
struct Track{
    int first;
    int second;
    int third;
};
typedef struct track{
    int first;
    int second;
    int third;
    struct track*next;
}track,*trackNode;
#endif //LAB4_FUN_H
