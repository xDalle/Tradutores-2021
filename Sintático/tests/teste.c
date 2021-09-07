int main()
{
  int i;
  int x;
  my_list = NIL;
  for (i; i < 10; i = i + 1) {
		writeln("Write 10 elements to the my_list: ");
		read(x);
		my_list = x : my_list;
	}

   my_other_list >> my_list;

   for (i = 0; i < 10; i = i + 1) {
    x = 2 + i;
    my_other_list = x : my_other_list;
	}

   if(my_list != NIL && my_list != NIL) {
      writeln("Lists are not empty!");
   }
   
   if (my_list > my_list ) {
      writeln("My list is bigger");
   } else if (my_list < my_list ) {
      writeln("My list is smaller");
   } else {
      writeln("Both lists are the same size");
   }

   my_other_list << my_list;

   writeln(! my_list);
   writeln(% my_other_list);

   return 0;
}