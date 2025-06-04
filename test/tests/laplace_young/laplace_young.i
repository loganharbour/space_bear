[Mesh]
  [gmg]
    type = GeneratedMeshGenerator
    dim = 2
    nx = 50
    ny = 50
  []
[]

[Variables]
  [u]
  []
[]

[Kernels]
  [diffusion]
    type = ADMatDiffusion
    variable = u
    diffusivity = k
  []
  [reaction]
    type = ADReaction
    variable = u
  []
[]

[BCs]
  [neumann]
    type = ADNeumannBC
    boundary = 'top right bottom left'
    variable = u
    value = 0.2
  []
[]

[Materials]
  [unob]
    type = UnobtaniumMaterial
    variable = u
  []
[]

[Executioner]
  type = Steady
[]

[Outputs]
  exodus = true
[]
