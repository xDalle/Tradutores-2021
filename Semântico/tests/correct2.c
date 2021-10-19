/* https://aprender3.unb.br/mod/page/view.php?id=464034 */

int list IL;
float list FL;

int list read_list(int n) {
	int i;
	i =  -435.7;
	int list new;
	new = NIL;
    i > 4;
    i > 4.3;
	for (i = 0; i < n ; i = i + 1) {
		int elem;
		writeln("Digite o elemento da lista: ");
		read(elem);
		new = elem : new;
	}
  
  /* Suponha que os elementos inseridos pelo usuário sejam -3.45, 2.54, 3, 5, 25, -1, 0, 6, 74, 0.
     O valor retornado será:
  
     new = [0,74,6,0,-1,25,5,3,2,-3]
  
  */
	return new;
}

float succ(int i) {
	return i+1;
}


int leq_10(float x) {
	return x <= 10;
}


int main() {

	writeln("Digite os número de elementos da lista: ");

	int n;
	float list FL10;
	read(n);


  	/* Suponha que n = 10  */
	
	IL  = read_list(n); /* IL = [0,74,6,0,-1,25,5,3,2,-3] */
	FL = succ >> IL;  /* FL = [1.0,75.0,7.0,1.0,0.0,26.0,6.0,4.0,3.0,-2.0] */

	FL10 = leq_10 <<  FL; /* FL = [1.0,7.0,1.0,0.0,6.0,4.0,3.0,-2.0] */ 

        if (FL10 != NIL) { 

            float list AUXL; int n; n = 0; 

            for (AUXL=FL10; AUXL != NIL; AUXL = !AUXL) { 

               n = n + 1; 

               write(?AUXL); write(" "); } writeln(" "); 

               write("A nova lista tem "); write(n); writeln(" elementos."); 

         } else writeln("A nova lista não possui elementos."); 

  return 0; 

}