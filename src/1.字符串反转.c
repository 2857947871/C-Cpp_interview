# include <stdio.h>
# include <string.h>

// 字符数组
char* reserverString_1(const char* str) {

    char* src = NULL;
    char tmp;
    int i, j;
    int len = strlen(str);

    src = (char* )str; // 移除const资格
    for (i = 0, j = len - 1; i < j; ++i, --j) {

        tmp = src[i];
        src[i] = src[j];
        src[j] = tmp;
    }

    return src;
}


int main() {

    const char str[15] = {"hello world"};
    char* dst = NULL;

    dst = reserverString_1(str);
    printf("%s\n", dst);

    return 0;
}