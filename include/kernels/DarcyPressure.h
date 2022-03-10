#pragma once

#include "ADKernelGrad.h"

class DarcyPressure : public ADKernelGrad
{
public:
  static InputParameters validParams();

  DarcyPressure (const InputParameters & parameters);

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;

  const ADMaterialProperty<Real> & _permeability;
  const ADMaterialProperty<Real> & _viscosity;

};
