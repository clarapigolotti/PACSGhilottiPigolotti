# APSC project: DE-PDE algorithm - fdaPDE library 

This repository contain the fdaPDE R library enriched with the Density Estimation - Partial Differential Equation (DE-PDE) algorithm. In this version the DE-PDE algorithm is not parallelized.

The source code is written in C++ and interfaced with R through .Call.

# Subfolder structure

/src contains all C++ code and a special file named Makevars necessary to build and install the R package, /R contains the R functions that wrap the C++ calls, /tests contains a script to test the package, /data contains the data to run the tests in /tests.

# Package installation

Download the .zip of the code, unzip it, then from the R console type

install.packages('/path/to/PACSGhilottiPigolotti', type='source', repos=NULL)

To install the package, please make sure that you have the package devtools already installed. Moreover, it could be asked to install all the library dependencies (rgl, plot3D, plot3Drgl, RcppEigen, geometry).


