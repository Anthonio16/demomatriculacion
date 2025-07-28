#include <stdio.h>
#include <string.h>

// Lista de placas de ejemplo
char placas[5][10] = {"ZXC123", "ABC456", "LMN789", "DEF234", "GHI567"};
int n = 5;

// B�SQUEDA SECUENCIAL
int busquedaSecuencial(char placa[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(placas[i], placa) == 0)
			return i; // Placa encontrada
	}
	return -1; // No encontrada
}

// B�SQUEDA BINARIA (requiere lista ordenada alfab�ticamente)
int busquedaBinaria(char placa[]) {
	int izquierda = 0, derecha = n - 1;
	
	while (izquierda <= derecha) {
		int medio = (izquierda + derecha) / 2;
		int cmp = strcmp(placas[medio], placa);
		
		if (cmp == 0)
			return medio; // Encontrado
		else if (cmp < 0)
			izquierda = medio + 1;
		else
			derecha = medio - 1;
	}
	
	return -1; // No encontrado
}

// ORDENAMIENTO SIMPLE (burbuja) necesario para binaria
void ordenarPlacas() {
	char temp[10];
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n-i-1; j++)
			if (strcmp(placas[j], placas[j+1]) > 0) {
				strcpy(temp, placas[j]);
				strcpy(placas[j], placas[j+1]);
				strcpy(placas[j+1], temp);
	}
}

int main() {
	char buscada[10];
	
	printf("Ingrese la placa a buscar: ");
	scanf("%s", buscada);
	
	// ?? B�squeda secuencial
	int posSec = busquedaSecuencial(buscada);
	if (posSec != -1)
		printf("Placa encontrada con b�squeda secuencial en posici�n %d\n", posSec);
	else
		printf("Placa no encontrada con b�squeda secuencial\n");
	
	// ?? Ordenar para b�squeda binaria
	ordenarPlacas();
	
	// ?? B�squeda binaria
	int posBin = busquedaBinaria(buscada);
	if (posBin != -1)
		printf("Placa encontrada con b�squeda binaria en posici�n %d (lista ordenada)\n", posBin);
	else
		printf("Placa no encontrada con b�squeda binaria\n");
	
	return 0;
}
