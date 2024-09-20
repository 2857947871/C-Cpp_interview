# include <stdio.h>
# include <stdlib.h>
# include <string.h>


// void* memcpy(void* dst, const void* src, size_t n)
void my_memcpy(void* dst, const void* src, size_t n) {

    if (dst == NULL || src == NULL) {
        perror("invalid src or dst\n");
        return;
    }

    char* psrc;
    char* pdst;

    // src在低地址并且内存重叠
    /*
    src: 位置: 0 - 9   内容: [a, b, c, d, e, f, g, h, i, j]
    dst: 位置: 5 - 14  内容: [None]

    psrc: 0 + 10 - 1 -> 9
    pdst: 5 + 10 - 1 -> 14
    
    内存重叠 -> 倒序复制
    while:
        mem[14] = mem[9]
                .
                .
                .
        mem[5]  = mem[0]
    */
    if ((src < dst) && (char*)src + n > (char* )dst) 
    {
        psrc = (char* )src + n - 1;
        pdst = (char* )dst + n - 1;

        while (n--) {
            *pdst-- = *psrc--;
        }
    }

    // src在高地址or内存不重叠 -> 正常复制
    /*
    src: 位置: 0  - 9    内容: [a, b, c, d, e, f, g, h, i, j]
    dst: 位置: 15 - 24   内容: [None]

    psrc: 0  + 10 - 1 -> 9
    pdst: 15 + 10 - 1 -> 24

    while:
        mem[15] = mem[0]
        mem[16] = mem[1]
                .
                .
                .
        mem[24] = mem[9]
    */
    else
    {
        psrc = (char* )src;
        pdst = (char* )dst;

        while (n--) {
            *pdst++ = *psrc++;
        }
    }
}

// void strcpy (char *dest,const char* src)
void my_strcpy (char *dst, const char* src) {

    char* p = dst;
    while (*src != '\0') { *p++ = *src++; }
    *p = '\0'; // 最后添加'\0'标志字符串结束
}

// int strcmp(const char *s,const char * t)
int my_strcmp(const char *s, const char * t) {

    while (*s != '\0' || *t != '\0') {
        if (*s != *t) {
            return *s - *t;
        }
    }

    return 0;
}

// char *strcat(char *dest，char *src)
char* my_strcat(char *head, char *tail) {
    char* p = malloc((strlen(head) + strlen(tail)) * sizeof(char));
    p = head + strlen(head);

    while (*tail != '\0') {
        *p++ = *tail++;
    }
    
    *p = '\0'; // 最后添加'\0'标志字符串结束
    
    return head;
}

// int strlen(char *src)
int my_strlen(const char* src) {
    if (src == NULL) {
        return 0;
    }

    int i = 0;
    while (src[i] != '\0') { ++i; }

    return i;
}

// 字符串 -> 整数
int my_atoi(char* s) {
    int i = 0;
    int num = 0;
    int sign = 0;

    if (s[0] == '-') {
        sign = -1;
        ++i;
    } else {
        sign = 1;
    }

    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else {
            break;
        }
        ++i;
    }

    return num * sign;
}

// 整数 -> 字符串
void my_itoa(int num, char* s) {

    int i = 0;
    int tmp = 0;

    if (num < 0) {
        s[i] = '-';
        num = -num;
        ++i;
    }

    while (num > 0)
    {
        tmp = num % 10;
        num = num / 10;
        s[i] = tmp + '0';
        i++;
    }

    // 反转数字部分
    int start = 0;
    int end = i - 1;
    while (start < end) {
        if (s[start] == '-')
            start++;
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }

    s[i] = '\0';
}

int main() {

/*
======================== memcpy ========================
*/
# if 0
    //  1. 内存不重叠
    char src[11] = "abcdefghij";
    char dst[11];

    my_memcpy(dst, src, 10);
    printf("dst: %s\n", dst);

    // 2. 内存重叠, src 在 dst 之前
    char src_dst[16] = "abcdefghij";
    my_memcpy(src_dst + 5, src_dst, 10);
    printf("src_dst: %s\n", src_dst + 5);

    // 3. 内存重叠，dst 在 src 之前
    char dst_src[16] = "abcdefghij";
    my_memcpy(dst_src, dst_src + 5, 5);
    printf("dst_src: %s\n", dst_src);
#endif

/*
======================== strcpy ========================
*/
# if 0
    char src[11] = "abcdefghij";
    char dst[11];

    my_strcpy(dst, src);
    printf("dst: %s\n", dst);

# endif

/*
======================== strcmp ========================
*/
# if 0
    int res = 0;
    char src[11] = "abcdefghij";
    char dst[11] = "fghijfghij";
    res = my_strcmp(src, dst);
    
    printf("res: %d\n", res);

# endif

/*
======================== strcat ========================
*/
# if 0
    char *tail = "fghij";
    char *head = (char*)malloc(21 * sizeof(char)); // 分配21个字符空间
    if (head == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    my_strcpy(head, "abcdefghij");

    head = my_strcat(head, tail);

    printf("p: %s\n", head);  // 期望输出: "abcdefghijfghij"

    free(head);
# endif

/*
======================== atoi&itoa ========================
*/
# if 1
    int i;
    char* num;
    char num_s[10] = {"-98765"};
    // char num_s[10] = {'-', '9', '8', '7', '6', '\0'};
    int num_i;

    for (i = 0; i < my_strlen(num_s); ++i) {
        printf("%c ", num_s[i]);
    }
    printf("\n");

    num_i = my_atoi(num_s);
    printf("num_i: %d\n", num_i);

    my_itoa(num_i, num);
    printf("num_s: %s\n", num);
    

# endif

    return 0;
}