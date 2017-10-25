// Copyright 2014 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "fpdfsdk/javascript/JS_Object.h"

#include "fpdfsdk/javascript/JS_Define.h"
#include "fpdfsdk/javascript/cjs_event_context.h"

CJS_EmbedObj::CJS_EmbedObj(CJS_Object* pJSObject) : m_pJSObject(pJSObject) {}

CJS_EmbedObj::~CJS_EmbedObj() {
}

CJS_Object::CJS_Object(v8::Local<v8::Object> pObject) {
  m_pIsolate = pObject->GetIsolate();
  m_pV8Object.Reset(m_pIsolate, pObject);
}

CJS_Object::~CJS_Object() {}

void CJS_Object::InitInstance(IJS_Runtime* pIRuntime) {}
