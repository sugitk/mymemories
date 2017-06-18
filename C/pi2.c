#include "multi.h"

int a[N+1], t[N+1], u[N+1];

void pi(void)
{
	int i, m;
	int k;

	/* John Machin (1680-1751, 1706) */
	/* 16 arctan(1/5) */
	t[0] = 16;  for (i = 1; i <= N; i++) t[i] = 0;
	shou(t, 5, t);

	for (i = 0; i <= N; i++) a[i] = t[i];

	i = m = 0;  k = 1;
	for ( ; ; ) {
		shou(t, 25, t);
		k += 2;
		shou(t, k, u);
		if (k & 2) sa(a, u, a);  else wa(a, u, a);
		if (isnotzero(u) == 0) break; 
	}

	/* 4 arctan(1/239) */
	t[0] = 4;  for (i = 1; i <= N; i++) t[i] = 0;
	shou(t, 239, t);
	sa(a, t, a);

	i = m = 0;  k = 1;
	for ( ; ; ) {
		shou(t, 239, t);
		shou(t, 239, t);
		k += 2;
		shou(t, k, u);
		if (k & 2) wa(a, u, a);  else sa(a, u, a);
		if (isnotzero(u) == 0) break; 
	}

	print(a);
}

int main()
{
	pi();
	return 0;
}
