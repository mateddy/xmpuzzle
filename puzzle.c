#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
int main() {
  char p[N][N][N], s[N*N+N], *ps;
  int i, j, k, x, y, z;

  gets(s);
  for (k = 0, ps = strtok(s, "|"), x = strlen(ps); ps; ps = strtok(NULL, "|"))
    strcpy(p[0][k++], ps);
  j = 1; z = k;
  while (gets(s)) {
    for (k = 0, ps = strtok(s, "|"); ps; ps = strtok(NULL, "|"))
      strcpy(p[j][k++], ps);
    ++j;
  }
  y = j;

  printf("l = 16;\ne = 0.16;\ng = 3;\n\n");
  printf("module m(v,w) { translate(v*l+[e,e,e]-3*e*w) cube((l-2*e)*[1,1,1]+(6*e-l)*w); }\n\n");

  printf("module a(i,j,k) { m([i,j,k],[0,0,0]); }\n");
  printf("module bx(i,j,k) { m([i,j,k],[1,0,0]); }\n");
  printf("module by(i,j,k) { m([i,j,k],[0,1,0]); }\n");
  printf("module bz(i,j,k) { m([i,j,k],[0,0,1]); }\n");
  printf("module cx(i,j,k) { m([i,j,k],[0,1,1]); }\n");
  printf("module cy(i,j,k) { m([i,j,k],[1,0,1]); }\n");
  printf("module cz(i,j,k) { m([i,j,k],[1,1,0]); }\n");
  printf("module d(i,j,k) { m([i,j,k],[1,1,1]); }\n\n");

  printf("module p() {\n");

  for (k = 0; k < z; ++k)
    for (j = 0; j < y; ++j)
      for (i = 0; i < x; ++i)
	if (p[j][k][i] != '.') {
	  printf("  a(%d,%d,%d);\n", i, y-1-j, k);
	  if (i>0 && p[j][k][i-1] != '.') {
	    printf("  bx(%d,%d,%d);\n", i, y-1-j, k);
	    if (k>0 && p[j][k-1][i] != '.' && p[j][k-1][i-1] != '.') {
	      printf("  cy(%d,%d,%d);\n", i, y-1-j, k);
	      if (j<y-1 && p[j+1][k][i] != '.' && p[j+1][k][i-1] != '.' && p[j+1][k-1][i] != '.' &&p[j+1][k-1][i-1] != '.') printf("  d(%d,%d,%d);\n", i, y-1-j, k);
	    }
	    if (j<y-1 && p[j+1][k][i] != '.' && p[j+1][k][i-1] != '.')
	      printf("  cz(%d,%d,%d);\n", i, y-1-j, k);
	  }
	  if (j<y-1 && p[j+1][k][i] != '.') {
	    printf("  by(%d,%d,%d);\n", i, y-1-j, k);
	    if (k>0 && p[j][k-1][i] != '.' && p[j+1][k-1][i] != '.')
	      printf("  cx(%d,%d,%d);\n", i, y-1-j, k);
	  }
	  if (k>0 && p[j][k-1][i] != '.') printf("  bz(%d,%d,%d);\n", i, y-1-j, k);
	}
  printf("}\np();\n");
}
