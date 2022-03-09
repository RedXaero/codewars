int peak_height (int rows, int cols, char mountain[rows][cols])
{
    int i, j, contador = 1, birdsCounter = 0, blancos = 0;
    char bird = '^';
    char borde = ' ';
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
              if(mountain[i][j] !=' '){
                 birdsCounter++;
              }
           }
      }
    if( birdsCounter == 0){
      return 0;
    }
  birdsCounter = 0;
  
    while(1){

        /* Cambiamos únicamente el borde de la matríz
         *
         * */
        for (j = 0; j < cols; ++j) {
            if(mountain[0][j] == bird)
                mountain[0][j] = contador + '0';

            if(mountain[rows - 1][j] == bird)
                mountain[rows - 1][j] = contador + '0';
        }

        for (int i = 0; i < rows ; ++i) {
            if(mountain[i][cols - 1] == bird)
                mountain[i][cols - 1] = contador + '0';

            if(mountain[i][0] == bird)
                mountain[i][0] = contador + '0';
        }

        /*Verificamos si hay bordes interiores
         * */
        for (i = 1; i < rows - 1; ++i) {
            for (j = 1; j < cols - 1; ++j) {
                if(mountain[i][j] == '^')
                    if( mountain[i][j + 1] == borde ||
                        mountain[i][j - 1] == borde ||
                        mountain[i + 1][j] == borde ||
                        mountain[i - 1][j] == borde)
                        mountain[i][j] = contador + '0';
            }
        }
        borde = contador + '0';

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(mountain[i][j] == '^'){
                  birdsCounter++;
                }       
            }
        }
        if(birdsCounter==0){
            
            return contador;
        }

        birdsCounter = 0;
        contador++;
    }
  return 666;
}