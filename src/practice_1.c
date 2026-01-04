/*
解析URL中的路径和查询字符串
例如：http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PARAMS 20

#define URL_NO_PARAM 0
#define URL_ERROR_FORMAT -1
#define URL_ERROR_NULL -2
#define URL_ERROR_MEMORY -3

typedef struct {
    char path[50];
    struct {
        char key[30];
        char value[30];
        int has_value;
    } KeyValuePair[MAX_PARAMS];
    int key_value_cnt;
} URL;

int url_process(const char *input, URL *url)
{
    if (input == NULL || url == NULL) return URL_ERROR_NULL;

    char *input_copy = strdup(input);

    if (input_copy == NULL) return URL_ERROR_MEMORY;

    memset(url, 0, sizeof(URL));

    char *saveptr1;
    char *header = strtok_r(input_copy, "?", &saveptr1);

    if (header == NULL) {
        free(input_copy);
        return URL_ERROR_FORMAT;
    }

    strncpy(url->path, header, sizeof(url->path) - 1);
    url->path[sizeof(url->path) - 1] = '\0';

    char *key_value_pairs = strtok_r(NULL, "?", &saveptr1);

    if (key_value_pairs == NULL) {
        free(input_copy);
        return URL_NO_PARAM;
    }

    char *saveptr2, *saveptr3;
    char *pair = strtok_r(key_value_pairs, "&", &saveptr2);

    int kv_cnt = 0;

    while (pair) {
        char *key = strtok_r(pair, "=", &saveptr3);
        char *value = strtok_r(NULL, "=", &saveptr3);
        if (kv_cnt < MAX_PARAMS) {
            if (key) {
                strncpy(url->KeyValuePair[kv_cnt].key, key, sizeof(url->KeyValuePair[kv_cnt].key) - 1);
                url->KeyValuePair[kv_cnt].key[sizeof(url->KeyValuePair[kv_cnt].key) - 1] = '\0';
            }
            if (value) {
                strncpy(url->KeyValuePair[kv_cnt].value, value, sizeof(url->KeyValuePair[kv_cnt].value) - 1);
                url->KeyValuePair[kv_cnt].value[sizeof(url->KeyValuePair[kv_cnt].value) - 1] = '\0';
                url->KeyValuePair[kv_cnt].has_value = 1;
            } else {
                url->KeyValuePair[kv_cnt].has_value = 0;
            }
            kv_cnt++;
        }
        pair = strtok_r(NULL, "&", &saveptr2);
    }
    url->key_value_cnt = kv_cnt;
    free(input_copy);
    return url->key_value_cnt;
}

// 下面是ai写的测试代码

// 打印URL结构的内容
void print_url_info(URL *url, int return_code)
{
    printf("\n=== URL解析结果 ===\n");
    printf("返回码: %d\n", return_code);
    
    if (return_code >= 0 || return_code == URL_NO_PARAM) {
        printf("路径: %s\n", url->path);
        printf("参数数量: %d\n", url->key_value_cnt);
        
        for (int i = 0; i < url->key_value_cnt; i++) {
            printf("参数 %d: ", i + 1);
            printf("key='%s'", url->KeyValuePair[i].key);
            
            if (url->KeyValuePair[i].has_value) {
                printf(", value='%s'", url->KeyValuePair[i].value);
            } else {
                printf(", value=<空>");
            }
            printf("\n");
        }
    } else {
        switch (return_code) {
            case URL_ERROR_FORMAT:
                printf("错误: URL格式不正确\n");
                break;
            case URL_ERROR_NULL:
                printf("错误: 输入或输出指针为NULL\n");
                break;
            case URL_ERROR_MEMORY:
                printf("错误: 内存分配失败\n");
                break;
            default:
                printf("错误: 未知错误码 %d\n", return_code);
        }
    }
    printf("==================\n\n");
}

// 主测试函数
int main(void)
{
    URL url;
    int result;
    
    printf("URL解析器测试程序\n");
    printf("==================\n");
    
    // 测试用例1：正常的完整URL
    printf("测试用例1: 正常的完整URL\n");
    const char *test1 = "http://www.google.cn/search?complete=1&hl=zh-CN&ie=GB2312&q=linux&meta=";
    result = url_process(test1, &url);
    print_url_info(&url, result);
    
    // 测试用例2：没有查询参数的URL
    printf("测试用例2: 没有查询参数的URL\n");
    const char *test2 = "http://www.example.com/index.html";
    result = url_process(test2, &url);
    print_url_info(&url, result);
    
    // 测试用例3：只有查询字符串，没有路径（异常情况）
    printf("测试用例3: 只有查询字符串，没有路径\n");
    const char *test3 = "?name=John&age=30";
    result = url_process(test3, &url);
    print_url_info(&url, result);
    
    // 测试用例4：空的value
    printf("测试用例4: 空的value\n");
    const char *test4 = "/api/user?name=John&empty=&age=30";
    result = url_process(test4, &url);
    print_url_info(&url, result);
    
    // 测试用例5：只有key没有value
    printf("测试用例5: 只有key没有value\n");
    const char *test5 = "/search?debug&q=test&verbose";
    result = url_process(test5, &url);
    print_url_info(&url, result);
    
    // 测试用例6：复杂的值（包含特殊字符）
    printf("测试用例6: 复杂的值\n");
    const char *test6 = "/search?q=C%2B%2B+tutorial&page=1&sort=recent";
    result = url_process(test6, &url);
    print_url_info(&url, result);
    
    // 测试用例7：空指针测试
    printf("测试用例7: 空指针测试\n");
    result = url_process(NULL, &url);
    print_url_info(&url, result);
    
    // 测试用例8：url指针为NULL
    printf("测试用例8: url指针为NULL\n");
    result = url_process(test1, NULL);
    printf("返回码: %d (应该是%d URL_ERROR_NULL)\n\n", result, URL_ERROR_NULL);
    
    // 测试用例9：内存分配失败（这个很难模拟，但我们可以测试边界）
    printf("测试用例9: 非常大的URL（测试边界）\n");
    char big_url[5000];
    strcpy(big_url, "/search?");
    for (int i = 0; i < 100; i++) {
        char param[50];
        sprintf(param, "param%d=value%d&", i, i);
        strcat(big_url, param);
    }
    result = url_process(big_url, &url);
    print_url_info(&url, result);
    
    // 测试用例10：提取并解析特定URL
    printf("测试用例10: 提取并解析特定URL\n");
    const char *test10 = "https://example.com/products?category=electronics&sort=price&limit=10&page=2";
    result = url_process(test10, &url);
    print_url_info(&url, result);
    
    // 测试用例11：模拟真实搜索引擎查询
    printf("测试用例11: 模拟真实搜索引擎查询\n");
    const char *test11 = "https://www.google.com/search?q=how+to+learn+C+programming&sourceid=chrome&ie=UTF-8";
    result = url_process(test11, &url);
    print_url_info(&url, result);
    
    return 0;
}