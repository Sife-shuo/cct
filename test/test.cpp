#include <iostream>
#include "../command.hpp"
#include <vector>

template <class S>
void printv(std::vector<S> v){
    printf("Printv: [ ");
    for (S x : v) cout<<x<<' ';
    printf("] \n");
}

int main(){
    string j("d 2 10 10100011");
    printv(_cmd_parse(j));
    return 0;
}