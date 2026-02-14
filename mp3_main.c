#if 0

name  : V Pavan Kumar Naik
user id : 25021B_097
description : This is a project to extract the mp3 tags content and dispaly as well as to edit the content of tags

#endif

#include<stdio.h>
#include<string.h>
#include "mp3_header.h"
int main(int argc, char** argv)
{
	if(argc < 2)								//if user enter only one 
	{
		printf("invalid entry check (./a.out --help)\n");
		return 0;
	}
	if(((strcmp(argv[1], "-v")) == 0) && argc == 3)				//for view
	{
		view_mp3(argv[argc - 1]);
	}
	else if((strcmp(argv[1], "-e") == 0) && argc == 5) 			//for edit
	{
		edit_mp3(argv, argc);
		printf("Edited successfully\n");
	}
	else if((strcmp(argv[1], "--help")) == 0 && argc == 2)			//for help
	{
		printf("%-10s\n", "mp3_TagReader options");
		printf("----------------------------------------------------------------------------------\n");
		printf("%-10s   |   %-10s\n", "Task", "proper syntax");
		printf("----------------------------------------------------------------------------------\n");
		printf("%-10s   |   %-10s%-5s%-10s\n", "<view>", "./a.out", "-v", "file_name");
		printf("----------------------------------------------------------------------------------\n");
		printf("%-10s   |   %-10s%-5s%-15s%-10s%-10s\n", "<edit>", "./a.out", "-e", "Tag_options", "new_name", "file_name");
		printf("----------------------------------------------------------------------------------\n");
		printf("\n--------------------\n");
		printf("Tag Options\n");
		printf("--------------------\n");
		printf("%-10s : %-5s\n", "Title", "-t");
		printf("%-10s : %-5s\n", "Artist", "-a");
		printf("%-10s : %-5s\n", "Album", "-A");
		printf("%-10s : %-5s\n", "Year", "-y");
		printf("%-10s : %-5s\n", "Music", "-C");
		printf("%-10s : %-5s\n", "Comment", "-c");
	}
	else									
	{
		printf("invalid entry check (./a.out --help)\n");
		return 0;
	}
}
