// Reconstruction batch mass_0275 — Sid Meier's Pirates! (2004), PE32 i386
// Source reconstruction from Ghidra 12.2 pseudocode corpus.
// Receiver convention: provider in_ECX pointer fields are exposed as an
// explicit `void* self` (or int* self) parameter for the scanner state object.
// Scans operate between the position field at self+0 and the end pointer
// stored at self+4 (see ScanEnd).
#include <cstdint>
#include <cstddef>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <malloc.h>
#include <windows.h>

extern void* FUN_0065aaac(size_t nmemb, size_t size);
extern int FUN_0060f548(int key, int* outIndex);
extern int FUN_0060f6ce(const char* msg);
extern void FUN_0060fcd3(int ctx, const void* fileInfo, uint32_t code,
                         const char* fmt, ...);
extern void FUN_0060f81e(void);
extern uint32_t FUN_0060fa04(void* self, char* p, void** out);
extern int FUN_00610287(void* self, char* p, uint32_t* out);
extern int FUN_0060f879(void* self, char* p, double* out);
extern int FUN_00610165(void* self, char* p, int* out);
extern int FUN_00610209(void* self, char* p, uint32_t* out);
extern int FUN_0060fbe0(void* self, char* p, uint32_t* out);
extern int FUN_0060fb96(void* self, char* p, uint32_t* out);
extern uint32_t FUN_0060fa88(void* self, char* p, char* out);
extern char* FUN_006104c3(void* self, char* p, uint32_t* out);
extern char* FUN_006105c8(void* self, char* p, int* out);
extern int FUN_0061060b(void* self, char* p, uint32_t* out);
extern uint32_t FUN_0061003c(void* self);
extern int FUN_0061032a(void* self, char* p, int* out);
extern int FUN_005f7fa4(const char* text, int one, void* out);

static inline char* ScanEnd(void* self) {
  return *reinterpret_cast<char**>(reinterpret_cast<char*>(self) + 4);
}

// 0x60f879 — observed shape: floating-point literal scanner.
// Consumes digits, one fractional part (identifier '.' + digits), an
// exponent ('e' digits | 'e' '-' digits). Leading '.' + digits form also
// accepted. On success copies the token to a stack buffer, atof()s it
// into *param_2 and returns the consumed length; returns 0 on failure.
int FUN_0060f879(void* self, char* param_1, double* param_2) {
  bool bVar1 = false;
  int iVar2;
  char* pcVar4;
  char* pcVar5;

  if (param_1 < ScanEnd(self)) {
    iVar2 = isdigit((int)*param_1);
    pcVar4 = param_1;
    if (iVar2 == 0) goto LAB_0060f89e;
    do {
      pcVar5 = pcVar4;
      pcVar4 = pcVar5 + 1;
      if (ScanEnd(self) <= pcVar4) break;
      iVar2 = isdigit((int)*pcVar4);
    } while (iVar2 != 0);
    if ((pcVar4 < ScanEnd(self)) && (*pcVar4 == '.')) {
      pcVar4 = pcVar5 + 2;
      if (pcVar4 < ScanEnd(self)) {
        do {
          iVar2 = isdigit((int)*pcVar4);
          if (iVar2 == 0) break;
          pcVar4 = pcVar4 + 1;
        } while (pcVar4 < ScanEnd(self));
      }
    } else {
      bVar1 = true;
    }
LAB_0060f922:;
    pcVar5 = pcVar4 + 1;
    if (pcVar5 < ScanEnd(self)) {
      iVar2 = tolower((int)*pcVar4);
      if (iVar2 != 0x65) goto LAB_0060f961;
      iVar2 = isdigit((int)*pcVar5);
      if (iVar2 == 0) goto LAB_0060f961;
      for (pcVar4 = pcVar4 + 2; pcVar4 < ScanEnd(self); pcVar4 = pcVar4 + 1) {
        iVar2 = isdigit((int)*pcVar4);
        if (iVar2 == 0) break;
      }
    } else {
LAB_0060f961:;
      if (pcVar4 + 2 < ScanEnd(self)) {
        iVar2 = tolower((int)*pcVar4);
        if ((iVar2 == 0x65) && (*pcVar5 == '-')) {
          iVar2 = isdigit((int)pcVar4[2]);
          if (iVar2 != 0) {
            for (pcVar4 = pcVar4 + 3; pcVar4 < ScanEnd(self); pcVar4 = pcVar4 + 1) {
              iVar2 = isdigit((int)*pcVar4);
              if (iVar2 == 0) break;
            }
            goto LAB_0060f9ad;
          }
        }
      }
      if (bVar1) goto LAB_0060f9f8;
    }
LAB_0060f9ad:;
    if (param_2 != (double*)0x0) {
      uint32_t uVar6 = (int)(intptr_t)(pcVar4 - param_1);
      char* pcVar7 = (char*)_alloca(uVar6 + 1);
      char* pcVar4b = param_1;
      for (uint32_t uVar3 = uVar6 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(uint32_t*)pcVar7 = *(uint32_t*)pcVar4b;
        pcVar4b = pcVar4b + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uint32_t uVar3 = uVar6 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar4b;
        pcVar4b = pcVar4b + 1;
        pcVar7 = pcVar7 + 1;
      }
      *(uint8_t*)((int)(intptr_t)pcVar7 - 1 + 1) = 0;
      double dVar8 = atof((char*)((int)(intptr_t)pcVar7 - uVar6));
      *param_2 = dVar8;
    }
    iVar2 = (int)(intptr_t)(pcVar4 - param_1);
    return iVar2;
  }
LAB_0060f89e:;
  if ((param_1 + 1 < ScanEnd(self)) && (*param_1 == '.')) {
    iVar2 = isdigit((int)param_1[1]);
    if (iVar2 != 0) {
      for (pcVar4 = param_1 + 2; pcVar4 < ScanEnd(self); pcVar4 = pcVar4 + 1) {
        iVar2 = isdigit((int)*pcVar4);
        if (iVar2 == 0) break;
      }
      goto LAB_0060f922;
    }
  }
LAB_0060f9f8:;
  return 0;
}

// 0x60fa04 — observed shape: identifier scanner.
// If *param_1 is alpha or '_', consumes isalnum or '_' continuation,
// duplicates the span via FUN_0065aaac(len+1, 1) and stores the copy in
// *param_2. Returns the span length, or 0 when no identifier starts here.
uint32_t FUN_0060fa04(void* self, char* param_1, void** param_2) {
  int iVar1;
  char* pcVar3;

  if ((param_1 < ScanEnd(self)) &&
      ((iVar1 = isalpha((int)*param_1), pcVar3 = param_1, iVar1 != 0 ||
        (*param_1 == '_')))) {
    do {
      pcVar3 = pcVar3 + 1;
      if (ScanEnd(self) <= pcVar3) break;
      iVar1 = isalnum((int)*pcVar3);
    } while ((iVar1 != 0) || (*pcVar3 == '_'));
    uint32_t uVar4 = (uint32_t)(int)(intptr_t)(pcVar3 - param_1);
    pcVar3 = (char*)FUN_0065aaac(uVar4 + 1, 1);
    if (pcVar3 != (char*)0x0) {
      char* pcVar5 = pcVar3;
      char* pcVar1 = param_1;
      for (uint32_t uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(uint32_t*)pcVar5 = *(uint32_t*)pcVar1;
        pcVar1 = pcVar1 + 4;
        pcVar5 = pcVar5 + 4;
      }
      for (uint32_t uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = *pcVar1;
        pcVar1 = pcVar1 + 1;
        pcVar5 = pcVar5 + 1;
      }
      pcVar3[uVar4] = '\0';
      *param_2 = pcVar3;
      return uVar4;
    }
  }
  return 0;
}

// 0x60fa88 — observed shape: operator / punctuation token scanner.
// Fills param_2 with the operator text (pre-zeroed to 4 bytes) and returns
// its length (1, 2 or 3). Handles "##"/"#@", "<="/">="/">"|="/" (with
// optional trailing '='), "-", duplicated punctuation, "=="-style doubled
// chars, ".."/"..." and plain single characters.
uint32_t FUN_0060fa88(void* self, char* param_1, char* param_2) {
  char* pcVar1;
  char cVar2;
  char cVar3;

  param_2[0] = '\0';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  *param_2 = *param_1;
  pcVar1 = param_1 + 1;
  if (ScanEnd(self) <= pcVar1) {
    return 1;
  }
  cVar2 = *param_1;
  if ((cVar2 == '#') && ((cVar3 = *pcVar1, cVar3 == '#' || (cVar3 == '@')))) {
    param_2[1] = cVar3;
    return 2;
  }
  cVar3 = *pcVar1;
  if (cVar2 != cVar3) {
    if (cVar3 == '=') {
      if (cVar2 < '0') {
        if ((cVar2 != '/') && (cVar2 != '!') &&
            ((cVar2 < '%') ||
             (('&' < cVar2) &&
              ((cVar2 < '*') || (('+' < cVar2) && (cVar2 != '-')))))) {
          return 1;
        }
      } else if ((cVar2 != '<') && (cVar2 != '>') && (cVar2 != '^') &&
                 (cVar2 != '|')) {
        return 1;
      }
      param_2[1] = '=';
      return 2;
    }
    if (cVar2 != '-') {
      return 1;
    }
    if (cVar3 == '>') {
      param_2[1] = '>';
      return 2;
    }
    return 1;
  }
  if (cVar2 < ';') {
    if ((cVar2 != ':') && (cVar2 != '&') && (cVar2 != '+') && (cVar2 != '-')) {
      if (cVar2 != '.') {
        return 1;
      }
      param_1 = param_1 + 2;
      if (ScanEnd(self) <= param_1) {
        return 1;
      }
      if (*param_1 == '.') {
        param_2[1] = cVar3;
        param_2[2] = *param_1;
        return 3;
      }
      return 1;
    }
  } else {
    if (cVar2 == '<') {
LAB_0060fb19:;
      param_2[1] = cVar3;
      if (ScanEnd(self) <= param_1 + 2) {
        return 2;
      }
      if (param_1[2] == '=') {
        param_2[2] = '=';
        return 3;
      }
      return 2;
    }
    if (cVar2 != '=') {
      if (cVar2 == '>') goto LAB_0060fb19;
      if (cVar2 != '|') {
        return 1;
      }
    }
  }
  param_2[1] = cVar3;
  return 2;
}

// 0x60fb96 — observed shape: floating suffix scanner ('f'/'h').
// 'f' reports type 7, 'h' reports type 6, otherwise type 5 is stored in
// *param_2 and no characters are consumed.
int FUN_0060fb96(void* self, char* param_1, uint32_t* param_2) {
  uint32_t uVar3 = 5;
  char* pcVar2;

  if (ScanEnd(self) <= param_1) {
    return 0;
  }
  int iVar1 = tolower((int)*param_1);
  if (iVar1 == 0x66) {
    uVar3 = 7;
  } else {
    pcVar2 = param_1;
    if (iVar1 != 0x68) goto LAB_0060fbcc;
    uVar3 = 6;
  }
  pcVar2 = param_1 + 1;
LAB_0060fbcc:;
  if (param_2 != (uint32_t*)0x0) {
    *param_2 = uVar3;
  }
  return (int)(intptr_t)(pcVar2 - param_1);
}

// 0x60fbe0 — observed shape: integer suffix scanner ('u'/'l').
// Consumes 'u' then an optional 'l'/'L'. Stores 4 into *param_2 when 'u'
// was seen, 3 when 'l' was seen without 'u'. Returns chars consumed.
int FUN_0060fbe0(void* self, char* param_1, uint32_t* param_2) {
  bool bVar2 = false;
  bool bVar1 = false;
  char* pcVar4 = param_1;

  if (param_1 < ScanEnd(self)) {
    do {
      if (bVar1) {
LAB_0060fc1b:;
        if (bVar2) break;
        int iVar3 = tolower((int)*pcVar4);
        if (iVar3 != 0x6c) break;
        bVar2 = true;
      } else {
        int iVar3 = tolower((int)*pcVar4);
        if (iVar3 != 0x75) goto LAB_0060fc1b;
        bVar1 = true;
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < ScanEnd(self));
  }
  if (param_2 != (uint32_t*)0x0) {
    if (bVar1) {
      *param_2 = 4;
    } else if (bVar2) {
      *param_2 = 3;
    }
  }
  return (int)(intptr_t)(pcVar4 - param_1);
}

// 0x60fc69 — observed shape: option-flag setter over the flag word array.
// Resolves the option name to an index with FUN_0060f548, then updates the
// four-bit flag field at self+0x1c -> (index*4). A value of 0xff clears
// bit 0x20 and sets bit 1; 0x10 sets bit 0x10; anything else clears the low
// nibble and ORs the masked value.
void FUN_0060fc69(void* self, int param_1, uint32_t param_2) {
  int in_ECX = (int)(intptr_t)self;
  int iVar1 = FUN_0060f548(param_1, &param_1);
  if (-1 < iVar1) {
    if (param_2 == 0xff) {
      uint32_t* puVar2 = (uint32_t*)(*(int*)(in_ECX + 0x1c) + param_1 * 4);
      *puVar2 = *puVar2 & 0x20;
      puVar2 = (uint32_t*)(param_1 * 4 + *(int*)(in_ECX + 0x1c));
      *puVar2 = *puVar2 | 1;
    } else if (param_2 == 0x10) {
      uint32_t* puVar2 = (uint32_t*)(*(int*)(in_ECX + 0x1c) + param_1 * 4);
      *puVar2 = *puVar2 | 0x10;
    } else {
      uint32_t* puVar2 = (uint32_t*)(*(int*)(in_ECX + 0x1c) + param_1 * 4);
      *puVar2 = *puVar2 & 0xfffffff0;
      puVar2 = (uint32_t*)(param_1 * 4 + *(int*)(in_ECX + 0x1c));
      *puVar2 = *puVar2 | (param_2 & 0xf);
    }
  }
  return;
}

// 0x60fcd3 — observed shape: diagnostic message formatter.
// Builds "file(includedFrom): error X<code>: <formatted text>\n" into a
// 4092-byte stack buffer, then emits it through FUN_0060f6ce and bumps the
// message counter at self+8. varargs forwarded to _vsnprintf.
void FUN_0060fcd3(int param_1, int param_2, int param_3, char* param_4,
                  ...) {
  char local_1004[4092];
  char* _Dest = local_1004;
  size_t _Count = 0xffe;
  va_list ap;
  va_start(ap, param_4);
  if (param_2 != 0) {
    if (*(int*)(param_2 + 0x10) != 0) {
      int iVar1 = _snprintf(_Dest, 0xffe, "%s", *(int*)(param_2 + 0x10));
      if (iVar1 < 0) {
        iVar1 = 0xffe;
      }
      _Dest = local_1004 + iVar1;
      _Count = 0xffe - iVar1;
    }
    int iVar1 = *(int*)(param_2 + 0x14);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    size_t sVar2 = (size_t)_snprintf(_Dest, _Count, "(%u): ", iVar1);
    if ((int)sVar2 < 0) {
      sVar2 = _Count;
    }
    _Dest = _Dest + sVar2;
    _Count = _Count - sVar2;
  }
  if (param_3 != 0) {
    size_t sVar2 = (size_t)_snprintf(_Dest, _Count, "error X%u: ", param_3);
    if ((int)sVar2 < 0) {
      sVar2 = _Count;
    }
    _Dest = _Dest + sVar2;
    _Count = _Count - sVar2;
  }
  size_t sVar2 = (size_t)_vsnprintf(_Dest, _Count, param_4, ap);
  if ((int)sVar2 < 0) {
    sVar2 = _Count;
  }
  _Dest[sVar2] = '\n';
  (_Dest + sVar2)[1] = '\0';
  va_end(ap);
  *(int*)(param_1 + 8) = *(int*)(param_1 + 8) + 1;
  FUN_0060f6ce(local_1004);
  return;
}

// 0x60fd9a — observed shape: severity-aware diagnostic (error vs warning).
// Looks the option index up, reads the flag word; a low nibble of 0xf is an
// error (counted at self+8), otherwise a warning gated by the warning mask
// at self+0x10 and the already-reported 0x20 bit; an eligible warning sets
// the 0x20 bit in the flag word and is counted at self+0xc. Formats
// "file(line): <severity> X<code>: text\n" and returns FUN_0060f6ce result.
int FUN_0060fd9a(int param_1, int param_2, int param_3, char* param_4,
                 ...) {
  char local_1010[4096];
  uint32_t local_10;
  char* _Dest = local_1010;
  size_t _Count = 0xffe;
  int local_8;
  va_list ap;
  va_start(ap, param_4);
  int iVar1 = FUN_0060f548(param_3, &local_8);
  if (-1 < iVar1) {
    iVar1 = local_8 * 4;
    local_10 = *(uint32_t*)(iVar1 + *(int*)(param_1 + 0x1c));
    uint32_t uVar2 = local_10 & 0xf;
    int* severity_count;
    const char* local_c;
    if (uVar2 == 0xf) {
      severity_count = (int*)(param_1 + 8);
      local_c = "error";
    } else {
      severity_count = (int*)(param_1 + 0xc);
      local_c = "warning";
      if ((((*(uint32_t*)(param_1 + 0x10) == 0) || (uVar2 == 0)) ||
           (*(uint32_t*)(param_1 + 0x10) < uVar2)) ||
          (((local_10 & 0x10) != 0 && ((local_10 & 0x20) != 0)))) {
        va_end(ap);
        return 0;
      }
      uint32_t* puVar3 = (uint32_t*)(*(int*)(param_1 + 0x1c) + iVar1);
      *puVar3 = *puVar3 | 0x20;
    }
    if (param_2 != 0) {
      if (*(int*)(param_2 + 0x10) != 0) {
        iVar1 = _snprintf(local_1010, 0xffe, "%s", *(int*)(param_2 + 0x10));
        if (iVar1 < 0) {
          iVar1 = 0xffe;
        }
        _Dest = local_1010 + iVar1;
        _Count = 0xffe - iVar1;
      }
      iVar1 = *(int*)(param_2 + 0x14);
      if (iVar1 == 0) {
        iVar1 = 1;
      }
      size_t sVar4 = (size_t)_snprintf(_Dest, _Count, "(%u): ", iVar1);
      if ((int)sVar4 < 0) {
        sVar4 = _Count;
      }
      _Dest = _Dest + sVar4;
      _Count = _Count - sVar4;
    }
    if (param_3 != 0) {
      size_t sVar4 = (size_t)_snprintf(_Dest, _Count, "%s X%u: ", local_c,
                                       param_3);
      if ((int)sVar4 < 0) {
        sVar4 = _Count;
      }
      _Dest = _Dest + sVar4;
      _Count = _Count - sVar4;
    }
    size_t sVar4 = (size_t)_vsnprintf(_Dest, _Count, param_4, ap);
    if ((int)sVar4 < 0) {
      sVar4 = _Count;
    }
    _Dest[sVar4] = '\n';
    (_Dest + sVar4)[1] = '\0';
    *severity_count = *severity_count + 1;
    va_end(ap);
    iVar1 = FUN_0060f6ce(local_1010);
    return iVar1;
  }
  va_end(ap);
  return iVar1;
}

// 0x61003c — observed shape: whitespace/comment skipper.
// Advances self[0] (cursor) while the next character is '\n' (bumping the
// line counter self[7] and returning 1), whitespace or 0x09..0x0d, a //
// line comment (consumed by FUN_0060f81e), a /* block comment (line counter
// updated per '\n', code 0x3e9 when unterminated), an optional-';' line
// comment when flag bit 2 of self[10] is set, or a backslash-newline
// continuation (also consuming \r\n). Returns 1 if any line break was seen.
uint32_t FUN_0061003c(void* selfp) {
  uint32_t* in_ECX = (uint32_t*)selfp;
  uint32_t local_8 = 0;

  if (*in_ECX < in_ECX[1]) {
    do {
      char* pcVar3 = (char*)*in_ECX;
      char cVar1 = *pcVar3;
      if (cVar1 == '\n') {
        pcVar3 = pcVar3 + 1;
        in_ECX[7] = in_ECX[7] + 1;
        local_8 = 1;
LAB_00610151:;
        *in_ECX = (uint32_t)(uintptr_t)pcVar3;
      } else {
        if ((cVar1 == ' ') || (('\b' < cVar1 && (cVar1 < '\x0e')))) {
          pcVar3 = pcVar3 + 1;
          goto LAB_00610151;
        }
        if (cVar1 == '/') {
          if ((pcVar3 + 1 < (char*)in_ECX[1]) && (pcVar3[1] == '/'))
            goto LAB_0061009a;
          char* pcVar2 = (char*)in_ECX[1];
          if ((pcVar2 <= pcVar3 + 1) || (pcVar3[1] != '*')) goto LAB_0061010e;
          *in_ECX = (uint32_t)(uintptr_t)(pcVar3 + 2);
          if (pcVar3 + 2 < pcVar2) {
            do {
              pcVar3 = (char*)*in_ECX;
              if (((*pcVar3 == '*') && (pcVar3 + 1 < pcVar2)) &&
                  (pcVar3[1] == '/'))
                break;
              if (*pcVar3 == '\n') {
                in_ECX[7] = in_ECX[7] + 1;
              }
              *in_ECX = (uint32_t)(uintptr_t)(pcVar3 + 1);
            } while (pcVar3 + 1 < (char*)in_ECX[1]);
          }
          if ((char*)*in_ECX < pcVar2) {
            pcVar3 = (char*)*in_ECX + 2;
            goto LAB_00610151;
          }
          FUN_0060fcd3((int)in_ECX[0xc], in_ECX + 2, 0x3e9,
                       "comment continues past end of file");
        } else {
LAB_0061010e:;
          if (((in_ECX[10] & 2) == 0) || (cVar1 != ';')) {
            if (cVar1 != '\\') {
              return local_8;
            }
            if ((pcVar3 + 1 < (char*)in_ECX[1]) && (pcVar3[1] == '\n')) {
              pcVar3 = pcVar3 + 2;
            } else {
              if ((char*)in_ECX[1] <= pcVar3 + 2) {
                return local_8;
              }
              if (pcVar3[1] != '\r') {
                return local_8;
              }
              if (pcVar3[2] != '\n') {
                return local_8;
              }
              pcVar3 = pcVar3 + 3;
            }
            in_ECX[7] = in_ECX[7] + 1;
            goto LAB_00610151;
          }
LAB_0061009a:;
          FUN_0060f81e();
        }
      }
    } while (*in_ECX < in_ECX[1]);
  }
  return local_8;
}

// 0x610165 — observed shape: 0x-prefixed hexadecimal literal scanner.
// Requires "0x" followed by an xdigit. Accumulates the digits (wrapping
// 32-bit), stores the value into *param_2, and reports code 0x3ea when the
// token exceeds 10 characters. Returns 0 when the prefix does not match.
int FUN_00610165(void* self, char* param_1, int* param_2) {
  int in_ECX = (int)(intptr_t)self;
  char* pcVar4 = param_1 + 2;
  int iVar2;

  if (*(char**)(in_ECX + 4) <= pcVar4 || *param_1 != '0' || param_1[1] != 'x' ||
      !isxdigit((int)*pcVar4)) {
    return 0;
  }
  iVar2 = 0;
  while (pcVar4 < *(char**)(in_ECX + 4) && isxdigit((int)*pcVar4)) {
    char cVar1 = *pcVar4;
    iVar2 = iVar2 * 0x10;
    if (cVar1 < 'a') {
      if (cVar1 < 'A') {
        iVar2 = iVar2 + -0x30 + (int)cVar1;
      } else {
        iVar2 = iVar2 + -0x37 + (int)cVar1;
      }
    } else {
      iVar2 = iVar2 + -0x57 + (int)cVar1;
    }
    pcVar4 = pcVar4 + 1;
  }
  if (param_2 != (int*)0x0) {
    *param_2 = iVar2;
  }
  if (10 < (int)(intptr_t)(pcVar4 - param_1)) {
    FUN_0060fcd3(*(int*)(in_ECX + 0x30), in_ECX + 8, 0x3ea,
                 "hex value truncated to 32bits");
  }
  return (int)(intptr_t)(pcVar4 - param_1);
}

// 0x610209 — observed shape: octal literal scanner.
// Requires a leading '0' and consumes the following '0'..'7' digits
// (excluding the leading zero). Sets the overflow flag when shifting out
// bits 29..31, stores the accumulated value into *param_2, and reports
// code 0x3eb on overflow. Returns the consumed length (0 when no match).
int FUN_00610209(void* self, char* param_1, uint32_t* param_2) {
  int in_ECX = (int)(intptr_t)self;
  char cVar1;
  bool bVar2;
  uint32_t uVar3;
  char* pcVar5;

  if ((param_1 < *(char**)(in_ECX + 4)) && (*param_1 == '0')) {
    uVar3 = 0;
    bVar2 = false;
    pcVar5 = param_1;
    while ((pcVar5 = pcVar5 + 1, pcVar5 < *(char**)(in_ECX + 4) &&
            (cVar1 = *pcVar5, '/' < cVar1) && (cVar1 < '8'))) {
      if ((uVar3 & 0xe0000000) != 0) {
        bVar2 = true;
      }
      uVar3 = cVar1 + -0x30 + uVar3 * 8;
    }
    if (param_2 != (uint32_t*)0x0) {
      *param_2 = uVar3;
    }
    if (bVar2) {
      FUN_0060fcd3(*(int*)(in_ECX + 0x30), in_ECX + 8, 0x3eb,
                   "octal value truncated to 32bits");
    }
    return (int)(intptr_t)(pcVar5 - param_1);
  }
  return 0;
}

// 0x610287 — observed shape: decimal literal scanner.
// Requires a leading digit, accumulates base-10 with overflow detection
// (pre-multiply > 0x19999999 or wrapped add), stores the value into
// *param_2, and reports code 0x3ec on overflow.
int FUN_00610287(void* self, char* param_1, uint32_t* param_2) {
  int in_ECX = (int)(intptr_t)self;
  bool bVar1;
  uint32_t uVar5;
  char* pcVar4;

  if ((*(char**)(in_ECX + 4) <= param_1) || !isdigit((int)*param_1)) {
    return 0;
  }
  uVar5 = 0;
  bVar1 = false;
  pcVar4 = param_1;
  if (param_1 < *(char**)(in_ECX + 4)) {
    do {
      if (isdigit((int)*pcVar4) == 0) break;
      if (0x19999999 < uVar5) {
        bVar1 = true;
      }
      uint32_t uVar3 = uVar5 * 10;
      uVar5 = *pcVar4 + -0x30 + uVar3;
      if (uVar5 < uVar3) {
        bVar1 = true;
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 < *(char**)(in_ECX + 4));
  }
  if (param_2 != (uint32_t*)0x0) {
    *param_2 = uVar5;
  }
  if (bVar1) {
    FUN_0060fcd3(*(int*)(in_ECX + 0x30), in_ECX + 8, 0x3ec,
                 "decimal value truncated to 32bits");
  }
  return (int)(intptr_t)(pcVar4 - param_1);
}

// 0x61032a — observed shape: single-character / escape-sequence scanner.
// A backslash (unless flag bit 4 is set) selects the escape table a,b,f,n,
// r,t,v, a 1..3 digit octal value, or \x<hex>; otherwise the character is
// taken literally. Reports code 0x3ef when the escape runs past EOF.
// Returns the consumed character count.
int FUN_0061032a(void* self, char* param_1, int* param_2) {
  int in_ECX = (int)(intptr_t)self;
  char cVar1;
  char* pcVar4;
  char* pcVar5;

  if (*(char**)(in_ECX + 4) <= param_1) {
    return 0;
  }
  cVar1 = *param_1;
  if ((cVar1 == '\\') && ((*(uint8_t*)(in_ECX + 0x28) & 4) == 0)) {
    pcVar4 = param_1 + 1;
    if (*(char**)(in_ECX + 4) <= pcVar4) {
      FUN_0060fcd3(*(int*)(in_ECX + 0x30), in_ECX + 8, 0x3ef,
                   "character continues past end of file");
    }
    cVar1 = *pcVar4;
    if (cVar1 == 'a') {
      *param_2 = 7;
    } else if (cVar1 == 'b') {
      *param_2 = 8;
    } else if (cVar1 == 'f') {
      *param_2 = 0xc;
    } else if (cVar1 == 'n') {
      *param_2 = 10;
    } else if (cVar1 == 'r') {
      *param_2 = 0xd;
    } else if (cVar1 == 't') {
      *param_2 = 9;
    } else {
      if (cVar1 != 'v') {
        if (('/' < cVar1) && (cVar1 < '8')) {
          char* pcVar5end = *(char**)(in_ECX + 4);
          if (param_1 + 4 < *(char**)(in_ECX + 4)) {
            pcVar5end = param_1 + 4;
          }
          int iVar3 = 0;
          for (; ((pcVar4 < pcVar5end && (cVar1 = *pcVar4, '/' < cVar1)) &&
                  (cVar1 < '8'));
               pcVar4 = pcVar4 + 1) {
            iVar3 = cVar1 + -0x30 + iVar3 * 8;
          }
          *param_2 = iVar3;
          pcVar5 = pcVar4;
          goto LAB_006104b8;
        }
        if ((cVar1 == 'x') &&
            ((pcVar5 = param_1 + 2, pcVar5 < *(char**)(in_ECX + 4) &&
              (isxdigit((int)*pcVar5) != 0)))) {
          int iVar3 = 0;
          while ((pcVar5 < *(char**)(in_ECX + 4) &&
                  (isxdigit((int)*pcVar5) != 0))) {
            cVar1 = *pcVar5;
            iVar3 = iVar3 * 0x10;
            if (cVar1 < 'a') {
              if (cVar1 < 'A') {
                iVar3 = iVar3 + -0x30 + (int)cVar1;
              } else {
                iVar3 = iVar3 + -0x37 + (int)cVar1;
              }
            } else {
              iVar3 = iVar3 + -0x57 + (int)cVar1;
            }
            pcVar5 = pcVar5 + 1;
          }
          *param_2 = iVar3;
          goto LAB_006104b8;
        }
        cVar1 = *pcVar4;
        pcVar5 = param_1 + 2;
        goto LAB_006104b3;
      }
      *param_2 = 0xb;
    }
    pcVar5 = param_1 + 2;
  } else {
    pcVar5 = param_1 + 1;
LAB_006104b3:;
    *param_2 = (int)cVar1;
  }
LAB_006104b8:;
  return (int)(intptr_t)(pcVar5 - param_1);
}

// 0x6104c3 — observed shape: qualified semantic identifier ("A.B.N").
// Requires flag bit 2 of self+0x28, two leading alphas and a '.', then
// "alpha alpha . number . number|identifier", all under 0x20 characters.
// Copies the span to a stack buffer, resolves it via FUN_005f7fa4, and on
// success stores the resolved value in *param_2. Returns span length or null.
char* FUN_006104c3(void* self, char* param_1, uint32_t* param_2) {
  int in_ECX = (int)(intptr_t)self;
  char local_30[4];
  char acStack_2c[28];
  uint8_t local_10[4];
  uint32_t local_c;
  uint32_t scratch;

  char* pcVar3 = param_1;
  if ((*(uint8_t*)(in_ECX + 0x28) & 2) == 0) {
    return (char*)0x0;
  }
  char* pcVar4 = param_1 + 1;
  if ((((pcVar4 < *(char**)(in_ECX + 4)) && isalpha((int)*param_1)) &&
       isalpha((int)*pcVar4)) &&
      ((pcVar3 + 2 < *(char**)(in_ECX + 4)) && (pcVar3[2] == '.'))) {
    int iVar1 = FUN_00610287(self, pcVar3 + 3, &scratch);
    if (((iVar1 != 0) && ((scratch < 0x100 &&
         (pcVar4 = pcVar3 + 3 + iVar1, pcVar4 < *(char**)(in_ECX + 4))))) &&
        (*pcVar4 == '.')) {
      pcVar4 = pcVar4 + 1;
      iVar1 = FUN_00610287(self, pcVar4, &scratch);
      if (iVar1 == 0) {
        iVar1 = FUN_0060fa04(self, pcVar4, (void**)&scratch);
        if (iVar1 == 0) {
          return (char*)0x0;
        }
        scratch = 0;
      }
      if ((scratch < 0x100) &&
          (pcVar4 = pcVar4 + (iVar1 - (int)(intptr_t)pcVar3),
           pcVar4 < (char*)0x20)) {
        char* pcVar5 = local_30;
        for (uint32_t uVar2 = (uint32_t)pcVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(uint32_t*)pcVar5 = *(uint32_t*)pcVar3;
          pcVar3 = pcVar3 + 4;
          pcVar5 = pcVar5 + 4;
        }
        for (uint32_t uVar2 = (uint32_t)pcVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar5 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          pcVar5 = pcVar5 + 1;
        }
        local_30[(int)(intptr_t)pcVar4] = '\0';
        iVar1 = FUN_005f7fa4(local_30, 1, local_10);
        if (-1 < iVar1) {
          *param_2 = local_c;
          return pcVar4;
        }
      }
    }
  }
  return (char*)0x0;
}

// 0x6105c8 — observed shape: single-quoted character literal scanner.
// On a leading quote, scans one character/escape via FUN_0061032a and
// requires a closing quote. Returns the length including both quotes.
char* FUN_006105c8(void* self, char* param_1, int* param_2) {
  int in_ECX = (int)(intptr_t)self;

  if ((param_1 < *(char**)(in_ECX + 4)) && (*param_1 == '\'')) {
    int iVar1 = FUN_0061032a(self, param_1 + 1, param_2);
    if ((iVar1 != 0) &&
        ((char* pcVar2 = param_1 + 1 + iVar1, pcVar2 < *(char**)(in_ECX + 4) &&
          (*pcVar2 == '\'')))) {
      return pcVar2 + (1 - (int)(intptr_t)param_1);
    }
  }
  return (char*)0x0;
}

// 0x61060b — observed shape: string literal scanner.
// Accepts a double quote, or '<' when flag bit 8 is set, and scans to the
// matching terminator ('"' or '>') while honouring backslash-newline and
// \r\n continuations (bumping the line counter at self+0x1c). Reports code
// code 0x3ed for an unterminated line, 0x3ee for EOF. The decoded span is
// allocated with FUN_0065aaac and escaped characters resolved through
// FUN_0061032a. Returns the length including both delimiters, or 0.
int FUN_0061060b(void* selfp, char* param_1, uint32_t* param_2) {
  int in_ECX = (int)(intptr_t)selfp;
  char cVar1;
  char* pcVar2;
  uint8_t* puVar3;
  char* pcVar5;
  char* pcVar6;
  char* pcVar7;
  char* pcVar8;
  char* pcVar9;
  uint32_t uVar10;
  const char* pcMsg;
  char closing;

  pcVar2 = param_1;
  if (*(char**)(in_ECX + 4) <= param_1) {
    return 0;
  }
  if (*param_1 == '\"') {
    closing = '\"';
  } else {
    if (*param_1 != '<') {
      return 0;
    }
    if ((*(uint8_t*)(in_ECX + 0x28) & 8) == 0) {
      return 0;
    }
    closing = '>';
  }
  pcVar9 = pcVar2 + 1;
  pcVar8 = pcVar9;
  if (pcVar9 < *(char**)(in_ECX + 4)) {
    pcVar6 = pcVar2 + 2;
    do {
      cVar1 = *pcVar8;
      if ((closing == cVar1) || (cVar1 == '\n')) break;
      pcVar5 = pcVar6;
      pcVar7 = pcVar8;
      if ((cVar1 == '\\') && ((*(uint8_t*)(in_ECX + 0x28) & 4) == 0)) {
        pcVar7 = pcVar8 + 1;
        pcVar5 = pcVar6 + 1;
        if (pcVar7 < *(char**)(in_ECX + 4)) {
          if (*pcVar7 != '\n') {
            if (((*pcVar7 != '\r') ||
                 (*(char**)(in_ECX + 4) <= pcVar5)) || (*pcVar5 != '\n'))
              goto LAB_00610689;
            pcVar7 = pcVar8 + 2;
            pcVar5 = pcVar6 + 2;
          }
          *(int*)(in_ECX + 0x1c) = *(int*)(in_ECX + 0x1c) + 1;
        }
      }
LAB_00610689:;
      pcVar8 = pcVar7 + 1;
      pcVar6 = pcVar5 + 1;
    } while (pcVar8 < *(char**)(in_ECX + 4));
  }
  if (pcVar8 < *(char**)(in_ECX + 4)) {
    if (*pcVar8 != '\n') goto LAB_006106c3;
    pcMsg = "string continues past end of line";
    uVar10 = 0x3ed;
  } else {
    pcMsg = "string continues past end of file";
    uVar10 = 0x3ee;
    pcVar8 = *(char**)(in_ECX + 4);
  }
  FUN_0060fcd3(*(int*)(in_ECX + 0x30), in_ECX + 8, uVar10, (char*)pcMsg);
LAB_006106c3:;
  puVar3 = (uint8_t*)FUN_0065aaac((int)(intptr_t)(pcVar8 - pcVar2), 1);
  if (puVar3 == (uint8_t*)0x0) {
    return 0;
  }
  *param_2 = (uint32_t)(uintptr_t)puVar3;
  do {
    pcVar6 = pcVar9 + 1;
    if (pcVar6 < pcVar8) {
      pcVar5 = pcVar9 + 2;
      do {
        if ((*pcVar9 != '\\') || ((*(uint8_t*)(in_ECX + 0x28) & 4) != 0)) break;
        if (*pcVar6 == '\n') {
          pcVar9 = pcVar9 + 2;
          pcVar5 = pcVar5 + 2;
          pcVar6 = pcVar6 + 2;
        } else {
          if (((*pcVar6 != '\r') || (pcVar8 <= pcVar5)) || (*pcVar5 != '\n'))
            break;
          pcVar9 = pcVar9 + 3;
          pcVar5 = pcVar5 + 3;
          pcVar6 = pcVar6 + 3;
        }
      } while (pcVar6 < pcVar8);
    }
    if (pcVar8 <= pcVar9) {
      *puVar3 = 0;
      return (int)(intptr_t)(pcVar8 - pcVar2) + 1;
    }
    int ch = 0;
    int iVar4 = FUN_0061032a(selfp, pcVar9, &ch);
    pcVar9 = pcVar9 + iVar4;
    *puVar3 = (uint8_t)ch;
    puVar3 = puVar3 + 1;
  } while (true);
}

// 0x610755 — observed shape: one-token scanner / dispatcher.
// Stores the options word at self[10], snapshots the cursor and line number
// into the token record (param_2[4], param_2[5]), skips trivia via
// FUN_0061003c (0xc on failure), reports 0xd at EOF, then classifies:
// quotes → 2, strings → 10, '<' (flag 4) → 0xb, identifiers → 0 (qualified)
// or 9, numbers → 5 with integer/float suffix handling else 2 with
// hex/octal/decimal handling, everything else → operator token (type 1).
// Finally records the token start (param_2[6]) and length (param_2[7]) and
// advances the cursor. Always returns 0.
uint32_t FUN_00610755(void* selfp, int param_1, uint32_t* param_2) {
  int* in_ECX = (int*)selfp;
  char cVar1;
  char* pcVar2;
  int iVar3;
  int iVar4;

  in_ECX[10] = param_1;
  param_2[4] = in_ECX[6];
  iVar4 = 0;
  param_2[5] = in_ECX[7];
  iVar3 = FUN_0061003c(selfp);
  if (iVar3 != 0) {
    *param_2 = 0xc;
    goto LAB_00610905;
  }
  param_2[4] = in_ECX[6];
  param_2[5] = in_ECX[7];
  pcVar2 = (char*)*in_ECX;
  if ((char*)in_ECX[1] <= pcVar2) {
    *param_2 = 0xd;
    goto LAB_00610905;
  }
  cVar1 = *pcVar2;
  if (((cVar1 < '0') || ('9' < cVar1)) && (cVar1 != '.')) {
    if (cVar1 == '\'') {
      iVar4 = (int)(intptr_t)FUN_006105c8(selfp, pcVar2, (int*)(param_2 + 2));
      if (iVar4 != 0) {
        *param_2 = 2;
        goto LAB_00610905;
      }
    } else if (cVar1 == '\"') {
      iVar4 = FUN_0061060b(selfp, pcVar2, param_2 + 2);
      if (iVar4 != 0) {
        *param_2 = 10;
        goto LAB_00610905;
      }
    } else if (((*(uint8_t*)(in_ECX + 10) & 4) == 0) || (cVar1 != '<')) {
      iVar3 = isalpha((int)cVar1);
      if ((iVar3 != 0) || (*(char*)*in_ECX == '_')) {
        if (((*(uint8_t*)(in_ECX + 10) & 2) != 0) &&
            (iVar4 = FUN_006104c3(selfp, (char*)*in_ECX, param_2 + 2),
             iVar4 != 0)) {
          *param_2 = 0;
          goto LAB_00610905;
        }
        iVar4 = (int)FUN_0060fa04(selfp, (char*)*in_ECX, (void**)(param_2 + 2));
        if (iVar4 != 0) {
          *param_2 = 9;
          goto LAB_00610905;
        }
      }
    } else {
      iVar4 = FUN_0061060b(selfp, pcVar2, param_2 + 2);
      if (iVar4 != 0) {
        *param_2 = 0xb;
        goto LAB_00610905;
      }
    }
LAB_006108f0:;
    iVar4 = (int)FUN_0060fa88(selfp, (char*)*in_ECX, (char*)(param_2 + 2));
    *param_2 = 1;
  } else {
    iVar4 = FUN_0060f879(selfp, pcVar2, (double*)(param_2 + 2));
    if (iVar4 == 0) {
      iVar4 = FUN_00610165(selfp, (char*)*in_ECX, (int*)(param_2 + 2));
      if (((iVar4 == 0) &&
           (iVar4 = FUN_00610209(selfp, (char*)*in_ECX, param_2 + 2),
            iVar4 == 0)) &&
          (iVar4 = FUN_00610287(selfp, (char*)*in_ECX, param_2 + 2),
           iVar4 == 0))
        goto LAB_006108f0;
      *param_2 = 2;
      iVar3 = FUN_0060fbe0(selfp, (char*)*in_ECX + iVar4, param_2);
    } else {
      *param_2 = 5;
      iVar3 = FUN_0060fb96(selfp, (char*)*in_ECX + iVar4, param_2);
    }
    iVar4 = iVar4 + iVar3;
  }
LAB_00610905:;
  param_2[6] = (uint32_t)*in_ECX;
  param_2[7] = (uint32_t)iVar4;
  *in_ECX = *in_ECX + iVar4;
  return 0;
}

// Helper for 0x610918: fixed-length, terminator-inclusive name compare
// (matches the observed compare loop against the uppercased local buffer).
static bool NameEq(const char* buf, const char* lit, int n) {
  bool b = true;
  while (n != 0) {
    n = n - 1;
    b = *buf == *lit;
    buf = buf + 1;
    lit = lit + 1;
    if (!b) break;
  }
  return b;
}

// 0x610918 — observed shape: vertex-declaration usage parser.
// Uppercases the leading alphabetic run into a local buffer, parses the
// trailing index with atoi (must be <= 0xf), rejects other trailing chars,
// then maps the name to a D3DDECLUSAGE value by fixed-length compares.
// Writes the usage into *param_2, the usage-index into *param_3 (0 for
// DIFFUSE, 1 for SPECULAR), and returns 0; E_FAIL (0x80004005) otherwise.
uint32_t FUN_00610918(char* param_1, uint8_t* param_2, uint8_t* param_3) {
  char cVar1;
  int iVar2;
  int iVar3;
  uint32_t uVar5;
  char* pcVar6;
  char local_20[27];
  uint8_t local_5;

  cVar1 = *param_1;
  pcVar6 = param_1;
  while ((cVar1 != '\0' && isalpha((int)*pcVar6))) {
    pcVar6 = pcVar6 + 1;
    cVar1 = *pcVar6;
  }
  if (*pcVar6 == '\0') {
    local_5 = 0;
  } else {
    iVar2 = atoi(pcVar6);
    local_5 = (uint8_t)iVar2;
  }
  if (0xf < local_5) {
    *param_2 = 0;
    *param_3 = 0xff;
    return 0x80004005;
  }
  uVar5 = (uint32_t)(int)(intptr_t)(pcVar6 - param_1);
  if ((uVar5 == 0) || (0x14 < uVar5)) {
    return 0x80004005;
  }
  cVar1 = *pcVar6;
  if (cVar1 != '\0') {
    do {
      if (isdigit((int)cVar1) == 0) break;
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar6;
    } while (cVar1 != '\0');
    if (*pcVar6 != '\0') {
      return 0x80004005;
    }
  }
  if (*param_1 != '\0') {
    int off = -(int)(intptr_t)param_1;
    do {
      if (isalpha((int)*param_1) == 0) break;
      iVar3 = toupper((int)*param_1);
      param_1[(int)(intptr_t)(local_20 + off)] = (char)iVar3;
      param_1 = param_1 + 1;
    } while (*param_1 != '\0');
  }
  local_20[uVar5] = '\0';

  int iVar3_ = 9;  // running length/leftover accumulator, as observed
  if (NameEq(local_20, "POSITION", 9)) {
    iVar3_ = 0;
    goto LAB_00610b42;
  }
  iVar3_ = 0xc;
  if (NameEq(local_20, "BLENDWEIGHT", 0xc)) {
    iVar3_ = 1;
    goto LAB_00610b42;
  }
  iVar3_ = 0xd;
  if (NameEq(local_20, "BLENDINDICES", 0xd)) {
    iVar3_ = 2;
    goto LAB_00610b42;
  }
  iVar3_ = 7;
  if (NameEq(local_20, "NORMAL", 7)) {
    iVar3_ = 3;
    goto LAB_00610b42;
  }
  iVar3_ = 6;
  if (NameEq(local_20, "PSIZE", 6)) {
    iVar3_ = 4;
    goto LAB_00610b42;
  }
  if (NameEq(local_20, "TEXCOORD", 9)) {
    iVar3_ = 5;
    goto LAB_00610b42;
  }
  if (NameEq(local_20, "TANGENT", 8)) {
    // left at 6 from the PSIZE pre-assignment (D3DDECLUSAGE_TANGENT)
    iVar3_ = 6;
    goto LAB_00610b42;
  }
  iVar3_ = 9;
  if (NameEq(local_20, "BINORMAL", 9)) {
    iVar3_ = 7;
    goto LAB_00610b42;
  }
  iVar3_ = 0xb;
  if (NameEq(local_20, "TESSFACTOR", 0xb)) {
    iVar3_ = 8;
    goto LAB_00610b42;
  }
  if (NameEq(local_20, "POSITIONT", 10)) {
    iVar3_ = 9;
    goto LAB_00610b42;
  }
  if (NameEq(local_20, "COLOR", 6)) {
    iVar3_ = 10;
    goto LAB_00610b42;
  }
  if (NameEq(local_20, "FOG", 4)) {
    // 0xb left over from the TESSFACTOR pre-assignment
    iVar3_ = 0xb;
    goto LAB_00610b42;
  }
  iVar3_ = 6;
  if (NameEq(local_20, "DEPTH", 6)) {
    iVar3_ = 0xc;
    goto LAB_00610b42;
  }
  iVar3_ = 7;
  if (NameEq(local_20, "SAMPLE", 7)) {
    iVar3_ = 0xd;
    goto LAB_00610b42;
  }
  iVar3_ = 8;
  if (NameEq(local_20, "DIFFUSE", 8)) {
    local_5 = 0;
  } else {
    if (!NameEq(local_20, "SPECULAR", 9)) {
      return 0x80004005;
    }
    local_5 = 1;
  }
  iVar3_ = 10;
LAB_00610b42:;
  *param_2 = (uint8_t)iVar3_;
  *param_3 = local_5;
  return 0;
}

// 0x610b5f — observed shape: case-insensitive string hash.
// Accumulates (h * 0x13 + toupper(c)) over the string and returns h % 7;
// returns 0 for a null or empty string.
uint32_t FUN_00610b5f(char* param_1) {
  char cVar1;
  uint32_t uVar3 = 0;

  if ((param_1 == (char*)0x0) || (cVar1 = *param_1, cVar1 == '\0')) {
    uVar3 = 0;
  } else {
    do {
      int iVar2 = toupper((int)cVar1);
      uVar3 = uVar3 * 0x13 + iVar2;
      param_1 = param_1 + 1;
      cVar1 = *param_1;
    } while (cVar1 != '\0');
    uVar3 = uVar3 % 7;
  }
  return uVar3;
}

// 0x610bd6 — observed shape: bucket-list flattening.
// Walks the seven hash buckets at self[0..6] and copies each chained record
// (next pointer at +0x20) consecutively into the caller array.
void FUN_00610bd6(void* selfp, int param_1) {
  int in_ECX = (int)(intptr_t)selfp;
  int iVar2 = 0;
  uint32_t uVar3 = 0;

  do {
    for (int iVar1 = *(int*)(in_ECX + uVar3 * 4); iVar1 != 0;
         iVar1 = *(int*)(iVar1 + 0x20)) {
      *(int*)(param_1 + iVar2 * 4) = iVar1;
      iVar2 = iVar2 + 1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 7);
  return;
}
