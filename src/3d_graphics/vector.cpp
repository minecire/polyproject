#include "3DGraphics.h"
#include <cmath>

class Vector3D{
	public:
		float x;
		float y;
		float z;
		Vector3D(float X, float Y, float Z){
			x = X;
			y = Y;
			z = Z;
		}
		Vector3D(){
			x = 0;
			y = 0;
			z = 0;
		}
		Vector3D copy(){
			return Vector3D(x, y, z);
		}
		float dot(Vector3D v){
			return v.x*x+v.y*y+v.z*z;
		}
		Vector3D add(Vector3D v){
			return Vector3D(x+v.x, y+v.y, z+v.z);
		}
		Vector3D subtract(Vector3D v){
			return Vector3D(x-v.x, y-v.y, z-v.z);
		}
		Vector3D rotate(Vector3D point, Vector3D rotation){

			Vector3D oldRotated = Vector3D(x,y,z).subtract(point);
			Vector3D rotated = oldRotated.copy().subtract(point);

			rotated.x = oldRotated.x * cos(rotation.z) - oldRotated.y * sin(rotation.z);
			rotated.y = oldRotated.x * sin(rotation.z) + oldRotated.y * cos(rotation.z);

			oldRotated.x = rotated.x;
			oldRotated.y = rotated.y;

			rotated.y = oldRotated.y * cos(rotation.x) - oldRotated.z * sin(rotation.x);
			rotated.z = oldRotated.y * sin(rotation.x) + oldRotated.z * cos(rotation.x);

			oldRotated.y = rotated.y;
			oldRotated.z = rotated.z;

			rotated.x = oldRotated.x * cos(rotation.y) - oldRotated.z * sin(rotation.y);
			rotated.z = oldRotated.x * sin(rotation.y) + oldRotated.z * cos(rotation.y);

			return rotated.add(point);
		}
};
