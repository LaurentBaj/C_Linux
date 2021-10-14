#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Student
{
	int rno;
	char name[20];
	int age; 
};

int main()
{

	FILE *file1, *file2;
	file1= fopen("sample.bin", "wb");

	struct Student s1 = {61, "Michael", 19};
	struct Student s2 = {62, "John", 20};
	struct Student s3;
	
	// Write two students into file
	fwrite(&s1, sizeof(struct Student), 1, file1);
	fwrite(&s2, sizeof(struct Student), 1, file1);	
	
	fclose(file1); // Close file editing
	file2=fopen("sample.bin", "rb"); // Read bin
	
	
	// Read contents of sample.bin from file2 (stream)
	// Read everything from &s3 as 1 structure of text 
	while(fread(&s3, sizeof(struct Student), 1, file2)) // Loops twice
	{
		printf("Roll number = %d  Name = %s Age = %d\n",
        s3.rno, s3.name, s3.age);
	}
	
	fclose(file2);
}
