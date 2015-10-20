#include <stdio.h>
#include <assert.h>

int main(int argc, char **argv)
{
	int i=20;

	printf("val : %d\n",i);
//	i++;
	printf("sz : %ld\n",sizeof(i++));
	printf("val : %d\n",i);
	
	return 0;
}
