#include "integration.h"

#include <limits>
#include <cmath>
#define _USE_MATH_DEFINES

//#ifndef __INTEGRATION_IMP_HPP__
//#define __INTEGRATION_IMP_HPP__

const std::vector<Real> IntegratorTriangleP2::w = std::vector<Real>{ {1./3, 1./3, 1./3} };
const VectorXr IntegratorTriangleP2::WEIGHTS = Eigen::Matrix<Real,3,1>(w.data());

const std::vector<Point> IntegratorTriangleP2::NODES = std::vector<Point> { {Point(1./6,1./6),Point(2./3,1./6),Point(1./6,2./3)} };

const std::vector<Real> IntegratorTriangleP4::w = std::vector<Real>{ {
0.2233815897,
0.2233815897,
0.2233815897,
0.1099517437,
0.1099517437,
0.1099517437
} };
const VectorXr IntegratorTriangleP4::WEIGHTS = Eigen::Matrix<Real,6,1>(w.data());


const std::vector<Point> IntegratorTriangleP4::NODES = std::vector<Point> { {
Point(0.4459484909,0.4459484909),
Point(0.4459484909,0.1081030182),
Point(0.1081030182,0.4459484909),
Point(0.0915762135, 0.0915762135),
Point(0.0915762135, 0.816847573),
Point(0.816847573, 0.0915762135)
} };


const std::vector<Real> IntegratorTetrahedronP2::w = std::vector<Real>{ {
1./4,
1./4,
1./4,
1./4
} };
const VectorXr IntegratorTetrahedronP2::WEIGHTS = Eigen::Matrix<Real,4,1>(w.data());


const std::vector<Point> IntegratorTetrahedronP2::NODES = std::vector<Point> { {
Point(0.5854101966249685 ,0.1381966011250105 ,0.1381966011250105),
Point(0.1381966011250105 ,0.1381966011250105 ,0.1381966011250105),
Point(0.1381966011250105 ,0.1381966011250105 ,0.5854101966249685),
Point(0.1381966011250105 ,0.5854101966249685 ,0.1381966011250105)
} };


const std::vector<Real> IntegratorTetrahedronP1::w = std::vector<Real>{ {
1
} };
const VectorXr IntegratorTetrahedronP1::WEIGHTS = Eigen::Matrix<Real,1,1>(w.data());

const std::vector<Point> IntegratorTetrahedronP1::NODES = std::vector<Point> { {
Point(1./4 ,1./4 ,1./4)
} };


// Gauss Legendre wights
const std::vector<Real> IntegratorGaussLeg4::w = std::vector<Real> {{
  0.002100365244475,
  0.003937685608733,
  0.003937685608733,
  0.002100365244475,
  0.018715815315013,
  0.035087705252933,
  0.035087705252933,
  0.018715815315013,
  0.037997147647950,
  0.071235620499740,
  0.071235620499740,
  0.037997147647950,
  0.028150383076926,
  0.052775277354230,
  0.052775277354230,
  0.028150383076926
}};

const VectorXr IntegratorGaussLeg4::WEIGHTS = Eigen::Matrix<Real,16,1>(w.data());

// Gauss Legendre nodes
const std::vector<Point> IntegratorGaussLeg4::NODES = std::vector<Point> { {
  Point(0.004820780989426, 0.064611063213548),
  Point(0.022913166676413, 0.0465186775265616),
  Point(0.046518677526561, 0.022913166676413),
  Point(0.064611063213548, 0.004820780989426),
  Point(0.022913166676413, 0.307096311531159),
  Point(0.108906255706834, 0.221103222500738),
  Point(0.221103222500738, 0.108906255706834),
  Point(0.307096311531159, 0.022913166676413),
  Point(0.046518677526561, 0.623471844265867),
  Point(0.221103222500738, 0.448887299291690),
  Point(0.448887299291690, 0.221103222500738),
  Point(0.623471844265867, 0.046518677526561),
  Point(0.064611063213548, 0.865957092583479),
  Point(0.307096311531159, 0.623471844265867),
  Point(0.623471844265867, 0.307096311531159),
  Point(0.865957092583479, 0.064611063213548)
} };


//#endif
