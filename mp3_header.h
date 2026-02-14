#ifndef MP3_HEADER_H
#define MP3_HEADER_H

typedef struct 
{
	char name[6];
	char value[20];
	char tag_option[4];
}name;
typedef struct
{
	name tags[6];
}tag_list;
static tag_list lists = {{{"TIT2", "TITLE", "-t"}, {"TPE1","ARTIST", "-a"}, {"TALB","ALBUM", "-A"}, {"TYER", "YEAR", "-y"}, {"TCON","MUSIC", "-C"}, {"COMM", "Comments", "-c"}}};

void view_mp3(char*);
void edit_mp3(char ** argv, int argc);
char* taglist(char * tag);
char *check_tag(char * Tag_option);

#endif
