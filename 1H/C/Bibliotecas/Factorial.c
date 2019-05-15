int factorial(x)
{
    int num=x;
    int acum=1;
    int i;

    for(i = num; i>0; i--)
    {
        acum = acum*i;
    }


    return(acum);
}
