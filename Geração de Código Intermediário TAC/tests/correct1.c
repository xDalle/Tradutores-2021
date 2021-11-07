int twice(int j){
    float i;
    i = 0;
    j = 1.0;
    int k;
    int p;
    p = 0 || j;
    k = -2 * -p;
    return !(i == 0) + k;
}

int zero(){
    return (0 || 0) || (0 && 1) || ((1 && 0) && (1 && 1));
}

int printN(float num, int n){
    int ctd;
    if(n < 1){
        writeln("Insira um numero igual ou maior do que 1...");
        return -1;
    }else{
        for(ctd = 1; ctd <= n; ctd = ctd + 1){
            write(num+ctd);
            if(ctd != n){
                write(", ");
            }else{
                writeln(".");
            }
        }
    }
    return 0;
}

int main() {

    float i;
    write("Insira um numero: ");

    read(i);

    float j;
    j = twice(j);

    write("O dobro eh: ");
    writeln(i * j);

    write("O oposto simetrico eh: ");
    writeln(zero() - i);

    int numeros_seguintes; numeros_seguintes = 20;

    write("Seus "); write(numeros_seguintes); write(" numeros seguintes sao: ");
    printN(i, numeros_seguintes);

    writeln("Ate mais!");
    return 123456789;
}