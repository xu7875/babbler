# pragma once
#include "ADKernelValue.h"

class DarcyAdvection:public ADKernelValue
{
public:
  static InputParameters validParams();
  DarcyAdvection(const InputParameters & parameters);

protected:
  virtual ADReal precomputeQpResidual() override;
  const ADVariableGradient & _pressure_grad;

  const ADMaterialProperty<Real> & _permeability;
  const ADMaterialProperty<Real> & _porosity;
  const ADMaterialProperty<Real> & _viscosity;
  const ADMaterialProperty<Real> & _density;
  const ADMaterialProperty<Real> & _specific_heat;

};
