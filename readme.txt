使用函数指针做函数回调，注意字符和字符串的区别void (*callname)(char *name)参数为指针与void (*callname)(char)不一样
%c表示字符，%s表示字符串，strcpy只能用在字符串上
函数指针A（指针名字随便取）可以当作一个参数，传入B函数，在B函数里让结构体的函数指针等于参数名A，相当于让结构体的函数指针与参数A建立联系，等价。他们两个的参数类型，参数个数以及参数返回值都是一样的。

void initStudent(Student * student, const char  *name, int score, void (*call_score)(int),void (*callname)(char *name)) {
    strcpy(student->name , name);
    student->score = score;
    student->callback = call_score;
    student->calback_name = callname;
}

