/* This file was generated by Maki Compiler, do not edit manually */

#include <precomp.h>

#include <api/script/objcontroller.h>
#include "h_querylist.h"

H_QueryList::H_QueryList(ScriptObject *o) : H_GuiObject(o) {
  inited = 0;
  obj = NULL;
  H_hook(o);
}

H_QueryList::H_QueryList() {
  inited = 0;
  obj = NULL;
}

void H_QueryList::H_hook(ScriptObject *o) {
  ASSERT(!inited);
  ScriptObjectController *controller = o->vcpu_getController();
  obj = controller->cast(o, queryListGuid);
  if (obj != o && obj != NULL)
    o = obj;
  else
    obj = NULL;

  addMonitorObject(o, &queryListGuid);
  if (loaded == 0) {
    onresetquery_id= WASABI_API_MAKI->maki_addDlfRef(o->vcpu_getController(), L"onResetQuery", this);
    loaded = 1;
  }
  inited=1;
}

H_QueryList::~H_QueryList() {
  if (!inited) return;
  WASABI_API_MAKI->maki_remDlfRef(this);
}

ScriptObject *H_QueryList::getHookedObject() {
  if (obj != NULL) return obj;
  return H_QUERYLIST_PARENT::getHookedObject();
}

int H_QueryList::eventCallback(ScriptObject *object, int dlfid, scriptVar **params, int nparams) {
  if (object != getHookedObject()) return 0;
  if (H_QUERYLIST_PARENT::eventCallback(object, dlfid, params, nparams)) return 1;
  if (dlfid == onresetquery_id) { hook_onResetQuery(); return 1; }
  return 0;
}

int H_QueryList::onresetquery_id=0;
int H_QueryList::loaded=0;
