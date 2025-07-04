#pragma once

#include "ADMaterial.h"

class UnobtaniumMaterial : public ADMaterial
{
public:
  static InputParameters validParams();

  UnobtaniumMaterial(const InputParameters & parameters);

protected:
  /// Necessary override. This is where the values of the properties are computed.
  virtual void computeQpProperties() override;

  /// The value of k
  ADMaterialProperty<Real> & _k;

  /// The variable gradient
  const ADVariableGradient & _grad_u;
};
