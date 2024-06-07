#include <stdio.h>
#include "string.h"


typedef struct {
    char name[50];
    int score;
    void (*callback)(int);
    void (*calback_name)(char *name);  //传入的是字符串，需要用char *name
} Student;

// 回调函数示例：打印成绩
void printScore(int score) {
    printf("student score ：%d \n", score);
}

void PrintfName(char *name)
{
        printf("name is %s \n", name); //字符串用%s，字符就用%c
}

// 初始化学生
void initStudent(Student * student, const char  *name, int score, void (*call_score)(int),void (*callname)(char *name)) {
    strcpy(student->name , name);
    student->score = score;
    student->callback = call_score;
    student->calback_name = callname;
}

// 运行回调函数
void runCallback(Student * student) {
    if (student->callback != NULL) {
        student->callback(student->score);
        student->calback_name(student->name);
    }
}

int main() {
    Student student1, student2;

    // 初始化学生1
    initStudent(&student1, "张三", 55, printScore,PrintfName);
    //  " "代表字符串   ' '代表字符

    // 初始化学生2
    initStudent(&student2, "lisi", 92,printScore, PrintfName);


    // 运行回调函数
    runCallback(&student1);
    runCallback(&student2);

    return 0;
}
