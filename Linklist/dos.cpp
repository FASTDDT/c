#include "basic.h"
void mysql_on(){
    system("net start mysql");
}
void mysql_off(){
system("net stop mysql");
};
char* redis_path(){
    char* s="d: & cd / & cd redis &";
    return s;
}

char* redis_on(char* path){
    char* dos="redis-server --service-start";
    char* s=strcat(path,dos);
    printf("%s",s);
    return strcat(path,dos);
}
char* redis_off(char* path){
    char* dos="redis-server --service-start";
    return strcat(path,dos);
}
int main(){

    redis_on(redis_path());
    return 0;
}

