#pragma once

// Include the base class so it can be extended
#include "ADIntegratedBC.h"

/**
 * An IntegratedBC representing the "No BC" boundary condition for
 * heat conduction.
 *
 * The residual is simply -test*k*grad_u*normal... the term you get
 * from integration by parts.  This is a standard technique for
 * truncating longer domains when solving the convection/diffusion
 * equation.
 *
 * See also: Griffiths, David F. "The 'no boundary condition' outflow
 * boundary condition.", International Journal for Numerical Methods
 * in Fluids, vol. 24, no. 4, 1997, pp. 393-411.
 */
class HeatConductionOutflow : public ADIntegratedBC
{
public:
  static InputParameters validParams();

  HeatConductionOutflow(const InputParameters & parameters);

protected:
  /**
   * This is called to integrate the residual across the boundary.
   */
  virtual ADReal computeQpResidual() override;

  /// Thermal conductivity of the material
  const ADMaterialProperty<Real> & _thermal_conductivity;
};
