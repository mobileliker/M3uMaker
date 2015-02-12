/*******************************************************************************
project name:M3u Maker
version:0.1
author:WayneWu
email:mobileliker@163.com
method:
find current dinary flac file name,output the file name to the file(List.m3u)
Update Log:
V0.1
(1)finish the basic method
(2)Achieve find flac file no matter Sensitive
*******************************************************************************/

#include "stdio.h"
#include "stdlib.h"
#include "dirent.h"
#include "string.h"

int main()
{    
	char suffix[] = ".flac\0";
	char file_name[260];
	char *index1;
	DIR * dir;
    struct dirent * ptr;
    FILE *fp;
    int i;
    dir = opendir("./");
    fp = fopen("List.m3u","w");
    while((ptr = readdir(dir)) != NULL)
    {
    	strcpy(file_name,ptr->d_name);
    	i = 0;
    	while(file_name[i] != '\0')
    	{
    		if(file_name[i] >= 'A' && file_name[i] <= 'Z')
    		{
    			file_name[i] = file_name[i]-'A'+'a';
    		}
    		i++;
    	}
        index1 = strstr(file_name,suffix);
        if(index1)
        {
        	fputs(ptr->d_name,fp);
        	fputs("\n",fp);
	        printf("%s\n", ptr->d_name);
        }
    }
    closedir(dir);
    fclose(fp);
	system("pause");
	return 0;
}
