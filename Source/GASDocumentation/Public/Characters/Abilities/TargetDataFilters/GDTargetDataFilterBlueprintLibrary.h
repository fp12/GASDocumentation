#pragma once

#include "Characters/Abilities/TargetDataFilters/GDNameTargetDataFilter.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GDTargetDataFilterBlueprintLibrary.generated.h"

class UGameplayAbility;

UCLASS(meta=(ScriptName="GDTargetDataFilterBlueprintLibrary"))
class GASDOCUMENTATION_API UGDTargetDataFilterBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
    
    /** Create a handle for filtering target data by name */
	UFUNCTION(BlueprintPure, Category = "Filter")
	static FGameplayTargetDataFilterHandle MakeGDNameFilterHandle(FGDNameTargetDataFilter Filter, AActor* FilterActor);

    /** Create a handle for filtering target data by name */
	UFUNCTION(BlueprintPure, Category = "Filter")
	static FGameplayTargetDataFilterHandle MakeGDNameFilterHandle_Simple(const UGameplayAbility* Ability, const FString& Name, bool CaseSensitive);
};