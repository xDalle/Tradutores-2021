int zacola(int a){
     return a+1;
}

int main(){
     int a;
     float b;
     b = -2.5;
     a = 1 + b;
     zacola(zacola(zacola(a)));
     return 0;
}