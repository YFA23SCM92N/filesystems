#include <stdlib.h>
#include "functions.h"
#include <string.h>

void console()
{
	char command[15];
	scanf("%s", command);
	int k = 1;
	while (1)
	{
		char source[20],destination[20];


			if (strcmp(command, "copy") == 0)
			{
				scanf("%s", source);
				copy_file(source);
			}
			else if (strcmp(command, "LIST") == 0)
			{
				displayList();
			}

			else if (strcmp(command, "copyfrom") == 0)
			{
				char destination[20];
				scanf("%s %s", source,destination);
				copyFromHarddisc(source, destination);
			}
		console();
	}
}

int main()
{

	//FILE* hdd=fopen(disc_name,"wb+");
	//createHardDisc(hdd);

	console();
	return 0;
}