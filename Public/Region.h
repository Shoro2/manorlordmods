#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ApprovalMemory.h"
#include "ClaimStatus.h"
#include "EAffinityType.h"
#include "EBuildingFunction.h"
#include "EConstructionStage.h"
#include "EGameplayEnvironment.h"
#include "EGrowthModifier.h"
#include "EItemSubcategory.h"
#include "EResidentialRequirement.h"
#include "ESettlementType.h"
#include "EStorageType.h"
#include "ETradeModifier.h"
#include "ETradePartnerLimit.h"
#include "ETradeRule.h"
#include "EUnitRole.h"
#include "FamilyConsumptionData.h"
#include "Good.h"
#include "LivingSpaceData.h"
#include "OnWorkerFamilyRemovedDelegate.h"
#include "Pair.h"
#include "Policy.h"
#include "Problem.h"
#include "RegionProviderInterface.h"
#include "SettlementRequirements.h"
#include "WorkerFamily.h"
#include "Region.generated.h"

class APawnCPP;
class ARegion;
class ASMBuildingMaster;
class ASMUnit;
class UApprovalComponent;
class UCityPlanningComponent;
class UInstancedStaticMeshComponent;
class UPerkComponent;

UCLASS(Blueprintable)
class MANORLORDS_API ARegion : public AActor, public IRegionProviderInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName regionUniqueTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString regionName;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWorkerFamilyRemoved OnWorkerFamilyRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESettlementType settlementType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARegion* outpostToRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isSettled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SettlementLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 tier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> squadsPresent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawnCPP* ownerPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* manor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 claimCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> residents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWorkerFamily> workerFamilies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> corpses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 retinueSquadID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString retinueName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isUnderAttack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float supplies_food;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float supplies_wood;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 regionalWealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAnyBuildingOnFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASMBuildingMaster* townCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCityPlanningComponent* CityPlanningComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPerkComponent* PerkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> Tech;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPolicy> policies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> policiesSigned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> taxRates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FProblem> problems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, int32> constructionReserve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> targetInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> Price;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ETradeRule> tradeRules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> forbidGlobalTradeGoodTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ETradePartnerLimit> tradePartnerLimits;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, uint8> tradeRouteLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ASMUnit*> tradeRouteMerchants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> tradeables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 nextLivestockOrderIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool autoBuyCommodities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 marketAtt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 expenses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UInstancedStaticMeshComponent*> regionalFoliage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UApprovalComponent* ApprovalComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Approval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FApprovalMemory> summedApprovalFactors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 publicOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FApprovalMemory> publicOrderMemory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FApprovalMemory> summedPublicOrderFactors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGood> overstockedGoods;
    
    ARegion(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void updateProblems();
    
    UFUNCTION(BlueprintCallable)
    void updateCropTypes();
    
    UFUNCTION(BlueprintCallable)
    void unlockTech(int32 techID);
    
    UFUNCTION(BlueprintCallable)
    bool unlockOneTradeLevel(int32 goodType);
    
    UFUNCTION(BlueprintCallable)
    bool unlockBranchStartQuest(int32 branchID);
    
    UFUNCTION(BlueprintCallable)
    void unassignFamily(int32 familyID);
    
    UFUNCTION(BlueprintCallable)
    void setTradeRouteLevelForGood(int32 goodType, uint8 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void setTech(int32 ID, int32 newTier);
    
    UFUNCTION(BlueprintCallable)
    void setShowTotalMarketDistribution(bool showFlag);
    
    UFUNCTION(BlueprintCallable)
    void setShowMarketDistribution(bool showFlag, EResidentialRequirement displayRequirement, EItemSubcategory InMustContainSubcategory);
    
    UFUNCTION(BlueprintCallable)
    void setProductionUnlimited(int32 goodType);
    
    UFUNCTION(BlueprintCallable)
    void setProductionLimit(int32 goodType, int32 NewLimit);
    
    UFUNCTION(BlueprintCallable)
    void setPolicySigned(int32 policyID, bool isSigned);
    
    UFUNCTION(BlueprintCallable)
    void setGlobalTradeAllowedForGood(int32 goodID, bool allowed);
    
    UFUNCTION(BlueprintCallable)
    void SetFamilyHome(int32 familyID, ASMBuildingMaster* newHome);
    
    UFUNCTION(BlueprintCallable)
    void setCraftingConsumptionUnlimited(int32 producedGoodType, int32 goodType);
    
    UFUNCTION(BlueprintCallable)
    void setCraftingConsumptionLimit(int32 producedGoodType, int32 goodType, int32 NewLimit);
    
    UFUNCTION(BlueprintCallable)
    void setConstructionReserveForGood(int32 goodType, int32 newReserveValue);
    
    UFUNCTION(BlueprintCallable)
    void renameRegion(const FString& NewName);
    
    UFUNCTION(BlueprintCallable)
    void removeWorkerFamilyAt(int32 familyID);
    
    UFUNCTION(BlueprintCallable)
    void redistributeMilitiaRecruits();
    
    UFUNCTION(BlueprintCallable)
    void recomodatePastureLivestock();
    
    UFUNCTION(BlueprintCallable)
    void reassignFamily(int32 familyID, ASMBuildingMaster* workplace);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isTechEnabled(int32 techID, int32 TechTier);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isTargetStockSetForGoodType(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isRegionStruggling();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isProductionLimited(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isOutpost();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isMapBorderRegion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isGlobalTradeAllowedForGood(int32 goodID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isCraftingConsumptionLimited(int32 producedGoodType, int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool isBeingClaimed(FClaimStatus& ClaimStatus);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasWeakFertility();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasSurplusOfGoodsMinusReservedSimple(const TArray<FGood>& needed, int32 producedGoodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasPolicy(int32 ID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasEnoughRouteLevelToTrade(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasEnoughPastureSpace();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasAnyUnassignedOxen();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool hasAnyHomelessFamilies();
    
    UFUNCTION(BlueprintCallable)
    void growPopulation();
    
    UFUNCTION(BlueprintCallable)
    void grantResources(const TArray<FGood>& resourcesToGrant, bool bAddLogPrompt);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getUnlockTradeLevelPriceForGoodType(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<ETradeModifier, int32> GetUnlockTradeLevelModifiersInPercents() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ASMUnit* getTradeRouteMerchantForGoodType(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 getTradeRouteLevel(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalStockOfDistributedGood(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalStableSpace();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalPastureSpace();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalPastureNeeds();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalNumReassignableFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalNumFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalNumAssignedFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalNumAssignableFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPair getTotalMarketVirtualStorageData(EStorageType storageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalLivestockCountOfType(EUnitRole AnimalType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalLivestockCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalImportExpenditure(ASMUnit* skipUnit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTotalFreeMarketStallLocations();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getTaxRate(const FName& taxType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint getSummedFactorsRecentPast(const TArray<FApprovalMemory>& factors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getStockOfMultipleGoods(const TArray<int32>& GoodTypes, TArray<FGood>& outGoods, bool minusReservation, bool sumNegative, bool allowEmpty);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getStockOfGoodMinusReservedForRallying(int32 Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getStockOfGoodIncludingEquipped(int32 Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getStockOfGood(int32 Type, bool minusReservation, bool bIncludePredictedCraftingOutput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getStock(bool includeReserved) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSettlementRequirements getSettlementRequirementFulfillment();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector getSettledRegionCenter();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuildingMaster*> getResidentialBuildings(bool includeNoRequirementHousing);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getRegionUniqueID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString getRegionName() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<ASMUnit*> getRegionBuilders();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FGood> getRegionalMarketSupply();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRegionalImportPriceModifierForGoodType(int32 goodType, float InBaseModifier) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRegionalExportPriceModifierForGoodType(int32 goodType, float InBaseModifier) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getProductionLimit(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<float> getPrices();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPriceOfGood(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPredictedHarvestForGoodType(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPredictedApprovalLossFromTaxes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getPopulationOfRole(EUnitRole populationRole);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumUnassignedLivestockOfType(int32 goodID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumUnassignedFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumTotalPopulation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumResidentsOfRoleAndLv(EUnitRole unitRole, int32 familyLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumResidentialBuildingsOfLvAndHigher(int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumResidentialBuildingsOfLv(int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumRequiredEqiupmentOfType(int32 goodID, bool includingAlreadyRallied);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumRecruitsNeeded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumProblemsOfType(const int32& Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumOccupiedPlots(int32& lvl1, int32& lvl2, int32& lvl3, int32& lvl4) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumHumanResidents();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumHomelessFamilies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumFamiliesOfLv(int32 familyLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumDevPointsSpent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumBurgagePlots(EConstructionStage InConstructionStage) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumAvailableRecruitsOfLv(int32 houseLv);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumAvailableRecruits();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumAssignedMilitaryStockOfType(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getNumAssignedMarketFamiliesPerBuildingFunction(EBuildingFunction buildingFunction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSettlementRequirements getNextSettlementLvRequirements();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<EGrowthModifier, int32> GetMonthlyPopGrowthModifiersWithValues() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMonthlyPopChange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMaxPolicies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPair getMarketVirtualStorageData(EStorageType storageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getMarketPercentageSupplied(EResidentialRequirement SupplyCategory, EItemSubcategory InLimitToSubcategory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPair getMarketFoodVarietyData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLivingSpaceData getLivingSpace() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float getLivestockPrice(const int32& livestockType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFinalUnlockTradeLevelModifier() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FFamilyConsumptionData> GetFamilyConsumptionData(const int32 familyID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<EGameplayEnvironment, float> GetEnviromentProportions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getCropTypes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getCraftingConsumptionLimit(int32 producedGoodType, int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getConstructionReserveForGood(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuildingMaster*> GetBuildings();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getBuildingCount(int32 bType, bool constructedOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void getAvailableRecruits(float minMeleeTraining, float minArcheryTraining, TArray<ASMUnit*>& outAllRecruits, TArray<ASMUnit*>& outFreeRecruits, int32 minHouseLv);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLivingSpaceData getAvailableLivingSpace() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 getAmtMarketSupplyToMeetDemand(int32 goodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMUnit*> getAllAvailableRecruits(bool includeNotDisbanded);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> getAllAvailablePolicies();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAffinityEffect(const EAffinityType Affinity);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EAffinityType> GetAffinitiesConnectedWithEnvironment(const EGameplayEnvironment Environment);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ASMBuildingMaster*> getActiveResidentialBuildings(bool includeNoRequirementHousing);
    
    UFUNCTION(BlueprintCallable)
    bool consumeRegionalWealth(int32 amt);
    
    UFUNCTION(BlueprintCallable)
    bool consumeGoodFromBuildingFunctionType(int32 goodType, int32 goodAmt, EBuildingFunction buildingFunction, bool respectReservation, bool bRedistributeMarketSupply);
    
    UFUNCTION(BlueprintCallable)
    bool consumeGood(int32 goodType, int32 goodAmt, ASMBuildingMaster* preferredBulding, bool scramble, bool respectReservation, bool bRedistributeMarketSupply);
    
    UFUNCTION(BlueprintCallable)
    void changeTradeRule(int32 goodID, ETradeRule newRule);
    
    UFUNCTION(BlueprintCallable)
    void changeTradePartnerLimit(int32 goodID, ETradePartnerLimit NewLimit);
    
    UFUNCTION(BlueprintCallable)
    void changeTaxRate(const FName& taxType, int32 NewRate);
    
    UFUNCTION(BlueprintCallable)
    void changeTargetInventory(int32 goodType, int32 Target);
    
    UFUNCTION(BlueprintCallable)
    void changeConstructionReserveBy(int32 goodType, int32 amt);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 calculateExpenses();
    
    UFUNCTION(BlueprintCallable)
    void assignFamily(int32 familyID, ASMBuildingMaster* workplace);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool areNextSettlementLvRequirementsFulfilled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool areAnyEnemySquadsPresent(bool includeEncamped);
    
    UFUNCTION(BlueprintCallable)
    void addRegionalWealth(int32 amt);
    
    UFUNCTION(BlueprintCallable)
    void AddNewFamilyMember(int32 familyID, ASMUnit* newMember);
    
    UFUNCTION(BlueprintCallable)
    int32 AddNewFamily(const TArray<ASMUnit*>& familyMembers);
    
    UFUNCTION(BlueprintCallable)
    void accomodateHomelessLivestock(ASMBuildingMaster* ignoreBuilding);
    
    UFUNCTION(BlueprintCallable)
    void accomodateHomelessFamilies(ASMBuildingMaster* ignoreBuilding);
    

    // Fix for true pure virtual functions not being implemented
};

