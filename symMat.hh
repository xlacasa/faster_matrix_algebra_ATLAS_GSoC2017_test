#ifndef SYMMAT_HH
#define SYMMAT_HH

#include "Eigen/Dense"
#include "Eigen/Core"
#include <iostream>
#include <string>
using namespace std;


//If more comments on the operators are needed I will add them
//with pleasure in no time, just tell me!

//By the way, I know it does not make sense to use try{} catch {} structures
//to handle the exceptions since I am ending the process everytime anyway,
//but I thought it might be useful to future modifications. If needed, I
//will delete them and make the program just throw an exception whenever
//matrix sizes do not match.

template <typename T>
class SymMat {

private:

	//Matrix Size
	int M_size;

    //UpperTriangle Array Size
    int SymMat_size;
    
    //Upper triangle of the matrix stored as a vector.
	vector<T> UpperTriangle;

	//Throws an exception if the SymMat matrix and the Eigen::Matrix are not the same size
	template <typename Derived>
	const static void check_equal_size(const SymMat<T>& M1, const Eigen::MatrixBase<Derived>& M2) {
		if (M1.size() != M2.rows() || M1.size() != M2.cols()) {
			string err = "The SymMat and the Eigen::Matrix are required to be the same size";
			throw err;
		}
	}

	//Throws an exception if both SymMat matrices are not the same size
	const static void check_equal_size(const SymMat<T>& M1, const SymMat<T>& M2) {
		if (M1.size() != M2.size()) {
			string err = "Both SymMat matrices are required to be the same size";
			throw err;
		}
	}


public:

	//Generic Constructor. (In a 3x3 Matrix, int size = 3)
	SymMat(const int size) {
		M_size = size;
		//Calculate how big the array has to be to store the matrix
		SymMat_size = M_size*(M_size+1)/2;
		//Create the array initialized at 0
		UpperTriangle = vector<T> (SymMat_size, 0);
	} 

	//Constructor from a generic Eigen::Matrix
	template <typename Derived>
	SymMat(const Eigen::MatrixBase<Derived>& M)  {
		M_size = M.cols();
		SymMat_size = M_size*(M_size+1)/2;
		vector<T> v(SymMat_size);
		//Put each element of the upper half
		//triangle in the array UpperTriangle
		for (int i = 0; i < M_size; ++i)
			for (int j = i; j < M_size; ++j) {
	            //Calculate where in the array is the Ai,j
	            //element
	            int pos = (M_size*i)+j - ((i*(i+1))/2);
	            //Fill the array
	            v[pos] = M(i,j);
	        }
		UpperTriangle = v;
	}

	//Size Consultor
	int size() const {
		return M_size;
	}

	//Mi,j modifier. Can be used to modify because it is passed by reference
	//To do so use the "=" operator. (e.g. SymMat<double> myMatrix(3); myMatrix(1,1) = 4.3;)
	T& operator()(int i, int j) {
		//Check that the indices awre inside boundaries
	    assert(j >= 0 && j < M_size);
	    assert(i >= 0 && i < M_size);
	    //Swap the indices if they are out of the Upper Triangle
	    if (i > j) {
	    	int aux = i;
	    	i = j;
	    	j = aux;
	    }
	    //Calculate where in the array is the Ai,j
		//element
		int pos = (M_size*i)+j - ((i*(i+1))/2);
	    return UpperTriangle[pos];
	}

	//Mi,j accessor. Only used to check value of Mi,j
	T operator()(int i, int j) const {
		//Check that the indices awre inside boundaries
	    assert(j >= 0 && j < M_size);
	    assert(i >= 0 && i < M_size);
	    //Swap the indices if they are out of the Upper Triangle
	    if (i > j) {
	    	int aux = i;
	    	i = j;
	    	j = aux;
	    }
	    //Calculate where in the array is the Ai,j
		//element
		int pos = (M_size*i)+j - ((i*(i+1))/2);
	    return UpperTriangle[pos];
	}

	//Operator of Addition SymMat+SymMat
	SymMat operator+(const SymMat<T>& M) const {
		try{	
			check_equal_size(*this, M);
			SymMat<T> result(this->M_size);
			for (int i = 0; i < SymMat_size; ++i) {
				result.UpperTriangle[i] = this->UpperTriangle[i] + M.UpperTriangle[i];
			}
			return result;
		}
		catch (string err){
			cout << "An error occurred: " << err << endl;
			exit(EXIT_FAILURE);
		}
	}

	//Operator of Substraction SymMat-SymMat
	SymMat operator-(const SymMat& M) const {
		try{
			check_equal_size(*this, M);
			SymMat<T> result(this->M_size);
			for (int i = 0; i < SymMat_size; ++i) {
				result.UpperTriangle[i] = this->UpperTriangle[i] - M.UpperTriangle[i];
			}
			return result;
		}
		catch (string err){
			cout << "An error occurred: " << err << endl;
			exit(EXIT_FAILURE);
		}
	}


	//Operator of Addition SymMat+Eigen::Matrix
	template <typename Derived>
	SymMat operator+(const Eigen::MatrixBase<Derived>& M) const {
		try {
			check_equal_size(*this, M);
			SymMat<T> result(this->M_size);
		    int pos = 0;
			for (int i = 0; i < M_size; ++i)
		        for (int j = i; j < M_size; ++j)
		            result.UpperTriangle[pos] = this->UpperTriangle[pos++] + M(i,j);
			return result;
		}
		catch (string err){
			cout << "An error occurred: " << err << endl;
			exit(EXIT_FAILURE);
		}
	} 

	//Operator of Substraction SymMat-Eigen::Matrix
	template <typename Derived>
	SymMat operator-(const Eigen::MatrixBase<Derived>& M) const {
		try {
			check_equal_size(*this, M);
			SymMat<T> result(this->M_size);
		    int pos = 0;
			for (int i = 0; i < M_size; ++i)
		        for (int j = i; j < M_size; ++j) 
		            result.UpperTriangle[i] = this->UpperTriangle[pos++] - M(i,j);
			return result;
		}
		catch (string err){
			cout << "An error occurred: " << err << endl;
			exit(EXIT_FAILURE);
		}
	}

	//Friend operator of Substraction Eigen::Matrix-SymMat, declared outside the class
	template <typename Derived, typename U>
	friend SymMat<U> operator-(const Eigen::MatrixBase<Derived>& M, const SymMat<U>& );

    //Operator of Multiplication SymMat*SymMat
    SymMat operator*(const SymMat& M) const {
		try {   
			check_equal_size(*this, M);
		    SymMat<T> result(this->M_size);
		    int sum = 0;
		    int pos = 0;
		    for (int i = 0; i < M_size; ++i) 
		        for (int j = i; j < M_size; ++j) {
		            for (int k = 0; k < M_size; ++k)
		                sum += (*this)(i, k) * M(k, j);
		            result.UpperTriangle[pos++] = sum;
		            sum = 0;
		        }
		    return result;
	    }
		catch (string err){
			cout << "An error occurred: " << err << endl;
			exit(EXIT_FAILURE);
		}
	}

	    
    //Operator of Multiplication SymMat*Eigen::Matrix
    template <typename Derived>
    SymMat operator*(const Eigen::MatrixBase<Derived>& M) const {
	    try {
	    	check_equal_size(*this, M);
		    SymMat<T> result(this->M_size);
		    int sum = 0;
		    int pos = 0;
		    for (int i = 0; i < M_size; ++i) 
		        for (int j = i; j < M_size; ++j) {
		            for (int k = 0; k < M_size; ++k)
		                sum += (*this)(i, k) * M(k, j);
		            result.UpperTriangle[pos++] = sum;
		            sum = 0;
		        }
		    return result;
		}
		catch (string err) {
			cout << "An error occurred: " << err << endl;
			exit(EXIT_FAILURE);
		}
	}

	//Friend operator of Multiplication Eigen::Matrix-SymMat, declared outside the class
	template <typename Derived, typename U>
	friend SymMat<U> operator*(const Eigen::MatrixBase<Derived>& M, SymMat<U>& );

	//Reading method for SymMat. READS ONLY THE UPPER TRIANGLE. If you want to input
	//the entire matrix,use the Eigen::Matrix standard input operator for an Eigen::Matrix
	//(Usage: SymMat<T> sM(3); sM.read() $1 2 3 4 5 6 (using the terminal as the default input channel)
	//would result in sM = 	1 2 3
	//						2 4 5
	//                      3 5 6
	//METHOD NOT NECESSARY, USED JUST FOR COMFORT
	void read() { 
		for (int i = 0; i < SymMat_size; ++i) {
			cin >> UpperTriangle[i];
		}             
	} 
};


/////////////////////////////////////////////////////////////////////////////
//Same operators, this time the order of the parameters is reversed so that//
//the Eigen::Matrix involved operations can be both ways. 				   //
//(E.g. SymMat + Eigen::Matrix OR Eigen::Matrix + SymMat are both possible)//
/////////////////////////////////////////////////////////////////////////////


//Operator of Addition Eigen::Matrix+SymMat
template <typename Derived, typename T>
inline SymMat<T> operator+(const Eigen::MatrixBase<Derived>& M, const SymMat<T>& sM)  {
	return sM + M;
} 

//Operator of Substraction Eigen::Matrix-SymMat
template <typename Derived, typename T>
inline SymMat<T> operator-(const Eigen::MatrixBase<Derived>& M,const SymMat<T>& sM)  {
	try {
		SymMat<T>::check_equal_size(sM, M);
		int size = sM.size();
		SymMat<T> result(size);
		int pos = 0;
		for (int i = 0; i < size; ++i)
	        for (int j = i; j < size; ++j, ++pos) 
	            result.UpperTriangle[pos] = M(i,j) - sM.UpperTriangle[pos];
		return result;
	}
	catch (string err){
		cout << "An error occurred: " << err << endl;
		exit(EXIT_FAILURE);
	}
}

//Operator of Multiplication Eigen::Matrix*SymMat
template <typename Derived, typename T>
inline SymMat<T> operator*(const Eigen::MatrixBase<Derived>& M, SymMat<T>& sM)  {
	try {
		//check_equal_size(sM, M);
		int size = sM.size();
	    SymMat<T> result(size);
	    int sum = 0;
	    int pos = 0;
	    for (int i = 0; i < size; ++i) 
	        for (int j = i; j < size; ++j) {
	            for (int k = 0; k < size; ++k)
	                sum += M(i, k) * sM(k, j);
	            result.UpperTriangle[pos++] = sum;
	            sum = 0;
	        }
	    return result;
    }
	catch (string err){
		cout << "An error occurred: " << err << endl;
		exit(EXIT_FAILURE);
	}
}


//Output Operator for SymMat (Usage: SymMat<T> sM; cout << sM;)
//NOT NECESSARY, USED JUST FOR COMFORT
template <typename T>
ostream& operator<<(ostream& output, SymMat<T>& sM) { 
	int size = sM.size();
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			output << sM(i, j) << "  ";
		}
		output << endl;
	} 
	return output;            
}

#endif


