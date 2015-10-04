#include <stdio.h>
int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int i,j;
	for (i = 1; i < 10; ++i) for (j =i+1; j < 10; ++j)
		if (gcd(10*i+j,10*j+i)>5)
			printf("%d %d  %d\n", 10*i+j, 10*j+i, gcd(10*i+j,10*j+i)); //meowmeow
}
