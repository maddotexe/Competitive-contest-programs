#include <stdio.h>
#include <string.h>

#define MAXN 200
#define min(a,b) (((a)<(b))?(a):(b))

typedef struct{
  int deg;
  int adj[MAXN];
} Node;

Node alist[MAXN];
char ART[MAXN], val[MAXN];
int id;

void addEdge(int x, int y){
  alist[x].adj[alist[x].deg++] = y;
  alist[y].adj[alist[y].deg++] = x;
}

void clearList(){
  memset(alist, 0, sizeof(alist));
}

int visit(int x, int root){
  int i, y, m, res, child = 0;
  
  res = val[x] = ++id;
  for(i = 0; i < alist[x].deg; i++){
    y = alist[x].adj[i];
    if(!val[y]){
      if(root && ++child > 1) ART[x] = 1;
      m = visit(y, 0);
      res = min(res, m);
      if(m >= val[x] && !root) ART[x] = 1;
    } else {
      res = min(val[y], res);
    }
  }
  return res;
}

void articulate(int n){
  int i;
  
  memset(ART, 0, sizeof(ART));
  memset(val, 0, sizeof(val));
  for(id = i = 0; i < n; i++)
    if(!val[i]) visit(i, 1);
}

int main(){
  int i, n, m, x, y, found, t, c = 0, d;
  
  /* Read in number of vertices, number of edges */
  scanf("%d", &t);
  while(t--){
  	c = 0;
	scanf("%d%d%d", &n, &m, &d);
    /* Read in edge between node x and node y */
    for(i = 0; i < m; i++){
      scanf("%d %d", &x, &y);
      addEdge(x,y);
    }
    
    /* Find articulation points */
    articulate(n);
    
    for(found = i = 0; i < n; i++)
      if(ART[i]){
	c++;
	found = 1;
      }
    printf("%d\n", c * d);
    clearList();
  }
  return 0;
}
