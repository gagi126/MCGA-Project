#define ICALL_TABLE_corlib 1

static int corlib_icall_indexes [] = {
187,
194,
195,
196,
197,
198,
199,
200,
201,
202,
205,
206,
372,
373,
375,
404,
405,
406,
426,
427,
428,
429,
430,
521,
522,
523,
526,
563,
564,
565,
568,
570,
572,
574,
579,
587,
588,
589,
590,
591,
592,
593,
594,
595,
596,
597,
598,
599,
600,
601,
602,
603,
604,
605,
606,
607,
608,
609,
610,
611,
612,
613,
697,
698,
699,
700,
701,
702,
703,
704,
705,
706,
707,
708,
709,
710,
711,
712,
713,
714,
715,
716,
717,
718,
719,
720,
721,
855,
856,
864,
867,
869,
875,
876,
878,
879,
883,
885,
886,
887,
888,
890,
891,
892,
895,
896,
899,
900,
901,
976,
977,
979,
987,
988,
989,
990,
991,
995,
996,
997,
998,
999,
1000,
1002,
1003,
1004,
1006,
1007,
1009,
1013,
1014,
1015,
1288,
1503,
1504,
7562,
7563,
7565,
7566,
7567,
7568,
7569,
7571,
7573,
7575,
7576,
7584,
7586,
7592,
7593,
7595,
7597,
7599,
7610,
7619,
7620,
7622,
7623,
7624,
7625,
7626,
7628,
7630,
8676,
8680,
8682,
8683,
8684,
8685,
8736,
8737,
8738,
8739,
8758,
8759,
8760,
8761,
8794,
8841,
8844,
8853,
8854,
8855,
8856,
9121,
9122,
9127,
9128,
9176,
9177,
9178,
9206,
9212,
9219,
9229,
9233,
9325,
9335,
9345,
9346,
9347,
9348,
9349,
9350,
9356,
9372,
9393,
9394,
9403,
9405,
9412,
9413,
9416,
9418,
9423,
9429,
9430,
9437,
9439,
9449,
9452,
9453,
9454,
9465,
9477,
9483,
9484,
9485,
9487,
9488,
9498,
9517,
9539,
9540,
9541,
9542,
9543,
9560,
9565,
9570,
9601,
9602,
10090,
10091,
10171,
10250,
10511,
10512,
10521,
10522,
10523,
10529,
10607,
10779,
10780,
11467,
11468,
12291,
12310,
12317,
12318,
12320,
};
void ves_icall_System_Array_InternalCreate (int,int,int,int,int);
int ves_icall_System_Array_GetCorElementTypeOfElementType_raw (int,int);
int ves_icall_System_Array_IsValueOfElementType_raw (int,int,int);
int ves_icall_System_Array_CanChangePrimitive (int,int,int);
int ves_icall_System_Array_FastCopy_raw (int,int,int,int,int,int);
int ves_icall_System_Array_GetLength_raw (int,int,int);
int ves_icall_System_Array_GetLowerBound_raw (int,int,int);
void ves_icall_System_Array_GetGenericValue_icall (int,int,int);
int ves_icall_System_Array_GetValueImpl_raw (int,int,int);
void ves_icall_System_Array_SetGenericValue_icall (int,int,int);
void ves_icall_System_Array_SetValueImpl_raw (int,int,int,int);
void ves_icall_System_Array_SetValueRelaxedImpl_raw (int,int,int,int);
void ves_icall_System_Runtime_RuntimeImports_Memmove (int,int,int);
void ves_icall_System_Buffer_BulkMoveWithWriteBarrier (int,int,int,int);
void ves_icall_System_Runtime_RuntimeImports_ZeroMemory (int,int);
int ves_icall_System_Delegate_AllocDelegateLike_internal_raw (int,int);
int ves_icall_System_Delegate_CreateDelegate_internal_raw (int,int,int,int,int);
int ves_icall_System_Delegate_GetVirtualMethod_internal_raw (int,int);
int ves_icall_System_Enum_GetEnumValuesAndNames_raw (int,int,int,int);
int ves_icall_System_Enum_ToObject_raw (int,int64_t,int);
int ves_icall_System_Enum_InternalGetCorElementType_raw (int,int);
int ves_icall_System_Enum_get_underlying_type_raw (int,int);
int ves_icall_System_Enum_InternalHasFlag_raw (int,int,int);
int ves_icall_System_Environment_get_ProcessorCount ();
int ves_icall_System_Environment_get_TickCount ();
int64_t ves_icall_System_Environment_get_TickCount64 ();
void ves_icall_System_Environment_FailFast_raw (int,int,int,int);
int ves_icall_System_GC_GetCollectionCount (int);
void ves_icall_System_GC_register_ephemeron_array_raw (int,int);
int ves_icall_System_GC_get_ephemeron_tombstone_raw (int);
void ves_icall_System_GC_SuppressFinalize_raw (int,int);
void ves_icall_System_GC_ReRegisterForFinalize_raw (int,int);
void ves_icall_System_GC_GetGCMemoryInfo (int,int,int,int,int,int);
int ves_icall_System_GC_AllocPinnedArray_raw (int,int,int);
int ves_icall_System_Object_MemberwiseClone_raw (int,int);
double ves_icall_System_Math_Abs_double (double);
float ves_icall_System_Math_Abs_single (float);
double ves_icall_System_Math_Acos (double);
double ves_icall_System_Math_Acosh (double);
double ves_icall_System_Math_Asin (double);
double ves_icall_System_Math_Asinh (double);
double ves_icall_System_Math_Atan (double);
double ves_icall_System_Math_Atan2 (double,double);
double ves_icall_System_Math_Atanh (double);
double ves_icall_System_Math_Cbrt (double);
double ves_icall_System_Math_Ceiling (double);
double ves_icall_System_Math_Cos (double);
double ves_icall_System_Math_Cosh (double);
double ves_icall_System_Math_Exp (double);
double ves_icall_System_Math_Floor (double);
double ves_icall_System_Math_Log (double);
double ves_icall_System_Math_Log10 (double);
double ves_icall_System_Math_Pow (double,double);
double ves_icall_System_Math_Sin (double);
double ves_icall_System_Math_Sinh (double);
double ves_icall_System_Math_Sqrt (double);
double ves_icall_System_Math_Tan (double);
double ves_icall_System_Math_Tanh (double);
double ves_icall_System_Math_FusedMultiplyAdd (double,double,double);
int ves_icall_System_Math_ILogB (double);
double ves_icall_System_Math_Log2 (double);
double ves_icall_System_Math_ModF (double,int);
float ves_icall_System_MathF_Acos (float);
float ves_icall_System_MathF_Acosh (float);
float ves_icall_System_MathF_Asin (float);
float ves_icall_System_MathF_Asinh (float);
float ves_icall_System_MathF_Atan (float);
float ves_icall_System_MathF_Atan2 (float,float);
float ves_icall_System_MathF_Atanh (float);
float ves_icall_System_MathF_Cbrt (float);
float ves_icall_System_MathF_Ceiling (float);
float ves_icall_System_MathF_Cos (float);
float ves_icall_System_MathF_Cosh (float);
float ves_icall_System_MathF_Exp (float);
float ves_icall_System_MathF_Floor (float);
float ves_icall_System_MathF_Log (float);
float ves_icall_System_MathF_Log10 (float);
float ves_icall_System_MathF_Pow (float,float);
float ves_icall_System_MathF_Sin (float);
float ves_icall_System_MathF_Sinh (float);
float ves_icall_System_MathF_Sqrt (float);
float ves_icall_System_MathF_Tan (float);
float ves_icall_System_MathF_Tanh (float);
float ves_icall_System_MathF_FusedMultiplyAdd (float,float,float);
int ves_icall_System_MathF_ILogB (float);
float ves_icall_System_MathF_Log2 (float);
float ves_icall_System_MathF_ModF (float,int);
int ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw (int,int,int);
int ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw (int,int,int);
int ves_icall_RuntimeType_make_array_type_raw (int,int,int);
int ves_icall_RuntimeType_make_byref_type_raw (int,int);
int ves_icall_RuntimeType_MakePointerType_raw (int,int);
int ves_icall_RuntimeType_MakeGenericType_raw (int,int,int);
int ves_icall_RuntimeType_GetMethodsByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetPropertiesByName_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetConstructors_native_raw (int,int,int);
void ves_icall_RuntimeType_GetPacking_raw (int,int,int,int);
int ves_icall_System_Activator_CreateInstanceInternal_raw (int,int);
int ves_icall_RuntimeType_get_DeclaringMethod_raw (int,int);
int ves_icall_System_RuntimeType_getFullName_raw (int,int,int,int);
int ves_icall_RuntimeType_GetGenericArguments_raw (int,int,int);
int ves_icall_RuntimeType_GetGenericParameterPosition_raw (int,int);
int ves_icall_RuntimeType_GetEvents_native_raw (int,int,int,int);
int ves_icall_RuntimeType_GetFields_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_GetInterfaces_raw (int,int);
int ves_icall_RuntimeType_GetNestedTypes_native_raw (int,int,int,int,int);
int ves_icall_RuntimeType_get_DeclaringType_raw (int,int);
int ves_icall_RuntimeType_get_Name_raw (int,int);
int ves_icall_RuntimeType_get_Namespace_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetAttributes_raw (int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetCorElementType_raw (int,int);
int ves_icall_RuntimeTypeHandle_HasInstantiation_raw (int,int);
int ves_icall_RuntimeTypeHandle_IsComObject_raw (int,int);
int ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_HasReferences_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetArrayRank_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetAssembly_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetElementType_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetModule_raw (int,int);
int ves_icall_RuntimeTypeHandle_IsGenericVariable_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetBaseType_raw (int,int);
int ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw (int,int,int);
int ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition_raw (int,int);
int ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw (int,int);
int ves_icall_RuntimeTypeHandle_is_subclass_of (int,int);
int ves_icall_RuntimeTypeHandle_IsByRefLike_raw (int,int);
int ves_icall_System_RuntimeTypeHandle_internal_from_name_raw (int,int,int,int,int,int);
int ves_icall_System_String_FastAllocateString_raw (int,int);
int ves_icall_System_String_InternalIsInterned_raw (int,int);
int ves_icall_System_String_InternalIntern_raw (int,int);
int ves_icall_System_Type_internal_from_handle_raw (int,int);
int ves_icall_System_ValueType_InternalGetHashCode_raw (int,int,int);
int ves_icall_System_ValueType_Equals_raw (int,int,int,int);
int ves_icall_System_Threading_Interlocked_CompareExchange_Int (int,int,int);
void ves_icall_System_Threading_Interlocked_CompareExchange_Object (int,int,int,int);
int ves_icall_System_Threading_Interlocked_Decrement_Int (int);
int ves_icall_System_Threading_Interlocked_Increment_Int (int);
int64_t ves_icall_System_Threading_Interlocked_Increment_Long (int);
int ves_icall_System_Threading_Interlocked_Exchange_Int (int,int);
void ves_icall_System_Threading_Interlocked_Exchange_Object (int,int,int);
int64_t ves_icall_System_Threading_Interlocked_CompareExchange_Long (int,int64_t,int64_t);
int64_t ves_icall_System_Threading_Interlocked_Exchange_Long (int,int64_t);
int ves_icall_System_Threading_Interlocked_Add_Int (int,int);
int64_t ves_icall_System_Threading_Interlocked_Add_Long (int,int64_t);
void ves_icall_System_Threading_Monitor_Monitor_Enter_raw (int,int);
void mono_monitor_exit_icall_raw (int,int);
int ves_icall_System_Threading_Monitor_Monitor_test_synchronised_raw (int,int);
void ves_icall_System_Threading_Monitor_Monitor_pulse_raw (int,int);
void ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw (int,int);
int ves_icall_System_Threading_Monitor_Monitor_wait_raw (int,int,int,int);
void ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw (int,int,int,int,int);
int ves_icall_System_Threading_Thread_GetCurrentProcessorNumber_raw (int);
void ves_icall_System_Threading_Thread_InitInternal_raw (int,int);
int ves_icall_System_Threading_Thread_GetCurrentThread ();
void ves_icall_System_Threading_InternalThread_Thread_free_internal_raw (int,int);
int ves_icall_System_Threading_Thread_GetState_raw (int,int);
void ves_icall_System_Threading_Thread_SetState_raw (int,int,int);
void ves_icall_System_Threading_Thread_ClrState_raw (int,int,int);
void ves_icall_System_Threading_Thread_SetName_icall_raw (int,int,int,int);
int ves_icall_System_Threading_Thread_YieldInternal ();
void ves_icall_System_Threading_Thread_SetPriority_raw (int,int,int);
void ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw (int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw (int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw (int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw (int,int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw (int,int,int,int,int,int);
int ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalGetLoadedAssemblies_raw (int);
int ves_icall_System_GCHandle_InternalAlloc_raw (int,int,int);
void ves_icall_System_GCHandle_InternalFree_raw (int,int);
int ves_icall_System_GCHandle_InternalGet_raw (int,int);
void ves_icall_System_GCHandle_InternalSet_raw (int,int,int);
int ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError ();
void ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError (int);
void ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw (int,int,int,int);
int ves_icall_System_Runtime_InteropServices_Marshal_IsPinnableType_raw (int,int);
int ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName_raw (int,int,int,int,int,int);
int mono_object_hash_icall_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetObjectValue_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw (int,int);
void ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw (int,int,int);
void ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_RunClassConstructor_raw (int,int);
int ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack ();
int ves_icall_System_Reflection_Assembly_GetExecutingAssembly_raw (int,int);
int ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw (int);
int ves_icall_System_Reflection_Assembly_InternalLoad_raw (int,int,int,int);
int ves_icall_System_Reflection_Assembly_InternalGetType_raw (int,int,int,int,int,int);
void mono_digest_get_public_token (int,int,int);
int ves_icall_System_Reflection_AssemblyName_GetNativeName (int);
int ves_icall_System_Reflection_AssemblyName_ParseAssemblyName (int,int,int,int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw (int,int,int,int);
int ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw (int,int);
int ves_icall_MonoCustomAttrs_IsDefinedInternal_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw (int,int);
int ves_icall_System_Reflection_RuntimeAssembly_get_EntryPoint_raw (int,int);
int ves_icall_System_Reflection_RuntimeAssembly_GetExportedTypes_raw (int,int);
int ves_icall_System_Reflection_RuntimeAssembly_get_location_raw (int,int);
int ves_icall_System_Reflection_RuntimeAssembly_get_code_base_raw (int,int);
int ves_icall_System_Reflection_RuntimeAssembly_get_fullname_raw (int,int);
int ves_icall_System_Reflection_RuntimeAssembly_InternalImageRuntimeVersion_raw (int,int);
int ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw (int,int);
int ves_icall_System_Reflection_RuntimeAssembly_GetModulesInternal_raw (int,int);
void ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw (int,int,int,int,int,int,int);
void ves_icall_RuntimeEventInfo_get_event_info_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_ResolveType_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetParentType_raw (int,int,int);
int ves_icall_RuntimeFieldInfo_GetFieldOffset_raw (int,int);
int ves_icall_RuntimeFieldInfo_GetValueInternal_raw (int,int,int);
void ves_icall_RuntimeFieldInfo_SetValueInternal_raw (int,int,int,int);
int ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw (int,int);
int ves_icall_reflection_get_token_raw (int,int);
void ves_icall_get_method_info_raw (int,int,int);
int ves_icall_get_method_attributes (int);
int ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw (int,int,int);
int ves_icall_System_MonoMethodInfo_get_retval_marshal_raw (int,int);
int ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw (int,int,int,int);
int ves_icall_RuntimeMethodInfo_get_name_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_base_method_raw (int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
void ves_icall_RuntimeMethodInfo_GetPInvoke_raw (int,int,int,int,int);
int ves_icall_RuntimeMethodInfo_MakeGenericMethod_impl_raw (int,int,int);
int ves_icall_RuntimeMethodInfo_GetGenericArguments_raw (int,int);
int ves_icall_RuntimeMethodInfo_GetGenericMethodDefinition_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw (int,int);
int ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw (int,int);
int ves_icall_InternalInvoke_raw (int,int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_RuntimeModule_GetMDStreamVersion_raw (int,int);
int ves_icall_System_Reflection_RuntimeModule_InternalGetTypes_raw (int,int);
void ves_icall_System_Reflection_RuntimeModule_GetGuidInternal_raw (int,int,int);
int ves_icall_System_Reflection_RuntimeModule_ResolveMethodToken_raw (int,int,int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_RuntimeParameterInfo_GetTypeModifiers_raw (int,int,int,int,int);
void ves_icall_RuntimePropertyInfo_get_property_info_raw (int,int,int,int);
int ves_icall_reflection_get_token_raw (int,int);
int ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw (int,int,int);
void ves_icall_AssemblyBuilder_basic_init_raw (int,int);
void ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw (int,int);
int ves_icall_CustomAttributeBuilder_GetBlob_raw (int,int,int,int,int,int,int,int);
void ves_icall_DynamicMethod_create_dynamic_method_raw (int,int);
void ves_icall_ModuleBuilder_basic_init_raw (int,int);
void ves_icall_ModuleBuilder_set_wrappers_type_raw (int,int,int);
int ves_icall_ModuleBuilder_getUSIndex_raw (int,int,int);
int ves_icall_ModuleBuilder_getToken_raw (int,int,int,int);
int ves_icall_ModuleBuilder_getMethodToken_raw (int,int,int,int);
void ves_icall_ModuleBuilder_RegisterToken_raw (int,int,int,int);
int ves_icall_TypeBuilder_create_runtime_class_raw (int,int);
int ves_icall_System_IO_Stream_HasOverriddenBeginEndRead_raw (int,int);
int ves_icall_System_IO_Stream_HasOverriddenBeginEndWrite_raw (int,int);
int ves_icall_System_Diagnostics_Debugger_IsLogging ();
void ves_icall_System_Diagnostics_Debugger_Log (int,int,int);
int ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass (int);
void ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree (int);
void ves_icall_Mono_RuntimeMarshal_FreeAssemblyName (int,int);
int ves_icall_Mono_SafeStringMarshal_StringToUtf8 (int);
void ves_icall_Mono_SafeStringMarshal_GFree (int);
static void *corlib_icall_funcs [] = {
// token 187,
ves_icall_System_Array_InternalCreate,
// token 194,
ves_icall_System_Array_GetCorElementTypeOfElementType_raw,
// token 195,
ves_icall_System_Array_IsValueOfElementType_raw,
// token 196,
ves_icall_System_Array_CanChangePrimitive,
// token 197,
ves_icall_System_Array_FastCopy_raw,
// token 198,
ves_icall_System_Array_GetLength_raw,
// token 199,
ves_icall_System_Array_GetLowerBound_raw,
// token 200,
ves_icall_System_Array_GetGenericValue_icall,
// token 201,
ves_icall_System_Array_GetValueImpl_raw,
// token 202,
ves_icall_System_Array_SetGenericValue_icall,
// token 205,
ves_icall_System_Array_SetValueImpl_raw,
// token 206,
ves_icall_System_Array_SetValueRelaxedImpl_raw,
// token 372,
ves_icall_System_Runtime_RuntimeImports_Memmove,
// token 373,
ves_icall_System_Buffer_BulkMoveWithWriteBarrier,
// token 375,
ves_icall_System_Runtime_RuntimeImports_ZeroMemory,
// token 404,
ves_icall_System_Delegate_AllocDelegateLike_internal_raw,
// token 405,
ves_icall_System_Delegate_CreateDelegate_internal_raw,
// token 406,
ves_icall_System_Delegate_GetVirtualMethod_internal_raw,
// token 426,
ves_icall_System_Enum_GetEnumValuesAndNames_raw,
// token 427,
ves_icall_System_Enum_ToObject_raw,
// token 428,
ves_icall_System_Enum_InternalGetCorElementType_raw,
// token 429,
ves_icall_System_Enum_get_underlying_type_raw,
// token 430,
ves_icall_System_Enum_InternalHasFlag_raw,
// token 521,
ves_icall_System_Environment_get_ProcessorCount,
// token 522,
ves_icall_System_Environment_get_TickCount,
// token 523,
ves_icall_System_Environment_get_TickCount64,
// token 526,
ves_icall_System_Environment_FailFast_raw,
// token 563,
ves_icall_System_GC_GetCollectionCount,
// token 564,
ves_icall_System_GC_register_ephemeron_array_raw,
// token 565,
ves_icall_System_GC_get_ephemeron_tombstone_raw,
// token 568,
ves_icall_System_GC_SuppressFinalize_raw,
// token 570,
ves_icall_System_GC_ReRegisterForFinalize_raw,
// token 572,
ves_icall_System_GC_GetGCMemoryInfo,
// token 574,
ves_icall_System_GC_AllocPinnedArray_raw,
// token 579,
ves_icall_System_Object_MemberwiseClone_raw,
// token 587,
ves_icall_System_Math_Abs_double,
// token 588,
ves_icall_System_Math_Abs_single,
// token 589,
ves_icall_System_Math_Acos,
// token 590,
ves_icall_System_Math_Acosh,
// token 591,
ves_icall_System_Math_Asin,
// token 592,
ves_icall_System_Math_Asinh,
// token 593,
ves_icall_System_Math_Atan,
// token 594,
ves_icall_System_Math_Atan2,
// token 595,
ves_icall_System_Math_Atanh,
// token 596,
ves_icall_System_Math_Cbrt,
// token 597,
ves_icall_System_Math_Ceiling,
// token 598,
ves_icall_System_Math_Cos,
// token 599,
ves_icall_System_Math_Cosh,
// token 600,
ves_icall_System_Math_Exp,
// token 601,
ves_icall_System_Math_Floor,
// token 602,
ves_icall_System_Math_Log,
// token 603,
ves_icall_System_Math_Log10,
// token 604,
ves_icall_System_Math_Pow,
// token 605,
ves_icall_System_Math_Sin,
// token 606,
ves_icall_System_Math_Sinh,
// token 607,
ves_icall_System_Math_Sqrt,
// token 608,
ves_icall_System_Math_Tan,
// token 609,
ves_icall_System_Math_Tanh,
// token 610,
ves_icall_System_Math_FusedMultiplyAdd,
// token 611,
ves_icall_System_Math_ILogB,
// token 612,
ves_icall_System_Math_Log2,
// token 613,
ves_icall_System_Math_ModF,
// token 697,
ves_icall_System_MathF_Acos,
// token 698,
ves_icall_System_MathF_Acosh,
// token 699,
ves_icall_System_MathF_Asin,
// token 700,
ves_icall_System_MathF_Asinh,
// token 701,
ves_icall_System_MathF_Atan,
// token 702,
ves_icall_System_MathF_Atan2,
// token 703,
ves_icall_System_MathF_Atanh,
// token 704,
ves_icall_System_MathF_Cbrt,
// token 705,
ves_icall_System_MathF_Ceiling,
// token 706,
ves_icall_System_MathF_Cos,
// token 707,
ves_icall_System_MathF_Cosh,
// token 708,
ves_icall_System_MathF_Exp,
// token 709,
ves_icall_System_MathF_Floor,
// token 710,
ves_icall_System_MathF_Log,
// token 711,
ves_icall_System_MathF_Log10,
// token 712,
ves_icall_System_MathF_Pow,
// token 713,
ves_icall_System_MathF_Sin,
// token 714,
ves_icall_System_MathF_Sinh,
// token 715,
ves_icall_System_MathF_Sqrt,
// token 716,
ves_icall_System_MathF_Tan,
// token 717,
ves_icall_System_MathF_Tanh,
// token 718,
ves_icall_System_MathF_FusedMultiplyAdd,
// token 719,
ves_icall_System_MathF_ILogB,
// token 720,
ves_icall_System_MathF_Log2,
// token 721,
ves_icall_System_MathF_ModF,
// token 855,
ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw,
// token 856,
ves_icall_RuntimeType_GetCorrespondingInflatedMethod_raw,
// token 864,
ves_icall_RuntimeType_make_array_type_raw,
// token 867,
ves_icall_RuntimeType_make_byref_type_raw,
// token 869,
ves_icall_RuntimeType_MakePointerType_raw,
// token 875,
ves_icall_RuntimeType_MakeGenericType_raw,
// token 876,
ves_icall_RuntimeType_GetMethodsByName_native_raw,
// token 878,
ves_icall_RuntimeType_GetPropertiesByName_native_raw,
// token 879,
ves_icall_RuntimeType_GetConstructors_native_raw,
// token 883,
ves_icall_RuntimeType_GetPacking_raw,
// token 885,
ves_icall_System_Activator_CreateInstanceInternal_raw,
// token 886,
ves_icall_RuntimeType_get_DeclaringMethod_raw,
// token 887,
ves_icall_System_RuntimeType_getFullName_raw,
// token 888,
ves_icall_RuntimeType_GetGenericArguments_raw,
// token 890,
ves_icall_RuntimeType_GetGenericParameterPosition_raw,
// token 891,
ves_icall_RuntimeType_GetEvents_native_raw,
// token 892,
ves_icall_RuntimeType_GetFields_native_raw,
// token 895,
ves_icall_RuntimeType_GetInterfaces_raw,
// token 896,
ves_icall_RuntimeType_GetNestedTypes_native_raw,
// token 899,
ves_icall_RuntimeType_get_DeclaringType_raw,
// token 900,
ves_icall_RuntimeType_get_Name_raw,
// token 901,
ves_icall_RuntimeType_get_Namespace_raw,
// token 976,
ves_icall_RuntimeTypeHandle_GetAttributes_raw,
// token 977,
ves_icall_reflection_get_token_raw,
// token 979,
ves_icall_RuntimeTypeHandle_GetGenericTypeDefinition_impl_raw,
// token 987,
ves_icall_RuntimeTypeHandle_GetCorElementType_raw,
// token 988,
ves_icall_RuntimeTypeHandle_HasInstantiation_raw,
// token 989,
ves_icall_RuntimeTypeHandle_IsComObject_raw,
// token 990,
ves_icall_RuntimeTypeHandle_IsInstanceOfType_raw,
// token 991,
ves_icall_RuntimeTypeHandle_HasReferences_raw,
// token 995,
ves_icall_RuntimeTypeHandle_GetArrayRank_raw,
// token 996,
ves_icall_RuntimeTypeHandle_GetAssembly_raw,
// token 997,
ves_icall_RuntimeTypeHandle_GetElementType_raw,
// token 998,
ves_icall_RuntimeTypeHandle_GetModule_raw,
// token 999,
ves_icall_RuntimeTypeHandle_IsGenericVariable_raw,
// token 1000,
ves_icall_RuntimeTypeHandle_GetBaseType_raw,
// token 1002,
ves_icall_RuntimeTypeHandle_type_is_assignable_from_raw,
// token 1003,
ves_icall_RuntimeTypeHandle_IsGenericTypeDefinition_raw,
// token 1004,
ves_icall_RuntimeTypeHandle_GetGenericParameterInfo_raw,
// token 1006,
ves_icall_RuntimeTypeHandle_is_subclass_of,
// token 1007,
ves_icall_RuntimeTypeHandle_IsByRefLike_raw,
// token 1009,
ves_icall_System_RuntimeTypeHandle_internal_from_name_raw,
// token 1013,
ves_icall_System_String_FastAllocateString_raw,
// token 1014,
ves_icall_System_String_InternalIsInterned_raw,
// token 1015,
ves_icall_System_String_InternalIntern_raw,
// token 1288,
ves_icall_System_Type_internal_from_handle_raw,
// token 1503,
ves_icall_System_ValueType_InternalGetHashCode_raw,
// token 1504,
ves_icall_System_ValueType_Equals_raw,
// token 7562,
ves_icall_System_Threading_Interlocked_CompareExchange_Int,
// token 7563,
ves_icall_System_Threading_Interlocked_CompareExchange_Object,
// token 7565,
ves_icall_System_Threading_Interlocked_Decrement_Int,
// token 7566,
ves_icall_System_Threading_Interlocked_Increment_Int,
// token 7567,
ves_icall_System_Threading_Interlocked_Increment_Long,
// token 7568,
ves_icall_System_Threading_Interlocked_Exchange_Int,
// token 7569,
ves_icall_System_Threading_Interlocked_Exchange_Object,
// token 7571,
ves_icall_System_Threading_Interlocked_CompareExchange_Long,
// token 7573,
ves_icall_System_Threading_Interlocked_Exchange_Long,
// token 7575,
ves_icall_System_Threading_Interlocked_Add_Int,
// token 7576,
ves_icall_System_Threading_Interlocked_Add_Long,
// token 7584,
ves_icall_System_Threading_Monitor_Monitor_Enter_raw,
// token 7586,
mono_monitor_exit_icall_raw,
// token 7592,
ves_icall_System_Threading_Monitor_Monitor_test_synchronised_raw,
// token 7593,
ves_icall_System_Threading_Monitor_Monitor_pulse_raw,
// token 7595,
ves_icall_System_Threading_Monitor_Monitor_pulse_all_raw,
// token 7597,
ves_icall_System_Threading_Monitor_Monitor_wait_raw,
// token 7599,
ves_icall_System_Threading_Monitor_Monitor_try_enter_with_atomic_var_raw,
// token 7610,
ves_icall_System_Threading_Thread_GetCurrentProcessorNumber_raw,
// token 7619,
ves_icall_System_Threading_Thread_InitInternal_raw,
// token 7620,
ves_icall_System_Threading_Thread_GetCurrentThread,
// token 7622,
ves_icall_System_Threading_InternalThread_Thread_free_internal_raw,
// token 7623,
ves_icall_System_Threading_Thread_GetState_raw,
// token 7624,
ves_icall_System_Threading_Thread_SetState_raw,
// token 7625,
ves_icall_System_Threading_Thread_ClrState_raw,
// token 7626,
ves_icall_System_Threading_Thread_SetName_icall_raw,
// token 7628,
ves_icall_System_Threading_Thread_YieldInternal,
// token 7630,
ves_icall_System_Threading_Thread_SetPriority_raw,
// token 8676,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_PrepareForAssemblyLoadContextRelease_raw,
// token 8680,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_GetLoadContextForAssembly_raw,
// token 8682,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFile_raw,
// token 8683,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalInitializeNativeALC_raw,
// token 8684,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalLoadFromStream_raw,
// token 8685,
ves_icall_System_Runtime_Loader_AssemblyLoadContext_InternalGetLoadedAssemblies_raw,
// token 8736,
ves_icall_System_GCHandle_InternalAlloc_raw,
// token 8737,
ves_icall_System_GCHandle_InternalFree_raw,
// token 8738,
ves_icall_System_GCHandle_InternalGet_raw,
// token 8739,
ves_icall_System_GCHandle_InternalSet_raw,
// token 8758,
ves_icall_System_Runtime_InteropServices_Marshal_GetLastPInvokeError,
// token 8759,
ves_icall_System_Runtime_InteropServices_Marshal_SetLastPInvokeError,
// token 8760,
ves_icall_System_Runtime_InteropServices_Marshal_StructureToPtr_raw,
// token 8761,
ves_icall_System_Runtime_InteropServices_Marshal_IsPinnableType_raw,
// token 8794,
ves_icall_System_Runtime_InteropServices_NativeLibrary_LoadByName_raw,
// token 8841,
mono_object_hash_icall_raw,
// token 8844,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetObjectValue_raw,
// token 8853,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_GetUninitializedObjectInternal_raw,
// token 8854,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_InitializeArray_raw,
// token 8855,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_RunClassConstructor_raw,
// token 8856,
ves_icall_System_Runtime_CompilerServices_RuntimeHelpers_SufficientExecutionStack,
// token 9121,
ves_icall_System_Reflection_Assembly_GetExecutingAssembly_raw,
// token 9122,
ves_icall_System_Reflection_Assembly_GetEntryAssembly_raw,
// token 9127,
ves_icall_System_Reflection_Assembly_InternalLoad_raw,
// token 9128,
ves_icall_System_Reflection_Assembly_InternalGetType_raw,
// token 9176,
mono_digest_get_public_token,
// token 9177,
ves_icall_System_Reflection_AssemblyName_GetNativeName,
// token 9178,
ves_icall_System_Reflection_AssemblyName_ParseAssemblyName,
// token 9206,
ves_icall_MonoCustomAttrs_GetCustomAttributesInternal_raw,
// token 9212,
ves_icall_MonoCustomAttrs_GetCustomAttributesDataInternal_raw,
// token 9219,
ves_icall_MonoCustomAttrs_IsDefinedInternal_raw,
// token 9229,
ves_icall_System_Reflection_FieldInfo_internal_from_handle_type_raw,
// token 9233,
ves_icall_System_Reflection_FieldInfo_get_marshal_info_raw,
// token 9325,
ves_icall_System_Reflection_RuntimeAssembly_get_EntryPoint_raw,
// token 9335,
ves_icall_System_Reflection_RuntimeAssembly_GetExportedTypes_raw,
// token 9345,
ves_icall_System_Reflection_RuntimeAssembly_get_location_raw,
// token 9346,
ves_icall_System_Reflection_RuntimeAssembly_get_code_base_raw,
// token 9347,
ves_icall_System_Reflection_RuntimeAssembly_get_fullname_raw,
// token 9348,
ves_icall_System_Reflection_RuntimeAssembly_InternalImageRuntimeVersion_raw,
// token 9349,
ves_icall_System_Reflection_Assembly_GetManifestModuleInternal_raw,
// token 9350,
ves_icall_System_Reflection_RuntimeAssembly_GetModulesInternal_raw,
// token 9356,
ves_icall_System_Reflection_RuntimeCustomAttributeData_ResolveArgumentsInternal_raw,
// token 9372,
ves_icall_RuntimeEventInfo_get_event_info_raw,
// token 9393,
ves_icall_reflection_get_token_raw,
// token 9394,
ves_icall_System_Reflection_EventInfo_internal_from_handle_type_raw,
// token 9403,
ves_icall_RuntimeFieldInfo_ResolveType_raw,
// token 9405,
ves_icall_RuntimeFieldInfo_GetParentType_raw,
// token 9412,
ves_icall_RuntimeFieldInfo_GetFieldOffset_raw,
// token 9413,
ves_icall_RuntimeFieldInfo_GetValueInternal_raw,
// token 9416,
ves_icall_RuntimeFieldInfo_SetValueInternal_raw,
// token 9418,
ves_icall_RuntimeFieldInfo_GetRawConstantValue_raw,
// token 9423,
ves_icall_reflection_get_token_raw,
// token 9429,
ves_icall_get_method_info_raw,
// token 9430,
ves_icall_get_method_attributes,
// token 9437,
ves_icall_System_Reflection_MonoMethodInfo_get_parameter_info_raw,
// token 9439,
ves_icall_System_MonoMethodInfo_get_retval_marshal_raw,
// token 9449,
ves_icall_System_Reflection_RuntimeMethodInfo_GetMethodFromHandleInternalType_native_raw,
// token 9452,
ves_icall_RuntimeMethodInfo_get_name_raw,
// token 9453,
ves_icall_RuntimeMethodInfo_get_base_method_raw,
// token 9454,
ves_icall_reflection_get_token_raw,
// token 9465,
ves_icall_InternalInvoke_raw,
// token 9477,
ves_icall_RuntimeMethodInfo_GetPInvoke_raw,
// token 9483,
ves_icall_RuntimeMethodInfo_MakeGenericMethod_impl_raw,
// token 9484,
ves_icall_RuntimeMethodInfo_GetGenericArguments_raw,
// token 9485,
ves_icall_RuntimeMethodInfo_GetGenericMethodDefinition_raw,
// token 9487,
ves_icall_RuntimeMethodInfo_get_IsGenericMethodDefinition_raw,
// token 9488,
ves_icall_RuntimeMethodInfo_get_IsGenericMethod_raw,
// token 9498,
ves_icall_InternalInvoke_raw,
// token 9517,
ves_icall_reflection_get_token_raw,
// token 9539,
ves_icall_reflection_get_token_raw,
// token 9540,
ves_icall_System_Reflection_RuntimeModule_GetMDStreamVersion_raw,
// token 9541,
ves_icall_System_Reflection_RuntimeModule_InternalGetTypes_raw,
// token 9542,
ves_icall_System_Reflection_RuntimeModule_GetGuidInternal_raw,
// token 9543,
ves_icall_System_Reflection_RuntimeModule_ResolveMethodToken_raw,
// token 9560,
ves_icall_reflection_get_token_raw,
// token 9565,
ves_icall_RuntimeParameterInfo_GetTypeModifiers_raw,
// token 9570,
ves_icall_RuntimePropertyInfo_get_property_info_raw,
// token 9601,
ves_icall_reflection_get_token_raw,
// token 9602,
ves_icall_System_Reflection_RuntimePropertyInfo_internal_from_handle_type_raw,
// token 10090,
ves_icall_AssemblyBuilder_basic_init_raw,
// token 10091,
ves_icall_AssemblyBuilder_UpdateNativeCustomAttributes_raw,
// token 10171,
ves_icall_CustomAttributeBuilder_GetBlob_raw,
// token 10250,
ves_icall_DynamicMethod_create_dynamic_method_raw,
// token 10511,
ves_icall_ModuleBuilder_basic_init_raw,
// token 10512,
ves_icall_ModuleBuilder_set_wrappers_type_raw,
// token 10521,
ves_icall_ModuleBuilder_getUSIndex_raw,
// token 10522,
ves_icall_ModuleBuilder_getToken_raw,
// token 10523,
ves_icall_ModuleBuilder_getMethodToken_raw,
// token 10529,
ves_icall_ModuleBuilder_RegisterToken_raw,
// token 10607,
ves_icall_TypeBuilder_create_runtime_class_raw,
// token 10779,
ves_icall_System_IO_Stream_HasOverriddenBeginEndRead_raw,
// token 10780,
ves_icall_System_IO_Stream_HasOverriddenBeginEndWrite_raw,
// token 11467,
ves_icall_System_Diagnostics_Debugger_IsLogging,
// token 11468,
ves_icall_System_Diagnostics_Debugger_Log,
// token 12291,
ves_icall_Mono_RuntimeClassHandle_GetTypeFromClass,
// token 12310,
ves_icall_Mono_RuntimeGPtrArrayHandle_GPtrArrayFree,
// token 12317,
ves_icall_Mono_RuntimeMarshal_FreeAssemblyName,
// token 12318,
ves_icall_Mono_SafeStringMarshal_StringToUtf8,
// token 12320,
ves_icall_Mono_SafeStringMarshal_GFree,
};
static uint8_t corlib_icall_handles [] = {
0,
1,
1,
0,
1,
1,
1,
0,
1,
0,
1,
1,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1,
0,
0,
0,
1,
0,
1,
1,
1,
1,
0,
1,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
0,
1,
1,
1,
1,
1,
1,
1,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1,
1,
0,
1,
1,
1,
1,
1,
0,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1,
0,
1,
1,
1,
1,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
0,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
0,
0,
0,
0,
0,
0,
0,
};
