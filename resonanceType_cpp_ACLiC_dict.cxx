// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedInicoficodIuser_filesdIunibodILabEMdIresonanceType_cpp_ACLiC_dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/home/nicofico/user_files/unibo/LabEM/./resonanceType.cpp"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *ResonanceType_Dictionary();
   static void ResonanceType_TClassManip(TClass*);
   static void delete_ResonanceType(void *p);
   static void deleteArray_ResonanceType(void *p);
   static void destruct_ResonanceType(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ResonanceType*)
   {
      ::ResonanceType *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ResonanceType));
      static ::ROOT::TGenericClassInfo 
         instance("ResonanceType", "resonanceType.hpp", 6,
                  typeid(::ResonanceType), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ResonanceType_Dictionary, isa_proxy, 4,
                  sizeof(::ResonanceType) );
      instance.SetDelete(&delete_ResonanceType);
      instance.SetDeleteArray(&deleteArray_ResonanceType);
      instance.SetDestructor(&destruct_ResonanceType);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ResonanceType*)
   {
      return GenerateInitInstanceLocal(static_cast<::ResonanceType*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::ResonanceType*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ResonanceType_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::ResonanceType*>(nullptr))->GetClass();
      ResonanceType_TClassManip(theClass);
   return theClass;
   }

   static void ResonanceType_TClassManip(TClass* theClass){
      theClass->CreateAttributeMap();
      TDictAttributeMap* attrMap( theClass->GetAttributeMap() );
      attrMap->AddProperty("file_name","/home/nicofico/user_files/unibo/LabEM/./resonanceType.hpp");
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ResonanceType(void *p) {
      delete (static_cast<::ResonanceType*>(p));
   }
   static void deleteArray_ResonanceType(void *p) {
      delete [] (static_cast<::ResonanceType*>(p));
   }
   static void destruct_ResonanceType(void *p) {
      typedef ::ResonanceType current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::ResonanceType

namespace {
  void TriggerDictionaryInitialization_resonanceType_cpp_ACLiC_dict_Impl() {
    static const char* headers[] = {
"./resonanceType.cpp",
nullptr
    };
    static const char* includePaths[] = {
"/home/nicofico/root/include",
"/home/nicofico/root/etc/",
"/home/nicofico/root/etc//cling",
"/home/nicofico/root/etc//cling/plugins/include",
"/home/nicofico/root/include/",
"/home/nicofico/root/include",
"/home/nicofico/root/include/",
"/home/nicofico/user_files/unibo/LabEM/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "resonanceType_cpp_ACLiC_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$resonanceType.hpp")))  __attribute__((annotate("$clingAutoload$./resonanceType.cpp")))  ResonanceType;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "resonanceType_cpp_ACLiC_dict dictionary payload"

#ifndef __ACLIC__
  #define __ACLIC__ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "./resonanceType.cpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"", payloadCode, "@",
"ResonanceType", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("resonanceType_cpp_ACLiC_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_resonanceType_cpp_ACLiC_dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_resonanceType_cpp_ACLiC_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_resonanceType_cpp_ACLiC_dict() {
  TriggerDictionaryInitialization_resonanceType_cpp_ACLiC_dict_Impl();
}
