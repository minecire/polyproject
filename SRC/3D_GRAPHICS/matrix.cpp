#include "3DGraphics.h"

class matrix4{
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

		}
};	
