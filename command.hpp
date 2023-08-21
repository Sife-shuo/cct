#include <string>
#include <vector>
#include "dem.hpp"
#include "bit.hpp"

using namespace std;
string HELP("");
//int str_to_int(string u);

vector<string> _cmd_parse(string u){
    vector<string> res;
    string tool;
    int l=u.size();
    for(int i=0;i<l;i++){
        if(u[i]==' '){
            res.push_back(tool);
            tool="";
        }else{
            tool=tool+u[i];
        }
    }
    if(tool.size()){
        res.push_back(tool);
    }
    return res;
}

void usage(){
    string u;
    cin>>u;
    if(u=="h"||u=="help"){
        cout<<HELP<<endl;
    }else{
        //vector<string> res=_cmd_parse(u);
        if(u=="d"){//DECIMAL
            string value;
            unsigned int fro,to2;
            cin>>fro>>to2>>value;
            NUM from=DECIMAL::NORMAL(value,fro);
            NUM to=DECIMAL::turn(from,to2);
            if(!to.fflag){
                printf("-");
            }
            cout<<OUT;
            cout<<(to.main)<<endl;
        }else if(u=="p"){//pseudocode
            string ftype,ttype;
            cin>>ftype>>ttype;
            try{
                TYPESIZE::turn(ftype,ttype);
            }catch(int err){
                if(err==-1){
                    cout<<OUT<<"Wrong TypeName\n";
                }
            }
        }else if(u=="exit"){//exit
            cout<<"[ Exit ]";
            throw 0;
        }
    }
}

/*
int str_to_int(string u){
    int sum=0,j=1,l=u.size();
    for(int i=l-1;i>=0;i--){
        sum+=DE_CONFIG.find(u[i])*j;
        j*=10;
    }
    return sum;
}
*/