# Copyright 2016 PDFium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

{
  'variables': {
    'pdf_enable_v8%': 1,
    'pdf_enable_xfa%': 0,  # Set to 1 in standalone builds by standalone.gypi.
  },
  'target_defaults': {
    'defines' : [
      'PNG_PREFIX',
      'PNGPREFIX_H',
      'PNG_USE_READ_MACROS',
    ],
    'include_dirs': [
      # This is implicit in GN.
      '<(DEPTH)',
    ],
    'conditions': [
      ['pdf_enable_v8==1', {
        'defines': [
          'PDF_ENABLE_V8',
        ],
        'include_dirs': [
          '<(DEPTH)/v8',
          '<(DEPTH)/v8/include',
        ],
      }],
      ['pdf_enable_xfa==1', {
        'defines': [
          'PDF_ENABLE_XFA',
        ],
      }],
    ],
  },
  'conditions': [
    ['pdf_enable_xfa==1 and OS!="win"', {
      'targets': [
        {
          'target_name': 'pdf_fm2js_fuzzer',
          'type': 'executable',
          'dependencies': [
            '../../pdfium.gyp:pdfium',
          ],
          'sources': [
            'pdf_fm2js_fuzzer.cc',
            'unittest_main.cc',
          ],
        },
        {
          'target_name': 'pdf_xml_fuzzer',
          'type': 'executable',
          'dependencies': [
            '../../pdfium.gyp:pdfium',
          ],
          'sources': [
            'pdf_xml_fuzzer.cc',
            'unittest_main.cc',
          ],
        },
      ],
    }],
  ]
}
