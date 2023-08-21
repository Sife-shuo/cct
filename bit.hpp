#include <string>
#include <vector>

using namespace std;

typedef struct {
    char * main;
    string type;
} TYPE;

namespace TYPESIZE{
    int g(string h);
    TYPE _to_char(string h);
    //template<typename T>
    void char_to_X(TYPE d,string totype);
    void turn(string ftype,string totype){
        //cout<<ftype<<endl<<totype<<endl;
        TYPESIZE::char_to_X(TYPESIZE::_to_char(ftype),totype);
        return ;
    }/*
    template<typename S>
    auto turns(S d,string ftype,string totype){
        if(totype=="c"){
            char l='0';
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="uc"){
            unsigned char l='0';
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="sc"){
            signed char='0';
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="i"){
            int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="ui"){
            unsigned int l=1;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="sdi"){
            signed int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="sti"){
            short int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);//to look between <signed int> and <short int>
        }else if(totype=="usi"){
            unsigned short int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="ssi"){
            signed short int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="li"){
            long int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="sli"){
            signed long int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="uli"){
            unsigned long int l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="f"){
            float l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="d"){
            double l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="ld"){
            long double l=0;
            return TYPESIZE::turn(d,ftype,totype,l);
        }else if(totype=="w"){
            wchar_t l='0';
            return TYPESIZE::turn(d,ftype,totype,l);
        }
    }*/
}


int TYPESIZE::g(string h){
    if(h=="c"){return sizeof(char);}
    else if(h=="uc"){return sizeof(unsigned char);}
    else if(h=="sc"){return sizeof(signed char);}
    else if(h=="i"){return sizeof(int);}
    else if(h=="ui"){return sizeof(unsigned int);}
    else if(h=="sdi"){return sizeof(signed int);}
    else if(h=="sti"){return sizeof(short int);}/*to look between <signed int> and <short int>*/
    else if(h=="usi"){return sizeof(unsigned short int);}
    else if(h=="ssi"){return sizeof(signed short int);}
    else if(h=="li"){return sizeof(long int);}
    else if(h=="sli"){return sizeof(signed long int);}
    else if(h=="uli"){return sizeof(unsigned long int);}
    else if(h=="f"){return sizeof(float);}
    else if(h=="d"){return sizeof(double);}
    else if(h=="ld"){return sizeof(long double);}
    //else if(h=="w"){return sizeof(wchar_t);}
    else{
        throw -1;
    }
    return 0;
}
/*
template <typename S>
S _str_to_int(S d,string h){
    int l=h.size(),k=1;
    S sum;
    for(int i=l-1;i>=0;i--){
        sum+=h[i]*k;
        k*=10;
    }
    return sum;
}
*/

//template<typename S>
TYPE TYPESIZE::_to_char(string h){
    char *f;
    if(h=="c"){static char j;cin>>j;f=(char *)(&j);}
    else if(h=="uc"){static unsigned char j;cin>>j;f=(char *)(&j);}
    else if(h=="sc"){static signed char j;cin>>j;f=(char *)(&j);}
    else if(h=="i"){static int j;cin>>j;f=(char *)(&j);}
    else if(h=="ui"){static unsigned int j;cin>>j;f=(char *)(&j);}
    else if(h=="sdi"){static signed int j;cin>>j;f=(char *)(&j);}
    else if(h=="sti"){static short int j;cin>>j;f=(char *)(&j);}/*to look between <signed int> and <short int>*/
    else if(h=="usi"){static unsigned short int j;cin>>j;f=(char *)(&j);}
    else if(h=="ssi"){static signed short int j;cin>>j;f=(char *)(&j);}
    else if(h=="li"){static long int j;cin>>j;f=(char *)(&j);}
    else if(h=="sli"){static signed long int j;cin>>j;f=(char *)(&j);}
    else if(h=="uli"){static unsigned long int j;cin>>j;f=(char *)(&j);}
    else if(h=="f"){static float j;cin>>j;f=(char *)(&j);}
    else if(h=="d"){static double j;cin>>j;f=(char *)(&j);}
    else if(h=="ld"){static long double j;cin>>j;f=(char *)(&j);}
    //else if(h=="w"){static wchar_t j;cin>>j;f=(char *)(&j);}
    TYPE type;
    type.type=h;
    type.main=f;
    return type;
}


template <typename S>
void printv(int i,int a,int b,S w){
    cout<<OUT;
    cout<<"["<<i<<":"<<b*i<<'-'<<b*(i+1)<<"B]:"<<w<<endl;
    return ;
}


void TYPESIZE::char_to_X(TYPE d,string totype){
    int times_b=TYPESIZE::g(totype);
    int times_a=TYPESIZE::g(d.type);
    int times=times_a/times_b;
    //cout<<times<<endl;
    for(int i=0;i<times;i++){
        if(totype=="c"){
            printv(i,times_a,times_b,*((d.main+i*times_b)));
        }else if(totype=="uc"){
            printv(i,times_a,times_b,*((unsigned char*)(d.main+i*times_b)));
        }else if(totype=="sc"){
            printv(i,times_a,times_b,*((signed char*)(d.main+i*times_b)));
        }else if(totype=="i"){
            printv(i,times_a,times_b,*((int*)(d.main+i*times_b)));
        }else if(totype=="ui"){
            printv(i,times_a,times_b,*((unsigned int*)(d.main+i*times_b)));
        }else if(totype=="sdi"){
            printv(i,times_a,times_b,*((signed int*)(d.main+i*times_b)));
        }else if(totype=="sti"){
            printv(i,times_a,times_b,*((short int*)(d.main+i*times_b)));/*to look between <signed int> and <short int>*/
        }else if(totype=="usi"){
            printv(i,times_a,times_b,*((unsigned short int*)(d.main+i*times_b)));
        }else if(totype=="ssi"){
            printv(i,times_a,times_b,*((signed short int*)(d.main+i*times_b)));
        }else if(totype=="li"){
            printv(i,times_a,times_b,*((long int*)(d.main+i*times_b)));
        }else if(totype=="sli"){
            printv(i,times_a,times_b,*((signed long int*)(d.main+i*times_b)));
        }else if(totype=="uli"){
            printv(i,times_a,times_b,*((unsigned long int*)(d.main+i*times_b)));
        }else if(totype=="f"){
            printv(i,times_a,times_b,*((float*)(d.main+i*times_b)));
        }else if(totype=="d"){
            printv(i,times_a,times_b,*((double*)(d.main+i*times_b)));
        }else if(totype=="ld"){
            printv(i,times_a,times_b,*((long double*)(d.main+i*times_b)));
        }/*else if(totype=="w"){
            printv(i,times_a,times_b,*((wchar_t*)(d.main+i*times_b)));
        }*/
    }
    return ;
};
/*
<template class T>
int TYPESIZE::turn(T d,string ftype,string totype){
    int f=TYPESIZE::g(ftype);
    int t=TYPESIZE::g(totype);
    if(f%t==0){
        if(h=="c"){char j=d;}
        else if(h=="uc"){return sizeof(unsigned char);}
        else if(h=="sc"){return sizeof(signed char);}
        else if(h=="i"){return sizeof(int);}
        else if(h=="ui"){return sizeof(unsigned int);}
        else if(h=="sdi"){return sizeof(signed int);}
        else if(h=="sti"){return sizeof(short int);}//to look between <signed int> and <short int>
        else if(h=="usi"){return sizeof(unsigned short int);}
        else if(h=="ssi"){return sizeof(signed short int);}
        else if(h=="li"){return sizeof(long int);}
        else if(h=="sli"){return sizeof(signed long int);}
        else if(h=="uli"){return sizeof(unsigned long int);}
        else if(h=="f"){return sizeof(float);}
        else if(h=="d"){return sizeof(double);}
        else if(h=="ld"){return sizeof(long double);}
        else if(h=="w"){return sizeof(wchar_t);}
        int j=d;
        for(int i=0;i<f/t;i++){
            if(h=="c"){
                char *l;
                l=(char *)(&j+t*i)
            }
            else if(h=="uc"){return sizeof(unsigned char);}
            else if(h=="sc"){return sizeof(signed char);}
            else if(h=="i"){return sizeof(int);}
            else if(h=="ui"){return sizeof(unsigned int);}
            else if(h=="sdi"){return sizeof(signed int);}
            else if(h=="sti"){return sizeof(short int);}//to look between <signed int> and <short int>
            else if(h=="usi"){return sizeof(unsigned short int);}
            else if(h=="ssi"){return sizeof(signed short int);}
            else if(h=="li"){return sizeof(long int);}
            else if(h=="sli"){return sizeof(signed long int);}
            else if(h=="uli"){return sizeof(unsigned long int);}
            else if(h=="f"){return sizeof(float);}
            else if(h=="d"){return sizeof(double);}
            else if(h=="ld"){return sizeof(long double);}
            else if(h=="w"){return sizeof(wchar_t);}
        }
    }else{
        throw("Byte count is not a multiple relationship");
    }
}*/