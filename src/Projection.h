#ifndef _PROJECTION_HPP_
#define _PROJECTION_HPP_


/*!  @brief A class to compute data projection over the domain.
*/
template<UInt ORDER, UInt mydim, UInt ndim>
class Projection{};

// Specialization for mydim == 2 and ndim == 2
/*!  @brief A class to compute data projection over the domain when mydim==2 and ndim==2. Actually, no projection is nedeed.
*/
template<UInt ORDER>
class Projection<ORDER,2,2>{
  private:
    MeshHandler<ORDER,2,2> mesh_;

  public:
    //! A constructor.
    Projection(MeshHandler<ORDER,2,2> m): mesh_(m){};
    void computeProjection(DEData& ){};
};


// Specialization for mydim == 2 and ndim == 3
/*!  @brief A class to compute data projection over the domain when mydim==2 and ndim==3.
*/
template<UInt ORDER>
class Projection<ORDER,2,3>{
  private:
    MeshHandler<ORDER,2,3> mesh_;

    //! A method to compute the maximum coordinate of a point.
    UInt getMaxCoor(const Point& ) const;
    //! A method to compute the Euclidean distance between two points.
    Real computeDistance(const Point&, const Point&) const;
    //! A method to compute the area of a 2D triangle.
    Real getAreaTriangle2d(const Point&, const Point&, const Point&) const;
    //! A method to compute the patch of a node.
    std::vector<UInt> computeNodePatch(UInt ) const;
    //! A method to compute the projection of a point to the plane defined by a triangle.
    std::pair<Point, Real> project(const Element<3*ORDER,2,3>& , const Point& ) const;

  public:
    //! A constructor.
    Projection(MeshHandler<ORDER,2,3> m): mesh_(m){};
    //! A method to compute projection of data points over a mesh.
    void computeProjection(DEData& );

};


// Specialization for mydim == 3 and ndim == 3
/*!  @brief A class to compute data projection over the domain when mydim==3 and ndim==3. Actually, no projection is nedeed.
*/
template<UInt ORDER>
class Projection<ORDER,3,3>{
  private:
    MeshHandler<ORDER,3,3> mesh_;

  public:
    //! A constructor.
    Projection(MeshHandler<ORDER,3,3> m): mesh_(m){};
    void computeProjection(DEData& ){};
};

#include "Projection_imp.h"

#endif
