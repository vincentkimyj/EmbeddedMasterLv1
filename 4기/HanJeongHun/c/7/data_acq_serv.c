#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _power_grid_info power_grid_info;

#if 0
struct _power_grid_info
{
	float power;
	float battery_cell_voltage[0];
};
#endif

struct _power_grid_info
{
	int data[0];
};

#define POWER_GRID_DATA_SIZE			4

typedef struct _air_harmonic_info air_harmonic_info;

struct _air_harmonic_info
{
	int data[0];
};

#define AIR_HARMONIC_DATA_SIZE			4

power_grid_info *init_power_grid_info(void)
{
	power_grid_info *tmp;

	tmp = (power_grid_info *)malloc(POWER_GRID_DATA_SIZE);

	return tmp;
}

air_harmonic_info *init_air_harmonic_info(void)
{
	air_harmonic_info *tmp;

	tmp = (air_harmonic_info *)malloc(AIR_HARMONIC_DATA_SIZE);

	return tmp;
}

int custom_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void receive_power_grid_data(power_grid_info **info)
{
	(*info)->data[0] = custom_random(1, 5);
}

void receive_air_harmonic_data(air_harmonic_info **info)
{
	(*info)->data[0] = custom_random(2, 4);
}

int main(void)
{
	int i, sum = 0;
	power_grid_info *receive_power_data;
	air_harmonic_info *receive_air_data;

	srand(time(NULL));
	printf("sizeof(power_grid_info) = %ld\n", sizeof(power_grid_info));

	receive_power_data = init_power_grid_info();
	receive_air_data = init_air_harmonic_info();

	for (i = 0; i < 10; i++)
	{
		receive_power_grid_data(&receive_power_data);
		receive_air_harmonic_data(&receive_air_data);
		//printf("power data = %d\n", receive_power_data->data[0]);

		sum += receive_power_data->data[0] * receive_air_data->data[0];
		printf("i = %d, sum = %d\n", i, sum);
	}


	printf("final sum = %d\n", sum);

	return 0;
}
