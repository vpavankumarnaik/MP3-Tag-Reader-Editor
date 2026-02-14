#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mp3_header.h"
void view_mp3(char* argv)
{
	FILE *fp = fopen(argv, "r");
	if(fp == 0)
	{
		printf("File not exist\n");
		return;
	}
	char id3[4];
	fread(id3, sizeof(id3) - 1, 1, fp);
	id3[3] = '\0';
	if((strcmp(id3, "ID3")) != 0)                                                 //check tag id3 is present
	{
		printf("It is not a mp3 file\n");
	}
	else
	{
		printf(".................................................................................................................\n");
		printf("MP3 Tag Reader and Editor for ID3v2\n");
		printf(".................................................................................................................\n");
		fseek(fp, 7, SEEK_CUR);                                               //fseek for moving offset in file
		for(int i = 0; i < 83 ; i++)
		{
			char tag[5];                                                  //read tag
			unsigned int size;
			fread(tag, sizeof(tag) - 1, 1, fp);                           
			fread(&size, 4, 1, fp);
			unsigned char *ptr = (char*)&size;                            //convert big endian to little endian
			for(int j = 0; j < 2; j++)
			{
				char temp = *(ptr + j);
				*(ptr + j) = *(ptr + (4 - j - 1));
				*(ptr + (4 - j - 1)) = temp;
			}
			if(taglist(tag) != NULL)
			{
				printf("%-10s", taglist(tag));
			}
			else
			{
				fseek(fp, 3 + size, SEEK_CUR);
				continue;
			}

			printf("%-10s", ":");
			fseek(fp, 3, SEEK_CUR);
			char content[size];
			fread(content, size - 1, 1, fp);
			content[size - 1] = '\0';

			printf("%-20s\n", content);
							
		}
		printf(".................................................................................................................\n");

	}
	fclose(fp);
}
