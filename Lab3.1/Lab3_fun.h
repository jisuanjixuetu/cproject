//
// Created by 86199 on 2022/11/9.
//

#ifndef LAB3_1_LAB3_FUN_H
#define LAB3_1_LAB3_FUN_H
void ChangeWorkingDirectory();
int RandomInt(int max, int min);
void scandata();
int ifFileName(/*const*/ char* filename);
int turn_int(int* pn, char* str);
void GenerateDataFiles_2dArr(int DataNum_int, const char* filename);
void GenerateDataFiles_StructArr(int DataNum_int, const char* filename);
#endif //LAB3_1_LAB3_FUN_H
