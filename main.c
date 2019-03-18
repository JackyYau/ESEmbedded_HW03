int intthrees(int a,int b,int c){
	return a+b+c;
}

int more(int a,int b,int c,int d,int e,int f){
	return a+b+c+d+e+f;
}






void reset_handler(void)
{
	intthrees(1,2,3);
	more(1,2,2,2,2,2);
	while (1)
		;
}
