#include <stdio.h>

int main()
{
    int age;
    char name[50];

    // 1. 跳过某些输入（*修饰符）
    scanf("%*s %d", &age);  // 跳过第一个字符串，读第二个整数

    // 2. 限制读取宽度
    char buf[11];
    scanf("%10s", buf);  // 最多读10个字符，保证不溢出

    // 3. 匹配特定字符
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);  // 输入：2023/12/25

    // 4. 字符集匹配
    char phone[20];
    scanf("%[0-9-]", phone);  // 只匹配数字和横线

    

    return 0;
}