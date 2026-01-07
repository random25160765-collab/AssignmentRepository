#include <stdio.h>
#include <string.h>

/* Convert INI files to XML files */

int ini_to_xml(const char *ini_fn, const char *xml_fn)
{
    FILE *ini = fopen(ini_fn, "r");
    FILE *xml = fopen(xml_fn, "w");
    if (!ini || !xml) {
        perror("Open ini and xml files");
        if (ini)    fclose(ini);
        if (xml)    fclose(xml);
        return -1;
    }

    fputs("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n", xml);
    fputs("<configuration>\n", xml);

    char line[1000];
    char section[100] = "";
    int in_section = 0;
    while (fgets(line, sizeof(line), ini)) {
        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] == ';' || line[0] == '\0') continue;
        if (line[0] == '[') {
            if (in_section) {
                fprintf(xml, "</%s>\n", section);
                in_section = 0;
            }
            char *end = strchr(line, ']');
            if (end == NULL) {
                fclose(ini);
                fclose(xml);
                return -2;
            }
            *end= '\0';
            strncpy(section, line + 1, sizeof(section));
            section[sizeof(section) - 1] = '\0';
            fprintf(xml, "<!-- Configuration of %s -->\n", section);
            fprintf(xml, "<%s>\n", section);
            in_section = 1;
        } else if (strchr(line, '=')) {
            char *key = line;
            char *value = strchr(line, '=');
            *value = '\0';
            value++;
            if (key && value) {
                key[strcspn(key, "\r\n")] = '\0';
                value += strspn(value, "\n"); 
                fprintf(xml, "\t<%s>%s</%s>\n", key, value, key);
            }
        }
    }
    if (in_section) {
        fprintf(xml, "</%s>\n", section);
        in_section = 0;
    }
    fprintf(xml, "</configuration>\n");
    fflush(xml);
    fclose(ini);
    fclose(xml);
    return 0;
}

void create_test_ini() {
    FILE *fp = fopen("test.ini", "w");
    if (!fp) {
        perror("Create test.ini");
        return;
    }
    
    // 典型INI文件结构
    fprintf(fp, "; This is a comment\n");
    fprintf(fp, "; Test configuration file for INI to XML converter\n\n");
    
    fprintf(fp, "[http]\n");
    fprintf(fp, "domain=www.example.com\n");
    fprintf(fp, "port=8080\n");
    fprintf(fp, "timeout=30\n");
    fprintf(fp, "ssl_enabled=true\n\n");
    
    fprintf(fp, "[database]\n");
    fprintf(fp, "host=localhost\n");
    fprintf(fp, "port=3306\n");
    fprintf(fp, "username=admin\n");
    fprintf(fp, "password=secret123\n");
    fprintf(fp, "database_name=myapp\n\n");
    
    fprintf(fp, "[logging]\n");
    fprintf(fp, "level=INFO\n");
    fprintf(fp, "file=/var/log/myapp.log\n");
    fprintf(fp, "max_size=10485760\n");
    fprintf(fp, "backup_count=5\n\n");
    
    fprintf(fp, "[features]\n");
    fprintf(fp, "enable_cache=true\n");
    fprintf(fp, "cache_size=1000\n");
    fprintf(fp, "enable_api=true\n");
    fprintf(fp, "api_version=v2\n");
    
    fclose(fp);
    printf("Created test.ini\n");
}

int main()
{
    int result = ini_to_xml("test.ini", "test.xml");
    return 0;
}
