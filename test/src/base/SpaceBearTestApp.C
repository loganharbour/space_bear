//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "SpaceBearTestApp.h"
#include "SpaceBearApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
SpaceBearTestApp::validParams()
{
  InputParameters params = SpaceBearApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SpaceBearTestApp::SpaceBearTestApp(InputParameters parameters) : MooseApp(parameters)
{
  SpaceBearTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

SpaceBearTestApp::~SpaceBearTestApp() {}

void
SpaceBearTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  SpaceBearApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"SpaceBearTestApp"});
    Registry::registerActionsTo(af, {"SpaceBearTestApp"});
  }
}

void
SpaceBearTestApp::registerApps()
{
  registerApp(SpaceBearApp);
  registerApp(SpaceBearTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
SpaceBearTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SpaceBearTestApp::registerAll(f, af, s);
}
extern "C" void
SpaceBearTestApp__registerApps()
{
  SpaceBearTestApp::registerApps();
}
