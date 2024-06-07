#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct fileData
{
	char file_name[20];
	int startBlock;
	int endBlock;
	int length;
};

struct metadata
{
	int magicNo[4];
	int freeBlocks;
	int noOfBlocks;
	struct fileData fileData[32];
	int arr[6400] = { 0 };
};

void writeToBlock(void *buff,int blockNum)
{
	FILE *hdd = fopen("hardDisc1.hdd", "rb+");
	int startPos = blockNum * 16384;
	fseek(hdd, startPos, SEEK_SET);

	memcpy(hdd, &buff, 16384 * sizeof(void*));
	rewind(hdd);

	struct metadata metadata;
	memcpy(&buff, hdd, 16834);
	memcpy(&metadata, buff, sizeof(struct metadata));
	metadata.freeBlocks = metadata.freeBlocks - 1;
	metadata.arr[blockNum] = 1;
	rewind(hdd);
	memcpy(buff, &metadata, sizeof(struct metadata));
	memcpy(hdd, buff, 16834*sizeof(void*));

	/*void *buff2 = (void*)malloc(16384 * sizeof(void*));
	void *buff1 = (void*)malloc(16384 * sizeof(void*));
	FILE *fptr=fopen(s,"rb+");
	memcpy(&buff1, fptr, 16384*sizeof(void*));

	FILE *hdd = fopen("hardDisc1.hdd", "rb+");
	int startPos = blockNum * 16384;
	fseek(hdd, startPos, SEEK_SET);
	
	memcpy(hdd, &buff1, 16384 * sizeof(void*));

	rewind(hdd);
	struct metadata metadata;
	memcpy(&buff2, hdd, 16834);
	memcpy(&metadata, buff2, sizeof(struct metadata));
	metadata.freeBlocks = metadata.freeBlocks - 1;
	metadata.arr[blockNum] = 1;
	rewind(hdd);
	memcpy(hdd, &metadata, sizeof(struct metadata));

	fclose(hdd);*/

}

void readFromBlock(char*s, int blockNum)
{
	void *buff1 = (void*)malloc(16384 * sizeof(void*));
	void *buff2 = (void*)malloc(16384 * sizeof(void*));


	int startPos = blockNum * 16384;
	FILE *hdd = fopen("hardDisc1.hdd", "rb+");
	fseek(hdd, startPos, SEEK_SET);
	memcpy(&buff1, hdd, 16384 * sizeof(void*));
	rewind(hdd);

	FILE *fptr = fopen(s, "rb+");
	memcpy(fptr, buff1, 16384 * sizeof(void*));
	fclose(fptr);

	struct metadata metadata;
	memcpy(&buff1, hdd, 16384 * sizeof(void*));
	rewind(hdd);
	memcpy(&metadata, buff1, sizeof(struct metadata));
	metadata.freeBlocks = metadata.freeBlocks - 1;
	metadata.arr[blockNum] = 1;

	memcpy(hdd, &metadata, sizeof(struct metadata));
	fclose(hdd);

}

void copyToHarddisc(char*s)
{
	FILE *source = fopen(s, "rb+");
	fseek(source, 0, SEEK_END);
	int size = ftell(source);
	rewind(source);
	int req_blocks = ceil(double(size / 16834));

	FILE *hdd = fopen("hardDisc1.hdd", "rb+");

	void *buff1 = (void*)malloc(16384 * sizeof(void*));
	memcpy(buff1, hdd, 16843 * sizeof(void*));
	rewind(hdd);
	struct metadata metadata;
	memcpy(&metadata, buff1, sizeof(struct metadata));

	if (metadata.noOfBlocks >= req_blocks)
	{
		int count = 0,flag=0;
		int i = 1;
		while (1)
		{
			if (i == 6439)
				break;

			if (metadata.arr[i] == 0)
			{
				count++;
				if (count == req_blocks)
				{
					flag = 1;
					break;
				}
			}
			else
			{
				count = 0;
			}

			i++;

		}
		if (flag == 1)
		{

		}
	}

}

void console()
{
	char command[15];
	scanf("%s", command);
	int k = 1;
	while (1)
	{

	}
}