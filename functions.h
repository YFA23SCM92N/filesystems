/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define  disc_name "hardDisk.hdd"
//# define disc_space 104857600
//#define file_size 1024
//#define table_fileSize 24

char *disc_name = "hardDisk3.hdd";
int disc_space = 104857600;
int file_size = 1024;
int  table_fileSize = 24;


struct node
{
	int count = 0;
	int rem_size;
};

struct node1
{
	int starting_pos;
	char s[16];
	int bool1;
};

void copyFromHarddisc(char *source,char *destination)
{

}

void displayList()
{
	FILE *hdd;
	hdd = fopen(disc_name, "rb+");
	int file_count = 9,i=0;
	struct node header;
	fread(&header,1,sizeof(struct node), hdd);
	struct node1 file_data;


	while (i < header.count)
	{
		fread(&file_data,1, sizeof(struct node1), hdd);
		printf("%s\n", file_data.s);
		i++;
	}
}

void createHardDisc(FILE *hdd)
{
	struct node *file1 = (struct node*)malloc(sizeof(struct node));
	//hdd = fopen(disc_name, "wb+");

	if (hdd != NULL)
	{
		int files = 0;
		int rem_size = disc_space - 8;
		file1->count = files;
		file1->rem_size = rem_size;
		fwrite(file1, sizeof(struct node), 1, hdd);
	}
	fclose(hdd);
}



void copy_file(char *s)
{
	FILE *hdd=NULL, *file;
	struct node1 file1; 
	struct node header;

	hdd = fopen(disc_name, "rb+");
	if (hdd != NULL)
	{
		int val1 = 5;
	
			
		val1 = 6;
		int val2 = 7;
		fread(&val1, 1, sizeof(int), hdd);
		fread(&val2, 1, sizeof(int), hdd);

		if (val2 >= table_fileSize)
		{

			int start_pos = 8 + (24 * (disc_space / (file_size + table_fileSize)));
			int k = 8 + (val1 * table_fileSize);
			fseek(hdd, k, SEEK_SET);

			strcpy(file1.s,s);
			file1.starting_pos = start_pos;
			file1.bool1 = 1;

			fseek(hdd, 8 + (val1*table_fileSize), SEEK_SET);

			fwrite(&file1, sizeof(struct node1), 1,hdd);

			int p = 8 + (table_fileSize*(disc_space / (file_size + table_fileSize)) + (val1*file_size));
			fseek(hdd, p, SEEK_SET);

			file = fopen(s, "r+");
			if (file != NULL)
			{


				char c;
				while (fread(&c, 1, sizeof(char), file) > 0)
				{
					fwrite(&c, sizeof(char), 1, hdd);
				}
				
				fclose(file);

				val1++;
				val2 = val2 - table_fileSize - file_size;

				fseek(hdd, 0, SEEK_SET);
				header.count = val1;
				header.rem_size = val2;

				fwrite(&header, sizeof(struct node), 1, hdd);
			}
		}
	}

	fclose(hdd);

}*/