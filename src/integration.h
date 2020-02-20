#ifndef __INTEGRATION_HPP__
#define __INTEGRATION_HPP__

#include "fdaPDE.h"
#include "mesh_objects.h"

class IntegratorTriangleP2{
	static const std::vector<Real> w;
	public:
	static const UInt ORDER = 1;
	//Number of nodes
	static const UInt NNODES = 3;
	//Point locations
	static const std::vector<Point> NODES;
	// static const std::vector<Real> WEIGHTS;
	static const VectorXr WEIGHTS;

	};

class IntegratorTriangleP4{
	static const std::vector<Real> w;
	public:
	static const UInt ORDER = 2;
	//Number of nodes
	static const UInt NNODES = 6;
	//Point locations
	static const std::vector<Point> NODES;
	static const VectorXr WEIGHTS;
	};

class IntegratorTetrahedronP2{
	static const std::vector<Real> w;

	public:
	static const UInt ORDER = 1;
	//Number of nodes
	static const UInt NNODES = 4;
	//Point locations
	static const std::vector<Point> NODES;
	static const VectorXr WEIGHTS;
	};

class IntegratorTetrahedronP1{
	static const std::vector<Real> w;

	public:
	static const UInt ORDER = 1;
	//Number of nodes
	static const UInt NNODES = 1;
	//Point locations
	static const std::vector<Point> NODES;
	static const VectorXr WEIGHTS;
	};

// For the computation of integrals in Density_Estimation, when mydim = 2
class IntegratorGaussLeg4
{
	private:
		static const std::vector<Real> w;

	public:
		//Number of nodes
		static const UInt NNODES = 16;
		//Point locations
		static const std::vector<Point> NODES;
		static const VectorXr WEIGHTS;
};

//#include "integration_imp.hpp"
#endif
