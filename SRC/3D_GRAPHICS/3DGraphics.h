#ifndef GRAPHICS3D_H
#define GRAPHICS3D_H
class Vector3D{
	public:
		float x;
		float y;
		float z;
		Vector3D(float X, float Y, float Z);
		Vector3D();
		float dot(Vector3D v);
		Vector3D add(Vector3D v);
		Vector3D subtract(Vector3D v);
		Vector3D rotate(Vector3D point, Vector3D rotation);
};
#endif
