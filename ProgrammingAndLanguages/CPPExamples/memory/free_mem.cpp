#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string>
using namespace std;
int main(int argc,char** agrv)
{
    FILE *fd;
    char buff[256];
    char str[20];
    int total = 0;
    int free = 0;
    int b_buff = 0;
    int p_cache = 0;

    float use=0;
    
    fd = fopen ("/proc/meminfo", "r");
    
    fgets (buff, sizeof(buff), fd);
    sscanf (buff, "%s %d %*s", str, &total);
    cout << str << total << endl;
    
    fgets (buff, sizeof(buff), fd);
    sscanf (buff, "%s %d %*s", str, &free);
    cout << str << free << endl;

    fgets (buff, sizeof(buff), fd);
    sscanf (buff, "%s %d %*s", str, &b_buff);
    cout << str << b_buff << endl;

    fgets (buff, sizeof(buff), fd);
    sscanf (buff, "%s %d %*s", str, &p_cache);
    cout << str << p_cache << endl;

    use=(float)((total - free - b_buff - p_cache) / (total * 0.01)); //百分比
    
    fclose(fd);    
    cout<<"use:"<<use<<endl;
    return 0;
}
