#include "symMat.hh"
using namespace std;
using namespace Eigen;

int main() {

	Matrix3d mat3d = 100 * Matrix3d::Random();
	Matrix4d mat4d = 100 * Matrix4d::Random();
	Matrix3f mat3f = 100 * Matrix3f::Random();
	Matrix4f mat4f = 100 * Matrix4f::Random();


	SymMat<double> SymMat3d(mat3d);
	SymMat<double> SymMat4d(mat4d);
	SymMat<float> SymMat3f(mat3f);
	SymMat<float> SymMat4f(mat4f);

	cout << SymMat3d << endl << endl;

	cout << "SymMat3d + SymMat3d = " << endl << endl;
	SymMat<double> res3d(3);
	res3d = SymMat3d + SymMat3d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat4d + SymMat4d = " << endl << endl;
	SymMat<double> res4d(4);
	res4d = SymMat4d + SymMat4d;
	cout << res4d<< endl << endl << endl;

	cout << "SymMat3f - SymMat3f = " << endl << endl;
	SymMat<float> res3f(3);
	res3f =  SymMat3f-SymMat3f;
	cout << res3f << endl << endl << endl;

	cout << "SymMat4f - SymMat4f = " << endl << endl;
	SymMat<float> res4f(4);
	res4f =  SymMat4f - SymMat4f;
	cout << res4f << endl << endl << endl;

	cout << "SymMat3d * SymMat3d = " << endl << endl;
	res3d = SymMat3d * SymMat3d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat4d * SymMat4d = " << endl << endl;
	res4d = SymMat4d * SymMat4d;
	cout << res4d<< endl << endl << endl;

	cout << "SymMat3f * SymMat3f = " << endl << endl;
	res3f =  SymMat3f*SymMat3f;
	cout << res3f << endl << endl << endl;

	cout << "SymMat4f * SymMat4f = " << endl << endl;
	res4f =  SymMat4f * SymMat4f;
	cout << res4f << endl << endl << endl;

	cout << "----------------------------------" << endl << endl << endl;

	cout << "SymMat3d + mat3d = " << endl << endl;
	res3d = SymMat3d + mat3d;
	cout << res3d << endl << endl << endl;

	cout << "mat3d + SymMat3d = " << endl << endl;
	res3d = mat3d + SymMat3d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat3f - mat3f = " << endl << endl;
	res3f =  SymMat3f-mat3f;
	cout << res3f << endl << endl << endl;

	cout << "mat3f - SymMat3f = " << endl << endl;
	res3f =  mat3f - SymMat3f;
	cout << res3f << endl << endl << endl;

	cout << "SymMat3d * mat3d = " << endl << endl;
	res3d = SymMat3d *mat3d;
	cout << res3d << endl << endl << endl;

	cout << "mat3d * SymMat3d = " << endl << endl;
	res3d = mat3d + SymMat3d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat3f * mat3f = " << endl << endl;
	res3f =  SymMat3f-mat3f;
	cout << res3f << endl << endl << endl;

	cout << "change middle element to 2.000 = " << endl << endl;
	res3f(1, 1) = 2.0000;
	cout << res3f << endl << endl << endl;

	cout << "check SymMat3d size = ";
	cout << SymMat3d.size() << endl << endl << endl;

	cout << "----------------------------------" << endl << endl << endl;

	//TO USE THE PART DOWN BELOW, UNCOMMENT ONLY THE OPERATION YOU WANT TO CHECK,
	//SINCE THE PROGRAM WILL EXIT WHEN THE SIZES DO NOT MATCH
/*
	cout << "should throw an exception because of" 
	<< " the different size of the SymMat matrices:" << endl << endl;

	cout << "SymMat3d + SymMat4d = " << endl << endl;
	res3d = SymMat3d + SymMat4d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat4d + SymMat3d = " << endl << endl;
	res4d = SymMat4d + SymMat3d;
	cout << res4d<< endl << endl << endl;

	cout << "SymMat3f - SymMat4f = " << endl << endl;
	res3f =  SymMat3f-SymMat4f;
	cout << res3f << endl << endl << endl;

	cout << "SymMat4f - SymMat3f = " << endl << endl;
	res4f =  SymMat4f - SymMat3f;
	cout << res4f << endl << endl << endl;

	cout << "SymMat4d * SymMat3d = " << endl << endl;
	res3d = SymMat4d * SymMat3d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat3d * SymMat4d = " << endl << endl;
	res4d = SymMat3d * SymMat4d;
	cout << res4d<< endl << endl << endl;

	cout << "SymMat4f * SymMat3f = " << endl << endl;
	res3f =  SymMat4f*SymMat3f;
	cout << res3f << endl << endl << endl;

	cout << "SymMat3f * SymMat4f = " << endl << endl;
	res4f =  SymMat3f * SymMat4f;
	cout << res4f << endl << endl << endl;


	cout << "----------------------------------" << endl << endl << endl; 

	cout << "should throw an exception because of"
	<< " the different size of the SymMat and Eigen::Matrix:" << endl << endl;

	cout << "SymMat3d + mat4d = " << endl << endl;
	res3d = SymMat3d + mat4d;
	cout << res3d << endl << endl << endl;

	cout << "mat3d + SymMat4d = " << endl << endl;
	res3d = mat3d + SymMat4d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat3f - mat4f = " << endl << endl;
	res3f =  SymMat3f-mat4f;
	cout << res3f << endl << endl << endl;

	cout << "mat3f - SymMat4f = " << endl << endl;
	res3f =  mat3f - SymMat4f;
	cout << res3f << endl << endl << endl;

	cout << "SymMat3d * mat4d = " << endl << endl;
	res3d = SymMat3d *mat4d;
	cout << res3d << endl << endl << endl;

	cout << "mat3d * SymMat4d = " << endl << endl;
	res3d = mat3d + SymMat4d;
	cout << res3d << endl << endl << endl;

	cout << "SymMat3f * mat4f = " << endl << endl;
	res3f =  SymMat3f-mat4f;
	cout << res3f << endl << endl << endl;
*/
	cout << "----------------------------------" << endl << endl << endl;

	cout << "END OF TEST" << endl << endl;




}
