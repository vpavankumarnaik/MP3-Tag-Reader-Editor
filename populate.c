#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mp3_header.h"
char* taglist(char *tagname)
{

	int i;
	for(i = 0; i < 6; i++)
	{
		if((strcmp(lists.tags[i].name, tagname)) == 0)
		{
			return lists.tags[i].value;
		}
	}
	if(i == 6)
	{
		//printf("tag not found\n");
		return 0;
	}
}
char *check_tag(char * Tag_option)
{
	int i;
	for(i = 0; i < 6; i++)
	{
		if(strcmp(lists.tags[i].tag_option, Tag_option) == 0)
		{
			return lists.tags[i].name;
		}
	}
	if(i == 6)
	{
		printf("tag not found\n");
		return 0;
	}
}	
