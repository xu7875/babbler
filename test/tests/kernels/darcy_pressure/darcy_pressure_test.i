[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [pressure]
  []
[]

[Kernels]
  [diffusion]
    type = DarcyPressure # Zero-gravity, divergence-free form of Darcy's law
    variable = pressure # Operate on the "pressure" variable from above
  []
[]

[Materials]
  [filter]
    type = PackedColumn # Provides permeability and viscosity of water through packed 1mm spheres
  []
[]

[BCs]
  [left]
    type = ADDirichletBC
    variable = pressure
    boundary = left
    value = 0
  []

  [right]
    type = ADDirichletBC
    variable = pressure
    boundary = right
    value = 1
  []
[]

[Executioner]
  type = Steady
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
