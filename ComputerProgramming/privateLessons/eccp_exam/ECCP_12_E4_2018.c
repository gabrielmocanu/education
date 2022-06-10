#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {

  int n;
  float x,y,z;
  float v1[100],v2[100],v3[100]; // pozitiile planetelor -> v1[0], v2[0], v3[0] -> reprezinta coordonatele primei planete
  float x_n,y_n,z_n; // pozitii de start pentru nava
  int i,j;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%f %f %f",&v1[i],&v2[i],&v3[i]);
  }
  scanf("%f %f %f",&x_n,&y_n,&z_n);

  float dist;
  float sum_dist = 0; // distanta pe care o parcurge nava
  float min_dist = 999999; // distanta minima dintre nava si o planeta
  int min_index; // pe ce planeta e distanta minima
  int vizitat[100] = {0};

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      dist = sqrt(pow(x_n - v1[j],2)+pow(y_n - v2[j],2)+pow(z_n - v3[j],2)); // calculam distanta

      if(dist < min_dist && vizitat[j] == 0){
        min_dist = dist; // actualizam minimul
        min_index = j; // retinem nava(indexul)
      }
    }

    vizitat[min_index] = 1; // vizitez planeta(marchez)
    x_n = v1[min_index]; // actualizez pozitia navei
    y_n = v2[min_index];
    z_n = v3[min_index];
    sum_dist = sum_dist + min_dist;
    min_dist = 9999999;
  }

  printf("%.2f\n",sum_dist);

  return 0;
}
