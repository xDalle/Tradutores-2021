int sum_10(int x){  // erro semântico 3 -> não se sabe o tipo passado para x, uma vez que não foi declarado na função exec.
    return x + 10;
}

float succ(int i){
    return i+1;
}

int exec(){    // erro semântico 2 -> programa não possui função main
    float list FL10;
    int k;
    k = sum_10(j);  // erro semântico 1 -> utilização de variável j não declarada no escopo.
    FL10 = succ >> writeln("lists");    // erro sintático 1 -> OUTPUT onde deveria ser sum_exp
    // erro semântico 4 -> assigment inválido, visto que o tipo retornado por succ >> writeln("lists") é inválido.
    float list AUXL;
    for(AUXL=FL10; AUXL return NIL; AUXL = !AUXL){    // erro sintático 2 -> RETURN onde deveria ser condition
        int j;
        write("bye...");
    }
}