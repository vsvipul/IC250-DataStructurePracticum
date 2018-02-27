#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

int retmax(char str[], FILE* fo)
{
	clock_t start, end;
    double cpu_time_used;
    start = clock();
	int i,max,tmp;
	FILE* f=fopen(str,"r");
	
	// O(n) algo begins
	if (f==NULL)
		return -1;
	fscanf(f,"%d",&max);
	while (fscanf(f,"%d",&tmp)!=EOF)
	{
		if (tmp>max)
			max=tmp;
	}
	printf("Max number in file %s is %d\n",str,max);
	// O(n) algo ends
	
	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    for (i=5;i<strlen(str);i++)
    {
    	if (str[i]=='.')
    		break;
    	if (str[i]=='k')
    	{
    		fprintf(fo,"000");
    		break;
    	}
    	fprintf(fo,"%c",str[i]);
    }
    fprintf(fo," %lf\n", cpu_time_used);
    fclose(f);
    return max;
}

int main()
{
	FILE* fo=fopen("out.dat","w");
	retmax("data_100.txt",fo);
	retmax("data_500.txt",fo);
	retmax("data_1000.txt",fo);
	retmax("data_2000.txt",fo);
	retmax("data_3000.txt",fo);
	retmax("data_4000.txt",fo);
	retmax("data_5000.txt",fo);
	retmax("data_6000.txt",fo);
	retmax("data_7000.txt",fo);
	retmax("data_8000.txt",fo);
	retmax("data_9000.txt",fo);
	retmax("data_10k.txt",fo);
	retmax("data_20k.txt",fo);
	retmax("data_30k.txt",fo);
	retmax("data_50k.txt",fo);
	retmax("data_1000k.txt",fo);
	retmax("data_5000k.txt",fo);
	//GNUplot part begins
	char* commandsForGnuplot[] = {"set title \"Input Size v/s Running Time\"","set xlabel \"Input Size\"", "set ylabel \"Running Time\"", "plot 'out.dat' smooth bezier"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    int i;
    for (i=0;i<4;i++)
    	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
	//GNUplot part ends
	return 0;
}