float sum(int i){
    return i+1.0;
}

int compare(){
    int list A_B;
    float list C99;
	
    A_B = NIL;
    for(int i = 0; i < 3; i = i + 1){
        A_B = i : A_B;
    }
	
    write(?C99);
    if(C99 != NIL){
        C99 = sum >> A_B;
    }
	
    return -1;
}