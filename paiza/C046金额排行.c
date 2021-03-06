/* 输入人名和对应人名买的书籍金额，要求输入根据花费金额大小的人名排行
如输入：名字长度20以内
3           
A B C
4
A 1000
B 1000
B 2000
C 2000
输出：
B
C
A
只使用了数组和字符串交换函数 */

#include <stdio.h>
#include <string.h>
int main(void){
    int n, m;
    scanf("%d", &n);   //输入人名个数
    char name[n][20]; //名字数组
    char book[20]; //临时储存人名变量
    int price;    //临时储存金额变量
    int money[n]; //金额数组
    int i, j; //外层和内层循环变量
       
    for (i = 0; i < n; i++){
        scanf("%s", name[i]); 
    }
    for (i = 0; i < n; i++){  //金额数组初始化为零
        money[i] = 0;
    }
    scanf("%d", &m);        //输入金额输入次数
    for (i = 0; i < m; i++){         
        scanf("%s %d", book, &price);
        for (j = 0; j < n; j++){
            if (strcmp(book, name[j]) == 0) //找到对应人名，进行金额累加
                money[j] += price; 
        }
    }       //得到和人名数组匹配的金额数组

    for (i = 0; i < n - 1; i++){       //对金额数组进行冒泡排序，循环n-1次
        for (j = 0; j < n - 1; j++){
            if (money[j] < money[j+1]){
                price = money[j];
                strcpy(book, name[j]);  //交换字符串变量，把后一项赋值给前项
                money[j] = money[j+1];
                strcpy(name[j], name[j+1]);
                money[j+1] = price;
                strcpy(name[j+1], book);
            }
        }
    }
    for (i = 0; i < n; i++){
        printf("%s\n", name[i]);
    }
    return 0;
}

//用相同的方法换成结构数组
#include <stdio.h>
#include <string.h>
struct read
{
    char name[20];
    int money;   
};                //定义一个结构
int main(void){
    int n, m;
    scanf("%d", &n);   //输入人名个数
    char people[20]; //临时储存人名变量
    int price;    //临时储存金额变量
    int i, j; //外层和内层循环变量
    struct read list[n];   //定义结构数组
    for (i = 0; i < n; i++){
        scanf("%s", list[i].name); //注意！调用结构数组中的数据时[i]跟在数组名list后面而不是变量name后面
    }
    for (i = 0; i < n; i++){  //金额数组初始化为零
        list[i].money = 0;
    }
    scanf("%d", &m);        //输入金额输入次数
    for (i = 0; i < m; i++){         
        scanf("%s %d", people, &price);
        for (j = 0; j < n; j++){
            if (strcmp(people, list[j].name) == 0) //找到对应人名，进行金额累加
                list[j].money += price; 
        }
    }       //得到和人名数组匹配的金额数组

    for (i = 0; i < n - 1; i++){       //对金额数组进行冒泡排序，循环n-1次
        for (j = 0; j < n - 1; j++){
            if (list[j].money < list[j+1].money){
                price = list[j].money;
                strcpy(people, list[j].name);  //交换字符串变量，把后一项赋值给前项
                list[j].money = list[j+1].money;
                strcpy(list[j].name, list[j+1].name);
                list[j+1].money = price;
                strcpy(list[j+1].name, people);
            }
        }
    }
    for (i = 0; i < n; i++){
        printf("%s\n", list[i].name);
    }
    return 0;
}
