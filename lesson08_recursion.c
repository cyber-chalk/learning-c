#include <stdio.h> 

int reccur (int n){
	if (n > 0) {
		reccur(n -1);
		printf("%d", n);
	}
	return n++;
}

int factorialise (int n) {

    if (n == 1) {
      return 1;
    }
   
    return n * factorialise(n - 1);
}

int gcd (int i, int n) {
	if (n == 0) return i;
	return gcd(n, i % n); 

}



int main () {
	reccur(50);
	printf("%d", factorialise(12));
	printf("%d", gcd(9, 6));


	return 0;
}