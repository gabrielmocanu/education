#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int v[10];
  int mat[9][9];
  int i,j;
  int ok = 1;

  for(i = 0;i < 9; i++){
    for(j = 0; j < 9; j++){
      scanf("%d\n",&mat[i][j]);
    }
  }

  //  linie
  for(i = 0; i < 9; i++){

    for(j = 0;j < 9; j++){
      v[mat[i][j]] = 1;
    }

    for(j = 1; j <= 9; j++){
      if(v[j] != 1)
        ok = 0;
    }

    if(ok == 0)
      break;
  }

  for(j = 1;j <= 9; j++){
    v[j] = 0;
  }


  // coloana
  for(i = 0; i < 9; i++){

    for(j = 0;j < 9; j++){
      v[mat[j][i]] = 1;
    }

    for(j = 1; j <= 9; j++){

      if(v[j] != 1){
        ok = 0;
      }

    }

    if(ok == 0)
      break;
  }

  for(j = 1;j <= 9; j++){
    v[j] = 0;
  }

    // patrat
    for(i = 0; i < 3; i++){

      for(j = 0;j < 3; j++){
        v[mat[i][j]] = 1;
      }
    }

      for(j = 1; j <= 9; j++){
        if(v[j] == 0)
          ok = 0;
      }

      for(j = 1;j <= 9; j++){
        v[j] = 0;
      }

    // patrat
    for(i = 0; i < 3; i++){

      for(j = 3;j < 6; j++){
        v[mat[i][j]] = 1;
      }
    }

      for(j = 1; j <= 9; j++){
        if(v[j] == 0)
          ok = 0;
      }
      for(j = 1;j <= 9; j++){
        v[j] = 0;
      }

    // patrat
    for(i = 0; i < 3; i++){

      for(j = 6;j < 9; j++){
        v[mat[i][j]] = 1;
      }
    }

      for(j = 1; j <= 9; j++){
        if(v[j] == 0)
          ok = 0;
      }
      for(j = 1;j <= 9; j++){
        v[j] = 0;
      }


    // patrat
    for(i = 3; i < 6; i++){

      for(j = 0;j < 3; j++){
        v[mat[i][j]] = 1;
      }
    }

      for(j = 1; j <= 9; j++){
        if(v[j] == 0)
          ok = 0;
      }
      for(j = 1;j <= 9; j++){
        v[j] = 0;
      }

    // patrat
    for(i = 3; i < 6; i++){

      for(j = 3;j < 6; j++){
        v[mat[i][j]] = 1;
      }
    }

      for(j = 1; j <= 9; j++){
        if(v[j] == 0)
          ok = 0;
      }
      for(j = 1;j <= 9; j++){
        v[j] = 0;
      }

    // patrat
    for(i = 3; i < 6; i++){

      for(j = 6;j < 9; j++){
        v[mat[i][j]] = 1;
      }
    }

      for(j = 1; j <= 9; j++){
        if(v[j] == 0)
          ok = 0;
      }
      for(j = 1;j <= 9; j++){
        v[j] = 0;
      }


      // patrat
      for(i = 6; i < 9; i++){

        for(j = 0;j < 3; j++){
          v[mat[i][j]] = 1;
        }
      }

        for(j = 1; j <= 9; j++){
          if(v[j] == 0)
            ok = 0;
        }
        for(j = 1;j <= 9; j++){
          v[j] = 0;
        }

      // patrat
      for(i = 6; i < 9; i++){

        for(j = 3;j < 6; j++){
          v[mat[i][j]] = 1;
        }
      }

        for(j = 1; j <= 9; j++){
          if(v[j] == 0)
            ok = 0;
        }
        for(j = 1;j <= 9; j++){
          v[j] = 0;
        }

      // patrat
      for(i = 6; i < 9; i++){

        for(j = 6;j < 9; j++){
          v[mat[i][j]] = 1;
        }
      }

        for(j = 1; j <= 9; j++){
          if(v[j] == 0)
            ok = 0;
        }
        for(j = 1;j <= 9; j++){
          v[j] = 0;
        }

    if(ok != 1)
      printf("Gresit\n");
    else
      printf("Corect\n");


  return 0;
}
