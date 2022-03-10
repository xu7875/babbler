[Mesh]
        type = GeneratedMesh
        dim = 2
        nx = 100
        ny = 10
        xmax = 0.304
        ymax = 0.0257
[]

[Problem]
        type = FEProblem
        coord_type = RZ
        rz_coord_axis = X
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
        [inlet]
                type = ADDirichletBC
                variable = pressure
                boundary = left
                value = 4000
        []
        [outlet]
                type = ADDirichletBC
                variable = pressure
                boundary = right
                value = 0
        []
[]

[Executioner]
  type = Steady # Steady state problem
  solve_type = NEWTON # Perform a Newton solve

  # Set PETSc parameters to optimize solver efficiency
  petsc_options_iname = '-pc_type -pc_hypre_type' # PETSc option pairs with values below
  petsc_options_value = ' hypre    boomeramg'
[]

[Outputs]
        exodus = true
[]
