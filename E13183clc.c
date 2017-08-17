#include<stdio.h>
#define EXIT_FAILURE 0
#define is_digit(x) (x<='9' && x>='0')
#define INT_MAX 2147483647
#define INT_MIN -2147483648

double power(int x,int n);
int strlength(char *ch);

long long int argtoint(char* string);
double argtof(char* string);

int checkBinaryFormat(char ** ch);
int checkHexFormat(char ** ch);
int checkIntFormat(char ** ch);
int checkDoubleFloatFormat(char ** ch);

long long int binarytoint(char* arg);
double binaryToFloat(char* arg);
long double binaryToDouble(char* arg);
char* inttobinary(char* arg);
char* hextoBinary(char* arg);
char* floatTobinary(char* arg);

int strlength(char *ch)//To find the length of the argument
{
    int i=0;
    while(ch[i]!='\0')
    {
        i++;
    }
    return i;
}
long long int argtoint(char* string)//To convert the argument to integer
{
    int sign=1;
    long long int output=0;
    int i=0;
    if(string[i]=='-')// if first arg is -,it is a negative number
    {
        sign=-1;
    }
    for(i=0; i<strlength(string); i++)
    {
        if(is_digit(string[i]))
            output=output*10+(string[i]-'0');
    }
    return output*sign;

}
double argtof(char* string)//convert arg to float number
{
    int sign=1;
    int decimal_point = 0;
    //find decimal point
    int i=0;
    if(string[i]=='-')
    {
        sign=-1;
    }
    for(i=0; i<strlength(string); i++)
    {
        if(string[i]!='.')
            decimal_point++;
        else
            break;
    }

    // decimal point found
    double output = 0;
    for(i=0; i < decimal_point; i++)
    {
        if(is_digit(string[i]))
        {

            output = output *10 + (string[i] - '0');
        }

    }
    for(i=decimal_point+1 ; i < strlength(string); i++)
    {
        if(is_digit(string[i]))
        {
            output = output + ((double)(string[i]-'0'))/power(10, i - decimal_point );

        }
    }

    return output*sign;
}


int checkBinaryFormat(char ** ch)//To check binary format
{
    int i,x;
    for(i=0; i<strlength(ch[3]); i++)
    {

        if(ch[3][i]=='1'||ch[3][i]=='0')
        {
            x=-1;
        }
        else
        {
            x=i;
            break;
        }

    }
    return x;//This function returns -1,if the binary is in correct order else the error location
}
int checkHexFormat(char ** ch)//To check Hex format
{
    int i,x;
    for(i=0; i<strlength(ch[3]); i++)
    {

        if(ch[3][i]=='0'||ch[3][i]=='1'||ch[3][i]=='2'||ch[3][i]=='3'||ch[3][i]=='4'||ch[3][i]=='5'||ch[3][i]=='6'||ch[3][i]=='7'||
                ch[3][i]=='8'||ch[3][i]=='9'||ch[3][i]=='a'||ch[3][i]=='b'||ch[3][i]=='c'||ch[3][i]=='d'||ch[3][i]=='e'||ch[3][i]=='f'||
                ch[3][i]=='A'||ch[3][i]=='B'||ch[3][i]=='C'||ch[3][i]=='D'||ch[3][i]=='E'||ch[3][i]=='F')
        {
            x=-1;
        }
        else
        {
            x=i;
            break;
        }

    }
    return x;//This function returns -1,if the arg is in correct order else the error location
}
int checkIntFormat(char ** ch)//To check the integer format
{
    int i,x;
    if(ch[3][0]=='0'||ch[3][0]=='1'||ch[3][0]=='2'||ch[3][0]=='3'||ch[3][0]=='4'||ch[3][0]=='5'||ch[3][0]=='6'||ch[3][0]=='7'||
            ch[3][0]=='8'||ch[3][0]=='9'||ch[3][0]=='-')
    {
        x=-1;//I changed here because argc can be 1.if so it skips the loop.
        for(i=1; i<strlength(ch[3]); i++)
        {

            if(ch[3][i]=='0'||ch[3][i]=='1'||ch[3][i]=='2'||ch[3][i]=='3'||ch[3][i]=='4'||ch[3][i]=='5'||ch[3][i]=='6'||ch[3][i]=='7'||
                    ch[3][i]=='8'||ch[3][i]=='9')
            {
                x=-1;
            }
            else
            {
                x=i;
                break;
            }

        }

    }
    else
    {
        x=0;
    }

    return x;//This function returns -1 if it is in correct format else the error location
}

int checkDoubleFloatFormat(char ** ch)//To check th double format and float format
{
    int i,x,count=0;
    if(ch[3][0]=='0'||ch[3][0]=='1'||ch[3][0]=='2'||ch[3][0]=='3'||ch[3][0]=='4'||ch[3][0]=='5'||ch[3][0]=='6'||ch[3][0]=='7'||
            ch[3][0]=='8'||ch[3][0]=='9'||ch[3][0]=='-')
    {
        for(i=1; i<strlength(ch[3]); i++)
        {

            if(ch[3][i]=='0'||ch[3][i]=='1'||ch[3][i]=='2'||ch[3][i]=='3'||ch[3][i]=='4'||ch[3][i]=='5'||ch[3][i]=='6'||ch[3][i]=='7'||
                    ch[3][i]=='8'||ch[3][i]=='9'||ch[3][i]=='.')
            {
                if(ch[3][i]=='.')
                {
                    count++;
                    if(count>1)
                    {
                        x=i;
                        break;
                    }
                }
                x=-1;
            }
            else
            {
                x=i;
                break;
            }

        }
    }
    else
    {
        x=0;
    }

    return x;//this function returns -1 if it is in correct order else the error location
}
double power(int x,int n)//To find the power of a number
{
    int i;
    double prod=1;
    if(n==0)
    {
        prod=1;
    }
    else if(n>0)
    {
        for(i=1; i<=n; i++)
        {
            prod=prod*x;
        }

    }
    else
    {
        n=-1*n;
        for(i=1; i<=n; i++)
        {
            prod=prod*x;
        }
        prod=1/prod;


    }

    return prod;
}
long long int binarytoint(char* arg)//TO convert binary number to integer
{
    long long int x=0;
    if(arg[0]=='0') //For positive numbers
    {
        int i;
        long long int sum=0;
        for(i=1; i<=31; i++)
        {
            if (arg[i]=='1')
            {
                sum=sum+power(2,(31-i));

            }

        }
        x=sum;
    }
    else  //for negative numbers
    {
        int i;
        long long int sum=0;
        for(i=31; i>=1; i--)//find 1s' complement
        {
            if(arg[i]=='1')
            {
                arg[i]='0';
                break;
            }
            else
            {
                arg[i]='1';
            }

        }//found 1's complement

        for(i=1; i<=31; i++)//find positive binary number by converting 1s' complement to number
        {
            if(arg[i]=='1')
            {
                arg[i]='0';

            }
            else
            {
                arg[i]='1';
            }

        }//found binary number;

        for(i=1; i<=31; i++)
        {
            if (arg[i]=='1')
            {
                sum=sum+power(2,(31-i));

            }

        }
        x=sum*-1;
    }

    return x;//This returns the number corresponding to binary number

}
char* inttobinary(char* arg)//To covert integer to binary
{
    int number = argtoint(arg);
    static char binaryArray[32];
    int pos[32];
    int i;
    if(number>=0)//for positive numbers
    {



        for(i=31; i>=0; i--)
        {
            int rem=number%2;
            pos[i]=rem;
            number=number/2;

        }

    }
    else//for negative numbers
    {
        number=number*-1;

        for(i=31; i>=0; i--)
        {
            int rem=number%2;
            pos[i]=rem;
            number=number/2;

        }


        for(i=0; i<32; i++)
        {
            if(pos[i]==0)
            {
                pos[i]=1;
            }
            else
            {
                pos[i]=0;
            }

        }

        for(i=31; i>=0; i--)//find 1s' complement
        {

            if(pos[i]==0)
            {
                pos[i]=1;;
                break;
            }
            else
            {
                pos[i]=0;
            }

        }

    }
    for(i=0; i<32; i++)
    {
        if(pos[i]==1)
        {
            binaryArray[i]='1' ;

        }
        else
        {
            binaryArray[i]='0' ;
        }


    }

    return  binaryArray;
}
char* hextoBinary(char* arg)//convert hex to binary
{

    int i;
    char pos[4];
    static char position[]= {0};
    int k=0,l=4;
    for(i=0; i<strlength(arg); i++)
    {

        if(arg[i]=='0')
        {
            pos[0]='0';
            pos[1]='0';
            pos[2]='0';
            pos[3]='0';

        }
        else if(arg[i]=='1')
        {

            pos[0]='0';
            pos[1]='0';
            pos[2]='0';
            pos[3]='1';

        }
        else if(arg[i]=='2')
        {

            pos[0]='0';
            pos[1]='0';
            pos[2]='1';
            pos[3]='0';

        }
        else if(arg[i]=='3')
        {
            pos[0]='0';
            pos[1]='0';
            pos[2]='1';
            pos[3]='1';

        }
        else if(arg[i]=='4')
        {

            pos[0]='0';
            pos[1]='1';
            pos[2]='0';
            pos[3]='0';
        }
        else if(arg[i]=='5')
        {

            pos[0]='0';
            pos[1]='1';
            pos[2]='0';
            pos[3]='1';

        }
        else if(arg[i]=='6')
        {

            pos[0]='0';
            pos[1]='1';
            pos[2]='1';
            pos[3]='0';


        }
        else if(arg[i]=='7')
        {

            pos[0]='0';
            pos[1]='1';
            pos[2]='1';
            pos[3]='1';

        }
        else if(arg[i]=='8')
        {

            pos[0]='1';
            pos[1]='0';
            pos[2]='0';
            pos[3]='0';


        }
        else if(arg[i]=='9')
        {

            pos[0]='1';
            pos[1]='0';
            pos[2]='0';
            pos[3]='1';


        }
        else if(arg[i]=='a'||arg[i]=='A')
        {

            pos[0]='1';
            pos[1]='0';
            pos[2]='1';
            pos[3]='0';

        }
        else if(arg[i]=='b'||arg[i]=='B')
        {

            pos[0]='1';
            pos[1]='0';
            pos[2]='0';
            pos[3]='1';

        }
        else if(arg[i]=='c'||arg[i]=='C')
        {

            pos[0]='1';
            pos[1]='1';
            pos[2]='0';
            pos[3]='0';

        }
        else if(arg[i]=='d'||arg[i]=='D')
        {

            pos[0]='1';
            pos[1]='1';
            pos[2]='0';
            pos[3]='1';

        }
        else if(arg[i]=='e'||arg[i]=='E')
        {

            pos[0]='1';
            pos[1]='1';
            pos[2]='1';
            pos[3]='0';

        }
        else if(arg[i]=='f'||arg[i]=='F')
        {

            pos[0]='1';
            pos[1]='1';
            pos[2]='1';
            pos[3]='1';

        }

        int j=0;
        while(k<l)
        {
            position[k]=pos[j];
            ++j;
            k++;

        }
        /* for(k; k<l; k++)
         {
             position[k]=pos[j];
             ++j;
         }*/

        l=l+4;

    }

    position[strlength(arg)*4]='\0';//set the null to last element of array
    return position;
}
double binaryToFloat(char* arg)//To convert binary to float
{
    int sign,i;
    if(arg[0]=='1')//get the sign of the number
    {
        sign=-1;
    }
    else
    {
        sign=1;
    }

    double exponent=0;
    for(i=1; i<=8; i++)
    {
        if (arg[i]=='1')
        {
            exponent=exponent+power(2,(8-i));

        }

    }
    double p=exponent-127;
    double powerVal=power(2,p);//get value of exponent part

    double mantissa=0;
    for(i=9; i<=31; i++)
    {
        if (arg[i]=='1')
        {
            mantissa=mantissa+power(2,(-1*(i-8)));

        }

    }
    double significant=1+mantissa;//get the value of mantissa

    double floatVal=sign*powerVal*significant;

    return floatVal;
}
long double binaryToDouble(char* arg) //if size is not enough change this to long double
{
    //to convert binary to double IEEE format
    int sign,i;
    if(arg[0]=='1')
    {
        sign=-1;
    }
    else
    {
        sign=1;
    }

    double exponent=0;
    for(i=1; i<=11; i++)
    {
        if (arg[i]=='1')
        {
            exponent=exponent+power(2,(11-i));

        }

    }
    double p=exponent-1023;
    double powerVal=power(2,p);

    double mantissa=0;
    for(i=12; i<=63; i++)
    {
        if (arg[i]=='1')
        {
            mantissa=mantissa+power(2,(-1*(i-11)));

        }

    }
    double significant=1+mantissa;

    long double doubleVal=sign*powerVal*significant;

    return doubleVal;
}
char* floatTobinary(char* arg)
{
    static char binArray[32]= {0};
    int count=0;
    int i=0;
    while(1)
    {
        if(arg[i]=='.')
            break;
        else
            count++;
        i++;
    }
    int intToBinary[32];
    int j,count1=0;
    double d=argtof(arg);
    int number=argtof(arg);

    for(i=0; number>=1; i++)
    {
        intToBinary[i]=number%2;
        number=number/2;
        count1++;
    }
    d=argtof(arg);
    number=argtof(arg);

    double p=d-number;

    int t;
    for(t=count1; t<=23; t++)
    {
        double q=(p*2);

        intToBinary[t]=(int)q;
        p=q-(int)q;

    }

    int ftob[32];
    if (arg[0]!='-')
    {
        ftob[0]=0;
    }
    int a=127+count1-1;
    for(i=1; i<9; i++)
    {
        ftob[i]=a%2;

        a=a/2;
    }

    for(j=1; j<=23; j++)
        ftob[8+j]=intToBinary[j];

    for(j=0; j<32; j++)
    {
        if(ftob[j]==0)
        {
            binArray[j]='0';
        }
        else
        {
            binArray[j]='1';
        }

    }
    binArray[32]='\0';

}



int main(int argc,char** argv)
{
    if((argc>0 && argc<4)||argc>4)//check the number of arguments
    {
        fprintf(stderr,"ERROR: The number of arguments is wrong.\nUsage: ./clc -<input format> -<output format> <input>\n");
        return EXIT_FAILURE;

    }
    else if (argv[1][1]== 'B')   // binary to something***************
    {
        if(strlength(argv[3])==32 ||strlength(argv[3])==64)//check the size of the argument
        {
            if(checkBinaryFormat(argv)==-1)//check the format of the argument
            {
                if(argv[2][1] == 'B')  // binary--->binary###########
                {

                    fprintf(stdout,"%s\n",argv[3]);
                }
                else if(argv[2][1]== 'H')// binary--->hexadecimal
                {
                    if(strlength(argv[3])==32)
                    {
                        fprintf(stdout,"ox%08x\n",(int)binarytoint(argv[3]));//for 32 bit
                    }
                    else
                    {
                        fprintf(stdout,"ox%016x\n",(int)binarytoint(argv[3]));//for 64 bit

                    }

                }
                else if(argv[2][1]== 'I')// binary--->integer
                {
                    if(strlength(argv[3])==32)
                    {
                        if(binarytoint(argv[3])>INT_MAX ||binarytoint(argv[3])<INT_MIN)
                        {
                            fprintf(stderr,"ERROR: This conversion is not possible.\n");
                        }
                        else
                        {
                            fprintf(stdout,"%lld\n",binarytoint(argv[3]));

                        }
                    }
                    else
                    {
                        fprintf(stderr,"ERROR: This conversion is not possible.\n");

                    }


                }
                else if(argv[2][1]== 'F')//binary--->single precision float
                {
                    if(strlength(argv[3])==32)//only can convert 32 binary
                    {
                        fprintf(stdout,"%.2f\n",(float)binaryToFloat(argv[3]));
                    }
                    else
                    {
                        fprintf(stderr,"ERROR: This conversion is not possible.\n");
                    }

                }
                else if(argv[2][1]== 'D') // binary--->single precision float
                {
                    if(strlength(argv[3])==64)//only can convert 64 bit binary
                    {
                        fprintf(stdout,"%lf\n",(double)binaryToDouble(argv[3]));
                    }
                    else
                    {
                        fprintf(stderr,"ERROR: This conversion is not possible.\n");
                    }



                }
                else
                {
                    fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");

                }

            }
            else
            {
                fprintf(stderr,"ERROR: Input format error at location %d.\n",checkBinaryFormat(argv));
            }


        }
        else
        {
            fprintf(stderr,"ERROR: The input size is wrong.\n");
        }
    }
    else if (argv[1][1]== 'H')   // hexadecimal to something***************
    {
        if(checkHexFormat(argv)==-1)
        {

            if(strlength(argv[3])==8 ||strlength(argv[3])==16)//check size of the argument
            {
                if(argv[2][1]== 'H') // hex-->hex
                {
                    fprintf(stdout,"%s\n",argv[3]);
                }
                else if(argv[2][1]== 'B')//hex--->binary
                {
                    fprintf(stdout,"%s\n",hextoBinary(argv[3]));

                }
                else if(argv[2][1]== 'I') //hex--->integer
                {

                    if(strlength(argv[3])==8)
                    {
                        if(binarytoint(hextoBinary(argv[3]))>INT_MAX ||binarytoint(hextoBinary(argv[3]))<INT_MIN)
                        {
                            fprintf(stderr,"ERROR: This conversion is not possible.\n");

                        }
                        else
                        {
                            fprintf(stdout,"%lld\n",binarytoint(hextoBinary(argv[3])));
                        }



                    }
                    else
                    {
                        fprintf(stderr,"ERROR: This conversion is not possible.\n");
                    }

                }
                else if(argv[2][1]== 'F') //hex--->single precision float
                {
                    if(strlength(argv[3])==8)
                    {
                        fprintf(stdout,"%.2f\n",(float)binaryToFloat(hextoBinary(argv[3])));
                    }
                    else
                    {
                        fprintf(stderr,"ERROR: This conversion is not possible.\n");
                    }

                }
                else if(argv[2][1]== 'D')  //hex--->double precision float
                {
                    if(strlength(argv[3])==16)
                    {
                        fprintf(stdout,"%lf\n",binaryToDouble(hextoBinary(argv[3])));
                    }
                    else
                    {
                        fprintf(stderr,"ERROR: This conversion is not possible.\n");
                    }

                }
                else
                {
                    fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");
                }

            }
            else
            {
                fprintf(stderr,"ERROR: The input size is wrong.\n");
            }


        }
        else
        {
            fprintf(stderr,"ERROR: Input format error at location %d.\n",checkHexFormat(argv));


        }

    }

    else if (argv[1][1]== 'I') //integer to something***************
    {
        if(checkIntFormat(argv)==-1)//Format is right
        {

            long long int value=argtoint(argv[3]);//check number is in integer range
            if(value>INT_MAX || value< INT_MIN)
            {
                fprintf(stderr,"ERROR: This conversion is not possible.\n");
            }
            else
            {
                if(argv[2][1]== 'B')// int-->binary
                {
                    fprintf(stdout,"%s\n", inttobinary(argv[3]));
                }
                else if(argv[2][1]== 'I')  // int--->int#########
                {

                    fprintf(stdout,"%s\n",argv[3]);
                }
                else if(argv[2][1]== 'F') //done int-->single precision float
                {
                    int val=argtoint(argv[3]);
                    fprintf(stdout,"%.2f\n",(float)val);

                }
                else if(argv[2][1]== 'H')    // int--->hex done
                {
                    int val=argtoint(argv[3]);
                    fprintf(stdout,"0x%08x\n",val);

                }
                else if(argv[2][1]== 'D')    // int--->double precision float
                {
                    fprintf(stderr,"ERROR: This conversion is not possible.\n");
                }
                else
                {
                    fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");

                }
            }

        }
        else
        {
            fprintf(stderr,"ERROR: Input format error at location %d.\n",checkIntFormat(argv));

        }

    }
    else if (argv[1][1]== 'F') //floating point to something***************
    {
        if(checkDoubleFloatFormat(argv)==-1)
        {
            if(argv[2][1]== 'I')   //  float---->int
            {
                long long int value=(long long int)argtof(argv[3]);//check number is in integer range
                if(value>INT_MAX || value< INT_MIN)
                {
                    fprintf(stderr,"ERROR: This conversion is not possible.\n");
                }
                else
                {
                    fprintf(stderr,"WARNING: There is a possibility for a precision loss.\n");
                    fprintf(stdout,"%d\n",(int)value);
                }

            }
            else if(argv[2][1]== 'F')  // done float--->single precision float#########
            {
                fprintf(stdout,"%s\n",argv[3]);
            }
            else if(argv[2][1]== 'H')  //float--->hex
            {
                fprintf(stdout,"ox%08x\n",(int)binarytoint(floatTobinary(argv[3])));


            }
            else if(argv[2][1]== 'B')   // float--->binary
            {
                fprintf(stdout,"%s\n",floatTobinary(argv[3]));
            }
            else if(argv[2][1]== 'D')   // float--->double precision float#######
            {
                fprintf(stderr,"ERROR: This conversion is not possible.\n");
            }
            else
            {
                fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");

            }

        }
        else
        {
            fprintf(stderr,"ERROR: Input format error at location %d.\n",checkDoubleFloatFormat(argv));


        }

    }
    else if (argv[1][1]== 'D') //floating point to something***************
    {
        if(checkDoubleFloatFormat(argv)==-1)
        {
            if(argv[2][1]== 'H')  //double--->hex
            {

            }
            else if(argv[2][1]== 'B')    // double--->binary
            {

            }
            else if(argv[2][1]== 'D')    // double--->double precision float##########
            {
                fprintf(stdout,"%s\n",argv[3]);
            }
            if(argv[2][1]== 'I')   // done float---->int
            {
                fprintf(stderr,"ERROR: This conversion is not possible.\n");
            }
            else if(argv[2][1]=='F')  //  double--->single precision float#########
            {

                fprintf(stderr,"ERROR: This conversion is not possible.\n");
            }
            else
            {
                fprintf(stderr,"ERROR: The output argument is wrong.\nPossible output arguments are -B, -H, -I, -F and -D.\n");

            }

        }
        else
        {
            fprintf(stderr,"ERROR: Input format error at location %d.\n",checkDoubleFloatFormat(argv));
        }


    }
    else
    {
        fprintf(stderr,"ERROR: The input argument is wrong.\nPossible input arguments are -B, -H, -I, -F and -D.\n");
        return EXIT_FAILURE;

    }



    return 0;
}
