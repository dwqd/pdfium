// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FXCRT_CSS_CFX_CSSSYNTAXPARSER_H_
#define CORE_FXCRT_CSS_CFX_CSSSYNTAXPARSER_H_

#include <stack>

#include "core/fxcrt/css/cfx_cssexttextbuf.h"
#include "core/fxcrt/css/cfx_csstextbuf.h"
#include "core/fxcrt/fx_string.h"

#define CFX_CSSSYNTAXCHECK_AllowCharset 1
#define CFX_CSSSYNTAXCHECK_AllowImport 2

enum class CFX_CSSSyntaxStatus : uint8_t {
  kError,
  kEOS,
  kNone,
  kStyleRule,
  kSelector,
  kDeclOpen,
  kDeclClose,
  kPropertyName,
  kPropertyValue,
};

class CFX_CSSSyntaxParser {
 public:
  CFX_CSSSyntaxParser(const wchar_t* pBuffer, int32_t iBufferSize);
  ~CFX_CSSSyntaxParser();

  void SetParseOnlyDeclarations();
  CFX_CSSSyntaxStatus DoSyntaxParse();
  WideStringView GetCurrentString() const;

 private:
  enum class SyntaxMode : uint8_t {
    kRuleSet,
    kComment,
    kUnknownRule,
    kSelector,
    kPropertyName,
    kPropertyValue,
  };

  void SwitchMode(SyntaxMode eMode);
  int32_t SwitchToComment();

  bool RestoreMode();
  void AppendCharIfNotLeadingBlank(wchar_t wch);
  void SaveTextData();

  bool m_bError = false;
  SyntaxMode m_eMode = SyntaxMode::kRuleSet;
  int32_t m_iTextDataLen = 0;
  CFX_CSSTextBuf m_Output;
  CFX_CSSExtTextBuf m_Input;
  std::stack<SyntaxMode> m_ModeStack;
};

#endif  // CORE_FXCRT_CSS_CFX_CSSSYNTAXPARSER_H_
