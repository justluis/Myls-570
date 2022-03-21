//Luis Duran Hernandez RedID:821948771. Jose Tiznado RedID:821741148
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

void _myls(char* dir, int flag){  
    struct dirent *myfile;
    DIR *directory;
    directory=opendir(dir);
         if(directory == NULL)
        {
            printf("Could not access %s", dir);
            exit (1);
        }
        if(directory != NULL && flag ==1) //print all of the files of the given directory with hidden files.
        {
            printf("%s\n", dir);
            while((myfile = readdir(directory)) != NULL) 
            {
                printf("%s\n", myfile->d_name);
            }
        }
        else if (directory != NULL && flag ==0 ) 
        {
            printf("%s\n", dir);
            while((myfile = readdir(directory)) != NULL) {
                if( myfile->d_name[0] != '.') //print all of the files of the given directory W/O hidden files.
                {
                    printf("%s\n", myfile->d_name);
                }
            }
    }
    closedir(directory);
}

int main(int argc, char* argv[]) {
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    int option_val;
    int index;
    int flag_val = 0;
    char *path=NULL;   
    
    
    if(argc == 1) //  0 arguments
            {
                printf("testing No arguments\n");
                _myls(cwd,flag_val);
            }
    
    while ((option_val = getopt(argc, argv, ":h:")) != -1) // parses argv[] until theres no more"options". getopt returns a -1 when theres no "options".
    {
        switch (option_val) 
        {
            case 'h': 
                if(optarg != NULL) 
                { 
                    flag_val=1;
                    _myls(optarg,flag_val); 
                }
            break;
        default:
            flag_val=1;      
            _myls(cwd,flag_val);
            exit(EXIT_FAILURE);
        }
    }
    for (index = optind; index < argc; index++) //loops tru the remaining arguments non options.with out needing '-h'
    {   
        _myls(argv[index],flag_val);
    }
}