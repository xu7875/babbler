# include "DarcyPressure.h"

registerMooseObject("BabblerApp", DarcyPressure);

InputParameters
DarcyPressure::validParams()
{
  InputParameters params = ADKernelGrad::validParams();
  params.addClassDescription("Compute the diffusion term for "
  "Darcy pressure ($p$) equation: "
"$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");
 //Add a required parameter.
 params.addRequiredParam<Real>("permeability", "The isotropic permeability ($K$)"
 "of the medium.");
 //Add optitional paramter and set its default value
 params.addParam<Real>(
   "viscosity",
   7.98e-04,
   "The dynamic viscosity ($\\mu$ of the fluid, the default value is that of"
   "water at 30 degree Celcius (7.98e-04 Pa-s).)");

  return params;

}

DarcyPressure::DarcyPressure(const InputParameters & parameters)
  :ADKernelGrad(parameters),
  _permeability(getParam<Real>("permeability")),
  _viscosity(getParam<Real>("viscosity"))
{
  if (_viscosity == 0)
  paramError("viscosity", "The viscosity must be a non-zero real number.");

}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()
{
  return (_permeability / _viscosity) * _grad_u[_qp];
}
