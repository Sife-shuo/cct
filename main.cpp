#include <iostream>
#include <string>
#include <vector>
#include "command.hpp"

using namespace std;
int main(){
    /*
    NUM b;
    b.fflag=true;
    string h("17");
    b.main=h;
    b.dema=8;
    NUM a=DECIMAL::turn(b,3);
    cout<<a.main<<endl;*/
    /*string j("i");
    string w("sti");
    int t=647483646;
    TYPESIZE::turn(t,j,w);*/
    //cout<<h[0]<<endl<<h[1];
    while(true){
        cout<<IN;
        //string h;
        //getline(cin,h);
        try{
            usage();
        }catch(int err){
            if(err==0){
                return 0;
            }
        }
    }
    return 0;
}