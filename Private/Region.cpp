#include "Region.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "ApprovalComponent.h"
#include "PerkComponent.h"

ARegion::ARegion(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->settlementType = ESettlementType::None;
    this->outpostToRegion = NULL;
    this->isSettled = false;
    this->SettlementLevel = 0;
    this->tier = 0;
    this->ownerPawn = NULL;
    this->manor = NULL;
    this->claimCost = 1000;
    this->retinueSquadID = 0;
    this->isUnderAttack = false;
    this->supplies_food = 0.00f;
    this->supplies_wood = 0.00f;
    this->regionalWealth = 0;
    this->bAnyBuildingOnFire = false;
    this->townCenter = NULL;
    this->CityPlanningComponent = NULL;
    this->PerkComponent = CreateDefaultSubobject<UPerkComponent>(TEXT("PerkComponent"));
    this->nextLivestockOrderIn = 0;
    this->autoBuyCommodities = true;
    this->marketAtt = 1;
    this->expenses = 0;
    this->ApprovalComponent = CreateDefaultSubobject<UApprovalComponent>(TEXT("ApprovalComponent"));
    this->Approval = 50;
    this->publicOrder = 100;
}

void ARegion::updateProblems() {
}

void ARegion::updateCropTypes() {
}

void ARegion::unlockTech(int32 techID) {
}

bool ARegion::unlockOneTradeLevel(int32 goodType) {
    return false;
}

bool ARegion::unlockBranchStartQuest(int32 branchID) {
    return false;
}

void ARegion::unassignFamily(int32 familyID) {
}

void ARegion::setTradeRouteLevelForGood(int32 goodType, uint8 NewLevel) {
}

void ARegion::setTech(int32 ID, int32 newTier) {
}

void ARegion::setShowTotalMarketDistribution(bool showFlag) {
}

void ARegion::setShowMarketDistribution(bool showFlag, EResidentialRequirement displayRequirement, EItemSubcategory InMustContainSubcategory) {
}

void ARegion::setProductionUnlimited(int32 goodType) {
}

void ARegion::setProductionLimit(int32 goodType, int32 NewLimit) {
}

void ARegion::setPolicySigned(int32 policyID, bool isSigned) {
}

void ARegion::setGlobalTradeAllowedForGood(int32 goodID, bool allowed) {
}

void ARegion::SetFamilyHome(int32 familyID, ASMBuildingMaster* newHome) {
}

void ARegion::setCraftingConsumptionUnlimited(int32 producedGoodType, int32 goodType) {
}

void ARegion::setCraftingConsumptionLimit(int32 producedGoodType, int32 goodType, int32 NewLimit) {
}

void ARegion::setConstructionReserveForGood(int32 goodType, int32 newReserveValue) {
}

void ARegion::renameRegion(const FString& NewName) {
}

void ARegion::removeWorkerFamilyAt(int32 familyID) {
}

void ARegion::redistributeMilitiaRecruits() {
}

void ARegion::recomodatePastureLivestock() {
}

void ARegion::reassignFamily(int32 familyID, ASMBuildingMaster* workplace) {
}

bool ARegion::isTechEnabled(int32 techID, int32 TechTier) {
    return false;
}

bool ARegion::isTargetStockSetForGoodType(int32 goodType) {
    return false;
}

bool ARegion::isRegionStruggling() {
    return false;
}

bool ARegion::isProductionLimited(int32 goodType) {
    return false;
}

bool ARegion::isOutpost() {
    return false;
}

bool ARegion::isMapBorderRegion() {
    return false;
}

bool ARegion::isGlobalTradeAllowedForGood(int32 goodID) {
    return false;
}

bool ARegion::isCraftingConsumptionLimited(int32 producedGoodType, int32 goodType) {
    return false;
}

bool ARegion::isBeingClaimed(FClaimStatus& ClaimStatus) {
    return false;
}

bool ARegion::hasWeakFertility() {
    return false;
}

bool ARegion::hasSurplusOfGoodsMinusReservedSimple(const TArray<FGood>& needed, int32 producedGoodType) {
    return false;
}

bool ARegion::hasPolicy(int32 ID) {
    return false;
}

bool ARegion::hasEnoughRouteLevelToTrade(int32 goodType) {
    return false;
}

bool ARegion::hasEnoughPastureSpace() {
    return false;
}

bool ARegion::hasAnyUnassignedOxen() {
    return false;
}

bool ARegion::hasAnyHomelessFamilies() {
    return false;
}

void ARegion::growPopulation() {
}

void ARegion::grantResources(const TArray<FGood>& resourcesToGrant, bool bAddLogPrompt) {
}

int32 ARegion::getUnlockTradeLevelPriceForGoodType(int32 goodType) {
    return 0;
}

TMap<ETradeModifier, int32> ARegion::GetUnlockTradeLevelModifiersInPercents() const {
    return TMap<ETradeModifier, int32>();
}

ASMUnit* ARegion::getTradeRouteMerchantForGoodType(int32 goodType) {
    return NULL;
}

uint8 ARegion::getTradeRouteLevel(int32 goodType) {
    return 0;
}

int32 ARegion::getTotalStockOfDistributedGood(int32 goodType) {
    return 0;
}

int32 ARegion::getTotalStableSpace() {
    return 0;
}

int32 ARegion::getTotalPastureSpace() {
    return 0;
}

int32 ARegion::getTotalPastureNeeds() {
    return 0;
}

int32 ARegion::GetTotalNumReassignableFamilies() {
    return 0;
}

int32 ARegion::getTotalNumFamilies() {
    return 0;
}

int32 ARegion::getTotalNumAssignedFamilies() {
    return 0;
}

int32 ARegion::getTotalNumAssignableFamilies() {
    return 0;
}

FPair ARegion::getTotalMarketVirtualStorageData(EStorageType storageType) {
    return FPair{};
}

int32 ARegion::GetTotalLivestockCountOfType(EUnitRole AnimalType) const {
    return 0;
}

int32 ARegion::getTotalLivestockCount() {
    return 0;
}

int32 ARegion::getTotalImportExpenditure(ASMUnit* skipUnit) {
    return 0;
}

int32 ARegion::getTotalFreeMarketStallLocations() {
    return 0;
}

int32 ARegion::getTaxRate(const FName& taxType) {
    return 0;
}

FIntPoint ARegion::getSummedFactorsRecentPast(const TArray<FApprovalMemory>& factors) {
    return FIntPoint{};
}

int32 ARegion::getStockOfMultipleGoods(const TArray<int32>& GoodTypes, TArray<FGood>& outGoods, bool minusReservation, bool sumNegative, bool allowEmpty) {
    return 0;
}

int32 ARegion::getStockOfGoodMinusReservedForRallying(int32 Type) {
    return 0;
}

int32 ARegion::getStockOfGoodIncludingEquipped(int32 Type) {
    return 0;
}

int32 ARegion::getStockOfGood(int32 Type, bool minusReservation, bool bIncludePredictedCraftingOutput) {
    return 0;
}

TArray<FGood> ARegion::getStock(bool includeReserved) const {
    return TArray<FGood>();
}

FSettlementRequirements ARegion::getSettlementRequirementFulfillment() {
    return FSettlementRequirements{};
}

FVector ARegion::getSettledRegionCenter() {
    return FVector{};
}

TArray<ASMBuildingMaster*> ARegion::getResidentialBuildings(bool includeNoRequirementHousing) {
    return TArray<ASMBuildingMaster*>();
}

int32 ARegion::getRegionUniqueID() {
    return 0;
}

FString ARegion::getRegionName() const {
    return TEXT("");
}

TArray<ASMUnit*> ARegion::getRegionBuilders() {
    return TArray<ASMUnit*>();
}

TArray<FGood> ARegion::getRegionalMarketSupply() {
    return TArray<FGood>();
}

float ARegion::GetRegionalImportPriceModifierForGoodType(int32 goodType, float InBaseModifier) const {
    return 0.0f;
}

float ARegion::GetRegionalExportPriceModifierForGoodType(int32 goodType, float InBaseModifier) const {
    return 0.0f;
}

int32 ARegion::getProductionLimit(int32 goodType) {
    return 0;
}

TArray<float> ARegion::getPrices() {
    return TArray<float>();
}

int32 ARegion::getPriceOfGood(int32 goodType) {
    return 0;
}

int32 ARegion::getPredictedHarvestForGoodType(int32 goodType) {
    return 0;
}

int32 ARegion::getPredictedApprovalLossFromTaxes() {
    return 0;
}

int32 ARegion::getPopulationOfRole(EUnitRole populationRole) {
    return 0;
}

int32 ARegion::getNumUnassignedLivestockOfType(int32 goodID) {
    return 0;
}

int32 ARegion::getNumUnassignedFamilies() {
    return 0;
}

int32 ARegion::getNumTotalPopulation() {
    return 0;
}

int32 ARegion::getNumResidentsOfRoleAndLv(EUnitRole unitRole, int32 familyLevel) {
    return 0;
}

int32 ARegion::getNumResidentialBuildingsOfLvAndHigher(int32 Level) {
    return 0;
}

int32 ARegion::getNumResidentialBuildingsOfLv(int32 Level) {
    return 0;
}

int32 ARegion::getNumRequiredEqiupmentOfType(int32 goodID, bool includingAlreadyRallied) {
    return 0;
}

int32 ARegion::getNumRecruitsNeeded() {
    return 0;
}

int32 ARegion::getNumProblemsOfType(const int32& Type) {
    return 0;
}

int32 ARegion::getNumOccupiedPlots(int32& lvl1, int32& lvl2, int32& lvl3, int32& lvl4) const {
    return 0;
}

int32 ARegion::getNumHumanResidents() {
    return 0;
}

int32 ARegion::getNumHomelessFamilies() {
    return 0;
}

int32 ARegion::getNumFamiliesOfLv(int32 familyLevel) {
    return 0;
}

int32 ARegion::getNumDevPointsSpent() {
    return 0;
}

int32 ARegion::getNumBurgagePlots(EConstructionStage InConstructionStage) const {
    return 0;
}

int32 ARegion::getNumAvailableRecruitsOfLv(int32 houseLv) {
    return 0;
}

int32 ARegion::getNumAvailableRecruits() {
    return 0;
}

int32 ARegion::getNumAssignedMilitaryStockOfType(int32 goodType) {
    return 0;
}

int32 ARegion::getNumAssignedMarketFamiliesPerBuildingFunction(EBuildingFunction buildingFunction) {
    return 0;
}

FSettlementRequirements ARegion::getNextSettlementLvRequirements() {
    return FSettlementRequirements{};
}

TMap<EGrowthModifier, int32> ARegion::GetMonthlyPopGrowthModifiersWithValues() const {
    return TMap<EGrowthModifier, int32>();
}

int32 ARegion::GetMonthlyPopChange() const {
    return 0;
}

int32 ARegion::getMaxPolicies() {
    return 0;
}

FPair ARegion::getMarketVirtualStorageData(EStorageType storageType) {
    return FPair{};
}

int32 ARegion::getMarketPercentageSupplied(EResidentialRequirement SupplyCategory, EItemSubcategory InLimitToSubcategory) {
    return 0;
}

FPair ARegion::getMarketFoodVarietyData() {
    return FPair{};
}

FLivingSpaceData ARegion::getLivingSpace() const {
    return FLivingSpaceData{};
}

float ARegion::getLivestockPrice(const int32& livestockType) {
    return 0.0f;
}

float ARegion::GetFinalUnlockTradeLevelModifier() const {
    return 0.0f;
}

TArray<FFamilyConsumptionData> ARegion::GetFamilyConsumptionData(const int32 familyID) {
    return TArray<FFamilyConsumptionData>();
}

TMap<EGameplayEnvironment, float> ARegion::GetEnviromentProportions() {
    return TMap<EGameplayEnvironment, float>();
}

TArray<int32> ARegion::getCropTypes() {
    return TArray<int32>();
}

int32 ARegion::getCraftingConsumptionLimit(int32 producedGoodType, int32 goodType) {
    return 0;
}

int32 ARegion::getConstructionReserveForGood(int32 goodType) {
    return 0;
}

TArray<ASMBuildingMaster*> ARegion::GetBuildings() {
    return TArray<ASMBuildingMaster*>();
}

int32 ARegion::getBuildingCount(int32 bType, bool constructedOnly) {
    return 0;
}

void ARegion::getAvailableRecruits(float minMeleeTraining, float minArcheryTraining, TArray<ASMUnit*>& outAllRecruits, TArray<ASMUnit*>& outFreeRecruits, int32 minHouseLv) {
}

FLivingSpaceData ARegion::getAvailableLivingSpace() const {
    return FLivingSpaceData{};
}

int32 ARegion::getAmtMarketSupplyToMeetDemand(int32 goodType) {
    return 0;
}

TArray<ASMUnit*> ARegion::getAllAvailableRecruits(bool includeNotDisbanded) {
    return TArray<ASMUnit*>();
}

TArray<int32> ARegion::getAllAvailablePolicies() {
    return TArray<int32>();
}

float ARegion::GetAffinityEffect(const EAffinityType Affinity) {
    return 0.0f;
}

TArray<EAffinityType> ARegion::GetAffinitiesConnectedWithEnvironment(const EGameplayEnvironment Environment) {
    return TArray<EAffinityType>();
}

TArray<ASMBuildingMaster*> ARegion::getActiveResidentialBuildings(bool includeNoRequirementHousing) {
    return TArray<ASMBuildingMaster*>();
}

bool ARegion::consumeRegionalWealth(int32 amt) {
    return false;
}

bool ARegion::consumeGoodFromBuildingFunctionType(int32 goodType, int32 goodAmt, EBuildingFunction buildingFunction, bool respectReservation, bool bRedistributeMarketSupply) {
    return false;
}

bool ARegion::consumeGood(int32 goodType, int32 goodAmt, ASMBuildingMaster* preferredBulding, bool scramble, bool respectReservation, bool bRedistributeMarketSupply) {
    return false;
}

void ARegion::changeTradeRule(int32 goodID, ETradeRule newRule) {
}

void ARegion::changeTradePartnerLimit(int32 goodID, ETradePartnerLimit NewLimit) {
}

void ARegion::changeTaxRate(const FName& taxType, int32 NewRate) {
}

void ARegion::changeTargetInventory(int32 goodType, int32 Target) {
}

void ARegion::changeConstructionReserveBy(int32 goodType, int32 amt) {
}

int32 ARegion::calculateExpenses() {
    return 0;
}

void ARegion::assignFamily(int32 familyID, ASMBuildingMaster* workplace) {
}

bool ARegion::areNextSettlementLvRequirementsFulfilled() {
    return false;
}

bool ARegion::areAnyEnemySquadsPresent(bool includeEncamped) {
    return false;
}

void ARegion::addRegionalWealth(int32 amt) {
}

void ARegion::AddNewFamilyMember(int32 familyID, ASMUnit* newMember) {
}

int32 ARegion::AddNewFamily(const TArray<ASMUnit*>& familyMembers) {
    return 0;
}

void ARegion::accomodateHomelessLivestock(ASMBuildingMaster* ignoreBuilding) {
}

void ARegion::accomodateHomelessFamilies(ASMBuildingMaster* ignoreBuilding) {
}


