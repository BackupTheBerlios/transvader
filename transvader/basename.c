#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* basename(const char* path)
{
	int i, j, position = 0;
	char* subString;
	
	if (path == 0 || *path == '\0')
	{
		return ".";
	}
	
	
	for (i = strlen(path) - 1; i + 1 ; i--)
	{
		if (*(path + i) == '/')
		{
			subString = malloc(strlen(path) - i);
			
			for (j = i +1 ; j < strlen(path); j++)
			{
				*(subString + position) = *(path + j);
				position++;
			}
			break;
		}
	}
	
	return subString;
}





int main(int argc, char** argv)
{
	printf("%s\n", basename("hallo"));
	printf("%s\n", basename(""));
	printf("%s\n", basename(0));
	
	printf("%s\n", basename("c:/programme/blabla/tmp/hallo"));
	
	return(0);	
}
