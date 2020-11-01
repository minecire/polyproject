#include "3DGraphics.h"
#include <cmath>

class matrix4{
	float determinant = 0;
	float data[4][4];
	float inverse[4][4];
	public:
		matrix4(Vector3D point, Vector3D rotation){
			data[3][0] = 0;
			data[3][1] = 0;
			data[3][2] = 0;
			data[3][3] = 1;

			Vector3D xAxis = Vector3D(1, 0, 0).rotate(Vector3D(), rotation);
			Vector3D yAxis = Vector3D(0, 1, 0).rotate(Vector3D(), rotation);
			Vector3D zAxis = Vector3D(0, 0, 1).rotate(Vector3D(), rotation);

			data[0][0] = xAxis.x;
			data[1][0] = xAxis.y;
			data[2][0] = xAxis.z;

			data[0][1] = yAxis.x;
			data[1][1] = yAxis.y;
			data[2][1] = yAxis.z;

			data[0][2] = zAxis.x;
			data[1][2] = zAxis.y;
			data[2][2] = zAxis.z;

			data[0][3] = point.x;
			data[1][3] = point.y;
			data[2][3] = point.z;

		};
	void calcInverse(){
		determinant = calcDeterminant(4, data);
	};

	//https://www.tutorialspoint.com/cplusplus-program-to-compute-determinant-of-a-matrix
	float calcDeterminant(int size, float data[][4]){
		if(size == 2){
			return(data[0][0]*data[1][1]-data[0][1]*data[1][0]);
		}
		float mini[size][size];
		float det = 0;
		for(int x = 0; x < size; x++) {
			int subi = 0;
			for (int i = 1; i < size; i++) {
				int subj = 0;
				for (int j = 0; j < size; j++) {
				if (j == x)
					continue;
				mini[subi][subj] = data[i][j];
				subj++;
			}
			subi++;
			det += pow(-1, x) * data[0][x] * calcDeterminant(size - 1, mini);
		}
        return det;
	}

	float** mult(float f)
	{
		float final[4][4];
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				final[i][j] = data[i][j]*f
			}
		}
		return final;
	};
}
