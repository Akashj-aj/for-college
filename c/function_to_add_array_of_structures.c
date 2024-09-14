int add_poly(struct poly p1[10], Struct poly p2[10], Struct poly p3[10], int t1, int t2)
{
    int i=0, j=0, k=0;
    while (i<t1 && j<t2)
    {
        if(p1[i].exp == p2[i].exp)
        {
            p3[k].cf = p1[i].cf + p2[i].cf
            p3[k].exp = p1[i].exp;
            i++; j++; k++;
        }
        else if(p1[i].exp > p2[i].exp)
        {
            p3[k].cf = p1[i].cf;
            p3[k].exp = p1[i].exp;
            i++; k++;
        }
        else
        {
            p3[k].cf = p2[j].cf;
            p3[k].exp = p2[j].exp;
            j++; k++;
        }
    }
}