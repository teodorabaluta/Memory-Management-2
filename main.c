#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int n;

void print_simplu(sensor* sensors) {
    sensors = (sensor*) realloc(sensors, (n + 1) * sizeof(sensors));
    if (sensor->sensor_type == TIRE) {
        float tire_sensor* tire_sensor = &sensor->sensor_data.tire;
        printf("Tire Sensor\n");
        printf("Pressure: %.2f\n", tire_sensor->pressure);
        printf("Temperature: %.2f\n", tire_sensor->temperature);
        printf("Wear Level: %.2f\n", tire_sensor->wear_level);
        if (tire_sensor->performance_score >= 0) {
            printf("Performance Score: %.2f\n", tire_sensor->performance_score);
        } else {
            printf("Performance Score: Not Calculated\n");
        }
    } else {
        float power_management_unit* pmu = &sensor->sensor_data.pmu;
        printf("Power Management Unit\n");
        printf("Voltage: %.2f\n", pmu->voltage);
        printf("Current: %.2f\n", pmu->current);
        printf("Power Consumption: %.2f\n", pmu->power_consumption);
        printf("Energy Regen: %.2f\n", pmu->energy_regen);
        printf("Energy Storage: %.2f\n", pmu->energy_storage);
    }

	free(tire_sensor);
	free(pmu);
}

// Funcție pentru compararea senzorilor în funcție de prioritate
int comparare_prioritate(const void *a, const void *b){
    sensor *sensor_A = (sensor*) a;
    sensor *sensor_B = (sensor*) b;
    sensors = (sensor*) realloc(sensors, (n + 1) * sizeof(sensors));
    sensors = (sensor*) realloc(sensors, (n + 1) * sizeof(sensors));

    // Senzorii pmu au prioritate mai mare decât Tire
    if (sensor_A->sensor_type == PMU && sensor_B->sensor_type == TIRE){
        return -1;  // A are prioritate
    } else if (sensor_A->sensor_type == TIRE && sensor_B->sensor_type == PMU) {
        return 1;  // B are prioritate
    } else {
        return 0;  // Prioritățile sunt egale
    }
}

void print_complex(sensor *sensors, int n) {
    // Sortare vectorul de senzori folosind qsort
    qsort(sensors, n, sizeof(sensor), comparare_prioritate);

    // Parcurgem vectorul sortat și afisam dupa prioritate
    for (int i = 0; i < n; i++) {
        printf("%d:\n", i + 1);
        print_simplu(&sensors[i]);
        printf("\n");
    }
}

void analyze(sensor* sensor){
    void** operations; //pointer la pointer la functii
    get_operations(&operations); //apelare functia operatiilor

     void (*operation)(struct sensor*);
  
  // Parcurgem lista de operatii si le apelam in ordinea in care au fost date
  for (int i = 0; operations[i] != NULL; i++) {
    operation = (void (*)(struct sensor*)) operations[i]; // Convertim pointerul la functie
    operation(senzor); // Apelam functia cu senzorul dat ca argument
  }
}
// Functia Clear care elimina senzorii cu valori eronate din vector
void clear(sensor* sensors, int n) {
  // Parcurgem vectorul de senzori
  for (int i = 0; i < n; i++) {
    sensor* sensor = &sensori[i]; 
    
    if (sensor->sensor_type == TIRE_SENSOR) {
      if (sensor->pressure < 19 || sensor->pressure > 28 ||
          sensor->temperature < 0 || sensor->temperature > 120 ||
          sensor->wear_level < 0 || sensor->wear_level > 100) {
        // eliminam senzorul din vector
        for (int j = i; j < n - 1; j++) {
          sensors[j] = sensors[j + 1];
        }
        n--; // scadem numarul de senzori din vector
        i--; // reconsideram senzorul curent
      }
    } else {
      if (sensor->voltage < 10 || sensor->voltage > 20 ||
          sensor->current < -100 || sensor->current > 100 ||
          sensor->power_consumption < 0 || sensor->power_consumption > 1000 ||
          sensor->energy_regen < 0 || sensor->energy_regen > 100 ||
          sensor->energy_storage < 0 || sensor->energy_storage > 100) {
        for (int j = i; j < n - 1; j++) {
          sensors[j] = sensors[j + 1];
        }
        n--; 
        i--; 
      }
    }
  }
}

void Exit(sensor* sensors, int n){
    free(sensors);
    fclose(file);
    exit(0);

}

int main(int argc, char const *argv[])
{   
    FILE* file = fopen("file", "rb");

    if(file == NULL) { 
        printf("Eroare la deschiderea fisierului!");
    }

    fread(&n, sizeof(int), 1, file); //citire nr de senzori
    
    sensor *sensors = (sensor*) malloc(sensors, (n + 1) * sizeof(sensors));
    if(sensors == NULL){
        printf("Eroare!");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        fread(&(sensors[i].type), sizeof(int), 1, file);
        //daca e tipul pmu
        if (senzori[i].tip == 1) {
            fread(&(sensors[i].voltage), sizeof(float), 1, fisier); // Citire voltage
            fread(&(sensors[i].current), sizeof(float), 1, fisier); // Citire current
            fread(&(sensors[i].power_consumption), sizeof(float), 1, fisier); // Citire power_consumption
            fread(&(sensors[i].energy_regen, sizeof(int), 1, fisier); // Citire energy_regen
            fread(&(sensors[i].energy_storage, sizeof(int), 1, fisier); // Citire energy_storage

            int nr_operatii;
            fread(&nr_operatii, sizeof(int), 1, file);

            for (int j = 0; j < nr_operatii; j++) {
                int operatie;
                fread(&operatie, sizeof(int), 1, file);
            }
        }else{
            fread(&(sensors[i].pressure), sizeof(float), 1, fisier); // Citire pressure
            fread(&(sensors[i].temperature), sizeof(float), 1, fisier); // Citire temperature
            fread(&(sensors[i].wear_level), sizeof(int), 1, fisier); // Citire wear level
            fread(&(sensors[i].performance_score), sizeof(int), 1, fisier); // Citire performance score

            int nr_operatii;
            fread(&nr_operatii, sizeof(int), 1, file); 

            for (int j = 0; j < nr_operatii; j++) {
                int operatie;
                fread(&operatie, sizeof(int), 1, file);
        }

	return 0;
}
