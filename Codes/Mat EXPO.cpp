struct mat{

ll ma[5][5];
int row,col;


};


mat multi(mat a,mat b)
{
    mat r;
    r.row=a.row;
    r.col=b.col;
    for(int i=0;i<r.row;i++)
    {
        for(int j=0;j<r.col;j++)
        {
            ll sum=0;
            for(int k=0;k<a.col;k++)
            {
                sum+=a.ma[i][k]*b.ma[k][j];
                sum%=mood;
            }
            r.ma[i][j]=sum;
            
        }
    }
    
    return r;
}

mat mpow(mat a,ll p)
{
    if(p==1)
        return a;
    if(p%2==1)
        return multi(a,mpow(a,p-1));
    mat temp=mpow(a,p/2);
    mat tt=multi(temp,temp);
    return tt;
}
