/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>

#include <api/script/objcontroller.h>
#include "h_layout.h"

H_Layout::H_Layout(ScriptObject *o) : H_Group(o) {
  inited = 0;
  obj = NULL;
  H_hook(o);
}

H_Layout::H_Layout() {
  inited = 0;
  obj = NULL;
}

void H_Layout::H_hook(ScriptObject *o) {
  ASSERT(!inited);
  ScriptObjectController *controller = o->vcpu_getController();
  obj = controller->cast(o, layoutGuid);
  if (obj != o && obj != NULL)
    o = obj;
  else
    obj = NULL;

  addMonitorObject(o, &layoutGuid);

  int iter = WASABI_API_APP->app_getInitCount();
  if (!loaded || loaded != iter) {
    ondock_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onDock", this);
    onundock_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onUndock", this);
    onscale_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onScale", this);
    onmove_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onMove", this);
    onendmove_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onEndMove", this);
    onuserresize_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onUserResize", this);
    onmouseenterlayout_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onMouseEnterLayout", this);
    onmouseleavelayout_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onMouseLeaveLayout", this);
    onsnapadjustchanged_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onSnapAdjustChanged", this);
    loaded = 1;
  }
  inited=1;
}

H_Layout::~H_Layout() {
  if (!inited) return;
  WASABI_API_MAKI->maki_remDlfRef(this);
}

ScriptObject *H_Layout::getHookedObject() {
  if (obj != NULL) return obj;
  return H_LAYOUT_PARENT::getHookedObject();
}

int H_Layout::eventCallback(ScriptObject *object, int dlfid, scriptVar **params, int nparams) {
  if (object != getHookedObject()) return 0;
  if (H_LAYOUT_PARENT::eventCallback(object, dlfid, params, nparams)) return 1;
  if (dlfid == ondock_id) { hook_onDock(); return 1; }
  if (dlfid == onundock_id) { hook_onUndock(); return 1; }
  if (dlfid == onscale_id) { hook_onScale(GET_SCRIPT_DOUBLE(*params[0])); return 1; }
  if (dlfid == onmove_id) { hook_onMove(); return 1; }
  if (dlfid == onendmove_id) { hook_onEndMove(); return 1; }
  if (dlfid == onuserresize_id) { hook_onUserResize(GET_SCRIPT_INT(*params[0]), GET_SCRIPT_INT(*params[1]), GET_SCRIPT_INT(*params[2]), GET_SCRIPT_INT(*params[3])); return 1; }
  if (dlfid == onmouseenterlayout_id) { hook_onMouseEnterLayout(); return 1; }
  if (dlfid == onmouseleavelayout_id) { hook_onMouseLeaveLayout(); return 1; }
  if (dlfid == onsnapadjustchanged_id) { hook_onSnapAdjustChanged(); return 1; }
  return 0;
}

int H_Layout::ondock_id=0;
int H_Layout::onundock_id=0;
int H_Layout::onscale_id=0;
int H_Layout::onmove_id=0;
int H_Layout::onendmove_id=0;
int H_Layout::onuserresize_id=0;
int H_Layout::onmouseenterlayout_id=0;
int H_Layout::onmouseleavelayout_id=0;
int H_Layout::onsnapadjustchanged_id=0;
int H_Layout::loaded=0;
