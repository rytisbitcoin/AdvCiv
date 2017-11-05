#pragma once

// area.h

#ifndef CIV4_AREA_H
#define CIV4_AREA_H

//#include "CvStructs.h"

class CvCity;
class CvPlot;

class CvArea
{

public:

  CvArea();
  virtual ~CvArea();

  void init(int iID, bool bWater);
	void uninit();
	void reset(int iID = 0, bool bWater = false, bool bConstructorCall = false);

	int calculateTotalBestNatureYield() const;																// Exposed to Python

	int countCoastalLand() const;																							// Exposed to Python
	int countNumUniqueBonusTypes() const;																			// Exposed to Python
	int countHasReligion(ReligionTypes eReligion, PlayerTypes eOwner = NO_PLAYER) const;		// Exposed to Python
	int countHasCorporation(CorporationTypes eCorporation, PlayerTypes eOwner = NO_PLAYER) const;		// Exposed to Python

	int getID() const;																							// Exposed to Python
	void setID(int iID);

	int getNumTiles() const;																									// Exposed to Python
	bool isLake() const;																											// Exposed to Python
	// <advc.030>
	void updateLake(bool checkRepr = true);
	void setRepresentativeArea(int areaId);
	// Should only be needed for computing the equivalence classes
	int getRepresentativeArea() const;
	bool canBeEntered(CvArea const& from, CvUnit const* u = NULL) const;
	// </advc.030>
	void changeNumTiles(int iChange);

	int getNumOwnedTiles() const;																							// Exposed to Python
	int getNumUnownedTiles() const;																						// Exposed to Python
	void changeNumOwnedTiles(int iChange);

	// <advc.300>
	std::pair<int,int> countOwnedUnownedHabitableTiles(
			bool ignoreBarb = false) const;
	int countCivCities() const;
	int countCivs(bool subtractOCC = false) const; // with at least 1 city
	bool hasAnyAreaPlayerBonus(BonusTypes bId) const;
	int numBarbCitiesEver() const;
	void barbCityCreated();
	// </advc.300>

	int getNumRiverEdges() const;																							// Exposed to Python
	void changeNumRiverEdges(int iChange);

	int getNumCities() const;																									// Exposed to Python

	int getNumUnits() const;																									// Exposed to Python

	int getTotalPopulation() const;																						// Exposed to Python

	int getNumStartingPlots() const;																					// Exposed to Python
	void changeNumStartingPlots(int iChange);

	bool isWater() const;																											// Exposed to Python

	int getUnitsPerPlayer(PlayerTypes eIndex) const;													// Exposed to Python
	void changeUnitsPerPlayer(PlayerTypes eIndex, int iChange);

	int getAnimalsPerPlayer(PlayerTypes eIndex) const;												// Exposed to Python
	void changeAnimalsPerPlayer(PlayerTypes eIndex, int iChange);

	int getCitiesPerPlayer(PlayerTypes eIndex) const;													// Exposed to Python
	void changeCitiesPerPlayer(PlayerTypes eIndex, int iChange);

	int getPopulationPerPlayer(PlayerTypes eIndex) const;											// Exposed to Python
	void changePopulationPerPlayer(PlayerTypes eIndex, int iChange);

	int getBuildingGoodHealth(PlayerTypes eIndex) const;											// Exposed to Python
	void changeBuildingGoodHealth(PlayerTypes eIndex, int iChange);

	int getBuildingBadHealth(PlayerTypes eIndex) const;												// Exposed to Python
	void changeBuildingBadHealth(PlayerTypes eIndex, int iChange);

	int getBuildingHappiness(PlayerTypes eIndex) const;												// Exposed to Python
	void changeBuildingHappiness(PlayerTypes eIndex, int iChange);
	// <advc.310>
	int getContinentalTradeRoutes(PlayerTypes eIndex) const;												// Exposed to Python
	void changeContinentalTradeRoutes(PlayerTypes eIndex, int iChange);
	// </advc.310>
	int getFreeSpecialist(PlayerTypes eIndex) const;													// Exposed to Python
	void changeFreeSpecialist(PlayerTypes eIndex, int iChange);

	int getPower(PlayerTypes eIndex) const;																		// Exposed to Python
	void changePower(PlayerTypes eIndex, int iChange);

	int getBestFoundValue(PlayerTypes eIndex) const;													// Exposed to Python
	void setBestFoundValue(PlayerTypes eIndex, int iNewValue);

	int getNumRevealedTiles(TeamTypes eIndex) const;													// Exposed to Python
	int getNumUnrevealedTiles(TeamTypes eIndex) const;												// Exposed to Python
	void changeNumRevealedTiles(TeamTypes eIndex, int iChange);

	int getCleanPowerCount(TeamTypes eIndex) const;
	bool isCleanPower(TeamTypes eIndex) const;																// Exposed to Python
	void changeCleanPowerCount(TeamTypes eIndex, int iChange);

	int getBorderObstacleCount(TeamTypes eIndex) const;
	bool isBorderObstacle(TeamTypes eIndex) const;																// Exposed to Python
	void changeBorderObstacleCount(TeamTypes eIndex, int iChange);

	AreaAITypes getAreaAIType(TeamTypes eIndex) const;												// Exposed to Python
	void setAreaAIType(TeamTypes eIndex, AreaAITypes eNewValue);

	CvCity* getTargetCity(PlayerTypes eIndex) const;													// Exposed to Python
	void setTargetCity(PlayerTypes eIndex, CvCity* pNewValue);

	int getYieldRateModifier(PlayerTypes eIndex1, YieldTypes eIndex2) const;	// Exposed to Python
	void changeYieldRateModifier(PlayerTypes eIndex1, YieldTypes eIndex2, int iChange);

	int getNumTrainAIUnits(PlayerTypes eIndex1, UnitAITypes eIndex2) const;		// Exposed to Python
	void changeNumTrainAIUnits(PlayerTypes eIndex1, UnitAITypes eIndex2, int iChange);

	int getNumAIUnits(PlayerTypes eIndex1, UnitAITypes eIndex2) const;				// Exposed to Python
	void changeNumAIUnits(PlayerTypes eIndex1, UnitAITypes eIndex2, int iChange);

	int getNumBonuses(BonusTypes eBonus) const;																// Exposed to Python
	int getNumTotalBonuses() const;																						// Exposed to Python
	void changeNumBonuses(BonusTypes eBonus, int iChange);

	int getNumImprovements(ImprovementTypes eImprovement) const;							// Exposed to Python
	void changeNumImprovements(ImprovementTypes eImprovement, int iChange);

protected:

	int m_iID;
	int m_iNumTiles;
	int m_iNumOwnedTiles;
	int m_iNumRiverEdges;
	int m_iNumUnits;
	int m_iNumCities;
	int m_iTotalPopulation;
	int m_iNumStartingPlots;
	int nBarbCitiesEver; // advc.300

	bool m_bWater;
	// <advc.030>
	bool m_bLake;
	int reprAreaId; // </advc.030>
	int* m_aiUnitsPerPlayer;
	int* m_aiAnimalsPerPlayer;
	int* m_aiCitiesPerPlayer;
	int* m_aiPopulationPerPlayer;
	int* m_aiBuildingGoodHealth;
	int* m_aiBuildingBadHealth;
	int* m_aiBuildingHappiness;
	int* m_aiContinentalTradeRoutes; // advc.310
	int* m_aiFreeSpecialist;
	int* m_aiPower;
	int* m_aiBestFoundValue;
	int* m_aiNumRevealedTiles;
	int* m_aiCleanPowerCount;
	int* m_aiBorderObstacleCount;

	AreaAITypes* m_aeAreaAIType;

	IDInfo* m_aTargetCities;

	int** m_aaiYieldRateModifier;
	int** m_aaiNumTrainAIUnits;
	int** m_aaiNumAIUnits;

	int* m_paiNumBonuses;
	int* m_paiNumImprovements;

public:

	// for serialization
	virtual void read(FDataStreamBase* pStream);
	virtual void write(FDataStreamBase* pStream);

};

#endif
