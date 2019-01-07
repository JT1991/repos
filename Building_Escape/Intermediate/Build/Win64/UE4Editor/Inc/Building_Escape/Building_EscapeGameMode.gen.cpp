// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Building_Escape/Building_EscapeGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBuilding_EscapeGameMode() {}
// Cross Module References
	BUILDING_ESCAPE_API UClass* Z_Construct_UClass_ABuilding_EscapeGameMode_NoRegister();
	BUILDING_ESCAPE_API UClass* Z_Construct_UClass_ABuilding_EscapeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_Building_Escape();
// End Cross Module References
	void ABuilding_EscapeGameMode::StaticRegisterNativesABuilding_EscapeGameMode()
	{
	}
	UClass* Z_Construct_UClass_ABuilding_EscapeGameMode_NoRegister()
	{
		return ABuilding_EscapeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ABuilding_EscapeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABuilding_EscapeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_Building_Escape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABuilding_EscapeGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Building_EscapeGameMode.h" },
		{ "ModuleRelativePath", "Building_EscapeGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABuilding_EscapeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABuilding_EscapeGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABuilding_EscapeGameMode_Statics::ClassParams = {
		&ABuilding_EscapeGameMode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009002ACu,
		nullptr, 0,
		nullptr, 0,
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ABuilding_EscapeGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ABuilding_EscapeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABuilding_EscapeGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABuilding_EscapeGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABuilding_EscapeGameMode, 3115573873);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABuilding_EscapeGameMode(Z_Construct_UClass_ABuilding_EscapeGameMode, &ABuilding_EscapeGameMode::StaticClass, TEXT("/Script/Building_Escape"), TEXT("ABuilding_EscapeGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABuilding_EscapeGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
