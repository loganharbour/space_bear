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
};
