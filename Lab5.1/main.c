#include <stdio.h>
#include <string.h>
#include "function.h"
int main(int argc, char *argv[])
{
    if(strcmp(argv[2],"1")==0)
    {   
        wordStatistics1(argv[1]);
        othersStatistics1(argv[1]);
        wordStatistics2(argv[1]);
        othersStatistics2(argv[1]);
    }
    else if(strcmp(argv[2],"2")==0)
    {   
        printf("已完成%s文件的统计,统计结果保存在文件“/Users/86322/Desktop/Lab5.result.txt中!\n",argv[1]);
        wordStatistics2(argv[1]);
        othersStatistics2(argv[1]);
    }
    else{
    	wordStatistics2(argv[1]);
        othersStatistics2(argv[1]);
	}
    return 0;
}
