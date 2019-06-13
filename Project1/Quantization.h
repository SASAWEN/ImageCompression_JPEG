#pragma once
#include<math.h>

class Quantization
{
private:
	int** Qy, **Qc;
public:
	Quantization();
	~Quantization();
	int** quantizeY(double** src);
	int** quantizeC(double** src);

};

