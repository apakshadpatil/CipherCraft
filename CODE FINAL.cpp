#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class file_class {
protected:
    int count;
    FILE* file;
    char ch;

public:
    int count_ch() {
        file = fopen("sample.txt", "r");
        while ((ch = fgetc(file)) != EOF) {
            count++;
        }
        fclose(file);
        return count;
    }
};

class encryption : public file_class {
public:

void assign(){
    FILE *file;
    file=fopen("sample.txt","r");
    int count=0;
    char ch;
    while((ch=fgetc(file))!=EOF)
	{
        count++;
    }
    cout<<count<<endl;
    fclose(file);
    int m=(count+15)/16;
    cout<<m<<endl;
    //------------------------------------------------------------------------------------
    char a[m][4][4],b[m][4][4];
    file=fopen("sample.txt", "r");
    int i,j,k,l;
	ofstream MyEnfile("encrypt.txt");
	for(k=0;k<m;k++)
	{
        for(i=0;i<4;i++)
		{
            for(j=0;j<4;j++)
			{
                int ch=fgetc(file);
                if(ch==EOF)
				{
                    a[k][i][j]=NULL;
                }
				 else 
				{
                    a[k][i][j]=static_cast<char>(ch);//i have done here type castin coz ch is int type so it is  taking hex of int ha ha ha 
                }     
            }
        }
        
	    for(i=0;i<=3;i++)
    	{
	    	for(j=0;j<=3;j++)
	    	{
	    		b[k][i][j]=a[k][j][i];
	    	}
	    }
	    for(i=0;i<=3;i++)
	    {
		    for(j=0;j<=3;j++)
		    {
			    a[k][i][j]=b[k][i][j];
		    }
	    }
	    for(i=0;i<=3;i++)
	    {
    		for(j=0;j<=3;j++)
    		{
    			if(j==0)
    			{
    				b[k][i][j]=a[k][i][j+2];
    			}			
    			if(j==2)
    			{
    				b[k][i][j]=a[k][i][j-2];
    			}
    		}
    	}
    	for(i=0;i<=3;i++)
    	{
    		for(j=0;j<=3;j++)
    		{			
			    a[k][i][j]=b[k][i][j];
		    }
	    }
	    for(i=0;i<=3;i++)
	    {
	    	for(j=0;j<=3;j++)
	    	{
	    		if(i==1)
	    		{
	    			a[k][i][j]=b[k][i+1][j];		
	    		}
	    		if(i==2)
	    		{
	    			a[k][i][j]=b[k][i-1][j];
	    		}
	    	}
	    }
	    for(i=0;i<=3;i++)
	    {
	    	for(j=0;j<=3;j++)
	    	{
			
	    		b[k][i][j]=a[k][i][j];
	    	}
	    }
	    for(int z=0,j=4;z<=3;z++)
	    {
	    	j--;
	    	for(l=0,i=4;l<=3;l++)
	    	{
	    		i--;
	    		b[k][z][l]=a[k][i][j];
	    	}
	    }
        for(i=0;i<=3;i++)
        {
            for(j=0;j<=3;j++)
            {
               a[k][i][j] = b[k][i][j];
            }
        }
		

        for(i=0;i<4;i++)
        {
        	for(j=0;j<4;j++)
        	{
        		MyEnfile<<hex<<setw(2)<<setfill('0')<<static_cast<int>(a[k][i][j]);
			}
		}
		
	}
	MyEnfile.close();
}
};

class decryption : public file_class {
	public:
void decrypt()
{
    FILE *file;
    file=fopen("encrypt.txt","r");
    int count=0;
    char ch;
    while((ch=fgetc(file))!=EOF)
    {
        count++;
    }
    fclose(file);
    int m=(count/16)/2;
    string a[m][4][4],b[m][4][4];
    file=fopen("encrypt.txt","r");
    int i,j,k,l;
	ofstream MyDCfile("decrypt.txt");
    string var[2];
    string ch2;
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                for(int l=0;l<2;l++)
                {
                    ch2=fgetc(file);
                    var[l]=ch2;
                }
                string item;
                item=var[0] + var[1];
                a[k][i][j]=item;
            }
        }
    for	(int p=0,j=4;p<=3;p++)
	{
		j--;
		for(l=0,i=4;l<=3;l++)
		{
			i--;
			b[k][p][l]=a[k][i][j];
		}
	}
	//6
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			a[k][i][j]=b[k][i][j];

		}

	}
	//5
	for	(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(i==1)
			{
				a[k][i][j]=b[k][i+1][j];		
			}
			if(i==2)
			{
				a[k][i][j]=b[k][i-1][j];
			}	
			

		}

	}
	//4
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			b[k][i][j]=a[k][i][j];

		}

	}
	//3
    for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			if(j==0)
			{
				b[k][i][j]=a[k][i][j+2];
			}
			
			if(j==2)
			{
				b[k][i][j]=a[k][i][j-2];
			}
	
		}

	}
	//2
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			a[k][i][j]=b[k][i][j];

		}

	}
	//1
	for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			b[k][i][j]=a[k][j][i];

		}

	}
	//0
    for(i=0;i<=3;i++)
	{
		for(j=0;j<=3;j++)
		{
			
			a[k][i][j]=b[k][i][j];
		}
	}

    }
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                stringstream ss;
                ss<<hex<<a[k][i][j];
                unsigned int hexv;
                ss>>hexv;
				if(hexv!=NULL)
                MyDCfile<<static_cast<char>(hexv);
            }
        }
    }
    MyDCfile.close();
}
};

int main()
 {
    int op;
    cout << "Welcome to ciphercraft\n";
    cout << "Select the Operation to perform on file\n1. Encryption\n2. Decryption\n";
    cin >> op;
    switch (op) {
        case 1:
            encryption obj1;
            obj1.assign();
            break;
        case 2:
            decryption obj2;
            obj2.decrypt();
            
break;
}
}
