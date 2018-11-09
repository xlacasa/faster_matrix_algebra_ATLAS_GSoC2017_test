#include "symMat.hh"
using namespace std;
using namespace Eigen;

int main() {
	//REMEMBER TO ADD DEFINE IFNDEF AND ENDIF TO .hh
	//TO DO: MAKE ALL OPERATORS OUTSIDE THE CLASS "FRIENDS"

	Matrix3d mat3d = 100 * Matrix3d::Random();
	Matrix4d mat4d = 100 * Matrix4d::Random();
	Matrix3f mat3f = 100 * Matrix3f::Random();
	Matrix4f mat4f = 100 * Matrix4f::Random();

	cout << endl << endl;

	cout << "Welcome! This program works with any type of Eigen::Matrix. " 
	<< "However, I will only use floats and doubles of sizes 3 and 4 for this example, "
	<< "since hard-coding every thing would be kind of a struggle..." << endl << endl;

	cout << "Let's take 4 randomly filled Eigen::Matrix :" << endl << endl;

	cout << "The first one is a 3x3 Matrix of Doubles. We will call it 'mat3d':" << endl << endl;
	cout << mat3d << endl << endl << endl;

	cout << "The second is a 4x4 Matrix of Doubles. We will call it 'mat4d':" << endl << endl;
	cout << mat4d << endl << endl << endl;

	cout << "The third one is a 3x3 Matrix of Floats. We will call it 'mat3f':" << endl << endl;
	cout << mat3f << endl << endl << endl;

	cout << "The fourth is a 4x4 Matrix of Floats. We will call it 'mat4f':" << endl << endl;
	cout << mat4f << endl << endl << endl;

	cout << "Now let's create a SymMat from each one. I'll call these 'SymMatXx'" << endl << endl;

	SymMat<double> SymMat3d(mat3d);
	SymMat<double> SymMat4d(mat4d);
	SymMat<float> SymMat3f(mat3f);
	SymMat<float> SymMat4f(mat4f);

	cout << "The SymMat3d looks like this:" << endl << endl;
	cout << SymMat3d << endl << endl << endl;

	cout << "The SymMat4d looks like this:" << endl << endl;
	cout << SymMat4d << endl << endl << endl;

	cout << "The SymMat3f looks like this:" << endl << endl;
	cout << SymMat3f << endl << endl << endl;

	cout << "The SymMat4f looks like this:" << endl << endl;
	cout << SymMat4f << endl << endl << endl;

	cout << "Alright, now let's do some basic operations to see how the SymMat syntax works!" << endl
	<< "(Take into account that I've stored the results in a SymMat. Hence they are automatically "
	<< "made into a symmetric Matrix using only the Upper Triangle)"<< endl << endl;

	cout << "SymMat3d + mat3d = " << endl << endl;
	SymMat<double> res3d(3);
	res3d = SymMat3d + mat3d;
	cout << res3d << endl << endl << endl;

	cout << "mat4d + SymMat4d = " << endl << endl;
	SymMat<double> res4d(4);
	res4d = mat4d + SymMat4d;
	cout << res4d<< endl << endl << endl;

	cout << "SymMat3f - mat3f = " << endl << endl;
	SymMat<float> res3f(3);
	res3f =  SymMat3f-mat3f;
	cout << res3f << endl << endl << endl;

	cout << "mat4f - SymMat4f = " << endl << endl;
	SymMat<float> res4f(4);
	res4f =  mat4f - SymMat4f;
	cout << res4f << endl << endl << endl;

	cout << "mat4f*SymMat4f = " << endl << endl;
	res4f =  mat4f*SymMat4f;
	cout << res4f << endl << endl << endl;

	cout << "Which is different from SymMat4f*mat4f = " << endl << endl;
	res4f =  SymMat4f*mat4f;
	cout << res4f << endl << endl << endl;

	cout << "Of course, you can also do all the previous operations using " <<
	"2 SymMats instead of a SymMat and an Eigen::Matrix. For example SymMat4f*SymMar4f =" << endl << endl;
	res4f =  SymMat4f*SymMat4f;
	cout << res4f << endl << endl << endl;

	cout << "(You can also fill a previously created SymMat passing the input to the terminal. To "<<
	"do so, use the 'SymMat<T>.read();' method in your program. When called, it will wait for an input of "<<
	"the numbers that will fill the upper triangle of the matrix, separated by spaces." << endl << endl <<
	"For example, if your 'SymMat<int> mat' is of size 3, you call the read() method on it, and input into the terminal " <<
	"$1 2 3 4 5 6, now your SymMat will look like:" <<endl<<
	"1 2 3" << endl <<
	"2 4 5" << endl <<
	"3 5 6" << endl << endl;

	cout << "Thank you very much for your patience and reading through all of it!" << endl
	<< "You can take a look at the .hh file, where the class SymMat and its methods are defined "
	<< "and specified (kind of). I hope it's understandable enough to play around with it!" << endl << endl;
}
