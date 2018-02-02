for(int i=0;i<=50;i++)
{
        ncr[i][0]=1;
}
for(int i=1;i<=52;i++)
{
	for(int j=1;j<=i;j++)
    {
        ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
    }
}
