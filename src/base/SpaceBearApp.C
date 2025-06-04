#include "SpaceBearApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
SpaceBearApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

SpaceBearApp::SpaceBearApp(InputParameters parameters) : MooseApp(parameters)
{
  SpaceBearApp::registerAll(_factory, _action_factory, _syntax);
}

SpaceBearApp::~SpaceBearApp() {}

void
SpaceBearApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAllObjects<SpaceBearApp>(f, af, syntax);
  Registry::registerObjectsTo(f, {"SpaceBearApp"});
  Registry::registerActionsTo(af, {"SpaceBearApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
SpaceBearApp::registerApps()
{
  registerApp(SpaceBearApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
SpaceBearApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  SpaceBearApp::registerAll(f, af, s);
}
extern "C" void
SpaceBearApp__registerApps()
{
  SpaceBearApp::registerApps();
}
