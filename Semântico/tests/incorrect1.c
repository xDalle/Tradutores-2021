float mult(int x, float y){
    return x * y;
}

int exec (float b, int c){
    int x;
    x = 4;
    x = (9 - 80);
    if(c == 0){
        int x;
        x = 9;
    }
    for(x = b; x < c; x = x+1){
        int j;
    }
    b = -9.6316;
    int b;    // erro semântico 1 -> redeclaração de variável já existente no escopo (vide tabela de símbolos)
    return mult(x, b);
}

int main(){
    int a;
    int b;
    float list j;
    b = exec(a);    // erro semântico 2 -> passagem errada da quantidade de parâmetros
    b = exec(a, j); // erro semântico 3 -> passagem errada do tipo do segundo parâmetro (lista)
    
    if(a = b)    // erro sintático 1 -> atribuição dentro do if.
        write("estou triste")    // erro sintático 2 -> comando não finalizado com ;
}