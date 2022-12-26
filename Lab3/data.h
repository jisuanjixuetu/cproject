//
// Created by 86199 on 2022/10/19.
//

#ifndef LAB3_DATA_H
#define LAB3_DATA_H
#define MAX_STR_LEN 100
 struct configinfo{
    char filesavepath[MAX_STR_LEN];
    char filename[MAX_STR_LEN] ;
    int number;
    int maxvalue1;
    int minvalue1;
    int maxvalue2;
    int minvalue2;
    int recordcount1;
    int recordcount2;
};


typedef  struct  DataItem{
    int  item1 ;     //数据记录三元组第一个元素
    int  item2 ;     //数据记录三元组第二个元素
    int  item3 ;     //数据记录三元组第三个元素
} DATAITEM;
#endif //LAB3_DATA_H
