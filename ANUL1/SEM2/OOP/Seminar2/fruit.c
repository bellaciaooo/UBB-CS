#include "fruit.h"
#include<stdlib.h>
#include<string.h>
void createFruit(char* name, char* color, int price)
{
	Fruit* fruit = (Fruit*)malloc(sizeof(Fruit));
    //check fruit not to be null
	fruit->name = (char*)malooc(sizeof(char) * (strlen(name) + 1));

	fruit->color = (char*)malooc(sizeof(char) * (strlen(color) + 1));
}
