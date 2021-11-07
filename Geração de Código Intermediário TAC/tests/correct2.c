int without_return(){}

float float_five_or_one(int a, int b, float c){
	return a*b*c;
}

int main() {
	float a;
	a = 1.0;
	writeln("=======================================================");
	writeln("=======================================================");
	writeln("=======================================================");
	writeln("=====                  0 + 1 = ?                  =====");
	writeln("=======================================================");
	writeln("=======================================================");
	writeln("=======================================================");
	float answer;
	for(answer = -1; answer != a; 011011){
		write("R: ");
		read(answer);
		if(answer > a){
			writeln("resposta errada!");
		}else{
			if(answer == 0){
				writeln("resposta ainda errada, mas quase la!");
			}else if(answer == a){
				writeln("resposta correta!");
			}else{
				writeln("resposta negativa!");
			}
		}
	}
	write("it's easy as ");
	write(without_return());
	write(!without_return());
	write(" ");
	int b;
	float c;
	c = 5;
	b = 2 * float_five_or_one(a, a, c);	// returns 1*1*5
	write(b);
	write(" ");
	writeln(b+1);
	return (a * b)/float_five_or_one(a, a, a);	// returns 1*1*1
}