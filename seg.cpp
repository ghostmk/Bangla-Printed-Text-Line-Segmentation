#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string>
using namespace std;


string coun(int ctr)
{
    ostringstream str1;
    string geek = str1.str();
    cout<<geek<<endl;
    return geek;

}
void comment(FILE *fp)
{
    int ch;
    char line[100];

    while ((ch = fgetc(fp)) != EOF && isspace(ch));
    if (ch == '#') {
        fgets(line, sizeof(line), fp);
        printf("%s",line);
        comment(fp);
    } else
        fseek(fp, -1, SEEK_CUR);
}
void drawrec(int **y,int **z,int row,int col,int ct)
{

    int s,a,b,c,d,i,j;
    for(s=2;s<ct;s++)
    {
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                if(y[i][j]==s)
                    goto aa;
        aa:
            a=i;

        for(i=row-1;i>=0;i--)
            for(j=0;j<col;j++)
                if(y[i][j]==s)
                    goto bb;
        bb:
        b=i;

        for(i=0;i<col;i++)
            for(j=0;j<row;j++)
                if(y[j][i]==s)
                    goto cc;
        cc:
        c=i;

        for(i=col-1;i>=0;i--)
            for(j=0;j<row;j++)
                if(y[j][i]==s)
                    goto dd;

        dd:
            d=i;

    for(i=c;i<=d;i++)
        z[a][i]=1;
    for(i=c;i<=d;i++)
        z[b][i]=1;
    for(i=a;i<=b;i++)
        z[i][c]=1;
    for(i=a;i<=b;i++)
        z[i][d]=1;


    }




}


void segrec(int **a,int row,int col,int i,int j,int x);
int segment(int **a,int row, int col)
{

    int i,j,ctr=2;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            if(a[i][j]==1)
              {
                  segrec(a,row,col,i,j,ctr++);
              }


return ctr;
}

void segrec(int **a,int row,int col,int i,int j,int x)
{

        a[i][j]=x;
        int k,l,m,n;
        if(i==0)
            m=0;
        else m=i-1;

        if(j==0)
            n=0;
        else
            n=j-1;
        for(k=m;k<row&&k<=i+1;k++)
            for(l=n;l<col&&l<=j+1;l++)
              if(a[k][l]==1)
                segrec(a,row,col,k,l,x);



}
void horz(int **a,int row, int col)
{
string t;
string b=".pbm";
     int ctr,coln=0;
     int *x=new int[row];

     for(int i=0;i<row;i++)
     {
         ctr=0;
          for(int j=0;j<col;j++)
          {
              if(a[i][j]==1)
                ctr++;
          }

          x[i]=ctr;
          if(ctr>coln)
            coln=ctr;

     }
        cout<<coln;

     int **z=(int **)malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++)
        z[i]=(int *)malloc(sizeof(int)*coln);

     int *img_in=(int *)malloc(sizeof(int)*row*coln);



     for(int i=0;i<row;i++)
     {

         for(int j=0;j<coln;j++)
         {
             if(j<x[i])
                z[i][j]=1;
             else
                z[i][j]=0;

         }
     }




    int is_ascii=1,temp,v;FILE *f;
    f=fopen("horz.pbm","wb");
    fprintf(f,"%c%c\n%d %d\n",'P','1',coln,row);

   int ctrs=0;
        for(int i=0;i<row;i++)
            for(int j=0;j<coln;j++)
                img_in[ctrs++]=z[i][j];




    for (int i = 0; i < row; i++) {
        for (int j = 0; j < coln; j++) {
            if (is_ascii == 1) {
                fprintf(f, "%d ", img_in[i*coln+j]);
            }
            else {
                temp = 0;
                for (int k = 0; k < 8; k++) {
                    v = img_in[i*coln+j+k];
                    temp |= (v << (7-k));
            }
                fprintf(f, "%c", temp);
            }

            if (((i*coln+j) % (coln+1)) == (coln)) {
                fprintf(f, "\n");
      }
    }
  }


  int p=0,c=0,start=0,en=0,ctrss=0;

  for(int i=1;i<row;i++)
   {

        p=c;
        c=x[i];

        if(p==0&&c!=0)
        {

            start=i;
            for(int k=i+1;k<row;k++)
            {

                p=c;
                c=x[k];

                if(p!=0&&c==0)
                    {en=k;i=k;goto zz;}
            }



        /////////////////////////////////////////////////////////////


    zz:

    ostringstream str1;
    str1 << ctrss++;
    string t = str1.str();
t=t+b;



        char *m=new char[t.size()];
        for(int h=0;h<t.size();h++)
            m[h]=t[h];


              //cout<<"  "<<m<<endl<<en-start+1<<endl;


         int is_ascii=1,temp,v;FILE *f;
    f=fopen(m,"wb");
    fprintf(f,"%c%c\n%d %d\n",'P','1',col,en-start+1);

    int *img_i=(int *)malloc(sizeof(int)*(en-start+1)*col);

   int ctrs=0;
        for(int i=start;i<=en;i++)
            for(int j=0;j<col;j++)
                img_i[ctrs++]=a[i][j];



    for (int i = 0; i <=en-start+1; i++) {
        for (int j = 0; j < col; j++) {
            if (is_ascii == 1) {
                fprintf(f, "%d ", img_i[i*col+j]);
            }
            else {
                temp = 0;
                for (int k = 0; k < 8; k++) {
                    v = img_i[i*col+j+k];
                    temp |= (v << (7-k));
            }
                fprintf(f, "%c", temp);
            }

            if (((i*col+j) % (col+1)) == (col)) {
                fprintf(f, "\n");
      }
    }
  }

        }
   }


}
int main()
{
    char ver[2];
    int row,col,x;
    int _max,i,j,is_ascii;


    //read the pgm file
    FILE *f;
    printf("\nEnter the file name with extension:");
    char name[20];
    scanf("%s",name);
    f=fopen(name,"rb");
    fscanf(f,"%s",ver);
    ver[2]='\0';
    printf("%s",ver);
    comment(f);
    fscanf(f,"%d",&col);
    comment(f);
    fscanf(f,"%d",&row);
    comment(f);

    if (strcmp(ver, "P1") == 0) {
        is_ascii = 1;
    }
    else if (strcmp(ver, "P4") == 0) {
        is_ascii = 0;
    }
    else {
        fprintf(stderr, "Error: Input file not in PBM format!\n");
        exit(1);
    }


  cout<<row<<" "<<col<<" ";

int *img_in=(int *)malloc(sizeof(int)*row*col);

  int c;
  int lum_val;
  int k;i=0;

  /* Read the rest of the PBM file. */
  while ((c = fgetc(f)) != EOF) {
    ungetc(c, f);
    if (is_ascii == 1) {
      fscanf(f, "%d ", &lum_val);
      img_in[i++] = lum_val;
    } else {
      lum_val = fgetc(f);
      /* Decode the image contents byte-by-byte. */
      for (k = 0; k < 8; k++) {
        img_in[i++] = (lum_val >> (7-k)) & 0x1;
      }
    }
  }
  int ctrs=i,ctrx=0;
  int **a=(int **)malloc(sizeof(int*)*row);
    for(i=0;i<row;i++)
        a[i]=(int *)malloc(sizeof(int)*col);

  int **z=(int **)malloc(sizeof(int*)*row);
    for(i=0;i<row;i++)
        z[i]=(int *)malloc(sizeof(int)*col);






is_ascii=1;
  f=fopen("testing1.pbm","wb");
fprintf(f,"%c%c\n%d %d\n",'P','1',col,row);

int v,temp;


   for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
	    if (is_ascii == 1) {
        fprintf(f, "%d ", img_in[i*col+j]);
	    } else {
	      temp = 0;
		    for (k = 0; k < 8; k++) {
          v = img_in[i*col+j+k];
          temp |= (v << (7-k));
		    }
        fprintf(f, "%c", temp);
	    }

      if (((i*col+j) % (col+1)) == (col)) {
        fprintf(f, "\n");
      }
    }
  }



  f=fopen(name,"rb");
    fscanf(f,"%s",ver);
    ver[2]='\0';
    printf("%s",ver);
    comment(f);
    fscanf(f,"%d",&col);
    comment(f);
    fscanf(f,"%d",&row);
    comment(f);

    if (strcmp(ver, "P1") == 0) {
        is_ascii = 1;
    }
    else if (strcmp(ver, "P4") == 0) {
        is_ascii = 0;
    }
    else {
        fprintf(stderr, "Error: Input file not in PBM format!\n");
        exit(1);
    }


  cout<<row<<" "<<col<<" ";



  i=0;

  /* Read the rest of the PBM file. */
  while ((c = fgetc(f)) != EOF) {
    ungetc(c, f);
    if (is_ascii == 1) {
      fscanf(f, "%d", &lum_val);
      img_in[i++] = lum_val;
    } else {
      lum_val = fgetc(f);
      /* Decode the image contents byte-by-byte. */
      for (k = 0; k < 8; k++) {
        img_in[i++] = (lum_val >> (7-k)) & 0x1;
      }
    }
  }




int  ctrmax=i;
  ctrs=0;
  for(i=0;i<row;i++)
    for(j=0;j<col;j++)
        z[i][j]=a[i][j]=img_in[ctrs++];



 horz(a,row,col);

 /* for(i=0;i<row;i++)
{
  for(j=0;j<col;j++)
        if(a[i][j]!=0)
            cout<<a[i][j];
            else
            cout<<" ";
cout<<endl;
}*/
ctrs=0;
for(i=0;i<row;i++)
    for(j=0;j<col;j++)
        img_in[ctrs++]=z[i][j];

        is_ascii=1;
  f=fopen("output.pbm","wb");
fprintf(f,"%c%c\n%d %d\n",'P','1',col,row);




   for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
	    if (is_ascii == 1) {
        fprintf(f, "%d ", img_in[i*col+j]);
	    } else {
	      temp = 0;
		    for (k = 0; k < 8; k++) {
          v = img_in[i*col+j+k];
          temp |= (v << (7-k));
		    }
        fprintf(f, "%c", temp);
	    }

      if (((i*col+j) % (col+1)) == (col)) {
        fprintf(f, "\n");
      }
    }
  }






cout<<"\nDone!\n Check output.pbm\n";
return 0;


}
