#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <limits.h>

void printmin(char str[], FILE* fo)
{
	clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    //Read from file and store in arrays
	int i=0,j=0;
	float xres1,xres2,yres1,yres2,x[10005],y[10005];
	FILE* f=fopen(str,"r");
	while (fscanf(f,"%f%f",&x[i],&y[j])!=EOF)
	{
		i++;j++;
	}

	//O(n^2) algo begins
	int len=i;
	float tmp, mindis = ((x[0]-x[1])*(x[0]-x[1])) + ((y[0]-y[1])*(y[0]-y[1]));
	for (i=0;i<len;i++)
	{
		for (j=i+1;j<len;j++)
		{
			tmp= ((x[i]-x[j])*(x[i]-x[j])) + ((y[i]-y[j])*(y[i]-y[j]));
			if (tmp < mindis)
			{
				mindis=tmp;
				xres1=x[i];
				xres2=x[j];
				yres1=y[i];
				yres2=y[j];
			}
		}
	}
	printf("Closes points in file %s are (%f,%f) and (%f,%f)\n",str,xres1,yres1,xres2,yres2);
	//O(n^2) algo ends

	end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    for (i=7;i<strlen(str);i++)
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
}

int main()
{
	FILE* fo=fopen("out.dat","w");
	printmin("data2d_10.txt",fo);
	printmin("data2d_50.txt",fo);
	printmin("data2d_100.txt",fo);
	printmin("data2d_500.txt",fo);
	printmin("data2d_1000.txt",fo);
	printmin("data2d_2000.txt",fo);
	printmin("data2d_5000.txt",fo);
	printmin("data2d_10k.txt",fo);
	//GNUplot part begins
	char* commandsForGnuplot[] = {"set title \"Input Size v/s Running Time\"","set xlabel \"Input Size\"", "set ylabel \"Running Time\"", "plot 'out.dat' smooth bezier"};
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    int i;
    for (i=0;i<4;i++)
    	fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]);
	//GNUplot part ends
	return 0;
}