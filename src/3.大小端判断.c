//  若数据的高位字节存储在内存的低地址处, 低位字节存储在内存的高地址处 -> 大端存储
//  若数据的低位字节存储在内存的低地址处, 高位字节存储在内存的高地址处 -> 小端存储
# include <stdio.h>
# include <stdlib.h>

int check_sys() {
    int a = 1;

    // (char* )&a: a的指针转换为 char* 类型的指针
    // char* 类型的指针指向内存中的单个字节
    // a在内存中(小端) 01 00 00 00 -> *(char* )&a 对 char* 指针解引用 -> 返回1个字节 -> 01
    // a在内存中(大端) 00 00 00 01 -> *(char* )&a 对 char* 指针解引用 -> 返回1个字节 -> 00
    return *(char* )&a;
}

int main() {
    if (check_sys() == 1)
    {
        printf("big\n");
    }
    else
    {
        printf("small\n");
    }
    system("pause");
    return 0;
}