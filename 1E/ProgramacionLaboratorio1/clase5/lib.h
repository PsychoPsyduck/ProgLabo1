int getInt(char* mensaje,
           char* mensajeError,
           int reintentos,
           int minimo,
           int maximo,
           int* resultado);

int getFloat(char* mensaje,
           char* mensajeError,
           int reintentos,
           float minimo,
           float maximo,
           int* resultado);

int getChar(char* mensaje,
           char* mensajeError,
           int reintentos,
           char minimo,
           char maximo,
           char* resultado);

float calcularPromedioV1(int valores[], int cantidad);

float calcularPromedioV2(int valores[], int cantidad, float* resultado);

