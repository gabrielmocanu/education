#include <stdio.h>

int main(int argc, char const *argv[]) {

  int n,m;
  int k;
  int i = 0;
  long long fact_n = 1;
  long long fact_k = 1;
  long long fact_n_k = 1;
  int a;
  int b;

  scanf("%d %d",&n,&m);
  // n! n-k! k!

  for(k = 0; k < n; k++){
    // prima data cand gasim C(n,k) > M iesim
    // Calculam C(n,k)
    if(k < n - k)
    {
      a = n-k+1;
      b = k;

      fact_n = 1;
      fact_k = 1;
      for(i = a;i <= n; i++)
      {
        fact_n = fact_n * i;
      }

      for(i = 1; i <= b; i++)
      {
        fact_k = fact_k * i;
      }

      if(fact_n / fact_k > m)
      {
        printf("%d\n",k);
        break;
      }


    }
    else
    {
      a = k + 1;
      b = n-k;


      fact_n = 1;
      fact_k = 1;

      for(i = a;i <= n; i++)
      {
        fact_n = fact_n * i;
      }

      for(i = 1; i <= b; i++)
      {
        fact_k = fact_k * i;
      }

      if(fact_n / fact_k > m)
      {
        printf("%d\n",k);
        break;
      }
    }
  }

  if(k == n)
  {
    printf("0\n");
  }

  return 0;

}
