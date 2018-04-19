#include<fstream>
#include<iostream>
using namespace std;

int G[100][3]; // graful colectie de muchii (i,j,k) unde k = costul
int n;             // numarul nodurilor
int L[100];     // setul arborilor disjuncti unde L[i]=j inseamna ca
                     // nodul i se gaseste in Arbore A_j
int m;            // numarul muchiilor
int d,c;

int read_data()
{fstream f;
f.open("input.dat",ios::in);
f>>n;
m=0;
while (!f.eof()) {
                         m++;
                        f>>G[m][1];
                        f>>G[m][2];
                        f>>G[m][3];
                        }m--;}

int sort_data()
{
int sorted=0;
int last=m-1;
while (!sorted) { sorted=1;
    for(int i=1;i<=last;i++)
        if ( G[i][3]>G[i+1][3]) {
                                            swap(G[i][1],G[i+1][1]);
                                            swap(G[i][2],G[i+1][2]);
                                            swap(G[i][3],G[i+1][3]);
                                            sorted=0;
                                         }
                       }
}

int init_data()
{for(int i=1;i<=n;i++)  L[i]=i;}

int compute_APM()
{
sort_data();

  int array[100], n, c, d, swap;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }

  printf("Sorted list in ascending order:\n");

  for ( c = 0 ; c < n ; c++ )
     printf("%d\n", array[c]);


    }


int main()
{read_data();
compute_APM();

}

