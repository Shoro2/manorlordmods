#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EProductionCategory.h"
#include "EYieldStatus.h"
#include "OnNewProductionAddedDelegate.h"
#include "OnNewTimeTrackedDelegate.h"
#include "ProductionTimeEntry.h"
#include "ProductionTrackerEntry.h"
#include "ProductionTrackerComponent.generated.h"

class AWeatherMaster;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MANORLORDS_API UProductionTrackerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 DateCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNewTimeTracked OnNewTimeTracked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNewProductionAdded OnNewProductionAdded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AWeatherMaster* weatherMasterPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProductionTimeEntry> timeEntries;
    
public:
    UProductionTrackerComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void setWeatherMasterPtr(AWeatherMaster* inWeatherMasterPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EYieldStatus GetYieldStatus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalTime() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<int32> GetTimePercentagesForAllCategories();
    
    UFUNCTION(BlueprintCallable)
    int32 GetTimePercentageForSpecificCategory(const EProductionCategory InCategory);
    
    UFUNCTION(BlueprintCallable)
    TArray<FProductionTimeEntry> getTimeEntries();
    
    UFUNCTION(BlueprintCallable)
    int32 GetNumberOfGoodTypesInLog();
    
    UFUNCTION(BlueprintPure)
    TMap<int32, int32> getGoodsProducedOver(const int64 NumDays) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FProductionTrackerEntry> GetEntriesOfItemType(const int32 ItemType);
    
    UFUNCTION(BlueprintPure)
    int64 ageOfBuildingInDays() const;
    
};

