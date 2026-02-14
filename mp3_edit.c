#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mp3_header.h"
void edit_mp3(char ** argv, int argc)
{
	FILE *fptr = fopen("temp.mp3", "w");
	FILE *fr = fopen(argv[argc - 1], "r");
	if(fr == NULL)
	{
		printf("File not exist\n");
		exit(0);
	}
	else
	{
		char edit_tag[5];                                                 	  //tag to edit
		char temp_content[100] = "";
		char header[10];
		if(check_tag(argv[2]) != NULL)
		{
			strcpy(edit_tag, check_tag(argv[2]));
		}
		if(argc >= 5)
		{
			for(int i = 3; i < (argc - 1); i++)
			{
				strcat(temp_content, argv[i]);
				strcat(temp_content, " ");
			}
		}
		else
		{
			strcpy(temp_content, argv[3]);                            	  //copy new_name from CL to content
		}
		fread(header, 10, 1, fr);
		fwrite(header, 10, 1, fptr);                                  		  //write 10bytes of header
		for(int i = 0; i < 6; i++)
		{
			char tag[5];
			fread(tag, 4, 1, fr);
			fwrite(tag, 4, 1, fptr);                                          //write tag
			unsigned int size;
			unsigned int new_size;
			fread(&size, 4, 1, fr);
			if(strcmp(tag, edit_tag) == 0)					  //if current tag is edit
			{
				unsigned char *ptr = (char*)&size;
				new_size = strlen(temp_content) + 1;
				unsigned char *ptr1 = (char*)&new_size;
				for(int j = 0; j < 2; j++)
				{
					char temp = *(ptr + j);                           //convert big endian previous size to liitle endian
					*(ptr + j) = *(ptr + (4 - j - 1));
					*(ptr + (4 - j - 1)) = temp;
					temp = *(ptr1 + j);                               //convert to big endian new_size of new_name
					*(ptr1 + j) = *(ptr1 + (4 - j - 1));
					*(ptr1 + (4 - j - 1)) = temp;
				}
				fwrite(&new_size, 4, 1, fptr);
				for(int j = 0; j < 2; j++)
				{
					char temp = *(ptr1 + j);                          //again convert new_size name to little endian
					*(ptr1 + j) = *(ptr1 + (4 - j - 1));
					*(ptr1 + (4 - j - 1)) = temp;
				}
				char flag[3];
				fread(flag, 3, 1, fr);
				fwrite(flag, 3, 1, fptr);                                 //write flags
				char content[new_size];
				strcpy(content, temp_content);                            //copy new_name from CL to content
				fwrite(content, new_size - 1, 1, fptr);
				fseek(fr, size - 1, SEEK_CUR);
				break;

			}
			else                                                              //if current tag is not to edit just write the content
			{
				if(strcmp(tag,"APIC") == 0)
				{
					break;
				}
				fwrite(&size, 4, 1, fptr);
				unsigned char *ptr = (char*)&size;
				for(int j = 0; j < 2; j++)
				{
					char temp = *(ptr + j);
					*(ptr + j) = *(ptr + (4 - j - 1));
					*(ptr + (4 - j - 1)) = temp;
				}
				char flag[3];
				fread(flag, 3, 1, fr);
				fwrite(flag, 3, 1, fptr);
				char content[size];
				fread(content, size - 1, 1, fr);
				fwrite(content, size - 1, 1, fptr);
				
			}

		}
		char ch;                                                                  //read and write char upto EOF
		while((fread(&ch, 1,1, fr)) == 1)
		{
				fwrite(&ch, 1, 1, fptr);
		}
	}
	remove(argv[argc - 1]);								  //remove the existing file
	rename("temp.mp3",argv[argc - 1]);						  //rename the temp.mp3 file to existing file
	fclose(fr);
	fclose(fptr);

}
