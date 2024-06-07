#include <stdio.h>
#include "string.h"


typedef struct {
    char name[50];
    int score;
    void (*callback)(int);
    void (*calback_name)(char *name);  //��������ַ�������Ҫ��char *name
} Student;

// �ص�����ʾ������ӡ�ɼ�
void printScore(int score) {
    printf("student score ��%d \n", score);
}

void PrintfName(char *name)
{
        printf("name is %s \n", name); //�ַ�����%s���ַ�����%c
}

// ��ʼ��ѧ��
void initStudent(Student * student, const char  *name, int score, void (*call_score)(int),void (*callname)(char *name)) {
    strcpy(student->name , name);
    student->score = score;
    student->callback = call_score;
    student->calback_name = callname;
}

// ���лص�����
void runCallback(Student * student) {
    if (student->callback != NULL) {
        student->callback(student->score);
        student->calback_name(student->name);
    }
}

int main() {
    Student student1, student2;

    // ��ʼ��ѧ��1
    initStudent(&student1, "����", 55, printScore,PrintfName);
    //  " "�����ַ���   ' '�����ַ�

    // ��ʼ��ѧ��2
    initStudent(&student2, "lisi", 92,printScore, PrintfName);


    // ���лص�����
    runCallback(&student1);
    runCallback(&student2);

    return 0;
}
