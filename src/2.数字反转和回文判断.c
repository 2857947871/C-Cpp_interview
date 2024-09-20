# include <stdio.h>
# include <string.h>
# include <stdlib.h>

// 数字反转
int reverse(int num) {

    int res = 0;
    
    while (num != 0) {
        res = res * 10 + num % 10;
        num = (num - num % 10) / 10;
    }
    
    return res;
}

// 回文判断
int palindrome_bool(char* str) {
    
    int idx = 0;
    int len = 0;
    len = strlen(str);
    char* str_ = (char* )malloc(sizeof(char) * len);
    
    idx = len - 1;
    while (idx != -1) {
        str_[len - 1 - idx] = str[idx];
        idx--;
    }
    
    printf("reverse: %s", str_);

    return strcmp(str, str_);
}

int main() {
    
    int num = 123;
    int res = 0;

    res = reverse(num);
    printf("reverse: %d\n", res);


    char str_1[10] = {"Hello"};
    res = palindrome_bool(str_1);
    if (res == 0) printf("this str is palindrome\n");
    else printf("this str is not palindrome\n");

    char str_2[10] = {"tenet"};
    res = palindrome_bool(str_2);
    if (res == 0) printf("this str is palindrome\n");
    else printf("this str is not palindrome\n");


    return 0;
}