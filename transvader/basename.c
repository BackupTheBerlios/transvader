/******************************************************************************
 *  basename.c
 *
 *  Retrieves the last part of a path string
 *
 *  Author: Mark Roesel
 *  Created: 2004-07-07 / Last updated: 2004-07-09
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/

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
			subString = (char*) malloc(strlen(path) - i);
			
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
