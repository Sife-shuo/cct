#include <string>

typedef struct NUM_DEV {
    bool fflag;//<0 is false
    std::string main;
    unsigned int dema;
} NUM;
char OUT[]={"[ Out ] >> "};
char IN[]={"[ In ]  << "};

using namespace std;

string DE_CONFIG = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
namespace DECIMAL{
    NUM NORMAL(int d,unsigned int dema);
    NUM NORMAL(string d,unsigned int dema);
    NUM X_to_10(NUM d);
    NUM _10_to_X(NUM d,unsigned int dema);
    NUM turn(NUM d,unsigned int dema){
        //cout<<"DMAIN:"<<d.main<<endl;
        return DECIMAL::_10_to_X(DECIMAL::X_to_10(d),dema);
    }
};

NUM DECIMAL::NORMAL(int d,unsigned int dema){
    NUM normal;
    if(d==0){
        string h="0";
        normal.main=h;
    }else{
        string h;
        int r=d;
        char w;
        while(r){
            w=r%10+'0';
            h=w+h;
            r=(r-r%10)/10;
        }
        normal.main=h;
    }
    if(d<0){
        normal.fflag=false;
    }else{
        normal.fflag=true;
    }
    normal.dema=dema;
    return normal;
}

NUM DECIMAL::NORMAL(string h,unsigned int dema){
    //cout<<"h:"<<h<<endl;
    NUM normal;
    string d=h;
    if(d[0]=='-'){
        normal.fflag=false;
        d.erase(0,1);
    }else{
        normal.fflag=true;
    }
    normal.main=d;
    //cout<<"MAIN:"<<d<<endl;
    normal.dema=dema;
    return normal;
}

NUM DECIMAL::X_to_10(NUM d){
    if(d.dema==10){return d;};
    int sum=0,j=1,l=d.main.size();
    for(int i=l-1;i>=0;i--){
        sum+=DE_CONFIG.find(d.main[i])*j;
        j*=d.dema;
    }
    if(!d.fflag){
        sum=-sum;
    }
    return DECIMAL::NORMAL(sum,10);
}

NUM DECIMAL::_10_to_X(NUM d,unsigned int dema){
    //cout<<"10 2 X d.main:"<<d.main<<endl;
    int sum=0,j=1,l=d.main.size();
    for(int i=l-1;i>=0;i--){
        sum+=DE_CONFIG.find(d.main[i])*j;
        j*=10;
    }
    string h;
    char w;
    while(sum){
        w=DE_CONFIG[sum%dema];
        h=w+h;
        sum=(sum-sum%dema)/dema;
    }
    NUM normal;
    normal.dema=dema;
    normal.main=h;
    normal.fflag=d.fflag;
    return normal;
}