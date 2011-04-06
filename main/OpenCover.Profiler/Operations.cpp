#include "StdAfx.h"
#include "Operations.h"

MapCanonicalNameOperationDetails Operations::m_mapNameOperationDetails;
MapOpsOperationDetails Operations::m_mapOpsOperationDetails;

#define nInlineNone           Null
#define nShortInlineVar       Byte
#define nShortInlineI         Byte
#define nInlineI              Dword
#define nInlineI8             Qword
#define nShortInlineR         Dword
#define nInlineR              Qword
#define nInlineMethod         Dword
#define nInlineSig            Dword
#define nInlineBrTarget       Dword
#define nInlineType           Dword
#define nInlineVar            Word
#define nShortInlineBrTarget  Byte
#define nInlineTok            Dword
#define nInlineField          Dword
#define nInlineSwitch         Dword
#define nInlineString         Dword

Operations Operations::m_operations;

Operations::Operations()
{
#define OPDEF(name, str, decs, incs, args, optp, stdlen, stdop1, stdop2, flow) \
    { \
    OperationDetails operation = {name, args, n##args, flow, stdlen, stdop1, stdop2, optp, _T(str)}; \
    m_mapNameOperationDetails[name] = operation;  \
    m_mapOpsOperationDetails[MAKEWORD(stdop1,stdop2)] = operation;  \
    }
#include "opcode.def"
#undef OPDEF
}
