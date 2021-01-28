#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdarg.h>


void myls(const char *dir) //and for multiple directories? dynamic variable arguments?
{
   // struct stat mystat; not sure if we need this to show the "flag" ('-h') for hidden files.
    
    struct dirent *myfile;
    DIR *mydir = opendir(dir);
    
    if (!mydir)
	{
		if (errno = ENOENT)
		{
			//If the directory is not found
			perror("Directory doesn't exist");
		}
		else
		{
			//If the directory is not readable then throw error and exit
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
    while ((myfile = readdir(mydir)) != NULL)
	{
		//If hidden files are found we continue
		if ( myfile->d_name[0] == '.')  //we need to modify this so it shows a "-h" flag next when hidden files are hidden (starting with a '.')
        {
            continue;
        }
        else{
            //we need to modify this so it shows a "-h" flag next when hidden files are hidden (starting with a '.')
        }
			
		printf("%s  ", myfile->d_name);
		
	}
	
}





int main(int argc, char* argv[]) {

if (argc == 1)
	{
		myls(".");
	}

else if (argc == 2)
    {

    }
    return 0;
}