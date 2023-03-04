#pragma once

typedef struct {
	char* name;
	char* color;
	int price;
} Fruit;

void createFruit(char* name, char* color, int price);

void destroyFruit(Fruit* fruit);