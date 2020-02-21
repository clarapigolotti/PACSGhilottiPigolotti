#ifndef _DESCENT_DIRECTION_IMP_HPP
#define _DESCENT_DIRECTION_IMP_HPP


template<typename Integrator, typename Integrator_noPoly, UInt ORDER, UInt mydim, UInt ndim>
std::unique_ptr<DirectionBase<Integrator, Integrator_noPoly, ORDER, mydim, ndim>>
DirectionGradient<Integrator, Integrator_noPoly, ORDER, mydim, ndim>::clone() const {

  return make_unique<DirectionGradient<Integrator, Integrator_noPoly, ORDER, mydim, ndim>>(*this);

}


template<typename Integrator, typename Integrator_noPoly, UInt ORDER, UInt mydim, UInt ndim>
VectorXr
DirectionGradient<Integrator, Integrator_noPoly, ORDER, mydim, ndim>::computeDirection(const VectorXr& g, const VectorXr& grad){

  return (- grad);
}


template<typename Integrator, typename Integrator_noPoly, UInt ORDER, UInt mydim, UInt ndim>
DirectionBFGS<Integrator, Integrator_noPoly, ORDER, mydim, ndim>::DirectionBFGS(const DirectionBFGS<Integrator, Integrator_noPoly, ORDER, mydim, ndim>& rhs):
DirectionBase<Integrator, Integrator_noPoly, ORDER, mydim, ndim>(rhs) {

  updateH_ = false;
  HInit_ = rhs.HInit_;
  HOld_ = rhs.HInit_;

}


template<typename Integrator, typename Integrator_noPoly, UInt ORDER, UInt mydim, UInt ndim>
std::unique_ptr<DirectionBase<Integrator, Integrator_noPoly, ORDER, mydim, ndim>>
DirectionBFGS<Integrator, Integrator_noPoly, ORDER, mydim, ndim>::clone() const {

  return make_unique<DirectionBFGS<Integrator, Integrator_noPoly, ORDER, mydim, ndim>>(*this);

}


template<typename Integrator, typename Integrator_noPoly, UInt ORDER, UInt mydim, UInt ndim>
VectorXr
DirectionBFGS<Integrator, Integrator_noPoly, ORDER, mydim, ndim>::computeDirection(const VectorXr& g, const VectorXr& grad){

  if(updateH_){
    VectorXr delta = g - gOld_;
    VectorXr gamma = grad - gradOld_;

    HOld_ = HOld_ + (1 + (gamma.dot(HOld_*gamma))/(delta.dot(gamma)))*(delta*delta.transpose())/(delta.dot(gamma)) -
          (HOld_*gamma*delta.transpose() + delta*gamma.transpose()*HOld_)/(delta.dot(gamma));

  }

  gOld_ = g;
  gradOld_ = grad;

  if(!updateH_) updateH_ = true;

  return (-HOld_*grad);
}


template<typename Integrator, typename Integrator_noPoly, UInt ORDER, UInt mydim, UInt ndim>
void
DirectionBFGS<Integrator, Integrator_noPoly, ORDER, mydim, ndim>::resetParameters(){
  updateH_ = false;
  HOld_ = HInit_;
}

#endif
