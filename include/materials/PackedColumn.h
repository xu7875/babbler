#pragma once

#include "Material.h"

// A helper class from MOOSE that linearly interpolates abscissa-ordinate pairs
#include "LinearInterpolation.h"

/**
 * Computes the permeability of a porous medium made up of packed steel spheres of a specified
 * diameter in accordance with Pamuk and Ozdemir (2012). This also provides a specified dynamic
 * viscosity of the fluid in the medium.
 */
class PackedColumn : public Material
{
public:
  static InputParameters validParams();

  PackedColumn(const InputParameters & parameters);

protected:
  /// Necessary override. This is where the property values are set.
  virtual void computeQpProperties() override;


  bool initInputData(const std::string & param_name, ADLinearInterpolation & interp);

  /// The radius of the spheres in the column
  const Function & _input_radius;
  /// The input porosity
  const Function & _input_porosity;
  /// Temperature
  const ADVariableValue & _temperature;

  /// Compute permeability based on the radius (mm)
  LinearInterpolation _permeability_interpolation;

  /// Fluid viscosity
  bool _use_fluid_mu_interp;
  const Real & _fluid_mu;
  ADLinearInterpolation _fluid_mu_interpolation;

  /// Fluid thermal conductivity
  bool _use_fluid_k_interp = false;
  const Real & _fluid_k;
  ADLinearInterpolation _fluid_k_interpolation;

  /// Fluid density
  bool _use_fluid_rho_interp = false;
  const Real & _fluid_rho;
  ADLinearInterpolation _fluid_rho_interpolation;

  /// Fluid specific heat
  bool _use_fluid_cp_interp;
  const Real & _fluid_cp;
  ADLinearInterpolation _fluid_cp_interpolation;

  /// Solid thermal conductivity
  bool _use_solid_k_interp = false;
  const Real & _solid_k;
  ADLinearInterpolation _solid_k_interpolation;

  /// Solid density
  bool _use_solid_rho_interp = false;
  const Real & _solid_rho;
  ADLinearInterpolation _solid_rho_interpolation;

  /// Fluid specific heat
  bool _use_solid_cp_interp;
  const Real & _solid_cp;
  ADLinearInterpolation _solid_cp_interpolation;

  /// The permeability (K)
  ADMaterialProperty<Real> & _permeability;

  /// The porosity (eps)
  ADMaterialProperty<Real> & _porosity;

  /// The viscosity of the fluid (mu)
  ADMaterialProperty<Real> & _viscosity;

  /// The bulk thermal conductivity
  ADMaterialProperty<Real> & _thermal_conductivity;

  /// The bulk heat capacity
  ADMaterialProperty<Real> & _specific_heat;

  /// The bulk density
  ADMaterialProperty<Real> & _density;
};
