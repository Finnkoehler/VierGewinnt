#include "renderer.h"
#include <iostream>

renderer::renderer(field* f)
{
	fieldmodel = f;
}
void renderer::renderField()
{
	std::cout << "\t";
	for (int i = 0; i < 7; i++)
		std::cout << i + 1 << "\t";
	std::cout << std::endl;
	int zeile = 1;
	for (int i = 0; i < 6; i++)
	{

		std::cout << zeile << "\t";
		for (int j = 0; j < 7; j++)
		{
			std::cout << int(fieldmodel->getPlayground().at(j).at(i).state) << "\t";
	
		}
		zeile++;
		std::cout << std::endl;
	}
}