#include <stdio.h>
#include <string.h>

// Lista de placas de ejemplo
char placas[5][10] = {"ZXC123", "ABC456", "LMN789", "DEF234", "GHI567"};
int n = 5;

// BÚSQUEDA SECUENCIAL
int busquedaSecuencial(char placa[]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(placas[i], placa) == 0)
			return i; // Placa encontrada
	}
	return -1; // No encontrada
}

// BÚSQUEDA BINARIA (requiere lista ordenada alfabéticamente)
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
// Main para función del código 
int main() {
	char buscada[10];
	
	printf("Ingrese la placa a buscar: ");
	scanf("%s", buscada);
	
	// ?? Búsqueda secuencial
	int posSec = busquedaSecuencial(buscada);
	if (posSec != -1)
		printf("Placa encontrada con búsqueda secuencial en posición %d\n", posSec);
	else
		printf("Placa no encontrada con búsqueda secuencial\n");
	
	// ?? Ordenar para búsqueda binaria
	ordenarPlacas();
	
	// ?? Búsqueda binaria
	int posBin = busquedaBinaria(buscada);
	if (posBin != -1)
		printf("Placa encontrada con búsqueda binaria en posición %d (lista ordenada)\n", posBin);
	else
		printf("Placa no encontrada con búsqueda binaria\n");
	
	return 0;
}
