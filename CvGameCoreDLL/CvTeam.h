#pragma once

// team.h

#ifndef CIV4_TEAM_H
#define CIV4_TEAM_H

//#include "CvEnums.h"

class CvArea;

class CvTeam
{

public:
	CvTeam();
	virtual ~CvTeam();

	DllExport void init(TeamTypes eID);
	DllExport void reset(TeamTypes eID = NO_TEAM, bool bConstructorCall = false);

protected:

	void uninit();

public:

/********************************************************************************/
/*		BETTER_BTS_AI_MOD						12/30/08		jdog5000		*/
/*																				*/
/*		     																	*/
/********************************************************************************/
	void resetPlotAndCityData( );
/********************************************************************************/
/*		BETTER_BTS_AI_MOD						END								*/
/********************************************************************************/


	void addTeam(TeamTypes eTeam);																								// Exposed to Python
	void shareItems(TeamTypes eTeam);
	void shareCounters(TeamTypes eTeam);
	void processBuilding(BuildingTypes eBuilding, int iChange);

	void doTurn();

	void updateYield();
	void updatePowerHealth();
	void updateCommerce();

	bool canChangeWarPeace(TeamTypes eTeam, bool bAllowVassal = false) const;																			// Exposed to Python
	DllExport bool canDeclareWar(TeamTypes eTeam) const;																// Exposed to Python
	bool canEventuallyDeclareWar(TeamTypes eTeam) const; // bbai, Exposed to Python
	//DllExport void declareWar(TeamTypes eTeam, bool bNewDiplo, WarPlanTypes eWarPlan); // Exposed to Python
	void declareWar(TeamTypes eTeam, bool bNewDiplo, WarPlanTypes eWarPlan, bool bPrimaryDoW = true, // K-Mod added bPrimaryDoW, Exposed to Python
			PlayerTypes sponsor = NO_PLAYER); // advc.100
	DllExport void makePeace(TeamTypes eTeam, bool bBumpUnits = true);																		// Exposed to Python
	// advc.100b To avoid changing the signature of the function above:
	void makePeaceBulk(TeamTypes eTeam, bool bBumpUnits = true, TeamTypes broker = NO_TEAM,
			bool bCapitulate = false, // advc.034
			CLinkList<TradeData>* reparations = NULL); // advc.039
	//bool canContact(TeamTypes eTeam) const; // Exposed to Python
	bool canContact(TeamTypes eTeam, bool bCheckWillingness = false) const; // K-Mod, Exposed to Python
	void meet(TeamTypes eTeam, bool bNewDiplo);																		// Exposed to Python
	void signPeaceTreaty(TeamTypes eTeam); // K-Mod
	void signOpenBorders(TeamTypes eTeam);																				// Exposed to Python
	void signDisengage(TeamTypes otherId); // advc.034
	void signDefensivePact(TeamTypes eTeam);																			// Exposed to Python
	// advc.003: const qualifier added
	bool canSignDefensivePact(TeamTypes eTeam) const;

	int getAssets() const;																															// Exposed to Python
	int getPower(bool bIncludeVassals) const;																																// Exposed to Python
	int getDefensivePower(TeamTypes eExcludeTeam = NO_TEAM) const;	// Exposed to Python
	int getEnemyPower() const;
	int getNumNukeUnits() const;																												// Exposed to Python
	int getVotes(VoteTypes eVote, VoteSourceTypes eVoteSource) const;
	bool isVotingMember(VoteSourceTypes eVoteSource) const;
	bool isFullMember(VoteSourceTypes eVoteSource) const;

/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      01/10/09                                jdog5000      */
/*                                                                                              */
/*                                                                                              */
/************************************************************************************************/
	bool isMasterPlanningLandWar(CvArea* pArea);
	bool isMasterPlanningSeaWar(CvArea* pArea);
	/*  <advc.003> Adding default for bIgnoreMinors to all of these. Also note that
		getAtWarCount is named deceptively similar to CvTeamAI::AI_getAtWarCounter */
	int getAtWarCount(bool bIgnoreMinors = true, bool bIgnoreVassals = false) const;																				// Exposed to Python
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/
	bool allWarsShared(TeamTypes otherId, // dlph.3
			/*  advc.130f: If false, check only if the war enemies of this team
				are included in those of otherId. (set inclusion) */
			bool checkBothWays = true) const;
	bool anyWarShared(TeamTypes otherId) const; // advc.130s
	int getWarPlanCount(WarPlanTypes eWarPlan, bool bIgnoreMinors = true) const;								// Exposed to Python
	int getAnyWarPlanCount(bool bIgnoreMinors = true) const;																		// Exposed to Python
	int getChosenWarCount(bool bIgnoreMinors = true) const;																		// Exposed to Python
	int getHasMetCivCount(bool bIgnoreMinors = true) const;																		// Exposed to Python
	// </advc.003>
	bool hasMetHuman() const;																														// Exposed to Python
	int getDefensivePactCount(TeamTypes eTeam = NO_TEAM) const;																									// Exposed to Python
	int getVassalCount(TeamTypes eTeam = NO_TEAM) const;
	bool isAVassal() const;																							// Exposed to Python
	bool canVassalRevolt(TeamTypes eMaster) const;
	 // advc.112: Moved a bit of code from canVassalRevolt into this subroutine
	bool isLossesAllowRevolt(TeamTypes eMaster) const;
	int getUnitClassMaking(UnitClassTypes eUnitClass) const;														// Exposed to Python
	int getUnitClassCountPlusMaking(UnitClassTypes eIndex) const;												// Exposed to Python
	int getBuildingClassMaking(BuildingClassTypes eBuildingClass) const;								// Exposed to Python
	int getBuildingClassCountPlusMaking(BuildingClassTypes eIndex) const;								// Exposed to Python
	int getHasReligionCount(ReligionTypes eReligion) const;															// Exposed to Python
	int getHasCorporationCount(CorporationTypes eCorporation) const;															// Exposed to Python

	int countTotalCulture() const; // Exposed to Python

	bool isInContactWithBarbarians() const; // advc.302

	int countNumUnitsByArea(CvArea* pArea) const;																				// Exposed to Python
	int countNumCitiesByArea(CvArea* pArea) const;																			// Exposed to Python
	int countTotalPopulationByArea(CvArea* pArea) const;																// Exposed to Python
	int countPowerByArea(CvArea* pArea) const;																					// Exposed to Python
	int countEnemyPowerByArea(CvArea* pArea) const;																			// Exposed to Python
	int countEnemyCitiesByArea(CvArea* pArea) const; // K-Mod
	int countEnemyPopulationByArea(CvArea* pArea) const; // bbai
	int countNumAIUnitsByArea(CvArea* pArea, UnitAITypes eUnitAI) const;								// Exposed to Python
	int countEnemyDangerByArea(CvArea* pArea, TeamTypes eEnemyTeam = NO_TEAM) const;																		// Exposed to Python
	EraTypes getCurrentEra() const; // advc.112b
	// K-Mod
	int getTypicalUnitValue(UnitAITypes eUnitAI, DomainTypes eDomain = NO_DOMAIN) const;

	int getResearchCost(TechTypes eTech, bool bGlobalModifiers = true, bool bTeamSizeModifiers = true) const; // (K-Mod added bools) Exposed to Python
	int getResearchLeft(TechTypes eTech) const;																// Exposed to Python

	bool hasHolyCity(ReligionTypes eReligion) const;																		// Exposed to Python
	bool hasHeadquarters(CorporationTypes eCorporation) const;																		// Exposed to Python
	bool hasBonus(BonusTypes eBonus) const;
	bool isBonusObsolete(BonusTypes eBonus) const;
	// <advc.301>
	bool canSeeReqBonuses(UnitTypes u);
	bool isRevealed(BonusTypes b);
	// </advc.301>

	bool isHuman() const;																																// Exposed to Python
	bool isBarbarian() const;																														// Exposed to Python
	bool isMinorCiv() const;																														// Exposed to Python
	PlayerTypes getLeaderID() const;																										// Exposed to Python
	void updateLeaderID(); // advc.003b
	PlayerTypes getSecretaryID() const;																									// Exposed to Python
	HandicapTypes getHandicapType() const;																							// Exposed to Python
	DllExport CvWString getName() const;																								// Exposed to Python
	CvWString getReplayName() const; // K-Mod

	DllExport int getNumMembers() const;																								// Exposed to Python
	void changeNumMembers(int iChange);

	DllExport int getAliveCount() const; // advc.155: Exposed to Python
	DllExport int isAlive() const;																											// Exposed to Python
	void changeAliveCount(int iChange);

	int getEverAliveCount() const;
	int isEverAlive() const;																														// Exposed to Python
	void changeEverAliveCount(int iChange);

	int getNumCities() const;																														// Exposed to Python
	void changeNumCities(int iChange);							

	int getTotalPopulation(bool bCheckVassals = true) const;																											// Exposed to Python
	void changeTotalPopulation(int iChange);	

	int getTotalLand(bool bCheckVassals = true) const;																														// Exposed to Python  
	void changeTotalLand(int iChange);														

	int getNukeInterception() const;																										// Exposed to Python
	void changeNukeInterception(int iChange);																			// Exposed to Python

	int getForceTeamVoteEligibilityCount(VoteSourceTypes eVoteSource) const;																				// Exposed to Python	
	bool isForceTeamVoteEligible(VoteSourceTypes eVoteSource) const;																								// Exposed to Python	
	void changeForceTeamVoteEligibilityCount(VoteSourceTypes eVoteSource, int iChange);												// Exposed to Python	
																																								
	int getExtraWaterSeeFromCount() const;																							// Exposed to Python	
	bool isExtraWaterSeeFrom() const;																										// Exposed to Python	
	void changeExtraWaterSeeFromCount(int iChange);																// Exposed to Python	
																																								
	int getMapTradingCount() const;																											// Exposed to Python	
	bool isMapTrading() const;																													// Exposed to Python	
	void changeMapTradingCount(int iChange);																			// Exposed to Python	
																																								
	int getTechTradingCount() const;																										// Exposed to Python	
	bool isTechTrading() const;																													// Exposed to Python	
	void changeTechTradingCount(int iChange);																			// Exposed to Python	
																																								
	int getGoldTradingCount() const;																										// Exposed to Python	
	bool isGoldTrading() const;																													// Exposed to Python	
	void changeGoldTradingCount(int iChange);																			// Exposed to Python	
																																								
	int getOpenBordersTradingCount() const;																							// Exposed to Python	
	bool isOpenBordersTrading() const;																				// Exposed to Python	
	void changeOpenBordersTradingCount(int iChange);															// Exposed to Python	
																																								
	int getDefensivePactTradingCount() const;																						// Exposed to Python	
	bool isDefensivePactTrading() const;																								// Exposed to Python						
	void changeDefensivePactTradingCount(int iChange);														// Exposed to Python	
																																									
	int getPermanentAllianceTradingCount() const;																				// Exposed to Python	
	bool isPermanentAllianceTrading() const;																						// Exposed to Python						
	void changePermanentAllianceTradingCount(int iChange);												// Exposed to Python	
																																									
	int getVassalTradingCount() const;																				// Exposed to Python	
	bool isVassalStateTrading() const;																						// Exposed to Python						
	void changeVassalTradingCount(int iChange);												// Exposed to Python	

	int getBridgeBuildingCount() const;																									// Exposed to Python	
	bool isBridgeBuilding() const;																						// Exposed to Python						
	void changeBridgeBuildingCount(int iChange);																	// Exposed to Python	
																																								
	int getIrrigationCount() const;																											// Exposed to Python	
	bool isIrrigation() const;																								// Exposed to Python	
	void changeIrrigationCount(int iChange);																			// Exposed to Python	
																																								
	int getIgnoreIrrigationCount() const;																								// Exposed to Python	
	bool isIgnoreIrrigation() const;																					// Exposed to Python	
	void changeIgnoreIrrigationCount(int iChange);																// Exposed to Python	
																																								
	int getWaterWorkCount() const;																											// Exposed to Python	
	bool isWaterWork() const;																									// Exposed to Python	
	void changeWaterWorkCount(int iChange);																				// Exposed to Python	

	int getVassalPower() const;																							// Exposed to Python	
	void setVassalPower(int iPower);																					// Exposed to Python	
	int getMasterPower() const;																							// Exposed to Python	
	void setMasterPower(int iPower);																					// Exposed to Python	

	int getEnemyWarWearinessModifier() const;																																			// Exposed to Python
	void changeEnemyWarWearinessModifier(int iChange);						// Exposed to Python
	void changeWarWeariness(TeamTypes eOtherTeam, const CvPlot& kPlot, int iFactor);

	bool isMapCentering() const;																							// Exposed to Python	
	void setMapCentering(bool bNewValue);																					// Exposed to Python	
																																								
	TeamTypes getID() const;																											// Exposed to Python	

	int getStolenVisibilityTimer(TeamTypes eIndex) const;
	bool isStolenVisibility(TeamTypes eIndex) const;																		// Exposed to Python
	void setStolenVisibilityTimer(TeamTypes eIndex, int iNewValue);
	void changeStolenVisibilityTimer(TeamTypes eIndex, int iChange);

	int getWarWeariness(TeamTypes eIndex, bool bUseEnemyModifer = false) const; // Exposed to Python. K-Mod added bUseEnemyModifier.
	void setWarWeariness(TeamTypes eIndex, int iNewValue);												// Exposed to Python
	void changeWarWeariness(TeamTypes eIndex, int iChange);												// Exposed to Python

	int getTechShareCount(int iIndex) const;																						// Exposed to Python
	bool isTechShare(int iIndex) const;																									// Exposed to Python
	void changeTechShareCount(int iIndex, int iChange);														// Exposed to Python

	int getCommerceFlexibleCount(CommerceTypes eIndex) const;														// Exposed to Python
	bool isCommerceFlexible(CommerceTypes eIndex) const;																// Exposed to Python
	void changeCommerceFlexibleCount(CommerceTypes eIndex, int iChange);					// Exposed to Python

	int getExtraMoves(DomainTypes eIndex) const;																				// Exposed to Python
	void changeExtraMoves(DomainTypes eIndex, int iChange);							// Exposed to Python

	bool isHasMet(TeamTypes eIndex) const;																		// Exposed to Python
	void makeHasMet(TeamTypes eIndex, bool bNewDiplo);

	// K-Mod
	bool isHasSeen(TeamTypes eIndex) const { return m_abHasSeen[eIndex]; };
	void makeHasSeen(TeamTypes eIndex) { m_abHasSeen[eIndex] = true; };
	// K-Mod end

	DllExport bool isAtWar(TeamTypes eIndex) const;																			// Exposed to Python
	DllExport void setAtWar(TeamTypes eIndex, bool bNewValue);

	bool isPermanentWarPeace(TeamTypes eIndex) const;																		// Exposed to Python
	void setPermanentWarPeace(TeamTypes eIndex, bool bNewValue);									// Exposed to Python

	bool isFreeTrade(TeamTypes eIndex) const;																	// Exposed to Python
	bool isOpenBorders(TeamTypes eIndex) const;																// Exposed to Python
	void setOpenBorders(TeamTypes eIndex, bool bNewValue);
	// <advc.034>
	bool isDisengage(TeamTypes eIndex) const;
	void setDisengage(TeamTypes eIndex, bool bNewValue);
	void cancelDisengage(TeamTypes otherId);
	// </advc.034>
	bool isDefensivePact(TeamTypes eIndex) const;															// Exposed to Python
	void setDefensivePact(TeamTypes eIndex, bool bNewValue);

	bool isForcePeace(TeamTypes eIndex) const;																// Exposed to Python
	void setForcePeace(TeamTypes eIndex, bool bNewValue);
	// advc.104:
	int turnsOfForcedPeaceRemaining(TeamTypes tId) const;
	bool isVassal(TeamTypes eIndex) const;																// Exposed to Python
	void setVassal(TeamTypes eIndex, bool bNewValue, bool bCapitulated);
	// advc.155: Exposed to Python
	TeamTypes getMasterTeam() const; // K-Mod

	void assignVassal(TeamTypes eVassal, bool bSurrender) const;																// Exposed to Python
	void freeVassal(TeamTypes eVassal) const;																// Exposed to Python

	bool isCapitulated() const; // advc.130v: Exposed to Python

	int getRouteChange(RouteTypes eIndex) const;																				// Exposed to Python
	void changeRouteChange(RouteTypes eIndex, int iChange);												// Exposed to Python

	int getProjectCount(ProjectTypes eIndex) const;														// Exposed to Python
	DllExport int getProjectDefaultArtType(ProjectTypes eIndex) const;
	DllExport void setProjectDefaultArtType(ProjectTypes eIndex, int value);
	DllExport int getProjectArtType(ProjectTypes eIndex, int number) const;
	DllExport void setProjectArtType(ProjectTypes eIndex, int number, int value);
	bool isProjectMaxedOut(ProjectTypes eIndex, int iExtra = 0) const;									// Exposed to Python
	DllExport bool isProjectAndArtMaxedOut(ProjectTypes eIndex) const;
	void changeProjectCount(ProjectTypes eIndex, int iChange);		// Exposed to Python
	DllExport void finalizeProjectArtTypes();

	int getProjectMaking(ProjectTypes eIndex) const;																		// Exposed to Python
	void changeProjectMaking(ProjectTypes eIndex, int iChange);

	int getUnitClassCount(UnitClassTypes eIndex) const;																	// Exposed to Python
	bool isUnitClassMaxedOut(UnitClassTypes eIndex, int iExtra = 0) const;							// Exposed to Python
	void changeUnitClassCount(UnitClassTypes eIndex, int iChange);

	int getBuildingClassCount(BuildingClassTypes eIndex) const;													// Exposed to Python
	bool isBuildingClassMaxedOut(BuildingClassTypes eIndex, int iExtra = 0) const;			// Exposed to Python
	void changeBuildingClassCount(BuildingClassTypes eIndex, int iChange);

	int getObsoleteBuildingCount(BuildingTypes eIndex) const;
	bool isObsoleteBuilding(BuildingTypes eIndex) const;																// Exposed to Python
	void changeObsoleteBuildingCount(BuildingTypes eIndex, int iChange);

	int getResearchProgress(TechTypes eIndex) const;																						// Exposed to Python
	void setResearchProgress(TechTypes eIndex, int iNewValue, PlayerTypes ePlayer);									// Exposed to Python
	void changeResearchProgress(TechTypes eIndex, int iChange, PlayerTypes ePlayer);								// Exposed to Python
	int changeResearchProgressPercent(TechTypes eIndex, int iPercent, PlayerTypes ePlayer);

	int getTechCount(TechTypes eIndex) const;																										// Exposed to Python
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                      07/27/09                                jdog5000      */
/*                                                                                              */
/* General AI                                                                                   */
/************************************************************************************************/
	int getBestKnownTechScorePercent() const;
/************************************************************************************************/
/* BETTER_BTS_AI_MOD                       END                                                  */
/************************************************************************************************/

	int getTerrainTradeCount(TerrainTypes eIndex) const;
	bool isTerrainTrade(TerrainTypes eIndex) const;																												// Exposed to Python
	void changeTerrainTradeCount(TerrainTypes eIndex, int iChange);

	int getRiverTradeCount() const;
	bool isRiverTrade() const;																												// Exposed to Python
	void changeRiverTradeCount(int iChange);

	int getVictoryCountdown(VictoryTypes eIndex) const;																							// Exposed to Python
	void setVictoryCountdown(VictoryTypes eIndex, int iTurnsLeft);
	void changeVictoryCountdown(VictoryTypes eIndex, int iChange);
	int getVictoryDelay(VictoryTypes eVictory) const;
	DllExport bool canLaunch(VictoryTypes eVictory) const;		// Exposed to Python 
	void setCanLaunch(VictoryTypes eVictory, bool bCan);
	int getLaunchSuccessRate(VictoryTypes eVictory) const;		// Exposed to Python
	void resetVictoryProgress();
	bool hasSpaceshipArrived() const; // K-Mod, Exposed to Python

	bool isParent(TeamTypes eTeam) const;

	bool isHasTech(TechTypes eIndex) const;																																			// Exposed to Python
	void setHasTech(TechTypes eIndex, bool bNewValue, PlayerTypes ePlayer, bool bFirst, bool bAnnounce);	// Exposed to Python
	/* advc.004a: A hack that allows other classes to pretend that a team knows
	   a tech for some computation. Should be toggled back afterwards. */
	void setHasTechTemporarily(TechTypes tt, bool b);
	/* <advc.134a> NB: Looks like the several stages (finite state machine)
	   aren't needed after all; i.e. would work with just offeringPeace
	   set to either the team whose peace offer is incoming or NO_TEAM otherwise. */
	void advancePeaceOfferStage(TeamTypes aiTeam = NO_TEAM);
	private: TeamTypes offeringPeace; int peaceOfferStage;
	public: // </advc.134a>

	bool isNoTradeTech(TechTypes eIndex) const;																														// Exposed to Python
	void setNoTradeTech(TechTypes eIndex, bool bNewValue);																					// Exposed to Python

	int getImprovementYieldChange(ImprovementTypes eIndex1, YieldTypes eIndex2) const;										// Exposed to Python 
	void changeImprovementYieldChange(ImprovementTypes eIndex1, YieldTypes eIndex2, int iChange);		// Exposed to Python 

	bool doesImprovementConnectBonus(ImprovementTypes eImprovement, BonusTypes eBonus) const; // K-Mod

	bool isFriendlyTerritory(TeamTypes eTeam) const;

	int getEspionagePointsAgainstTeam(TeamTypes eIndex) const;																							// Exposed to Python
	void setEspionagePointsAgainstTeam(TeamTypes eIndex, int iValue);																							// Exposed to Python
	void changeEspionagePointsAgainstTeam(TeamTypes eIndex, int iChange);																				// Exposed to Python

	int getTotalUnspentEspionage() const; // K-Mod

	int getEspionagePointsEver() const;																							// Exposed to Python
	void setEspionagePointsEver(int iValue);																							// Exposed to Python
	void changeEspionagePointsEver(int iChange);																				// Exposed to Python

	int getCounterespionageTurnsLeftAgainstTeam(TeamTypes eIndex) const;																							// Exposed to Python
	void setCounterespionageTurnsLeftAgainstTeam(TeamTypes eIndex, int iValue);																		// Exposed to Python
	void changeCounterespionageTurnsLeftAgainstTeam(TeamTypes eIndex, int iChange);																// Exposed to Python

	int getCounterespionageModAgainstTeam(TeamTypes eIndex) const;																							// Exposed to Python
	void setCounterespionageModAgainstTeam(TeamTypes eIndex, int iValue);																		// Exposed to Python
	void changeCounterespionageModAgainstTeam(TeamTypes eIndex, int iChange);																// Exposed to Python

	void verifySpyUnitsValidPlot();

	void setForceRevealedBonus(BonusTypes eBonus, bool bRevealed);
	bool isForceRevealedBonus(BonusTypes eBonus) const;

	bool isBonusRevealed(BonusTypes eBonus) const; // K-Mod. (the definitive answer)

	// advc.108: New function
	void revealSurroundingPlots(CvPlot& center, int range) const;

	DllExport int countNumHumanGameTurnActive() const;
	void setTurnActive(bool bNewValue, bool bTurn = true);
	bool isTurnActive() const;

	bool hasShrine(ReligionTypes eReligion);

	DllExport void getCompletedSpaceshipProjects(std::map<ProjectTypes, int>& mapProjects) const;
	DllExport int getProjectPartNumber(ProjectTypes projectType, bool bAssert) const;
	DllExport bool hasLaunched() const;

	// advc.136a: Made public
	void testCircumnavigated();
	// <advc.127b> Both return -1 if no team member has a capital
	int getCapitalX() const;
	int getCapitalY() const;
	private: CvCity* getLeaderCapital() const; public:
	// </advc.127b>
	virtual void AI_init() = 0;
	virtual void AI_reset(bool bConstructor) = 0;
	virtual void AI_doTurnPre() = 0;
	virtual void AI_doTurnPost() = 0;
	virtual void AI_makeAssignWorkDirty() = 0;
	virtual void AI_updateAreaStrategies(bool bTargets = true) = 0;
	virtual bool AI_shareWar(TeamTypes eTeam) const = 0;			// Exposed to Python
	virtual void AI_updateWorstEnemy(bool updateRivalTrade = true) = 0; // advc.130p
	virtual int AI_getAtWarCounter(TeamTypes eIndex) const = 0;     // Exposed to Python
	virtual void AI_setAtWarCounter(TeamTypes eIndex, int iNewValue) = 0;
	virtual int AI_getAtPeaceCounter(TeamTypes eIndex) const = 0;
	virtual void AI_setAtPeaceCounter(TeamTypes eIndex, int iNewValue) = 0;
	virtual int AI_getHasMetCounter(TeamTypes eIndex) const = 0;
	virtual void AI_setHasMetCounter(TeamTypes eIndex, int iNewValue) = 0;
	virtual int AI_getOpenBordersCounter(TeamTypes eIndex) const = 0;
	virtual void AI_setOpenBordersCounter(TeamTypes eIndex, int iNewValue) = 0;
	virtual int AI_getDefensivePactCounter(TeamTypes eIndex) const = 0;
	virtual void AI_setDefensivePactCounter(TeamTypes eIndex, int iNewValue) = 0;
	virtual int AI_getShareWarCounter(TeamTypes eIndex) const = 0;
	virtual void AI_setShareWarCounter(TeamTypes eIndex, int iNewValue) = 0;
	virtual int AI_getWarSuccess(TeamTypes eIndex) const = 0;    // Exposed to Python
	virtual void AI_setWarSuccess(TeamTypes eIndex, int iNewValue) = 0;
	virtual void AI_changeWarSuccess(TeamTypes eIndex, int iChange) = 0;
	virtual int AI_getEnemyPeacetimeTradeValue(TeamTypes eIndex) const = 0;
	virtual void AI_setEnemyPeacetimeTradeValue(TeamTypes eIndex, int iNewValue) = 0;
	virtual int AI_getEnemyPeacetimeGrantValue(TeamTypes eIndex) const = 0;
	virtual void AI_setEnemyPeacetimeGrantValue(TeamTypes eIndex, int iNewValue) = 0;
	virtual WarPlanTypes AI_getWarPlan(TeamTypes eIndex) const = 0;
	virtual bool AI_isChosenWar(TeamTypes eIndex) const = 0;
	virtual bool AI_isSneakAttackPreparing(TeamTypes eIndex) const = 0;
	virtual bool AI_isSneakAttackReady(TeamTypes eIndex) const = 0;
	virtual void AI_setWarPlan(TeamTypes eIndex, WarPlanTypes eNewValue, bool bWar = true) = 0;

protected:

	TeamTypes m_eID; // advc.003: Moved here for easier access in the debugger
	int m_iNumMembers;
	int m_iAliveCount;
	int m_iEverAliveCount;
	int m_iNumCities;
	int m_iTotalPopulation;
	int m_iTotalLand;
	int m_iNukeInterception;
	int m_iExtraWaterSeeFromCount;
	int m_iMapTradingCount;
	int m_iTechTradingCount;
	int m_iGoldTradingCount;
	int m_iOpenBordersTradingCount;
	int m_iDefensivePactTradingCount;
	int m_iPermanentAllianceTradingCount;
	int m_iVassalTradingCount;
	int m_iBridgeBuildingCount;
	int m_iIrrigationCount;
	int m_iIgnoreIrrigationCount;
	int m_iWaterWorkCount;
	int m_iVassalPower;
	int m_iMasterPower;
	int m_iEnemyWarWearinessModifier;
	int m_iRiverTradeCount;
	int m_iEspionagePointsEver;

	bool m_bMapCentering;
	bool m_bCapitulated;

	//TeamTypes m_eID; // advc.003: Moved up

	int* m_aiStolenVisibilityTimer;
	int* m_aiWarWeariness;
	int* m_aiTechShareCount;
	int* m_aiCommerceFlexibleCount;
	int* m_aiExtraMoves;
	int* m_aiForceTeamVoteEligibilityCount;

	bool* m_abAtWar;
	bool* m_abHasMet;
	bool* m_abHasSeen; // K-Mod
	bool* m_abPermanentWarPeace;
	bool* m_abOpenBorders;
	bool m_abDisengage[MAX_CIV_PLAYERS]; // advc.034
	bool* m_abDefensivePact;
	bool* m_abForcePeace;
	bool* m_abVassal;
	// <advc.003b>
	TeamTypes masterId;
	PlayerTypes leaderId;
	// </advc.003b>
	bool* m_abCanLaunch;

	int* m_paiRouteChange;
	int* m_paiProjectCount;
	int* m_paiProjectDefaultArtTypes;
	std::vector<int> *m_pavProjectArtTypes;
	int* m_paiProjectMaking;
	int* m_paiUnitClassCount;
	int* m_paiBuildingClassCount;
	int* m_paiObsoleteBuildingCount;
	int* m_paiResearchProgress;
	int* m_paiTechCount;
	int* m_paiTerrainTradeCount;
	int* m_aiVictoryCountdown;

	int* m_aiEspionagePointsAgainstTeam;
	int* m_aiCounterespionageTurnsLeftAgainstTeam;
	int* m_aiCounterespionageModAgainstTeam;

	bool* m_pabHasTech;
	bool* m_pabNoTradeTech;

	int** m_ppaaiImprovementYieldChange;

	std::vector<BonusTypes> m_aeRevealedBonuses;

	void doWarWeariness();

	void updateTechShare(TechTypes eTech);
	void updateTechShare();

	void processTech(TechTypes eTech, int iChange);

	void cancelDefensivePacts();
	void allowDefensivePactsToBeCanceled(); // dlph.3
	void makeUnwillingToTalk(TeamTypes otherId); // advc.104i
	// <advc.039>
	CvWString const tradeItemString(TradeableItems itemType, int data,
			TeamTypes fromId) const; // </advc.039>
	void announceTechToPlayers(TechTypes eIndex, bool bPartial = false);

	virtual void read(FDataStreamBase* pStream);
	virtual void write(FDataStreamBase* pStream);
};

#endif
