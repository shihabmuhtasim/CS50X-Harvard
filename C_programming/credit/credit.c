#include <stdio.h>
#include <cs50.h>

int main (void){
    int long card=get_long("Number: ");
    //printf("Number %li",card);
    //len of number

    int len=0;
    int long temp=card;
    while(temp>0){
        temp/=10;
        len++;
    }
    //printf("LEN %i",len);

    //get the 100 value
    int long mod=1;
    for (int i=0;i<len-1;i++){
        mod*=10;
        // printf("MOD %li\n",mod);
    }
    int long mod_copy=mod;

    //start adding
    int long copy=card;
    int sum=0;

    int  temp2;
    for (int i=0; i<len; i++){
        if (i%2==0){
            temp2=copy/mod;
            temp2*=2;
            int size=sizeof(temp2);
            if(size==1){
                sum+=temp2;

            }
            else{
                int y=temp2/10;
                sum+=y;

                y=temp2%10;
                sum+=y;



            }

            copy=copy%mod;
            mod=mod/10;
        }
        else{
            temp2=copy/mod;
            sum+=temp2;
            copy=copy%mod;
            mod=mod/10;
        }

    }
    int last_dig= sum%10;
    // printf("CHECKSUM %i\n",sum);
    if (last_dig==0){
        int v_digit= card/mod_copy;
        mod_copy=mod_copy/10;
        int f_digits=card/mod_copy;
        if (len==15 && (f_digits==34 ||f_digits==37)){
            printf("AMEX\n");
        }
        else if (len==15 && (f_digits>50 && f_digits<56 )){
            printf("MASTERCARD\n");
        }
        else if (len>12 && len<17 && (v_digit==4 )){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }

    }
    else{
        printf("INVALID\n");
    }




}
