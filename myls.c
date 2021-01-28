#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>


void _ls(const char *dir,int op_a,int op_l)
{
    //Function logic here
}


int main(int argc, char* argv[]) {

    struct dirent *myfile;
    struct stat mystat;
    DIR *mydir = opendir(argv[1]);
    char buf[512];

    if(mydir == NULL) {
        sprintf("Could not access ", argv[1]);
        return 0;
    }

    while((myfile = readdir(mydir)) != NULL) {
        sprintf(buf,"%s/%s", argv[1], myfile->d_name);
        stat(buf, &mystat);
        printf("%s\n", myfile->d_name);
    }
    closedir(mydir);
    return 0;
}